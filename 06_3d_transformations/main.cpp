#include <graphics.h>
#include <conio.h>
#include <stdio.h>

struct Point {
    int x, y, z;
};

void drawCube(struct Point p[])
{
    /* Front face */
    line(p[0].x, p[0].y, p[1].x, p[1].y);
    line(p[1].x, p[1].y, p[2].x, p[2].y);
    line(p[2].x, p[2].y, p[3].x, p[3].y);
    line(p[3].x, p[3].y, p[0].x, p[0].y);

    /* Back face */
    line(p[4].x, p[4].y, p[5].x, p[5].y);
    line(p[5].x, p[5].y, p[6].x, p[6].y);
    line(p[6].x, p[6].y, p[7].x, p[7].y);
    line(p[7].x, p[7].y, p[4].x, p[4].y);

    /* Connecting edges */
    line(p[0].x, p[0].y, p[4].x, p[4].y);
    line(p[1].x, p[1].y, p[5].x, p[5].y);
    line(p[2].x, p[2].y, p[6].x, p[6].y);
    line(p[3].x, p[3].y, p[7].x, p[7].y);
}

void main()
{
    int gd = DETECT, gm;
    int i, choice, tx, ty, tz;
    float sx, sy, sz;

    struct Point cube[8] = {
        {100, 100, 0},
        {200, 100, 0},
        {200, 200, 0},
        {100, 200, 0},
        {140, 60, 50},
        {240, 60, 50},
        {240, 160, 50},
        {140, 160, 50}
    };

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    drawCube(cube);                      /* original cube (white) */

    printf("\n1. Translation");
    printf("\n2. Scaling");
    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter tx ty tz : ");
        scanf("%d%d%d", &tx, &ty, &tz);
        for (i = 0; i < 8; i++)
        {
            cube[i].x += tx;
            cube[i].y += ty;
            cube[i].z += tz;
        }
        break;

    case 2:
        printf("Enter sx sy sz : ");
        scanf("%f%f%f", &sx, &sy, &sz);
        for (i = 0; i < 8; i++)
        {
            cube[i].x *= sx;
            cube[i].y *= sy;
            cube[i].z *= sz;
        }
        break;
    }

    /* cleardevice();  <- removed so the original white cube stays visible */
    setcolor(RED);
    drawCube(cube);                      /* transformed cube (red) */

    getch();
    closegraph();
}
