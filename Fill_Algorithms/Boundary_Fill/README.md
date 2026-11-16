# Practical 8 - Boundary Fill Algorithm

**Aim:** To fill an enclosed area until a specified boundary colour is reached.

**Simple idea:** Start from an inside pixel. Colour it and its four neighbours, but stop when a pixel has the boundary colour (WHITE).

**Important:** The outline must be closed. The seed point `(200, 150)` must be inside the shape.

**Functions used:** `getpixel()`, `putpixel()`, `rectangle()`.

**Difference from Flood Fill:** Flood Fill checks for the old interior colour. Boundary Fill checks for the boundary colour.

**Note:** This is a simple recursive 4-connected version for learning. A very large area can cause a recursion stack overflow.
