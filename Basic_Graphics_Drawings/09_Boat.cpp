#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(150, 280, 450, 280);
    line(150, 280, 210, 360);
    line(210, 360, 390, 360);
    line(390, 360, 450, 280);            // Boat
    line(300, 100, 300, 280);            // Mast
    line(300, 110, 200, 250);
    line(200, 250, 300, 250);
    line(310, 120, 400, 250);
    line(310, 250, 400, 250);
    line(100, 390, 520, 390);            // Water

    getch(); closegraph(); return 0;
}