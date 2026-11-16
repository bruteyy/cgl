#include <graphics.h>
#include <conio.h>

// Fill all connected pixels having the old colour.
void floodFill(int x, int y, int oldColor, int newColor)
{
    int color = getpixel(x, y);

    if (color != oldColor || color == newColor)
        return;

    putpixel(x, y, newColor);

    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a closed rectangle.
    setcolor(WHITE);
    rectangle(150, 100, 450, 350);

    // Fill inside the rectangle.
    floodFill(200, 150, BLACK, YELLOW);

    getch();
    closegraph();
    return 0;
}
