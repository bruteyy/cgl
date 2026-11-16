#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(500, 100, 40);                // Sun
    line(0, 350, 150, 180);              // Mountains
    line(150, 180, 300, 350);
    line(200, 350, 370, 150);
    line(370, 150, 540, 350);
    line(0, 350, 640, 350);              // Ground
    rectangle(80, 300, 110, 390);        // Tree trunk
    circle(95, 270, 45);                 // Tree top
    line(0, 390, 640, 390);

    getch(); closegraph(); return 0;
}