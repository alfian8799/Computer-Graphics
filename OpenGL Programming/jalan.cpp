

#include "jalan.h"
#include <GL/glut.h>


void Jalan::jalan() {

    glColor3f(1.0, 0.75, 0.0);
    glBegin(GL_QUADS);

    //Bagian Kanan Jalan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glVertex3f(-100, -0.1, -10.0);
    glVertex3f(-100, -0.1, 0.10);
    glVertex3f(100, -0.1, 0.10);
    glVertex3f(100, -0.1, -10.0);
    glPopMatrix();
    glEnd();



    // Garis tengah jalan

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0, 0.1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-100, -0.1, -1.0);
    glVertex3f(-100, -0.1, 1.);
    glVertex3f(-50, -0.1, 1.);
    glVertex3f(-50, -0.1, -1.0);

    glVertex3f(0, -0.1, 1.);
    glVertex3f(0, -0.1, -1);
    glVertex3f(50, -0.1, -1);
    glVertex3f(50, -0.1, 1);
    glEnd();
    glPopMatrix();


    glBegin(GL_QUADS);
    //Bagian Kiri Jalan
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glVertex3f(-100, -0.1, 0);
    glVertex3f(-100, -0.1, 10);
    glVertex3f(100, -0.1, 10);
    glVertex3f(100, -0.1, 0);
    glPopMatrix();
    glEnd();

}

void Jalan::pinggiranJalan()
{
    //kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.0, 0.0);
    glVertex3f(-200, -0.1, -500);
    glVertex3f(-200, -0.1, -25.0);
    glVertex3f(1000, -0.1, -25.0);
    glVertex3f(1000, -0.1, -500);
    glEnd();
    glPopMatrix();


    //kiri
    glColor3f(0.1, 0.0, 0.0);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-200, -0.1, 25.0);
    glVertex3f(-200, -0.1, 500);
    glVertex3f(1000, -0.1, 500);
    glVertex3f(1000, -0.1, 25.0);
    glEnd();
    glPopMatrix();
}
