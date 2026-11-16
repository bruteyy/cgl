#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int x, y;
    int y0 = 240;              /* midline (vertical centre) */
    float A = 50;              /* amplitude */
    float f = 0.03;            /* frequency */

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* reference axis */
    line(0, y0, 639, y0);

    /* plot the sine wave point by point */
    for (x = 0; x <= 639; x++)
    {
        y = (int)(y0 - A * sin(f * x) + 0.5);
        putpixel(x, y, YELLOW);
    }

    getch();
    closegraph();
    return 0;
}
