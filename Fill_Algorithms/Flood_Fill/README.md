# Practical 7 - Flood Fill Algorithm

**Aim:** To fill a connected area with a new colour using the Flood Fill algorithm.

**Simple idea:** Start from one inside pixel. If its colour is the old colour, change it and check its four neighbours (left, right, up, down).

**Important:** `floodFill(200, 150, BLACK, YELLOW)` starts inside the rectangle. Change the starting point if you change the shape.

**Functions used:** `getpixel()`, `putpixel()`, `rectangle()`.

**Note:** This is a simple recursive 4-connected version for learning. A very large area can cause a recursion stack overflow.
