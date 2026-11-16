#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(300, 150, 25);                // Centre
    circle(300, 105, 25);
    circle(345, 150, 25);
    circle(300, 195, 25);
    circle(255, 150, 25);
    line(300, 220, 300, 400);            // Stem
    line(300, 300, 240, 260);            // Leaves
    line(300, 340, 360, 300);

    getch(); closegraph(); return 0;
}