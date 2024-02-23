#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();

    glBegin(GL_QUADS);

    // Bagian Biru
    glColor3d(0, 0.4, 1);
    glVertex3f(0.17f, -0.7f, 0.0f);
    glVertex3f(-0.17f, -0.7f, 0.0f);
    glVertex3f(-0.1f, -0.6f, 0.0f);
    glVertex3f(0.1f, -0.6f, 0.0f);

    // Bagian Hitam
    glColor3d(0, 0, 0.3);
    glVertex3f(0.1f, -0.75f, 0.0f);
    glVertex3f(-0.1f, -0.75f, 0.0f);
    glVertex3f(0.0f, -0.63f, 0.0f);
    glVertex3f(0.0f, -0.63f, 0.0f);

    // Bagian Merah
    glColor3d(0.6, 0, 0);
    glVertex3f(0.05f, -0.60f, 0.0f);
    glVertex3f(-0.05f, -0.60f, 0.0f);
    glVertex3f(0.0f, -0.55f, 0.0f);
    glVertex3f(0.0f, -0.55f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 0.2, 0.2);
    glVertex3f(-0.03f, -0.75f, 0.0f);
    glVertex3f(0.03f, -0.75f, 0.0f);
    glVertex3f(0.0f, -0.85f, 0.0f);
    glEnd();


    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Contoh Gambar Burung");

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
