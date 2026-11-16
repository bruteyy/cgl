#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    int y;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    // Draw Rectangle
    rectangle(150,100,350,250);
    // Set Fill Color
    setcolor(RED);
    // Scan Line Filling
    for(y = 101; y < 250; y++)
    {
        line(151, y, 349, y);
    }
    getch();
    closegraph();
    return 0;
}
