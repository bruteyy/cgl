#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(150, 80, 150, 430);             // Pole
    rectangle(150, 100, 400, 260);       // Flag outline
    line(150, 153, 400, 153);
    line(150, 206, 400, 206);
    circle(275, 180, 22);                // Chakra outline
    line(275, 158, 275, 202);
    line(253, 180, 297, 180);
    line(260, 165, 290, 195);
    line(290, 165, 260, 195);
    line(125, 430, 175, 430);

    getch(); closegraph(); return 0;
}