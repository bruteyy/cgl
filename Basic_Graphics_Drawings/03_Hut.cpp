#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(150, 220, 420, 400);
    line(120, 220, 285, 80);
    line(285, 80, 450, 220);
    line(120, 220, 450, 220);
    rectangle(250, 300, 320, 400);
    rectangle(175, 260, 225, 310);

    getch(); closegraph(); return 0;
}