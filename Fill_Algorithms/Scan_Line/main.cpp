#include <graphics.h>
#include <conio.h>

// Sort intersection x-coordinates in increasing order.
void sortPoints(int x[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int px[5] = {150, 300, 450, 400, 200};
    int py[5] = {150, 80, 150, 350, 350};
    int y, i, j, k, n = 5;
    int intersections[10];
    float x;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw polygon outline.
    setcolor(WHITE);
    for (i = 0; i < n; i++)
        line(px[i], py[i], px[(i + 1) % n], py[(i + 1) % n]);

    // Process each horizontal scan line.
    setcolor(YELLOW);
    for (y = 80; y <= 350; y++)
    {
        k = 0;

        // Find where this scan line cuts polygon edges.
        for (i = 0; i < n; i++)
        {
            j = (i + 1) % n;

            if ((py[i] <= y && py[j] > y) ||
                (py[j] <= y && py[i] > y))
            {
                x = px[i] + (float)(y - py[i]) *
                    (px[j] - px[i]) / (py[j] - py[i]);

                intersections[k] = (int)x;
                k++;
            }
        }

        // Sort intersections and fill between pairs.
        sortPoints(intersections, k);

        for (i = 0; i + 1 < k; i += 2)
            line(intersections[i], y, intersections[i + 1], y);
    }

    getch();
    closegraph();
    return 0;
}
