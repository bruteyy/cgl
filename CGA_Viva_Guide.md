# CGA Practicals 1–6: Viva Questions & Answers
## Easy explanations based on the actual C++ code

This guide is based on the `main.cpp` files and README files in the supplied `CGA_Practicals.zip`.

## Quick Navigation — Jump to Any Practical

Click a practical below to jump directly to its viva questions and code explanation.

1. [Practical 1 — Basic Graphics Primitives](#practical-1--basic-graphics-primitives)
2. [Practical 2 — Concave Polygon Filling Using Scan-Line Algorithm](#practical-2--concave-polygon-filling-using-scan-line-algorithm)
3. [Practical 3 — Cohen-Sutherland Line Clipping](#practical-3--cohen-sutherland-line-clipping)
4. [Practical 4 — Curve Generation Using a Sine Wave](#practical-4--curve-generation-using-a-sine-wave)
5. [Practical 5 — 2D Transformations](#practical-5--2d-transformations)
6. [Practical 6 — 3D Points and Transformations](#practical-6--3d-points-and-transformations)

---

**How to use this guide:** First understand the “What the program does” section for each practical. Then practise saying the short answers aloud. The extra code questions prepare you for questions such as “Why did you use this function?”, “What does this variable do?” and “Explain this line.”

> **Important:** A few README descriptions do not exactly match the submitted source code. Where that happens, this guide explains what the actual `main.cpp` implements and clearly points out the difference. Do not claim that a feature exists in the code if it does not.

---

# Practical 1 — Basic Graphics Primitives

## 1. What the program does

This program opens a graphics screen and draws four basic things:
1. A single white pixel at coordinate `(80, 80)`.
2. A horizontal line from `(100, 150)` to `(400, 150)`.
3. A triangle by joining three points.
4. A hexagon by joining six points.

The program uses the `graphics.h` library. It does not use a special triangle or hexagon function. Instead, it draws each side using the `line()` function.

## 2. Understand the important code

```cpp
#include <graphics.h>
#include <conio.h>
```
- `graphics.h` provides graphics functions such as `initgraph()`, `line()`, `putpixel()` and `closegraph()`.
- `conio.h` provides `getch()`, which waits for a key press.

```cpp
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
```
- `gd` means graphics driver.
- `gm` means graphics mode.
- `DETECT` asks the graphics system to detect a suitable driver/mode.
- `initgraph()` starts graphics mode.
- The final argument is the path to the BGI driver files. The path must match the computer's Turbo C++ installation.

```cpp
putpixel(80, 80, WHITE);
```
Plots one pixel at x = 80, y = 80, in white.

```cpp
line(100, 150, 400, 150);
```
Draws a line from the first coordinate `(100,150)` to the second coordinate `(400,150)`.

The triangle and hexagon are made by calling `line()` repeatedly. To close a polygon, the last point must be joined back to the first point.

```cpp
getch();
closegraph();
```
`getch()` waits for a key so the output remains visible. `closegraph()` closes graphics mode and releases graphics resources.

## 3. Viva questions and answers

**Q1. What is a computer graphics primitive?**  
**Answer:** A graphics primitive is a basic building block used to create a drawing. Examples are points, lines, circles and polygons. Complex pictures can be made by combining these basic shapes.

**Q2. What are the primitives used in this program?**  
**Answer:** The program uses a point, a line, a triangle and a hexagon. The point is drawn using `putpixel()`. The line and the polygon sides are drawn using `line()`.

**Q3. What is the use of `graphics.h`?**  
**Answer:** `graphics.h` is a graphics library used in Turbo C++/BGI. It provides functions to draw shapes, set colours, plot pixels and control graphics mode.

**Q4. What does `initgraph()` do?**  
**Answer:** `initgraph()` initializes the graphics system and switches the program into graphics mode. Without it, BGI drawing functions cannot work correctly.

**Q5. What is `DETECT`?**  
**Answer:** `DETECT` is a constant used to request automatic detection of the graphics driver. The graphics system selects a suitable driver and mode.

**Q6. What is the BGI path?**  
**Answer:** BGI stands for Borland Graphics Interface. The BGI path tells the program where the graphics driver files are stored. In this code, the path is `C:\\TURBOC3\\BGI`. If Turbo C++ is installed somewhere else, this path may need to be changed.

**Q7. How do you draw a single point?**  
**Answer:** We use `putpixel(x, y, color)`. It colours one pixel at the given x and y coordinate. In our program, `putpixel(80, 80, WHITE)` plots a white point.

**Q8. What is the difference between `putpixel()` and `line()`?**  
**Answer:** `putpixel()` colours one individual pixel. `line()` draws a continuous line between two given endpoints.

**Q9. How is a triangle drawn in this program?**  
**Answer:** We select three vertices and connect them using three `line()` calls. The third line joins the last vertex back to the first vertex, closing the triangle.

**Q10. How is a hexagon drawn?**  
**Answer:** A hexagon has six vertices and six sides. We connect each vertex to the next one using `line()`, and then connect the sixth vertex back to the first vertex.

**Q11. What are x and y coordinates?**  
**Answer:** They specify the position of a point on the screen. The x-coordinate controls horizontal position and the y-coordinate controls vertical position. In the usual BGI screen coordinate system, the origin is at the top-left, x increases to the right and y increases downward.

**Q12. Why is `getch()` used?**  
**Answer:** It waits for the user to press a key. It keeps the graphics output visible instead of allowing the program to close immediately.

**Q13. What does `closegraph()` do?**  
**Answer:** It closes graphics mode and releases the resources used by the graphics system.

**Q14. Can we draw a polygon without `drawpoly()`?**  
**Answer:** Yes. We can join its vertices with multiple `line()` calls, as this program does. Another option in BGI is `drawpoly()`.

**Q15. What happens if we do not join the last vertex to the first?**  
**Answer:** The shape remains open. It will look like a series of connected lines rather than a closed polygon.

**Q16. What is the difference between a regular and an irregular polygon?**  
**Answer:** In a regular polygon, all sides and all interior angles are equal. In an irregular polygon, the sides or angles are not all equal.

**Q17. What is the output of this program?**  
**Answer:** The graphics screen displays one white point, one horizontal line, one triangle and one hexagon.

---

# Practical 2 — Concave Polygon Filling Using Scan-Line Algorithm

## 1. What the program does

This program lets the user create a polygon using mouse clicks and fills it using the scan-line algorithm.

- Left-click adds a polygon vertex.
- Right-click finishes collecting vertices.
- The program joins the last vertex to the first to close the polygon.
- It scans the polygon horizontally, one y-coordinate at a time.
- For each scanline, it finds where that horizontal line intersects the polygon edges.
- It sorts the intersection x-coordinates and draws horizontal lines between pairs.
- The fill colour alternates between red and yellow bands.
- Finally, it redraws the polygon boundary in white.

The code allows up to 50 vertices because `MAXV` is set to 50. At least three vertices are needed for a valid polygon.

## 2. Understand the important code

### Header files

```cpp
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
```
- `graphics.h`: drawing functions.
- `conio.h`: `getch()`.
- `dos.h`: DOS interrupt support such as `int86()`.
- `stdio.h`: input/output functions such as `printf()`.

### Maximum vertices and storage

```cpp
#define MAXV 50
int vx[MAXV], vy[MAXV];
```
- `MAXV` sets the maximum number of polygon vertices to 50.
- `vx[]` stores the x-coordinate of each vertex.
- `vy[]` stores the y-coordinate of each vertex.
- The same index in both arrays represents one point. For example, `(vx[0], vy[0])` is the first vertex.

```cpp
float xs[MAXV], t;
```
`xs[]` stores the x-coordinates where the current scanline intersects polygon edges. `t` is a temporary variable used while sorting.

### Mouse functions

The program uses mouse interrupt `0x33` through `int86()`.

- `initMouse()` sets `AX = 0` to initialize the mouse and checks whether a mouse is available.
- `showMouse()` sets `AX = 1` to show the mouse pointer.
- `hideMouse()` sets `AX = 2` to hide the pointer while drawing.
- `getMouse()` sets `AX = 3` to read the mouse buttons and position.
- The mouse x-coordinate is returned in `CX`, y-coordinate in `DX`, and button status in `BX`.
- In this program, bit 0 indicates the left button and bit 1 indicates the right button.

```cpp
if (btn & 1)
```
Checks whether the left mouse button is pressed.

```cpp
if (btn & 2)
```
Checks whether the right mouse button is pressed.

The `&` operator here is bitwise AND. It tests a particular button bit.

### Closing the polygon

```cpp
line(vx[n - 1], vy[n - 1], vx[0], vy[0]);
```
Connects the last entered vertex to the first vertex. This closes the polygon.

### Finding the vertical range

The program finds `ymin` and `ymax`, the smallest and largest y-coordinates among all vertices. It only needs to scan between these values.

### Scan-line intersection formula

```cpp
xs[cnt] = vx[i] + (float)(y - vy[i]) * (vx[j] - vx[i])
                         / (vy[j] - vy[i]);
```
This calculates the x-coordinate where the horizontal scanline at y intersects an edge from vertex `i` to vertex `j`.

### Avoiding incorrect intersections

```cpp
if (vy[i] == vy[j])
    continue;
```
Skips horizontal edges. They do not create a single crossing point for a horizontal scanline.

```cpp
if ((vy[i] <= y && y < vy[j]) || (vy[j] <= y && y < vy[i]))
```
This is a half-open edge test. It includes one endpoint of an edge but excludes the other endpoint in a consistent way. This prevents a shared vertex from being counted twice.

### Sorting and filling

The nested loops sort the intersection x-values in ascending order using a simple bubble-sort-style method.

```cpp
for (k = 0; k + 1 < cnt; k += 2)
    line((int)xs[k], y, (int)xs[k + 1], y);
```
This fills between the first and second intersection, then the third and fourth, and so on. This is the odd-even filling rule.

```cpp
if ((y / 4) % 2 == 0)
    setcolor(RED);
else
    setcolor(YELLOW);
```
Changes the fill colour in bands of four scanlines, alternating red and yellow.

## 3. Viva questions and answers

**Q1. What is a polygon?**  
**Answer:** A polygon is a closed 2D shape made up of straight line segments. The line segments meet at points called vertices. A triangle, rectangle and pentagon are examples.

**Q2. What is a concave polygon?**  
**Answer:** A concave polygon has at least one interior angle greater than 180 degrees. A horizontal line can enter and leave a concave polygon multiple times, so it may intersect the polygon boundary more than twice.

**Q3. What is polygon filling?**  
**Answer:** Polygon filling is the process of colouring the inside area of a closed polygon while keeping its boundary visible.

**Q4. What is the scan-line algorithm?**  
**Answer:** The scan-line algorithm fills a polygon one horizontal line at a time. For each horizontal line, it finds the points where the line intersects polygon edges, sorts those points from left to right, and fills between pairs of intersections.

**Q5. Why is it called a scan-line algorithm?**  
**Answer:** Because the algorithm scans the polygon horizontally, line by line, from its minimum y-coordinate to its maximum y-coordinate.

**Q6. Why can the scan-line algorithm fill a concave polygon?**  
**Answer:** A concave polygon may have multiple inside and outside sections along one scanline. The algorithm sorts all intersections and fills between pairs, so it can handle more than one filled span on the same scanline.

**Q7. What is a vertex?**  
**Answer:** A vertex is a corner point where two polygon edges meet.

**Q8. Why do we need at least three vertices?**  
**Answer:** Three non-collinear vertices are the minimum needed to form a closed polygon. With fewer than three vertices, the program displays “Invalid polygon.”

**Q9. Why is `MAXV` defined as 50?**  
**Answer:** It limits the number of vertices the program can store. The arrays are declared with 50 elements, so the program can store up to 50 polygon vertices.

**Q10. Why are `vx[]` and `vy[]` separate arrays?**  
**Answer:** One array stores all x-coordinates and the other stores all y-coordinates. Matching indices form a point. For example, `vx[2]` and `vy[2]` give the third vertex.

**Q11. How does the user draw the polygon?**  
**Answer:** The user left-clicks at each corner to add a vertex. When all vertices are entered, the user right-clicks to finish. The program then closes and fills the polygon.

**Q12. How does the program detect a left click?**  
**Answer:** The mouse status is returned in `btn`. The expression `btn & 1` checks bit 0, which represents the left mouse button in this program.

**Q13. How does the program detect a right click?**  
**Answer:** The expression `btn & 2` checks bit 1, which represents the right mouse button.

**Q14. What is `int86()`?**  
**Answer:** `int86()` is a Turbo C/DOS function used to call a software interrupt. This program calls interrupt `0x33`, which is the traditional DOS mouse interrupt.

**Q15. What is interrupt `0x33` used for here?**  
**Answer:** It is used to communicate with the mouse driver. The program uses different values in the AX register to initialize, show, hide and read the mouse.

**Q16. Why do we hide the mouse pointer while drawing?**  
**Answer:** To avoid the pointer interfering visually with the graphics being drawn. The program hides it before drawing a new boundary segment and shows it again afterward.

**Q17. What is a scanline?**  
**Answer:** A scanline is a horizontal line across the graphics screen. The program processes one y-coordinate at a time.

**Q18. Why do we calculate `ymin` and `ymax`?**  
**Answer:** They define the vertical range of the polygon. The program only needs to scan from the smallest vertex y-coordinate to the largest vertex y-coordinate.

**Q19. Why are horizontal edges ignored?**  
**Answer:** A horizontal edge has the same y-coordinate at both ends. It does not give one unique crossing point for a horizontal scanline, and the intersection formula would divide by zero because `yj - yi` is zero.

**Q20. Why do we sort the intersection points?**  
**Answer:** The polygon edges are checked in their stored order, not necessarily from left to right. Sorting makes the x-coordinates go from smallest to largest, so the program can correctly pair them and fill the inside sections.

**Q21. What is the odd-even rule?**  
**Answer:** After sorting the intersections from left to right, the scanline is considered inside the polygon between the first and second intersections, outside until the third, inside between the third and fourth, and so on. So the program fills pairs: 1–2, 3–4, etc.

**Q22. Why is the half-open condition used?**  
**Answer:** It avoids counting a shared polygon vertex twice when a scanline passes through it. Counting the same vertex twice could create an incorrect number of intersections and incorrect filling.

**Q23. What is the purpose of the `cnt` variable?**  
**Answer:** `cnt` counts how many edge intersections were found for the current scanline. It is reset to zero for every new scanline.

**Q24. What is the purpose of `j = (i + 1) % n`?**  
**Answer:** It selects the next vertex to form an edge. The modulo operator `%` makes the last vertex connect back to vertex zero, so the polygon is treated as closed.

**Q25. Which sorting technique is used?**  
**Answer:** The code uses a simple bubble-sort-style nested loop. It compares neighbouring x-values and swaps them if they are in the wrong order.

**Q26. How is the fill colour changed?**  
**Answer:** The program uses `setcolor()`. It alternates red and yellow based on `(y / 4) % 2`, creating colour bands four scanlines high.

**Q27. Why is the boundary drawn again after filling?**  
**Answer:** The fill lines may overlap or visually cover parts of the boundary. Redrawing the polygon edges in white makes the outline clear.

**Q28. What is the difference between convex and concave polygons?**  
**Answer:** In a convex polygon, every interior angle is less than 180 degrees and a line segment between any two points inside stays inside. A concave polygon has at least one interior angle greater than 180 degrees and can have an inward dent.

**Q29. What happens if the user enters fewer than three vertices?**  
**Answer:** The program displays “Invalid polygon”, waits for a key press, closes graphics mode and ends.

**Q30. What is the final output?**  
**Answer:** The user-drawn polygon is filled with alternating red and yellow horizontal bands, and its boundary is drawn in white.

---

# Practical 3 — Cohen-Sutherland Line Clipping

## 1. What the program does

This program clips a line against a rectangular clipping window.

The clipping window is fixed in the code:
- `xmin = 100`
- `ymin = 100`
- `xmax = 300`
- `ymax = 250`

The user enters two endpoints of a line. The program draws the rectangle and the original line. It then calculates a 4-bit region code, also called an outcode, for each endpoint.

Depending on the outcodes:
- It accepts the line if both endpoints are inside.
- It rejects the line if both endpoints are outside on the same side.
- Otherwise, it finds an intersection with a window boundary, replaces an outside endpoint, calculates its new outcode and repeats.

If accepted, the clipped part is drawn in red.

## 2. Understand the important code

### Header files and region constants

```cpp
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define LEFT 1
#define RIGHT 2
#define TOP 4
#define BOTTOM 8
```
The four constants represent four outside regions:
- LEFT = `0001` (1)
- RIGHT = `0010` (2)
- TOP = `0100` (4)
- BOTTOM = `1000` (8)

Each is a separate bit, so bitwise operators can test the region.

### Clipping window

```cpp
int xmin = 100, ymin = 100, xmax = 300, ymax = 250;
```
These values define the rectangle. A point inside the rectangle must satisfy `xmin <= x <= xmax` and `ymin <= y <= ymax`, according to the code's coordinate comparisons.

### Region-code function

```cpp
int code(float x, float y)
{
    int c = 0;
    if (x < xmin) c |= LEFT;
    if (x > xmax) c |= RIGHT;
    if (y < ymin) c |= TOP;
    if (y > ymax) c |= BOTTOM;
    return c;
}
```
- Starts with code zero, meaning inside.
- Checks whether the point is left, right, above or below the window.
- `|=` is bitwise OR assignment. It sets the appropriate bit without clearing bits already set.
- Returns the final 4-bit region code.

### Accept and reject tests

```cpp
while (c1 || c2)
```
Repeats while at least one endpoint is outside.

```cpp
if (c1 & c2)
```
If the bitwise AND is non-zero, both endpoints share at least one outside region. The line can be rejected without calculating intersections.

If both outcodes are zero, the loop is not entered and the line is accepted.

### Intersection calculations

For a left boundary, the x-coordinate is fixed at `xmin`, and y is calculated from the line equation.

For a right boundary, x is fixed at `xmax`.

For a top boundary, y is fixed at `ymin`, and x is calculated.

For a bottom boundary, y is fixed at `ymax`.

After calculating the intersection, the code replaces whichever endpoint was outside and recalculates that endpoint's outcode.

## 3. Viva questions and answers

**Q1. What is clipping in computer graphics?**  
**Answer:** Clipping is the process of removing the parts of an object that lie outside a selected viewing area. Only the portion inside the clipping window is displayed.

**Q2. What is line clipping?**  
**Answer:** Line clipping means checking a line against a clipping window and keeping only the part of the line that lies inside that window.

**Q3. What is a clipping window?**  
**Answer:** A clipping window is a selected rectangular area. Only the portion of a line or object inside this area is accepted for display.

**Q4. Which line clipping algorithm is used in this practical?**  
**Answer:** The Cohen-Sutherland line clipping algorithm.

**Q5. What is an outcode or region code?**  
**Answer:** An outcode is a 4-bit code assigned to each line endpoint. It tells whether the point is outside the clipping window on the left, right, top or bottom. If all four bits are zero, the point is inside.

**Q6. What are the four region-code bits?**  
**Answer:** LEFT is `0001`, RIGHT is `0010`, TOP is `0100` and BOTTOM is `1000` in this program.

**Q7. Why are bitwise operators used?**  
**Answer:** Each outside region is represented by a separate bit. Bitwise OR sets the required region bits, and bitwise AND checks whether two endpoints share an outside region.

**Q8. What does `c |= LEFT` mean?**  
**Answer:** It performs bitwise OR between `c` and `LEFT`, then stores the result back in `c`. It sets the LEFT bit while keeping any other bits that are already set.

**Q9. When is a line trivially accepted?**  
**Answer:** When both endpoint outcodes are zero. That means both endpoints are inside the clipping window, so the complete line is accepted.

**Q10. When is a line trivially rejected?**  
**Answer:** When the bitwise AND of the two endpoint outcodes is non-zero. This means both endpoints are outside on at least one common side of the window, so the line cannot pass through the rectangular window.

**Q11. What does `c1 & c2` check?**  
**Answer:** It checks whether the two outcodes have any common set bit. If the result is non-zero, the line is rejected.

**Q12. Why does the program use a `while` loop?**  
**Answer:** After clipping one endpoint at a boundary, the new endpoint may still be outside another boundary. So the program recalculates the outcode and repeats the accept/reject tests until the line is accepted or rejected.

**Q13. How do you find the intersection with the left boundary?**  
**Answer:** The x-coordinate is set to `xmin`. The y-coordinate is calculated using the line equation: `y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1)`.

**Q14. How do you find the intersection with the right boundary?**  
**Answer:** The x-coordinate is set to `xmax`, and y is calculated using the same line equation with `xmax`.

**Q15. How do you find the intersection with the top boundary?**  
**Answer:** The y-coordinate is set to `ymin`. The x-coordinate is calculated using `x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1)`.

**Q16. How do you find the intersection with the bottom boundary?**  
**Answer:** The y-coordinate is set to `ymax`, and x is calculated using the same horizontal-boundary formula with `ymax`.

**Q17. What does the `code()` function do?**  
**Answer:** It checks the position of a point relative to the clipping window and returns its 4-bit outcode.

**Q18. Why are the endpoints stored as floating-point values?**  
**Answer:** The intersection of a line and a window boundary may have decimal coordinates. Using `float` helps preserve those fractional values during clipping calculations.

**Q19. What happens after an intersection is calculated?**  
**Answer:** The program replaces the outside endpoint with the intersection point and calculates a new outcode for that endpoint. Then it repeats the clipping tests.

**Q20. What is the difference between accepting and rejecting a line?**  
**Answer:** Accepting means the line has a visible portion inside the clipping window. Rejecting means there is no portion of the line inside the window.

**Q21. What are the clipping window coordinates in this program?**  
**Answer:** The window's top-left and bottom-right limits are defined by `xmin = 100`, `ymin = 100`, `xmax = 300` and `ymax = 250`.

**Q22. What do the colours represent in the output?**  
**Answer:** The original line is drawn using the default drawing colour, and the accepted clipped segment is drawn in red.

**Q23. What is the main advantage of Cohen-Sutherland?**  
**Answer:** It can quickly accept or reject many lines using simple 4-bit outcodes, without calculating intersections when they are unnecessary.

**Q24. What is the final output?**  
**Answer:** The program displays the clipping rectangle and original line. If a part of the line lies inside the rectangle, that clipped part is drawn in red and “Line Accepted” is printed. Otherwise, “Line Rejected” is printed.

---

# Practical 4 — Curve Generation Using a Sine Wave

## 1. What the program does

This program generates a sine wave by calculating its y-coordinate for each x-coordinate and plotting the resulting pixel.

The equation used is:

`y = y0 - A * sin(f * x)`

The values in the program are:
- `y0 = 240`: vertical centre line.
- `A = 50`: amplitude, or height from the centre line to a peak.
- `f = 0.03`: frequency factor, which controls how quickly the wave repeats.

The program first draws a horizontal reference line at y = 240. Then a `for` loop runs x from 0 to 639. For every x, it calculates y and plots a yellow pixel.

## 2. Understand the important code

```cpp
#include <graphics.h>
#include <conio.h>
#include <math.h>
```
- `graphics.h` is used for drawing.
- `conio.h` provides `getch()`.
- `math.h` provides the `sin()` function.

```cpp
int y0 = 240;
float A = 50;
float f = 0.03;
```
These store the midline, amplitude and frequency factor.

```cpp
line(0, y0, 639, y0);
```
Draws a horizontal reference axis from the left edge to the right edge of the 640-pixel-wide drawing area.

```cpp
for (x = 0; x <= 639; x++)
```
Moves through every horizontal pixel position.

```cpp
y = (int)(y0 - A * sin(f * x) + 0.5);
```
Calculates the y-position. `sin()` returns a floating-point value. The `+ 0.5` and integer conversion are used as a simple rounding approach for the positive screen y-values produced here.

```cpp
putpixel(x, y, YELLOW);
```
Plots one yellow pixel at the calculated coordinate.

## 3. Viva questions and answers

**Q1. What is curve generation?**  
**Answer:** Curve generation is the process of creating a curve by calculating points using a mathematical equation and plotting those points on the screen.

**Q2. Which curve is generated in this practical?**  
**Answer:** A sine wave is generated using the mathematical sine function.

**Q3. What is the equation used in the program?**  
**Answer:** The equation is `y = y0 - A * sin(f * x)`. Here, `y0` is the midline, `A` is the amplitude and `f` controls the wave's oscillation.

**Q4. What is a sine wave?**  
**Answer:** A sine wave is a smooth, repeating wave that moves above and below a central line. It is based on the sine trigonometric function.

**Q5. What is amplitude?**  
**Answer:** Amplitude is the maximum distance between the wave's centre line and its peak or trough. In this program, the amplitude is 50 pixels.

**Q6. What is frequency in this code?**  
**Answer:** The variable `f` controls how quickly the sine wave oscillates as x increases. A larger frequency factor makes the wave complete more cycles over the same horizontal distance.

**Q7. What is `y0`?**  
**Answer:** `y0` is the vertical centre line or midline of the wave. In this program, it is 240, so the reference line is drawn at y = 240.

**Q8. Why do we use `sin()`?**  
**Answer:** The `sin()` function calculates the sine of an angle. Its output is used in the equation to calculate the vertical position of each point of the wave.

**Q9. Why is `math.h` included?**  
**Answer:** Because the program uses the mathematical `sin()` function, which is declared in `math.h`.

**Q10. Does the `sin()` function take degrees or radians?**  
**Answer:** The C/C++ `sin()` function takes its input in radians, not degrees. In this program, `f * x` is used as the angle in radians.

**Q11. Why is the sine term subtracted from `y0`?**  
**Answer:** On a computer screen, y-coordinates increase downward. Subtracting the sine value makes positive sine values move upward on the screen, which gives the expected wave orientation.

**Q12. Why is `putpixel()` used?**  
**Answer:** The program generates the curve point by point. `putpixel()` plots each calculated point in yellow. Since x increases by one pixel each time, the plotted points form a continuous-looking wave.

**Q13. Why does the loop run from 0 to 639?**  
**Answer:** The graphics area used by the program is treated as 640 pixels wide, with x-coordinates from 0 through 639. The loop calculates one point for every horizontal pixel position.

**Q14. What happens if amplitude is increased?**  
**Answer:** The wave becomes taller because its peaks and troughs move farther from the midline.

**Q15. What happens if amplitude is decreased?**  
**Answer:** The wave becomes shorter and flatter because its peaks and troughs move closer to the midline.

**Q16. What happens if frequency is increased?**  
**Answer:** The wave oscillates more quickly, so more cycles appear over the same horizontal distance.

**Q17. What happens if frequency is decreased?**  
**Answer:** The wave oscillates more slowly, so fewer cycles appear across the screen.

**Q18. Why is a reference axis drawn?**  
**Answer:** It shows the centre line of the sine wave. It helps us see how far the wave moves above and below its midline.

**Q19. What is the range of the sine function?**  
**Answer:** The sine function always returns a value between -1 and +1. Therefore, with amplitude 50, the wave varies approximately 50 pixels above and below its centre line.

**Q20. What other curves can be generated in computer graphics?**  
**Answer:** Examples include circles, ellipses, Bezier curves and B-spline curves. Different mathematical equations or curve-generation algorithms are used to create them.

**Q21. What is the final output?**  
**Answer:** The output is a yellow sine wave plotted across the screen, with a horizontal reference line at y = 240.

---

# Practical 5 — 2D Transformations

## 1. What the program does

This program starts with a rectangle whose original coordinates are:
- Top-left: `(150, 150)`
- Bottom-right: `(250, 250)`

It displays a menu and lets the user select one of these operations:
1. Translation
2. Scaling
3. Rotation
4. Reflection
5. Shearing
6. Exit

The original rectangle is drawn in white, and the transformed rectangle is drawn in red.

**Important code-based clarification:** The README discusses homogeneous coordinates and lists more transformation variants, but the actual `main.cpp` implements these five operations using direct coordinate formulas. Its reflection option is the screen-style reflection across a horizontal line at y = 240. Its shearing option is X-shear. The program does not implement a separate Y-axis reflection or Y-shear menu option.

## 2. Understand the important code

### Drawing function

```cpp
void drawRect(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    rectangle(x1, y1, x2, y2);
}
```
This is a user-defined function:
- `drawRect()` avoids repeating the same drawing instructions.
- `setcolor(color)` selects the colour.
- `rectangle()` draws the rectangle using two opposite corner coordinates.

### Original rectangle

```cpp
int x1 = 150, y1 = 150;
int x2 = 250, y2 = 250;
```
These variables store the original rectangle's top-left and bottom-right coordinates.

### Menu loop

```cpp
while (1)
```
Creates a loop that keeps showing the menu until the Exit option is selected.

### Translation

```cpp
drawRect(x1 + tx, y1 + ty, x2 + tx, y2 + ty, RED);
```
Adds `tx` to each x-coordinate and `ty` to each y-coordinate. This moves the rectangle without changing its size or shape.

### Scaling

```cpp
drawRect(x1 * sx, y1 * sy, x2 * sx, y2 * sy, RED);
```
Multiplies x-coordinates by `sx` and y-coordinates by `sy`. This changes the size relative to the origin `(0,0)`.

### Rotation

The code converts the entered angle from degrees to radians:

```cpp
float rad = angle * 3.14 / 180;
```

Then it applies:

`x' = x * cos(rad) - y * sin(rad)`  
`y' = x * sin(rad) + y * cos(rad)`

It calculates the transformed position of all four rectangle corners and joins them using `line()`.

### Reflection

```cpp
drawRect(x1, -y2 + 480, x2, -y1 + 480, RED);
```
This flips the rectangle vertically around the horizontal screen line y = 240. The constant 480 is twice 240, so the formula is `y' = 480 - y`.

### Shearing

```cpp
X[0] = x1 + shx * y1;
Y[0] = y1;
```
The program uses X-shear. It changes each point's x-coordinate by an amount proportional to its y-coordinate. The y-coordinate remains unchanged.

## 3. Viva questions and answers

**Q1. What is a 2D transformation?**  
**Answer:** A 2D transformation changes the position, size, orientation or shape of an object in a two-dimensional plane. Examples include translation, scaling, rotation, reflection and shearing.

**Q2. Which object is transformed in this program?**  
**Answer:** A rectangle is transformed. Its original top-left coordinate is `(150,150)` and bottom-right coordinate is `(250,250)`.

**Q3. What are the transformations available in the menu?**  
**Answer:** Translation, scaling, rotation, reflection and shearing. The sixth option exits the program.

**Q4. What is translation?**  
**Answer:** Translation means moving an object from one position to another without changing its size, shape or orientation. We add `tx` to x and `ty` to y.

**Q5. What is the translation formula?**  
**Answer:** `x' = x + tx` and `y' = y + ty`. Here, `tx` is horizontal movement and `ty` is vertical movement.

**Q6. What happens if `tx` is positive?**  
**Answer:** The object moves towards the right because its x-coordinates increase.

**Q7. What happens if `ty` is positive?**  
**Answer:** In the usual screen coordinate system, the object moves downward because y-coordinates increase downward.

**Q8. What is scaling?**  
**Answer:** Scaling changes the size of an object. It can make the object larger or smaller by multiplying its coordinates by scaling factors.

**Q9. What is the scaling formula?**  
**Answer:** `x' = x * sx` and `y' = y * sy`. `sx` is the horizontal scaling factor and `sy` is the vertical scaling factor.

**Q10. What happens when the scaling factor is greater than 1?**  
**Answer:** The corresponding coordinate values become larger, so the object expands in that direction relative to the origin.

**Q11. What happens when the scaling factor is between 0 and 1?**  
**Answer:** The corresponding coordinate values become smaller, so the object shrinks towards the origin.

**Q12. What is uniform scaling?**  
**Answer:** Uniform scaling uses the same scaling factor for both x and y directions. The proportions of the object are maintained.

**Q13. What is non-uniform scaling?**  
**Answer:** Non-uniform scaling uses different scaling factors for x and y. The width and height change by different amounts, so the proportions may change.

**Q14. What is rotation?**  
**Answer:** Rotation means turning an object around a fixed point by a specified angle. In this program, the rectangle's four corners are rotated around the origin.

**Q15. What is the 2D rotation formula?**  
**Answer:** `x' = x cos θ - y sin θ` and `y' = x sin θ + y cos θ`. This is the standard counter-clockwise rotation formula for a positive angle in mathematical coordinates.

**Q16. Why is the angle converted into radians?**  
**Answer:** The `sin()` and `cos()` functions in C/C++ expect angles in radians. The user enters degrees, so the program converts them using `radians = degrees * 3.14 / 180`.

**Q17. Why are `sin()` and `cos()` used in rotation?**  
**Answer:** They calculate the trigonometric values needed to find the new x and y coordinates of each corner after rotation.

**Q18. What is reflection?**  
**Answer:** Reflection creates a mirror image of an object across a line or axis. In this program, the rectangle is flipped vertically around the horizontal screen line y = 240.

**Q19. What reflection formula is used in this code?**  
**Answer:** The y-coordinate is changed using `y' = 480 - y`, while x remains unchanged. This reflects the rectangle around y = 240 because 480 is twice 240.

**Q20. Is the program reflecting about the mathematical X-axis at y = 0?**  
**Answer:** No. The code uses `y' = 480 - y`, so it reflects around the horizontal screen line y = 240, not around y = 0.

**Q21. What is shearing?**  
**Answer:** Shearing slants an object. It shifts points in one direction by an amount proportional to their coordinate in another direction. It can make a rectangle look like a slanted parallelogram.

**Q22. Which type of shearing is implemented in this program?**  
**Answer:** X-shear. The x-coordinate changes according to `x' = x + shx * y`, while y stays the same.

**Q23. What is the purpose of `shx`?**  
**Answer:** `shx` is the X-shear factor. It controls how much the x-coordinate changes according to the point's y-coordinate.

**Q24. What is the difference between translation and scaling?**  
**Answer:** Translation moves the object without changing its size. Scaling changes the object's size relative to a reference point.

**Q25. What is the difference between rotation and reflection?**  
**Answer:** Rotation turns an object by an angle. Reflection creates a mirror image across a line.

**Q26. What is the purpose of the `drawRect()` function?**  
**Answer:** It is a user-defined function that draws a rectangle in a selected colour. It keeps the code shorter and avoids repeating `setcolor()` and `rectangle()` instructions.

**Q27. Why are four points used during rotation?**  
**Answer:** A rectangle has four corners. The program calculates the new position of each corner and then joins the four transformed points to draw the rotated rectangle.

**Q28. Why is the original rectangle drawn in white and the transformed rectangle in red?**  
**Answer:** Different colours make it easy to compare the original object with its transformed version.

**Q29. What are homogeneous coordinates?**  
**Answer:** Homogeneous coordinates add one extra coordinate to a point. A 2D point `(x,y)` is represented as `(x,y,1)`. This allows translation, scaling, rotation and other transformations to be represented using 3×3 matrices. The actual submitted code uses direct formulas rather than explicitly multiplying 3×3 matrices.

**Q30. Why are 3×3 matrices used for 2D homogeneous transformations?**  
**Answer:** A 2D point is extended to three values `(x,y,1)`. A 3×3 matrix can then represent translation, scaling, rotation, reflection and shearing in a consistent matrix form.

**Q31. Does the code rotate around the rectangle's centre?**  
**Answer:** No. The rotation formula is applied directly to the original coordinates, so the rectangle rotates around the origin `(0,0)`. To rotate around its centre, we would first translate the centre to the origin, rotate, and then translate it back.

**Q32. Does the code scale around the rectangle's centre?**  
**Answer:** No. It multiplies the coordinates directly, so scaling is about the origin `(0,0)`. The object can change both size and position on the screen.

**Q33. Why is `cleardevice()` used?**  
**Answer:** It clears the graphics screen so the next drawing can be displayed without old graphics remaining behind.

**Q34. What is the final output?**  
**Answer:** The program displays the original white rectangle and the selected transformed rectangle in red.

---

# Practical 6 — 3D Points and Transformations

## 1. What the program does

This program creates a cube using eight 3D points and draws its twelve edges.

It provides two menu operations:
1. Translation
2. Scaling

The original cube is drawn in white. After the user chooses a transformation and enters values, the program changes the cube's vertex coordinates and draws the transformed cube in red.

**Important code-based clarification:** The README explains homogeneous coordinates and 4×4 matrices. However, the actual `main.cpp` does not create or multiply 4×4 matrices. It stores points in a `struct Point` and applies translation or scaling directly to each point's x, y and z values. The back face is already given shifted x/y screen coordinates to make the cube look 3D. The `drawCube()` function draws only x and y, so the z-coordinate is not used for projection during drawing.

## 2. Understand the important code

### Structure for a 3D point

```cpp
struct Point {
    int x, y, z;
};
```
A structure groups three integer values together. Each `Point` stores the x, y and z coordinates of one cube vertex.

### Drawing function

```cpp
void drawCube(struct Point p[])
```
This function receives an array of cube points and draws the cube's edges.

It draws:
- Four edges of the front face.
- Four edges of the back face.
- Four connecting edges between the faces.

Total = 4 + 4 + 4 = 12 edges.

### Cube vertices

```cpp
struct Point cube[8] = {
    {100, 100, 0},
    {200, 100, 0},
    {200, 200, 0},
    {100, 200, 0},
    {140, 60, 50},
    {240, 60, 50},
    {240, 160, 50},
    {140, 160, 50}
};
```
The array stores eight vertices. The first four form the front face, and the next four form the back face.

### Translation

```cpp
cube[i].x += tx;
cube[i].y += ty;
cube[i].z += tz;
```
Adds the translation values to every vertex. All vertices move by the same amount, so the cube's size and shape remain the same.

### Scaling

```cpp
cube[i].x *= sx;
cube[i].y *= sy;
cube[i].z *= sz;
```
Multiplies each vertex coordinate by the scaling factor. This changes the cube's size relative to the origin.

### Drawing colours

The original cube is drawn before transformation using the default white colour. Then:

```cpp
setcolor(RED);
drawCube(cube);
```
sets red and draws the transformed cube.

## 3. Viva questions and answers

**Q1. What is 3D computer graphics?**  
**Answer:** 3D computer graphics represents objects using three dimensions: width, height and depth. A 3D point has x, y and z coordinates.

**Q2. What is the difference between 2D and 3D?**  
**Answer:** 2D uses two coordinates, x and y, to represent position on a flat plane. 3D uses x, y and z, where z represents depth.

**Q3. What is a 3D point?**  
**Answer:** A 3D point is a location represented by three coordinates `(x, y, z)`.

**Q4. Which object is used in this practical?**  
**Answer:** A cube is used. It is represented by eight vertices and twelve edges.

**Q5. How many vertices does a cube have?**  
**Answer:** A cube has eight vertices.

**Q6. How many edges does a cube have?**  
**Answer:** A cube has twelve edges.

**Q7. How many faces does a cube have?**  
**Answer:** A cube has six square faces.

**Q8. What is a structure in C/C++?**  
**Answer:** A structure is a user-defined data type that groups related variables under one name. Here, `struct Point` groups the x, y and z coordinates of one point.

**Q9. Why is `struct Point` used?**  
**Answer:** It makes it easy to store and manage the three coordinates of each cube vertex together. Instead of maintaining separate arrays for x, y and z, we can use one array of points.

**Q10. Why is the cube array of size 8?**  
**Answer:** Because a cube has eight vertices. The program stores each vertex as one `Point` element in the array.

**Q11. What is the purpose of `drawCube()`?**  
**Answer:** `drawCube()` is a user-defined function that draws all twelve edges of the cube by joining the correct pairs of vertices.

**Q12. How does the program draw the front face?**  
**Answer:** It connects the first four points: 0 to 1, 1 to 2, 2 to 3 and 3 to 0.

**Q13. How does the program draw the back face?**  
**Answer:** It connects the next four points: 4 to 5, 5 to 6, 6 to 7 and 7 to 4.

**Q14. How are the front and back faces connected?**  
**Answer:** Four additional lines connect corresponding vertices: 0 to 4, 1 to 5, 2 to 6 and 3 to 7.

**Q15. What is 3D translation?**  
**Answer:** 3D translation moves an object from one position to another in three-dimensional space without changing its size or shape.

**Q16. What is the 3D translation formula?**  
**Answer:** `x' = x + tx`, `y' = y + ty` and `z' = z + tz`. The same translation values are added to every vertex.

**Q17. What do `tx`, `ty` and `tz` mean?**  
**Answer:** `tx` is movement along the x-axis, `ty` is movement along the y-axis and `tz` is movement along the z-axis.

**Q18. What is 3D scaling?**  
**Answer:** 3D scaling changes the size of an object along the x, y and z directions.

**Q19. What is the 3D scaling formula?**  
**Answer:** `x' = x * sx`, `y' = y * sy` and `z' = z * sz`. The scale factors determine how much the object expands or shrinks in each direction.

**Q20. What are `sx`, `sy` and `sz`?**  
**Answer:** They are scaling factors for the x, y and z axes respectively.

**Q21. What happens if all three scaling factors are equal?**  
**Answer:** The object undergoes uniform scaling. All dimensions change by the same factor, so its proportions are maintained.

**Q22. What happens if the scaling factors are different?**  
**Answer:** The object undergoes non-uniform scaling. Its dimensions change by different amounts, so its proportions may change.

**Q23. What is the difference between translation and scaling?**  
**Answer:** Translation changes the position of the object but not its size. Scaling changes the size of the object relative to the origin.

**Q24. What are homogeneous coordinates?**  
**Answer:** Homogeneous coordinates represent a 3D point `(x,y,z)` using four values `(x,y,z,1)`. The extra coordinate allows translation to be represented as a matrix multiplication along with other transformations.

**Q25. What is the size of a 3D homogeneous transformation matrix?**  
**Answer:** It is a 4×4 matrix.

**Q26. Why are homogeneous coordinates useful?**  
**Answer:** They allow translation, scaling, rotation and other transformations to be represented in one consistent matrix form. Multiple transformations can also be combined by multiplying matrices.

**Q27. Does this submitted code actually multiply a 4×4 matrix?**  
**Answer:** No. The README describes the homogeneous-coordinate method, but the submitted `main.cpp` uses direct formulas. Translation uses `+=`, and scaling uses `*=` on each coordinate.

**Q28. What is projection in computer graphics?**  
**Answer:** Projection is the process of representing a 3D object on a 2D screen. A computer screen has only horizontal and vertical coordinates, so depth must be represented visually.

**Q29. Does `drawCube()` use the z-coordinate to draw the cube?**  
**Answer:** No. It passes only the x and y values to the BGI `line()` function. The back face already has shifted x and y values, which makes the cube look three-dimensional. The z-coordinate is stored and transformed, but it is not directly used by `drawCube()`.

**Q30. Why are the back-face coordinates shifted?**  
**Answer:** The back face is stored with different x and y coordinates from the front face. This offset creates the visual depth effect of a cube on a 2D screen.

**Q31. Does the program implement rotation?**  
**Answer:** No. The actual menu in `main.cpp` provides translation and scaling only.

**Q32. Why is the original cube drawn before transformation?**  
**Answer:** So we can compare the original cube with the transformed cube. The original is white and the transformed version is red.

**Q33. Why is `setcolor(RED)` used?**  
**Answer:** It changes the drawing colour to red before the transformed cube is drawn.

**Q34. Why is the `cleardevice()` line commented out?**  
**Answer:** It is commented out so the original white cube remains visible when the transformed red cube is drawn. If the screen were cleared at that point, the original cube would disappear.

**Q35. What is the final output?**  
**Answer:** The program displays the original white cube and the translated or scaled cube in red.

---

# Common Code and Programming Questions

These questions may be asked after any of the six practicals.

**Q1. What is a header file?**  
**Answer:** A header file contains declarations of functions, macros and other definitions that a program can use. For example, `graphics.h` provides graphics functions.

**Q2. What is a library?**  
**Answer:** A library is a collection of pre-written functions that programmers can use instead of writing everything from the beginning.

**Q3. What is a function?**  
**Answer:** A function is a named block of code that performs a particular task. For example, `drawCube()` draws a cube, and `code()` calculates a clipping region code.

**Q4. What is an array?**  
**Answer:** An array stores multiple values of the same data type under one name. Each value is accessed using an index.

**Q5. What is a loop?**  
**Answer:** A loop repeats a block of code while a condition is true or for a specified number of iterations. This is useful for processing multiple vertices or screen pixels.

**Q6. What is the difference between `for` and `while` loops?**  
**Answer:** A `for` loop is commonly used when the number of repetitions is known. A `while` loop repeats as long as its condition remains true.

**Q7. What is an if-else statement?**  
**Answer:** It is a decision-making statement. The `if` block runs when the condition is true; otherwise, the `else` block runs.

**Q8. What is a variable?**  
**Answer:** A variable is a named memory location used to store a value, such as an integer, decimal number or character.

**Q9. What is the difference between `int` and `float`?**  
**Answer:** `int` stores whole numbers, such as 10 or -5. `float` stores decimal values, such as 2.5 or 3.14.

**Q10. What is the modulo operator `%`?**  
**Answer:** It returns the remainder after integer division. In the polygon program, `(i + 1) % n` helps connect the last vertex back to the first.

**Q11. What is the difference between `=` and `==`?**  
**Answer:** `=` assigns a value to a variable. `==` compares two values and checks whether they are equal.

**Q12. What is the difference between `&` and `&&`?**  
**Answer:** `&` is bitwise AND when used with integer values, while `&&` is logical AND used to combine conditions. In the Cohen-Sutherland program, `&` checks bits in region codes.

**Q13. What is a comment in C/C++?**  
**Answer:** A comment is text written for explanation. The compiler ignores it. A single-line comment begins with `//`, and a block comment is written between `/*` and `*/`.

**Q14. What is the purpose of `printf()`?**  
**Answer:** `printf()` displays formatted output on the console.

**Q15. What is the purpose of `scanf()`?**  
**Answer:** `scanf()` reads input entered by the user and stores it in variables.

**Q16. Why is `&` used before a variable in `scanf()`?**  
**Answer:** It passes the variable's memory address to `scanf()`, allowing the function to store the entered value in that variable.

**Q17. What is a compiler?**  
**Answer:** A compiler translates source code written in a programming language into machine code or another lower-level form that can be executed.

**Q18. What is debugging?**  
**Answer:** Debugging is the process of finding and correcting errors in a program.

**Q19. What is BGI?**  
**Answer:** BGI stands for Borland Graphics Interface. It is the graphics system used by traditional Turbo C++ graphics programs.

**Q20. Why do these programs use Turbo C++ and `graphics.h`?**  
**Answer:** The practicals are written for the traditional BGI graphics environment. Turbo C++ with the correct BGI driver setup provides the functions used by these programs.

---

# Quick Revision — Remember These Before the Viva

| Practical | Main concept | Important function / formula |
|---|---|---|
| 1 | Basic graphics primitives | `putpixel()`, `line()`, `initgraph()` |
| 2 | Scan-line polygon filling | Edge intersections, sorting, odd-even rule |
| 3 | Cohen-Sutherland clipping | 4-bit outcodes, bitwise AND |
| 4 | Sine wave generation | `y = y0 - A * sin(f*x)` |
| 5 | 2D transformations | Translation, scaling, rotation, reflection, X-shear |
| 6 | 3D transformations | 8 vertices, 12 edges, translation, scaling |

## Important formulas

**Scan-line edge intersection:**

`x = xi + (y - yi) * (xj - xi) / (yj - yi)`

**Cohen-Sutherland line intersection:**

For a vertical boundary:

`y = y1 + (y2 - y1) * (x - x1) / (x2 - x1)`

For a horizontal boundary:

`x = x1 + (x2 - x1) * (y - y1) / (y2 - y1)`

**Sine wave:**

`y = y0 - A * sin(f * x)`

**2D translation:**

`x' = x + tx`  
`y' = y + ty`

**2D scaling:**

`x' = x * sx`  
`y' = y * sy`

**2D rotation:**

`x' = x*cos(θ) - y*sin(θ)`  
`y' = x*sin(θ) + y*cos(θ)`

**2D X-shear:**

`x' = x + shx*y`  
`y' = y`

**3D translation:**

`x' = x + tx`  
`y' = y + ty`  
`z' = z + tz`

**3D scaling:**

`x' = x*sx`  
`y' = y*sy`  
`z' = z*sz`

## Last viva tip

If the examiner points to a line of code and asks what it does, explain it in this order:

1. **What it is:** function, variable, condition, loop or formula.
2. **What it takes:** input values or coordinates.
3. **What it does:** the operation performed.
4. **Why it is used:** how it helps the practical produce its output.

For example:

“`putpixel(x, y, YELLOW)` is a graphics function. It takes an x-coordinate, a y-coordinate and a colour. It colours one pixel at that position. We use it in the sine-wave practical to plot every calculated point of the curve.”
