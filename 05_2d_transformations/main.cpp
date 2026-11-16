#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void drawRect(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    rectangle(x1, y1, x2, y2);
}

int main()
{
    int gd = DETECT, gm;
    int ch;
    int x1 = 150, y1 = 150;
    int x2 = 250, y2 = 250;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (1)
    {
        cleardevice();
        outtextxy(10, 10, "Original Rectangle : WHITE");
        outtextxy(10, 25, "Transformed Rectangle : RED");
        drawRect(x1, y1, x2, y2, WHITE);

        printf("\n\n1. Translation");
        printf("\n2. Scaling");
        printf("\n3. Rotation");
        printf("\n4. Reflection");
        printf("\n5. Shearing");
        printf("\n6. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        cleardevice();
        drawRect(x1, y1, x2, y2, WHITE);

        switch (ch)
        {
        case 1:
        {
            int tx, ty;
            printf("Enter tx and ty : ");
            scanf("%d%d", &tx, &ty);
            drawRect(x1 + tx, y1 + ty, x2 + tx, y2 + ty, RED);
            break;
        }

        case 2:
        {
            float sx, sy;
            printf("Enter sx and sy : ");
            scanf("%f%f", &sx, &sy);
            drawRect(x1 * sx, y1 * sy, x2 * sx, y2 * sy, RED);
            break;
        }

        case 3:
        {
            float angle;
            printf("Enter Angle : ");
            scanf("%f", &angle);
            float rad = angle * 3.14 / 180;
            int X[4], Y[4];
            X[0] = x1; Y[0] = y1;
            X[1] = x2; Y[1] = y1;
            X[2] = x2; Y[2] = y2;
            X[3] = x1; Y[3] = y2;
            setcolor(RED);
            for (int i = 0; i < 4; i++)
            {
                int nx = X[i] * cos(rad) - Y[i] * sin(rad);
                int ny = X[i] * sin(rad) + Y[i] * cos(rad);
                X[i] = nx;
                Y[i] = ny;
            }
            line(X[0], Y[0], X[1], Y[1]);
            line(X[1], Y[1], X[2], Y[2]);
            line(X[2], Y[2], X[3], Y[3]);
            line(X[3], Y[3], X[0], Y[0]);
            break;
        }

        case 4:
        {
            drawRect(x1, -y2 + 480, x2, -y1 + 480, RED);
            break;
        }

        case 5:
        {
            float shx;
            printf("Enter Shearing Factor : ");
            scanf("%f", &shx);
            int X[4], Y[4];
            X[0] = x1 + shx * y1;
            Y[0] = y1;
            X[1] = x2 + shx * y1;
            Y[1] = y1;
            X[2] = x2 + shx * y2;
            Y[2] = y2;
            X[3] = x1 + shx * y2;
            Y[3] = y2;
            setcolor(RED);
            line(X[0], Y[0], X[1], Y[1]);
            line(X[1], Y[1], X[2], Y[2]);
            line(X[2], Y[2], X[3], Y[3]);
            line(X[3], Y[3], X[0], Y[0]);
            break;
        }

        case 6:
            closegraph();
            return 0;
        }
        getch();
    }
}
