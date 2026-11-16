#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Region Code Values
#define LEFT 1
#define RIGHT 2
#define TOP 4
#define BOTTOM 8

// Clipping Window Coordinates
int xmin = 100, ymin = 100, xmax = 300, ymax = 250;

// Function to calculate region code
int code(float x, float y)
{
    int c = 0;              // Assume point is inside

    if (x < xmin)
        c |= LEFT;          // Point is left of window
    if (x > xmax)
        c |= RIGHT;         // Point is right of window
    if (y < ymin)
        c |= TOP;           // Point is above window
    if (y > ymax)
        c |= BOTTOM;        // Point is below window

    return c;
}

void main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;   // Line endpoints
    float x, y;             // Intersection point
    int c1, c2, c;          // Region codes

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Read line coordinates
    printf("Enter x1 y1 : ");
    scanf("%f%f", &x1, &y1);
    printf("Enter x2 y2 : ");
    scanf("%f%f", &x2, &y2);

    // Draw clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    line(x1, y1, x2, y2);

    // Find region codes
    c1 = code(x1, y1);
    c2 = code(x2, y2);

    // Repeat until both points are inside
    while (c1 || c2)
    {
        // Reject if both points are outside on same side
        if (c1 & c2)
        {
            printf("Line Rejected");
            getch();
            closegraph();
            return;
        }

        // Select the outside point
        if (c1 != 0)
            c = c1;
        else
            c = c2;

        // Clip against Left boundary
        if (c & LEFT)
        {
            y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            x = xmin;
        }
        // Clip against Right boundary
        else if (c & RIGHT)
        {
            y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            x = xmax;
        }
        // Clip against Top boundary
        else if (c & TOP)
        {
            x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            y = ymin;
        }
        // Clip against Bottom boundary
        else
        {
            x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            y = ymax;
        }

        // Replace first endpoint if it was outside
        if (c == c1)
        {
            x1 = x;
            y1 = y;
            // Compute new region code
            c1 = code(x1, y1);
        }
        // Replace second endpoint if it was outside
        else
        {
            x2 = x;
            y2 = y;
            // Compute new region code
            c2 = code(x2, y2);
        }
    }

    // Draw clipped line in red
    setcolor(RED);
    line(x1, y1, x2, y2);

    printf("Line Accepted");

    getch();
    closegraph();
}
