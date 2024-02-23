
#include "pohon.h"
#include <math.h>
#ifdef __APPLE__ // untuk program yang dijalankan di MacOS
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else // untuk program yang dijalankan di Windows
#include <GL/glut.h>
#endif


void pohon1()
{ 

// POHON 1 
//============== batang pohon ================
GLUquadricObj * quadratic;
quadratic = gluNewQuadric();
glPushMatrix();
glColor3ub(62,20,0);
glRotatef(90,-20,0,0);
glScalef(2,2,2);
gluCylinder(quadratic,0.35f,0.35f,2.0f,32,32);
glPopMatrix();
 
//===============daun pohon=================
// bawah
glColor3f(0,1,0);
glPushMatrix();
glTranslatef(0,1.8,0);
glRotatef(90,-20,0,0);
glutSolidCone(2,5,4,4);
glPopMatrix();

// atas
glPushMatrix();
glTranslatef(0,3.8,0);
glRotatef(90,-20,0,0);
glutSolidCone(2,5,4,4);
glPopMatrix();


}

void pohon2()
{
    // pohon daun bulet
    // batang
    GLUquadricObj * quadratic;
    quadratic = gluNewQuadric();

    glPushMatrix();
    glColor3f(8.0, 0.5, 0);
    glTranslatef(14,0,0);
    glRotatef(90,-2,0,0);
    glutSolidCone(0.7,5,40,40);
    glPopMatrix();

    // daun
    //============= baris 1 ==========
    // baris 1 depan kanan
    glColor3ub(124,252,0);

    glPushMatrix();
    glTranslatef(14.7,3.3,0.98);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();
    // baris 1 depan kiri
    glPushMatrix();
    glTranslatef(13.4,3.3,0.98);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();
    // baris 1 dbelakang kiiri
    glPushMatrix();
    glTranslatef(13.4,3.3,-0.98);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();
    // baris 1 belakang kanan
    glPushMatrix();
    glTranslatef(14.7,3.3,-0.98);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();

    //samping kiri
    glPushMatrix();
    glTranslatef(13,3.3,0.0);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();

    //samping kanan
    glPushMatrix();
    glTranslatef(15.2,3.3,0.0);
    glRotatef(90,-2,0,0);
    glutSolidSphere(1,50,50);
    glPopMatrix();
    //============ baris 2=============
    // depan kanan
    glPushMatrix();
    glTranslatef(14.5,4.5,0.8);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();
    // depan kiri
    glPushMatrix();
    glTranslatef(13.5,4.5,0.8);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();
    // belakang kanan
    glPushMatrix();
    glTranslatef(14.7,4.5,-0.8);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();
    // belakang kiri
    glPushMatrix();
    glTranslatef(13.4,4.5,-0.8);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();

    //samping kiri
    glPushMatrix();
    glTranslatef(13,4.6,0.0);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();

    //samping kanan
    glPushMatrix();
    glTranslatef(15.2,4.6,0.0);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.8,50,50);
    glPopMatrix();
    // ============ baris 3 ==============
    glPushMatrix();
    glTranslatef(14,5.7,0);
    glRotatef(90,-2,0,0);
    glutSolidSphere(0.9,50,50);
    glPopMatrix();
}

void pohon3()
{
    // POHON tandus
    GLUquadricObj * quadratic;
    quadratic = gluNewQuadric();

    // batang berdiri
    glPushMatrix();
    glColor3ub(62,20,0);
    glTranslatef(8,0,0);
    glRotatef(90,-20,0,0);
    glScalef(2,2,2);
    gluCylinder(quadratic,0.35f,0.35f,5.0f,32,32);
    glPopMatrix();

    //batang kanan
    glPushMatrix();
    glColor3ub(62,20,0);
    glTranslatef(8,3.3,0);
    glRotatef(-93,20,-20,8);
    glScalef(2,2,2);
    gluCylinder(quadratic,0.35f,0.35f,2.0f,10,10);
    glPopMatrix();

    //batang kiri
    glPushMatrix();
    glColor3ub(62,20,0);
    glTranslatef(8,5,0);
    glRotatef(180,30,-25,-30);
    glScalef(2,2,2);
    gluCylinder(quadratic,0.35f,0.35f,2.2f,10,10);
    glPopMatrix();
}

void masjid()
{
    // ==== badan masjid ======
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(3,4,3);
    glScalef(6,2.4,6);
    glutSolidCube(3.4);
    glPopMatrix();

    //====== kubah =======
    glPushMatrix();
    glColor3ub(255,255,0);
    glTranslatef(3,8,3);
    glutSolidSphere(5,40,40);
    glPopMatrix();

    // ==== menara =====
    GLUquadric * quadratic;
    quadratic = gluNewQuadric();
    // ==== kanan depan ======
    glColor3f(0, 0, 0.8);
    glPushMatrix();
    glTranslatef(11.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri depan ======
    glPushMatrix();
    glTranslatef(-5.4,13,11.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kiri belakang ======
    glPushMatrix();
    glTranslatef(-5.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();
    // ==== kanan belakang ======
    glPushMatrix();
    glTranslatef(11.4,13,-5.3);
    glRotatef(90,20,0,0);
    gluCylinder(quadratic,2.7,2.7,13,50,50);
    glPopMatrix();

    // ======= pintu =========
    // depan
    glPushMatrix();
    glColor3ub(160,84,45);
    glTranslatef(-1,-0.1,13.25);
    glBegin(GL_POLYGON);
    glVertex3f(2,0,0);
    glVertex3f(6,0,0);
    glVertex3f(6,3,0);
    glVertex3f(2,3,0);
    glEnd();
    glPopMatrix();
}

