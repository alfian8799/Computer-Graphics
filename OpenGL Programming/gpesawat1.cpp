#include <GL/glut.h>

void drawStone() {
    // glBegin(GL_POLYGON); // Memulai penggambaran poligon
    // glVertex3f(-0.9f, 1.0f, 0.0f); // Titik 1
    // glVertex3f(-0.1f, 1.2f, 0.0f); // Titik 2
    // glVertex3f(0.0f, 1.0f, 0.0f); // Titik 3
    // glVertex3f(0.0f, 0.8f, 0.0f); // Titik 4
    // glVertex3f(-1.0f, 0.9f, 0.0f); // Titik 5
    // glVertex3f(-1.0f, 0.9f, 0.0f); // Titik 6
    // glEnd(); //



    glBegin(GL_POLYGON);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.9f, 1.3f, 0.0f);
    glVertex3f(0.5f, 1.2f, 0.0f);
    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(0.7f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.9f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(-0.9f, 1.3f, 0.0f);
    glVertex3f(-0.5f, 1.2f, 0.0f);
    glVertex3f(-0.5f, 1.1f, 0.0f);
    glVertex3f(-0.7f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 0.9f, 0.0f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Example: Render a stone
    glColor3f(0.4f, 0.4f, 0.4f); // Grey color for the stone
    drawStone();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Batu");
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f); // Background color
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); // Setting the viewing area
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
