
#include <GL/glut.h>

void init()

{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.8, 0.8, 0.8, 0.0);

    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);

    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void home()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the display window

    // Translate the entire house upwards
    glPushMatrix();
    glTranslatef(0.0, 200.0, 0.0); // Adjust the second parameter (Y-axis) for higher position

    // Draw the house elements

        // Roof
    glColor3f(18.0 / 255.0, 72.0 / 255.0, 107.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(100, 250);
    glVertex2i(300, 250);
    glVertex2i(350, 175);
    glVertex2i(150, 175);
    glEnd();

    // Top of Front Wall
    glColor3f(15.0 / 255.0, 60.0 / 255.0, 89.0 / 255.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 250);
    glVertex2i(50, 175);
    glVertex2i(150, 175);
    glEnd();

    // Front Wall
    glColor3f(55.0 / 255.0, 120.0 / 255.0, 130.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 175);
    glVertex2i(150, 175);
    glVertex2i(150, 50);
    glVertex2i(50, 50);
    glEnd();

    // Front Door
    glColor3f(0.8, 0.6, 0.4); // Light brown color
    glBegin(GL_POLYGON);
    glVertex2i(75, 125);
    glVertex2i(125, 125);
    glVertex2i(125, 50);
    glVertex2i(75, 50);
    glEnd();

    // Front Door Lock
    glColor3f(0.3, 0.7, 0.9);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2i(85, 85);
    glEnd();

    // Side Wall
    glColor3f(120.0 / 255.0, 214.0 / 255.0, 198.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(150, 175);
    glVertex2i(350, 175);
    glVertex2i(350, 50);
    glVertex2i(150, 50);
    glEnd();

    // Window
    glColor3f(0.2, 0.4, 0.8);
    glBegin(GL_POLYGON);
    glVertex2i(215, 160);
    glVertex2i(275, 160);
    glVertex2i(275, 115);
    glVertex2i(215, 115);
    glEnd();

    // Line of Window
    glColor3f(0.1, 0.2, 0.5);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(245, 160);
    glVertex2i(245, 115);
    glVertex2i(215, 136);
    glVertex2i(275, 136);
    glEnd();

    // Draw the chimney on the roof
    glColor3f(0.5, 0.5, 0.5); // Grey color for the chimney
    glBegin(GL_POLYGON);
    glVertex2i(250, 250);   // Top-left corner of the chimney
    glVertex2i(250, 275);   // Top-right corner of the chimney
    glVertex2i(275, 275);   // Bottom-right corner of the chimney
    glVertex2i(275, 250);   // Bottom-left corner of the chimney
    glEnd();

    // Draw the garden bed on the right side of the house
    glColor3f(0.1, 0.6, 0.1); // Green color for the garden bed
    glBegin(GL_POLYGON);
    glVertex2i(500, 40);  // Bottom-left corner of the garden bed
    glVertex2i(750, 40);  // Bottom-right corner of the garden bed
    glVertex2i(750, 200); // Top-right corner of the garden bed
    glVertex2i(500, 200); // Top-left corner of the garden bed
    glEnd();

    // Draw vegetable plants in the garden
    glColor3f(0.8, 0.3, 0.2); // Reddish color for the vegetable plants
    glPointSize(10);
    glBegin(GL_POINTS);
    // Position of the vegetable plants
    glVertex2i(550, 75);
    glVertex2i(550, 100);
    glVertex2i(550, 125);
    glVertex2i(550, 150);
    glVertex2i(550, 175);

    glVertex2i(600, 75);
    glVertex2i(600, 100);
    glVertex2i(600, 125);
    glVertex2i(600, 150);
    glVertex2i(600, 175);

    glVertex2i(650, 75);
    glVertex2i(650, 100);
    glVertex2i(650, 125);
    glVertex2i(650, 150);
    glVertex2i(650, 175);

    glVertex2i(700, 75);
    glVertex2i(700, 100);
    glVertex2i(700, 125);
    glVertex2i(700, 150);
    glVertex2i(700, 175);
    glEnd();

    // Grey color for the road
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(800, -100); // Bottom-left corner of the road (geser ke bawah)
    glVertex2i(0, -100);   // Bottom-right corner of the road (geser ke bawah)
    glVertex2i(0, -30);    // Top-right corner of the road (geser ke bawah)
    glVertex2i(800, -30);  // Top-left corner of the road (geser ke bawah)
    glEnd();

    // Grey color for the shape
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(75, 50);    // Bottom-left corner
    glVertex2i(125, 50);   // Bottom-right corner
    glVertex2i(125, -100); // Top-right corner
    glVertex2i(75, -100);  // Top-left corner
    glEnd();



    // Draw the first bird on the roof
    glColor3f(0.0, 0.0, 0.0); // Black color for the bird
    glBegin(GL_LINES);
    glVertex2i(200, 290); // Bird body - top
    glVertex2i(205, 285);

    glVertex2i(205, 285); // Bird body - bottom
    glVertex2i(210, 290);

    glVertex2i(205, 285); // Bird wing - left
    glVertex2i(203, 282);

    glVertex2i(205, 285); // Bird wing - right
    glVertex2i(207, 282);
    glEnd();

    // Draw the second bird on the roof
    glBegin(GL_LINES);
    glVertex2i(230, 290); // Bird body - top
    glVertex2i(235, 285);

    glVertex2i(235, 285); // Bird body - bottom
    glVertex2i(240, 290);

    glVertex2i(235, 285); // Bird wing - left
    glVertex2i(233, 282);

    glVertex2i(235, 285); // Bird wing - right
    glVertex2i(237, 282);
    glEnd();

    // Draw the third bird on the roof
    glBegin(GL_LINES);
    glVertex2i(215, 300); // Bird body - top
    glVertex2i(220, 295);

    glVertex2i(220, 295); // Bird body - bottom
    glVertex2i(225, 300);

    glVertex2i(220, 295); // Bird wing - left
    glVertex2i(218, 292);

    glVertex2i(220, 295); // Bird wing - right
    glVertex2i(222, 292);
    glEnd();



    // Restore the original transformation matrix
    glPopMatrix();

    // Process all OpenGL routines as quickly as possible
    glFlush();
}

int main(int argc, char** argv)

{

    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set top - left display window position.
    glutInitWindowPosition(100, 100);

    // Set display window width and height
    glutInitWindowSize(720, 480);

    // Create display window with the given title
    glutCreateWindow("RUMAH 2D GT ");

    // Execute initialization procedure
    init();

    // Send graphics to display window
    glutDisplayFunc(home);

    // Display everything and wait.
    glutMainLoop();
}