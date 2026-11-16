#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(100, 150, 500, 340);       // Bus body
    line(100, 230, 500, 230);
    rectangle(130, 175, 210, 220);       // Windows
    rectangle(225, 175, 305, 220);
    rectangle(320, 175, 400, 220);
    rectangle(415, 175, 475, 220);
    circle(190, 350, 35);                // Wheels
    circle(420, 350, 35);

    getch(); closegraph(); return 0;
}