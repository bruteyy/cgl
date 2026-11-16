#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(200, 100, 400, 250);       // Head
    circle(250, 170, 20);                // Eyes
    circle(350, 170, 20);
    line(270, 220, 330, 220);            // Mouth
    rectangle(250, 250, 350, 370);       // Body
    line(200, 280, 130, 350);            // Arms
    line(400, 280, 470, 350);
    line(270, 370, 240, 430);            // Legs
    line(330, 370, 360, 430);
    line(300, 100, 300, 60);             // Antenna
    circle(300, 50, 10);

    getch(); closegraph(); return 0;
}