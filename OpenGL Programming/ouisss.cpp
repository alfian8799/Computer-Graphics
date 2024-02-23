
#include <GL/glut.h> //OPTIONAL
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
    //Roof
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    // Set line segment color as glColor3f(R,G,B)
    glColor3f(1, 0.8, 0);
    glBegin(GL_POLYGON);
    glVertex2i(100, 250);
    glVertex2i(300, 250);
    glVertex2i(350, 175);
    glVertex2i(150, 175);
    glEnd();
    // Top of Front Wall
    glColor3f(1, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 250);
    glVertex2i(50, 175);
    glVertex2i(150, 175);
    glEnd();
    // Front Wall
    glColor3f(0.3, 0.3, 1);
    glBegin(GL_POLYGON);
    glVertex2i(50, 175);
    glVertex2i(150, 175);
    glVertex2i(150, 50);
    glVertex2i(50, 50);
    glEnd();
    // Front Door
    glColor3f(0.7, 0.2, 0.9);
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
    //side Wall
    glColor3f(0.5, 0.6, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(150, 175);
    glVertex2i(350, 175);
    glVertex2i(350, 50);
    glVertex2i(150, 50);
    glEnd();
    // window
    glColor3f(0.1, 0.4, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(215, 160);
    glVertex2i(275, 160);
    glVertex2i(275, 115);
    glVertex2i(215, 115);
    glEnd();
    // line of window
    glColor3f(0.3, 0.4, 0.5);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(245, 160);
    glVertex2i(245, 115);
    glVertex2i(215, 136);
    glVertex2i(275, 136);
    glEnd();
    // Entrance Path
    glColor3f(0.5, 0.5, 0.5);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(150, 50);
    glVertex2i(105, 0);
    glVertex2i(20, 0);
    glEnd();
    // karpet
    glColor3f(0.5, 0.8, 0.6);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(25, 25);
    glVertex2i(75, 25);
    glVertex2i(50, 0);
    glVertex2i(10, 0);
    glEnd();
    // cerobong
    glColor3f(0.1, 0.1, 0.1);
    glLineWidth(7);
    glBegin(GL_POLYGON);
    glVertex2i(275, 300);
    glVertex2i(250, 300);
    glVertex2i(250, 200);
    glVertex2i(275, 200);
    glEnd();
    // Process all OpenGL routine s as quickly as possible
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
    glutCreateWindow("RUMAH PIGMan");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(home);
    // Display everything and wait.
    glutMainLoop();
}