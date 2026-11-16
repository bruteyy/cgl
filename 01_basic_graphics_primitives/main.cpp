#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Point */
    putpixel(80, 80, WHITE);

    /* Line */
    line(100, 150, 400, 150);

    /* Triangle */
    line(200, 100, 100, 300);
    line(100, 300, 300, 300);
    line(300, 300, 200, 100);

    /* Hexagon */
    line(250, 100, 350, 150);
    line(350, 150, 350, 250);
    line(350, 250, 250, 300);
    line(250, 300, 150, 250);
    line(150, 250, 150, 150);
    line(150, 150, 250, 100);

    getch();
    closegraph();
    return 0;
}
