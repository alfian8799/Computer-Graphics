#include <stdlib.h>
#include <GL/glut.h>

GLfloat quadY = 0; // Variabel posisi Y awal kotak
GLfloat rotationAngle = 0; // Variabel untuk menyimpan sudut rotasi

void drawQuad() {
    glPushMatrix();
    glRotatef(rotationAngle, 0, 0, 1); // Rotasi objek
    glBegin(GL_QUADS);
    glVertex2f(-50, -50 + quadY); // Menggunakan variabel posisi Y
    glVertex2f(50, -50 + quadY);  // untuk menggerakkan kotak.
    glVertex2f(50, 50 + quadY);   // 
    glVertex2f(-50, 50 + quadY);  // 
    glEnd();
    glPopMatrix();
}

void myKeyboard(unsigned char key, int x, int y) {
    if (key == 'q') {
        glRotatef(10, 0, 0, -4); // Rotasi searah jarum jam
    }
    else if (key == 'e') {
        glRotatef(10, 0, 0, 4); // Rotasi berlawanan arah jarum jam
    }
    else if (key == 'w') {
        quadY += 10; // Gerakan ke atas dengan menambahkan nilai ke Y
    }
    else if (key == 's') {
        quadY -= 10; // Gerakan ke bawah dengan mengurangi nilai dari Y
    }
    else if (key == 'r') {
        glColor3f(1, 0, 0); // Merubah warna objek menjadi merah
        glutPostRedisplay(); // Redraw to apply the color change
    }
    else if (key == 'g') {
        glColor3f(0, 1, 0); // Merubah warna objek menjadi hijau
        glutPostRedisplay(); // Redraw to apply the color change
    }
    else if (key == 'b') {
        glColor3f(0, 0, 1); // Merubah warna objek menjadi biru
        glutPostRedisplay(); // Redraw to apply the color change
    }
    else if (key == 'y') {
        glColor3f(1, 1, 0); // Merubah warna objek menjadi kuning
        glutPostRedisplay(); // Redraw to apply the color change
    }
}

void mySpecialKeyboard(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        glRotatef(4, 0, 0, 1); // Putar objek searah jarum jam saat tombol panah kiri ditekan
    }
    else if (key == GLUT_KEY_RIGHT) {
        glRotatef(4, 0, 0, -1); // Putar objek berlawanan arah jarum jam saat tombol panah kanan ditekan
    }
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawQuad(); // Menambahkan kotak
    glFlush();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("keyboard");
    gluOrtho2D(-320., 320., -340., 340.);
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySpecialKeyboard); // Mendeteksi tombol keyboard khusus
    glutTimerFunc(1, timer, 0);
    glClearColor(0.7, 0.7, 0.7, 0); // Warna abu-abu untuk latar belakang
    glColor3f(0, 0, 1); // Warna biru
    glutMainLoop();
    return 0;
}
