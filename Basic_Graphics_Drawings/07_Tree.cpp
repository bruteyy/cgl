#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(280, 250, 340, 430);       // Trunk
    circle(310, 190, 80);
    circle(250, 230, 55);
    circle(370, 230, 55);

    getch(); closegraph(); return 0;
}