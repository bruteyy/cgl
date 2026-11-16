# Computer Graphics – Viva Questions & Answers

Complete preparation notes for all 13 practicals.
5 clear points for each answer. Use these short points for journal writing and quick viva revision.

---

## Practical 1: Graphics Primitives

**Q1. What is a graphics primitive?**
1. Graphics primitives are basic elements used to create images.
2. They include points, lines, circles, rectangles and polygons.
3. They are the building blocks of computer graphics.
4. They help create complex shapes and designs.
5. They are used in drawing, animation and image creation.

**Q2. How would you modify the code to draw a dashed line instead of a solid line?**
1. Divide the line into small segments.
2. Draw alternate segments and leave gaps between them.
3. Use a loop to repeat the drawing process.
4. Control the length of the segments and gaps.
5. This produces a dashed-line effect instead of a solid line.

**Q3. How is a polygon represented in graphics?**
1. A polygon is a closed 2D shape.
2. It consists of three or more vertices.
3. Each vertex is represented by an (x, y) coordinate.
4. Its edges connect consecutive vertices.
5. The last vertex is connected to the first vertex to close the polygon.

**Q4. How can you make the point more visible (e.g., larger or brighter)?**
1. Increase the size of the point.
2. Use a bright colour such as red or yellow.
3. Increase its brightness or intensity.
4. Draw a larger circle instead of a single pixel.
5. Use a contrasting colour to make it clearly visible.

---

## Practical 2: Scan-Line Polygon Filling Algorithm

**Q1. Differentiate between a convex and a concave polygon in terms of their interior angle.**
1. A convex polygon has all interior angles less than 180 degrees.
2. A concave polygon has at least one interior angle greater than 180 degrees.
3. A convex polygon has no inward dent.
4. A concave polygon has at least one inward dent.
5. Any line joining two points inside a convex polygon remains inside it; this is not always true for a concave polygon.

**Q2. For vertices A(2, 3), B(5, 8), C(8, 4), D(4, 1), test point E(6, 5) using the inside-outside test.**
1. Use the ray-casting method to check the point.
2. Draw an imaginary horizontal ray from E(6, 5).
3. Count the number of times the ray intersects the polygon edges.
4. The ray intersects the polygon boundary at two points.
5. Since the number of intersections is even, point E(6, 5) is outside the polygon.

**Q3. If a scan line intersects a polygon's edges three times, will a point above this scan line be inside or outside the polygon? Justify your answer.**
1. Use the odd-even rule to determine the position.
2. Count the boundary crossings along a ray from the test point.
3. An odd number of crossings indicates an inside point.
4. An even number of crossings indicates an outside point.
5. If the ray from the point crosses all three edges, the point is inside the polygon.

**Q4. What is the significance of the Edge Table and Active Edge List (AEL) in the scan-line fill algorithm?**
1. The Edge Table stores information about all polygon edges.
2. It contains edge information such as minimum Y, maximum Y and X-intersection details.
3. The Active Edge List stores edges currently intersecting the scan line.
4. It helps calculate and sort intersection points efficiently.
5. Horizontal spans are drawn between pairs of intersections to fill the polygon.

---

## Practical 3: Cohen-Sutherland Line Clipping Algorithm

**Q1. What is line clipping in computer graphics?**
1. Line clipping is the process of removing unwanted portions of a line.
2. It is performed with respect to a clipping window.
3. The portion inside the window is retained.
4. The portion outside the window is rejected.
5. It helps display only the required part of a line.

**Q2. What are region codes and how are they used?**
1. Region codes are 4-bit binary codes.
2. They represent the position of a point relative to the clipping window.
3. They indicate the TOP, BOTTOM, RIGHT and LEFT regions.
4. A code of 0000 represents a point inside the window.
5. They help identify lines that can be accepted or rejected.

**Q3. What is the purpose of logical AND in this algorithm?**
1. Logical AND is used to compare two region codes.
2. It helps identify lines completely outside the clipping window.
3. If the AND result is non-zero, the line can be rejected.
4. If the AND result is zero, further clipping checks are required.
5. It reduces unnecessary calculations and improves efficiency.

---

## Practical 4: Bezier Curve Generation

**Q1. What is a Bezier curve?**
1. A Bezier curve is a smooth mathematical curve.
2. It is defined using control points.
3. The first and last control points define its endpoints.
4. Other control points control its shape and direction.
5. It is widely used in computer graphics, animation and designing.

**Q2. How are control points used to influence the shape of the curve?**
1. Control points determine the shape of a Bezier curve.
2. Moving a control point changes the curve's direction.
3. Moving points changes the curve's bending.
4. The curve generally follows the control polygon.
5. Control points provide greater control over the curve's shape.

**Q3. What is the difference between linear and cubic Bezier curves?**
1. A linear Bezier curve uses two control points.
2. A cubic Bezier curve uses four control points.
3. A linear Bezier curve produces a straight line.
4. A cubic Bezier curve produces a smooth curved shape.
5. Cubic curves provide more control over the curve's shape.

