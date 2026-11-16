#include <graphics.h>
#include <conio.h>

// Fill inside an outline until the boundary colour is reached.
void boundaryFill(int x, int y, int fillColor, int boundaryColor)
{
    int color = getpixel(x, y);

    if (color != boundaryColor && color != fillColor)
    {
        putpixel(x, y, fillColor);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a closed boundary.
    setcolor(WHITE);
    rectangle(150, 100, 450, 350);

    // Fill inside, stopping at the white boundary.
    boundaryFill(200, 150, GREEN, WHITE);

    getch();
    closegraph();
    return 0;
}
