#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(150, 200, 400, 400);       // House body
    line(150, 200, 275, 80);             // Roof
    line(275, 80, 400, 200);
    rectangle(250, 300, 310, 400);       // Door
    rectangle(175, 240, 225, 290);       // Window
    rectangle(325, 240, 375, 290);       // Window

    getch(); closegraph(); return 0;
}