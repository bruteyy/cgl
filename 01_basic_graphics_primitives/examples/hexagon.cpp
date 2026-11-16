#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    line(250,100,350,150);
    line(350,150,350,250);
    line(350,250,250,300);
    line(250,300,150,250);
    line(150,250,150,150);
    line(150,150,250,100);
    getch();
    closegraph();
    return 0;
}
