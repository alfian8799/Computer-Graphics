#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

float posX = 0.0;
float posY = -0.8;

int enemyCount = 0;
float enemyX[50];
float enemyY[50];
bool enemyAlive[50];
bool bulletActive = false;
float bulletX = 0.0;
float bulletY = -0.8;

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

void drawEnemies() {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyAlive[i]) {
            glPushMatrix();
            glColor3f(0.0, 1.0, 0.0);
            glTranslatef(enemyX[i], enemyY[i], 0.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(0.0, -0.1);
            glVertex2f(-0.1, 0.1);
            glVertex2f(0.1, 0.1);
            glEnd();
            glPopMatrix();
        }
    }
}

void drawBullet() {
    if (bulletActive) {
        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(bulletX, bulletY, 0.0);
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
    drawEnemies();
    drawBullet();

    glutSwapBuffers();
}

void update(int value) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyAlive[i]) {
            enemyY[i] -= 0.005;  // Kecepatan pergerakan musuh
            if (enemyY[i] < -1.0) {
                enemyAlive[i] = false;
            }
        }
    }

    if (bulletActive) {
        bulletY += 0.02;
        if (bulletY > 1.0) {
            bulletY = -0.8;
            bulletActive = false;
        }
    }

    for (int i = 0; i < enemyCount; i++) {
        if (bulletActive && enemyAlive[i] && bulletY >= enemyY[i] - 0.1 && bulletX >= enemyX[i] - 0.1 && bulletX <= enemyX[i] + 0.1) {
            bulletActive = false;
            bulletY = -0.8;
            enemyAlive[i] = false;
        }
    }

    // Spawn new enemy if any enemy is destroyed
    for (int i = 0; i < enemyCount; i++) {
        if (!enemyAlive[i]) {
            enemyX[i] = (rand() % 20 - 10) * 0.1;
            enemyY[i] = 1.0;
            enemyAlive[i] = true;
            break;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        if (posX > -0.9) posX -= 0.1;
        break;
    case 'd':
        if (posX < 0.9) posX += 0.1;
        break;
    case 's':
        if (posY > -0.9) posY -= 0.1;
        break;
    case 'w':
        if (posY < 0.9) posY += 0.1;
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
            bulletX = posX;
            bulletY = -0.8;
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
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Space Shooter");

    enemyCount = 5; // Number of enemies

    for (int i = 0; i < enemyCount; i++) {
        enemyX[i] = (rand() % 20 - 10) * 0.1;
        enemyY[i] = 1.0;
        enemyAlive[i] = true;
    }

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    return 0;
}
