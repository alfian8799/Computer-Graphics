#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

float posX = 0.0;
float posY = 0.0;
float bulletY = 0.0;
bool bulletActive = false;

void drawPlane() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(posX, posY, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glEnd();
    glPopMatrix();
}

void drawBullet() {
    if (bulletActive) {
        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(posX, bulletY, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(-0.01, 0.05);
        glVertex2f(-0.01, -0.05);
        glVertex2f(0.01, -0.05);
        glVertex2f(0.01, 0.05);
        glEnd();
        glPopMatrix();
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPlane();
    drawBullet();

    glutSwapBuffers();
}

void update(int value) {
    if (bulletActive) {
        bulletY += 0.02;
        if (bulletY > 1.0) {
            bulletY = 0.0;
            bulletActive = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        posX -= 0.1;
        break;
    case 'd':
        posX += 0.1;
        break;
    case 's':
        posY -= 0.1;
        break;
    case 'w':
        posY += 0.1;
        break;
    case 27: // Escape key
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        if (!bulletActive) {
            bulletY = posY;
            bulletActive = true;
        }
        break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Space Shooter");

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    return 0;
}
