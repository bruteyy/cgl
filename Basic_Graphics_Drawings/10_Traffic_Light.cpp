#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(240, 70, 400, 430);
    circle(320, 140, 45);                // Red light
    circle(320, 250, 45);                // Yellow light
    circle(320, 360, 45);                // Green light
    rectangle(300, 430, 340, 470);       // Stand

    getch(); closegraph(); return 0;
}