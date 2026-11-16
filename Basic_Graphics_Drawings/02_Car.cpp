#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(100, 300, 160, 220);
    line(160, 220, 330, 220);
    line(330, 220, 400, 300);
    line(100, 300, 100, 350);
    line(100, 350, 430, 350);
    line(430, 350, 430, 300);
    line(400, 300, 430, 300);
    line(100, 300, 430, 300);
    circle(180, 350, 35);
    circle(350, 350, 35);
    line(190, 230, 190, 300);
    line(310, 230, 350, 300);

    getch(); closegraph(); return 0;
}