**Q4. What are the applications of Bezier curves?**
1. They are used in logo designing.
2. They are used in computer animation.
3. They are used in font and text designing.
4. They are used in CAD and graphic designing.
5. They are used to create smooth shapes and curves.

**Q5. How is curve smoothness controlled?**
1. Smoothness is controlled by adjusting control points.
2. Proper positioning of control points creates smooth curves.
3. The direction of control handles affects the curve.
4. Smooth joining of curve segments avoids sharp corners.
5. Continuity between connected curves improves smoothness.

---

## Practical 5: 2D Transformations

**Q1. What is the difference between translation and rotation?**
1. Translation moves an object from one position to another.
2. Rotation turns an object around a fixed point.
3. Translation changes the position of an object.
4. Rotation changes the orientation of an object.
5. Translation uses distance values, while rotation uses an angle.

**Q2. How does scaling affect the shape of an object?**
1. Scaling changes the size of an object.
2. It can increase or decrease the object's dimensions.
3. Scaling uses X-axis and Y-axis scale factors.
4. Uniform scaling maintains the original proportions.
5. Non-uniform scaling can change the object's proportions.

**Q3. How is matrix multiplication used in 2D transformations?**
1. Matrix multiplication is used to transform object coordinates.
2. Each point is represented using homogeneous coordinates.
3. A transformation matrix is created for translation, rotation or scaling.
4. The coordinate matrix is multiplied by the transformation matrix.
5. The result gives the new coordinates of the transformed object.

---

## Practical 6: 3D Transformations Using Homogeneous Coordinates

**Q1. What are homogeneous coordinates?**
1. Homogeneous coordinates represent points using an extra coordinate.
2. In 2D, (x, y) becomes (x, y, 1).
3. In 3D, (x, y, z) becomes (x, y, z, 1).
4. They make matrix-based transformations easier.
5. They are used in translation, rotation and scaling.

**Q2. Why are they used in 3D transformations?**
1. They make 3D transformations easier to perform.
2. They represent translation using matrices.
3. They combine multiple transformations into one matrix.
4. They simplify matrix multiplication.
5. They are widely used in computer graphics and animation.

**Q3. What are the advantages of matrix multiplication in transformation?**
1. It makes calculations simple and systematic.
2. It combines multiple transformations.
3. It reduces repeated calculations.
4. It allows translation, rotation and scaling to be applied together.
5. It improves efficiency in computer graphics.

---

## Practical 7: Image Cropping, Resizing and Rotation

**Q1. What is the purpose of cropping in image editing?**
1. Cropping removes unwanted parts of an image.
2. It helps focus on the main subject.
3. It improves image composition.
4. It removes unnecessary background areas.
5. It helps create images of the required size and aspect ratio.

**Q2. How does resizing affect image quality?**
1. Resizing changes the dimensions of an image.
2. Increasing the size may reduce image sharpness.
3. Decreasing the size may remove some image details.
4. Maintaining the aspect ratio prevents unwanted stretching.
5. Proper resizing helps maintain good image quality.

**Q3. What is the difference between rotate and flip?**
1. Rotation turns an image around a fixed point.
2. Flipping creates a mirror image.
3. Rotation changes the image's angle.
4. Flip can be horizontal or vertical.
5. Rotation turns the image, while flipping reverses its orientation.

---

## Practical 8: Photoshop – Image Composition and Layer Management

**Q1. What is the primary advantage of using layers in image editing?**
1. Layers allow separate editing of image elements.
2. They make editing easier and more flexible.
3. They allow changes without affecting other elements.
4. They help arrange different objects properly.
5. They support non-destructive editing when used correctly.

**Q2. What is the purpose of using layers in Photoshop?**
1. Layers help combine multiple images.
2. They allow adding text, shapes and effects separately.
3. They help control the position of objects.
4. They support transparency and masking.
5. They make complex image compositions easier to manage.

**Q3. What is the function of the Dodge and Burn tools?**
1. The Dodge tool is used to lighten image areas.
2. The Burn tool is used to darken image areas.
3. Both tools help improve image contrast.
4. They are used to adjust highlights and shadows.
5. They help create depth and realistic effects in images.

---

## Practical 9: Blender – Character Animation

**Q1. What is the difference between rigging and skinning?**
1. Rigging is the process of creating a skeleton for a 3D model.
2. Skinning is the process of attaching the model's mesh to the skeleton.
3. Rigging creates bones and joints.
4. Skinning controls how the mesh moves with the bones.
5. Both are important for character animation.

**Q2. What are Shape Keys and how are they used?**
1. Shape Keys are used to change the shape of a 3D object.
2. They store different versions of an object's shape.
3. They are used for facial expressions and body movements.
4. They can create smiling, blinking and mouth movements.
5. They are widely used in character animation.

**Q3. What is Inverse Kinematics (IK)?**
1. Inverse Kinematics is a technique used in 3D animation.
2. It controls a chain of connected bones.
3. The animator moves the end point of the bone chain.
4. The connected bones automatically adjust their positions.
5. It is commonly used for character arms, legs and walking animations.

