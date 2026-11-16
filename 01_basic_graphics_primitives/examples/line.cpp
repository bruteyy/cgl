#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    line(100, 150, 400, 150);
    getch();
    closegraph();
    return 0;
}
