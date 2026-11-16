# CGA Practicals – Viva Questions and Answers

Answers are placed directly below the original viva questions. The practical READMEs and source files are also included in this ZIP.

## Practical 1: Basic Graphics Primitives

1. **What is a graphics primitive?**
   **Answer:** The basic building block of a drawing, such as a point, line or polygon.

2. **What does `initgraph()` do?**
   **Answer:** It switches the screen to graphics mode and loads the graphics driver. `DETECT` lets it pick the driver and mode automatically.

3. **What is the BGI path?**
   **Answer:** The folder that holds the Borland Graphics Interface driver files (`.bgi`), which `initgraph()` needs.

4. **How do you plot a single point?**
   **Answer:** With `putpixel(x, y, color)`, which colours the pixel at (x, y).

5. **How is a polygon drawn using `line()`?**
   **Answer:** Join each vertex to the next one, and join the last vertex back to the first so the shape is closed.

6. **Why is `getch()` used?**
   **Answer:** It holds the output screen until a key is pressed, otherwise the window closes immediately.

## Practical 2: Concave Polygon Filling (Scan Line Algorithm)

1. **What is the scan-line algorithm?**
   **Answer:** A polygon-filling method that processes one horizontal line at a time: find the edge crossings, sort them, and fill between pairs.

2. **Why do we sort the intersections?**
   **Answer:** The edges are not met in left-to-right order, so the x-values must be sorted before pairing them as fill spans.

3. **What is the odd-even rule?**
   **Answer:** Crossings are paired (1st-2nd, 3rd-4th, ...). Between an odd and the next even crossing the scanline is inside the polygon.

4. **Why is the half-open test (yi <= y < yj) used?**
   **Answer:** So that a vertex shared by two edges is counted once, not twice, which would otherwise break the pairing.

5. **Why are horizontal edges ignored?**
   **Answer:** They are parallel to the scanline, so they have no single crossing point (and yj - yi would be zero).

6. **What is a concave polygon?**
   **Answer:** A polygon with at least one interior angle greater than 180 degrees, so a line can cut its boundary more than twice.

7. **How is the mouse read in Turbo C?**
   **Answer:** Through interrupt 33h using `int86()`. Function 0 initializes, 1 shows, 2 hides and 3 reads the position and button status.

## Practical 3: Cohen-Sutherland Line Clipping

1. **What is clipping?**
   **Answer:** Removing the part of a picture that lies outside a chosen window, so only the visible part is drawn.

2. **What is a region code (outcode)?**
   **Answer:** A 4-bit code for a point: one bit each for LEFT, RIGHT, TOP and BOTTOM, set when the point is outside on that side.

3. **When is a line trivially accepted?**
   **Answer:** When both endpoint codes are 0000, so both points are inside the window.

4. **When is a line trivially rejected?**
   **Answer:** When the bitwise AND of the two codes is not zero, which means both points are outside on the same side.

5. **Why is the algorithm repeated in a loop?**
   **Answer:** One clip moves an endpoint to a boundary but the new point may still be outside another boundary, so the tests are repeated until accept or reject.

6. **How is the intersection with a boundary found?**
   **Answer:** From the line equation: for a vertical boundary x = xmin or xmax, y = y1 + slope * (x - x1); for a horizontal boundary y = ymin or ymax, x = x1 + (y - y1) / slope.

7. **What happens if a line is outside but its codes do not share a bit?**
   **Answer:** It is not trivially rejected. It is clipped step by step, and may finally be rejected after clipping.

## Practical 4: Curve Generation (Sine Wave)

1. **What is curve generation?**
   **Answer:** Drawing a curve by calculating its points from an equation and plotting them one by one.

2. **What do A, f and y0 control in the sine wave?**
   **Answer:** A is the height of the wave, f is how fast it oscillates (how many waves fit on the screen), and y0 is the vertical centre line.

3. **Why is the angle in radians?**
   **Answer:** The `sin()` function of `math.h` takes radians, not degrees.

4. **Why is the sine term subtracted from y0?**
   **Answer:** On the screen, y increases downward, so subtracting makes the wave go up for positive values of sine.

5. **Why is `putpixel()` used instead of `line()`?**
   **Answer:** The curve is plotted point by point; with a step of 1 pixel the points form a smooth-looking wave.

6. **Name other curves that can be generated.**
   **Answer:** Circle, ellipse, Bezier curve and B-spline. A flower can be made from a polar equation such as r = a * cos(k * theta).

## Practical 5: 2D Transformations

1. **What are homogeneous coordinates?**
   **Answer:** Writing a 2D point (x, y) as (x, y, 1) so that translation, which is an addition, can also be done by matrix multiplication.

2. **Why is a 3x3 matrix used for 2D transformations?**
   **Answer:** With the extra coordinate, translation, scaling, rotation, reflection and shear all become 3x3 matrices, and combined transformations are just matrix products.

3. **Write the rotation formula.**
   **Answer:** x' = x cos(t) - y sin(t) and y' = x sin(t) + y cos(t), about the origin, counter-clockwise for positive t.

4. **How do you rotate about a point other than the origin?**
   **Answer:** Translate that point to the origin, rotate, then translate back.

5. **What is reflection about the X-axis?**
   **Answer:** (x, y) becomes (x, -y). In this program, on screen coordinates, it is done as y' = 480 - y.

6. **What is shearing?**
   **Answer:** It slants the shape. X-shear moves each point sideways by an amount proportional to its y: x' = x + shx * y, y' = y.

7. **Is the order of transformations important?**
   **Answer:** Yes. Matrix multiplication is not commutative, so translate-then-rotate gives a different result than rotate-then-translate.

## Practical 6: 3D Transformations

1. **Why are homogeneous coordinates used in 3D?**
   **Answer:** A 4th coordinate (1) lets translation be written as a 4x4 matrix too, so all transformations are matrix multiplications and can be combined.

2. **What is the size of a 3D transformation matrix?**
   **Answer:** 4x4.

3. **Write the 3D translation matrix.**
   **Answer:** Identity matrix with tx, ty, tz in the last column: [[1,0,0,tx],[0,1,0,ty],[0,0,1,tz],[0,0,0,1]].

4. **What does scaling about the origin do?**
   **Answer:** It multiplies each coordinate by sx, sy, sz, so the object also moves away from (or towards) the origin. To scale about the object's own centre, translate to the origin, scale, and translate back.

5. **How many vertices and edges does a cube have?**
   **Answer:** 8 vertices and 12 edges.

6. **How is a 3D object shown on a 2D screen?**
   **Answer:** By projection. Here an oblique projection is used: X = x + 0.5z and Y = y + 0.5z.