---

## Practical 10: Green Screen Removal in Blender

**Q1. What are the key parameters in the Keying node, and how do they affect the result?**
1. Key Color selects the green background colour to remove.
2. Threshold controls the range of colours removed.
3. Tolerance determines how much colour variation is accepted.
4. Edge adjustments help remove unwanted green borders.
5. These parameters help produce a clean and realistic result.

**Q2. Why is green commonly used in green screens?**
1. Green is different from most human skin tones.
2. It is easy to separate from the subject.
3. Digital cameras capture green colour effectively.
4. It requires less effort for background removal.
5. It helps produce clean and accurate results.

**Q3. Why is good lighting important when shooting green screen footage?**
1. Good lighting makes the green background uniform.
2. It reduces unwanted shadows.
3. It prevents uneven green colour.
4. It makes background removal easier.
5. It produces a clean and professional final video.

**Q4. What node in Blender is used to remove the green background?**
1. The Keying Node is used to remove the green background.
2. It is available in Blender's Compositor.
3. It uses a selected key colour to identify the background.
4. It creates transparency for the removed background.
5. The foreground can then be combined with another background using the Alpha Over node.

**Q5. How do masks help in refining a green screen composition?**
1. Masks select specific areas of an image.
2. They help remove unwanted objects.
3. They hide unwanted background areas.
4. They improve the edges around the subject.
5. They help create a cleaner and more realistic composition.

---

## Practical 11: Blender – Text Morph Animation

**Q1. What is a Shape Key in Blender?**
1. A Shape Key is used to change the shape of a 3D object.
2. It stores different shapes of the same object.
3. It helps create smooth shape transitions.
4. It is used for facial expressions and text morphing.
5. It is useful in character animation.

**Q2. Why do we convert text to mesh?**
1. Text is converted into a mesh to edit its geometry.
2. It allows editing individual vertices and faces.
3. It helps create Shape Keys.
4. It provides more control over the shape of the text.
5. It is useful for text morphing and 3D animation.

**Q3. What modifier helps in matching geometry for morphing?**
1. The Remesh Modifier helps create uniform mesh geometry.
2. It converts geometry into a more consistent mesh structure.
3. It helps prepare objects for morphing.
4. Similar topology is important for smooth morphing.
5. It helps achieve better transitions between shapes.

**Q4. How do you animate Shape Keys?**
1. Create a base shape and add Shape Keys.
2. Create different shapes using the Shape Keys.
3. Select the required Shape Key.
4. Insert keyframes by changing its Value from 0 to 1.
5. Play the animation to see the smooth shape transition.

---

## Practical 12: Unity – 2D Platformer Game

**Q1. What physics engine does Unity use for 2D games?**
1. Unity uses a Box2D-based 2D physics engine.
2. It is used to simulate physical movements.
3. It handles collisions between 2D objects.
4. It supports gravity and forces.
5. It helps create realistic 2D game movements.

**Q2. What component is responsible for gravity in Unity 2D?**
1. The Rigidbody2D component is responsible for physics-based movement.
2. It applies gravity to the Game Object.
3. It controls the object's movement and velocity.
4. Gravity Scale controls the effect of gravity.
5. It helps objects fall naturally in a 2D game.

**Q3. How is collision detection handled in Unity 2D?**
1. Unity uses Collider2D components to detect collisions.
2. Rigidbody2D handles physics-based movement.
3. When two objects touch, collision detection occurs.
4. OnCollisionEnter2D() detects collision events.
5. It is used for detecting player contact with walls, enemies and platforms.

---

## Practical 13: Unity – Basic Scene Creation

**Q1. What is a Game Object in Unity?**
1. A Game Object is the basic element of a Unity scene.
2. It can represent a player, camera, light or other object.
3. Every Game Object has a Transform component.
4. Components can be added to give it different functions.
5. Game Objects are used to create games and interactive scenes.

**Q2. What is the purpose of the Main Camera?**
1. The Main Camera displays the game scene.
2. It shows the player's view of the game.
3. It captures objects visible within its view.
4. It helps display the game on the screen.
5. Without a camera, the scene cannot be viewed through the normal gameplay camera.

**Q3. Why is lighting used in Unity?**
1. Lighting makes the scene visible.
2. It creates realistic brightness and shadows.
3. It improves the appearance of objects.
4. It creates different moods and environments.
5. It makes the game scene more attractive and realistic.

**Q4. What is the function of the Transform component?**
1. The Transform component controls an object's position.
2. It controls the rotation of an object.
3. It controls the scale of an object.
4. It helps move objects in 2D and 3D space.
5. Every Game Object in Unity has a Transform component.

**Q5. What are the main panels in the Unity Editor?**
1. Scene View: Used to create and edit the game scene.
2. Game View: Shows how the game looks during gameplay.
3. Hierarchy: Displays all Game Objects in the current scene.
4. Inspector: Shows and edits the properties of selected objects.
5. Project Window: Displays game assets, scripts, images and other files.
