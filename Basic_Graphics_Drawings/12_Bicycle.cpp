#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(150, 320, 65);                // Wheels
    circle(430, 320, 65);
    line(150, 320, 260, 320);
    line(260, 320, 330, 220);
    line(330, 220, 430, 320);
    line(150, 320, 230, 220);
    line(230, 220, 330, 220);
    line(230, 220, 260, 320);
    line(330, 220, 370, 220);            // Handle
    line(230, 220, 210, 190);            // Seat post
    line(190, 190, 240, 190);

    getch(); closegraph(); return 0;
}