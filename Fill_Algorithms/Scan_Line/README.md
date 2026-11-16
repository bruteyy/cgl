# Practical 9 - Scan-Line Polygon Fill Algorithm

**Aim:** To fill a polygon using the Scan-Line Fill algorithm.

**Simple idea:**
1. Draw the polygon.
2. Move a horizontal line from the polygon's top to bottom.
3. Find where the scan line intersects polygon edges.
4. Sort the intersection x-coordinates.
5. Draw between the 1st-2nd, 3rd-4th intersections, and so on.

**Functions used:** `line()`.

**Note:** This is an easy educational version for a simple polygon. It uses integer intersection positions and a basic edge-crossing rule; production implementations handle shared vertices and horizontal edges more carefully.
