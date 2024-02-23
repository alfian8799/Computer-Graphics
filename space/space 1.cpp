
#include <GL\glut.h>
#include<math.h>
#include<string>
#include <time.h>
#include <sstream>

using namespace std;

void update(int);
float speed = 0.0f;
int healthCount = 3;
int score = 0;

float _move = 0.0f;
float obstacleSpeed1 = 0.0f;
float _obstacle1 = 0.0f;
int flag = 0;
int obstacleFlag = 0;
int random = 0;
float _stars;

void drawText(const char* text, int length, float x, float y) {
    glMatrixMode(GL_PROJECTION);
    double* matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2f(x, 0.9f);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}


void specialKeys(int key, int x, int y) {
    switch (key) {

    case GLUT_KEY_UP:
        if (flag == 0) {
            flag = 1;
            if (score <= 5) {
                obstacleSpeed1 = 0.008f;
                speed = 0.01f;
            }
            else if (score > 5 && score <= 10) {
                obstacleSpeed1 = 0.01f;
                speed = 0.013f;
            }
            else if (score > 10 && score <= 15) {
                obstacleSpeed1 = 0.012f;
                speed = 0.016f;
            }
            else if (score > 15 && score <= 20) {
                obstacleSpeed1 = 0.014f;
                speed = 0.019f;
            }
            else if (score > 20 && score <= 30) {
                obstacleSpeed1 = 0.016f;
                speed = 0.022f;
            }
            else if (score > 30 && score <= 40) {
                obstacleSpeed1 = 0.020f;
                speed = 0.028f;
            }
            else if (score > 40 && score <= 50) {
                obstacleSpeed1 = 0.024f;
                speed = 0.034f;
            }
            else if (score > 50) {
                obstacleSpeed1 = 0.028f;
                speed = 0.040f;
            }
        }
        else {
            flag = 0;
            if (score <= 5) {
                obstacleSpeed1 = 0.008;
                speed = -0.01f;
            }
            else if (score > 5 && score <= 10) {
                obstacleSpeed1 = 0.01;
                speed = -0.013f;
            }
            else if (score > 10 && score <= 15) {
                obstacleSpeed1 = 0.012f;
                speed = -0.016f;
            }
            else if (score > 15 && score <= 20) {
                obstacleSpeed1 = 0.014f;
                speed = -0.019f;
            }
            else if (score > 20 && score <= 30) {
                obstacleSpeed1 = 0.016f;
                speed = -0.022f;
            }
            else if (score > 30 && score <= 40) {
                obstacleSpeed1 = 0.020f;
                speed = -0.028f;
            }
            else if (score > 40 && score <= 50) {
                obstacleSpeed1 = 0.024f;
                speed = -0.034f;
            }
            else if (score > 50) {
                obstacleSpeed1 = 0.028f;
                speed = -0.040f;
            }
        }
        break;
    }
}

// Dipanggil saat jendela diubah ukurannya
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawScene() {

    srand(time(NULL));

    glColor3ub(255, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    _stars -= 0.001f;

    // Game Over and Score Display
    if (healthCount == 0) {
        // Game Over
        glColor3d(1, 1, 1);
        stringstream convert; // stringstream digunakan untuk konversi
        string text = "score: ";// string yang akan berisi hasil
        convert << score;
        text = text + convert.str();// string yang akan berisi skor
        drawText(text.data(), text.size(), -0.21f, 0.4f);

        _obstacle1 = 0.0f;
        obstacleSpeed1 = 0.0f;
        _stars = 0.0f;
        speed = 0.0f;
        _move = 0.0f;
    }
    else {
        glColor3d(1, 1, 1);
        string text;
        stringstream convert;
        convert << score;// tambahkan nilai dari Number ke dalam karakter dalam stream
        text = convert.str();
        drawText(text.data(), text.size(), 0.0f, 0.4f);
    }



    // bintang
    glColor3d(1, 1, 1);
    glPointSize(3);
    glPushMatrix();
    glTranslatef(0.0f, _stars, 0.0f);
    glBegin(GL_POINTS);
    glVertex3f(0.5f, 1.99f, 0.0f);
    glVertex3f(-0.97f, 1.97f, 0.0f);
    glVertex3f(0.1f, 1.977f, 0.0f);
    glVertex3f(0.7f, 1.97f, 0.0f);
    glVertex3f(-0.9f, 1.92f, 0.0f);
    glVertex3f(-0.6f, 1.92f, 0.0f);
    glVertex3f(0.97f, 1.86f, 0.0f);
    glVertex3f(-0.2f, 1.82f, 0.0f);
    glVertex3f(0.55f, 1.83f, 0.0f);
    glVertex3f(-0.87f, 1.80f, 0.0f);

    float incre = 0.24f;
    for (int i = 0; i < 20; i++) {
        glVertex3f(0.5f, 1.99f - incre, 0.0f);
        glVertex3f(-0.97f, 1.97f - incre, 0.0f);
        glVertex3f(0.1f, 1.977f - incre, 0.0f);
        glVertex3f(0.7f, 1.97f - incre, 0.0f);
        glVertex3f(-0.9f, 1.92f - incre, 0.0f);
        glVertex3f(-0.6f, 1.92f - incre, 0.0f);
        glVertex3f(0.97f, 1.86f - incre, 0.0f);
        glVertex3f(-0.2f, 1.82f - incre, 0.0f);
        glVertex3f(0.55f, 1.83f - incre, 0.0f);
        glVertex3f(-0.87f, 1.80f - incre, 0.0f);
        incre += 0.25;
    }

    if (_stars <= -1) {
        _stars = 0.0f;
    }

    glEnd();
    glPopMatrix();







    // nyawa
    if (healthCount == 3) {
        //nyawa
        glColor3d(1, 0, 0);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(0.96f, 0.96f, 0.0f);
        glVertex3f(0.91f, 0.96f, 0.0f);
        glVertex3f(0.91f, 0.90f, 0.0f);
        glVertex3f(0.96f, 0.90f, 0.0f);

        glVertex3f(0.88f, 0.96f, 0.0f);
        glVertex3f(0.83f, 0.96f, 0.0f);
        glVertex3f(0.83f, 0.90f, 0.0f);
        glVertex3f(0.88f, 0.90f, 0.0f);

        glVertex3f(0.80f, 0.96f, 0.0f);
        glVertex3f(0.75f, 0.96f, 0.0f);
        glVertex3f(0.75f, 0.90f, 0.0f);
        glVertex3f(0.80f, 0.90f, 0.0f);
        glEnd();
        glPopMatrix();
    }
    else if (healthCount == 2) {
        glColor3d(1, 0, 0);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(0.96f, 0.97f, 0.0f);
        glVertex3f(0.91f, 0.97f, 0.0f);
        glVertex3f(0.91f, 0.91f, 0.0f);
        glVertex3f(0.96f, 0.91f, 0.0f);

        glVertex3f(0.88f, 0.97f, 0.0f);
        glVertex3f(0.83f, 0.97f, 0.0f);
        glVertex3f(0.83f, 0.91f, 0.0f);
        glVertex3f(0.88f, 0.91f, 0.0f);
        glEnd();
        glPopMatrix();
    }
    else if (healthCount == 1) {
        glColor3d(1, 0, 0);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(0.96f, 0.97f, 0.0f);
        glVertex3f(0.91f, 0.97f, 0.0f);
        glVertex3f(0.91f, 0.91f, 0.0f);
        glVertex3f(0.96f, 0.91f, 0.0f);
        glEnd();
        glPopMatrix();
    }


    // Player
    glColor3d(1, 0, 0);
    glPushMatrix();
    _move += speed;
    glTranslatef(_move, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    // Bagian Biru (Ubah menjadi Kuning)
    glColor3d(1.0, 0.7, 0.0);
    glVertex3f(0.17f, -0.7f, 0.0f);
    glVertex3f(-0.17f, -0.7f, 0.0f);
    glVertex3f(-0.1f, -0.6f, 0.0f);
    glVertex3f(0.1f, -0.6f, 0.0f);

    // Bagian Biru tua (Ubah menjadi Oranye)
    glColor3d(0, 0, 0.3);
    glVertex3f(0.1f, -0.75f, 0.0f);
    glVertex3f(-0.1f, -0.75f, 0.0f);
    glVertex3f(0.0f, -0.63f, 0.0f);
    glVertex3f(0.0f, -0.63f, 0.0f);

    // Bagian Merah (Ubah menjadi Oranye)
    glColor3d(1.0, 0.4, 0.0);
    glVertex3f(0.05f, -0.60f, 0.0f);
    glVertex3f(-0.05f, -0.60f, 0.0f);
    glVertex3f(0.0f, -0.55f, 0.0f);
    glVertex3f(0.0f, -0.55f, 0.0f);
    glEnd();


    // ekor
    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 0.2, 0.2);
    glVertex3f(-0.03f, -0.75f, 0.0f);
    glVertex3f(0.03f, -0.75f, 0.0f);
    glVertex3f(0.0f, -0.85f, 0.0f);
    glEnd();
    glPopMatrix();



    // rintangan 
    if (obstacleFlag == 0) {
        random = rand() % 7 + 1;
    }
    if (random == 1 && (obstacleFlag == 0 || obstacleFlag == 1)) {
        obstacleFlag = 1;
        _obstacle1 -= obstacleSpeed1;
        // Rintangan Kiri
        glColor3d(0.4f, 0.4f, 0.4f);
        glPushMatrix();
        glTranslatef(0.0f, _obstacle1, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.9f, 0.0f);
        glVertex3f(-1.0f, 0.9f, 0.0f);
        glEnd();
        glPopMatrix();

        if (_obstacle1 <= -2) {
            obstacleFlag = 0;
            _obstacle1 = 0.0f;
            score++;
        }
    }
    else if (random == 2 && (obstacleFlag == 0 || obstacleFlag == 2)) {
        obstacleFlag = 2;
        _obstacle1 -= obstacleSpeed1;
        // Rintangan Kanan
        glColor3d(0.4f, 0.4f, 0.4f);
        glPushMatrix();
        glTranslatef(0.0f, _obstacle1, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.9f, 0.0f);
        glVertex3f(1.0f, 0.9f, 0.0f);
        glEnd();
        glPopMatrix();

        if (_obstacle1 <= -2) {
            obstacleFlag = 0;
            _obstacle1 = 0.0f;
            score++;
        }
    }
    else if (random == 3 && (obstacleFlag == 0 || obstacleFlag == 3)) {
        obstacleFlag = 3;
        _obstacle1 -= obstacleSpeed1;
        // Rintangan Tengah
        glColor3d(0.4f, 0.4f, 0.4f);
        glPushMatrix();
        glTranslatef(0.0f, _obstacle1, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, 1.0f, 0.0f);
        glVertex3f(0.5f, 0.9f, 0.0f);
        glVertex3f(1.0f, 0.9f, 0.0f);

        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 0.9f, 0.0f);
        glVertex3f(-1.0f, 0.9f, 0.0f);
        glEnd();
        glPopMatrix();

        if (_obstacle1 <= -2) {
            obstacleFlag = 0;
            _obstacle1 = 0.0f;
            score++;  // Penambahan Skor
        }
    }
    // else if (random == 4 && (obstacleFlag == 0 || obstacleFlag == 4)) {
    //     obstacleFlag = 4;
    //     _obstacle1 -= obstacleSpeed1;
    //     // Rintangan Tengah
    //     glColor3d(0.4f, 0.4f, 0.4f);
    //     glPushMatrix();
    //     glTranslatef(0.0f, _obstacle1, 0.0f);
    //     glBegin(GL_QUADS);
    //     glVertex3f(1.0f, 1.0f, 0.0f);
    //     glVertex3f(0.5f, 1.0f, 0.0f);
    //     glVertex3f(0.5f, 0.9f, 0.0f);
    //     glVertex3f(1.0f, 0.9f, 0.0f);
    //     glEnd();
    //     glPopMatrix();

    //     if (_obstacle1 <= -2) {
    //         obstacleFlag = 0;
    //         _obstacle1 = 0.0f;
    //         score++;  // Penambahan Skor
    //     }
    // }
    // else if (random == 5 && (obstacleFlag == 0 || obstacleFlag == 5)) {
    //     obstacleFlag = 5;
    //     _obstacle1 -= obstacleSpeed1;
    //     // Rintangan kiri kecil
    //     glColor3d(0.4f, 0.4f, 0.4f);
    //     glPushMatrix();
    //     glTranslatef(0.0f, _obstacle1, 0.0f);
    //     glBegin(GL_QUADS);
    //     glVertex3f(-1.0f, 1.0f, 0.0f);
    //     glVertex3f(-0.5f, 1.0f, 0.0f);
    //     glVertex3f(-0.5f, 0.9f, 0.0f);
    //     glVertex3f(-1.0f, 0.9f, 0.0f);
    //     glEnd();
    //     glPopMatrix();

    //     if (_obstacle1 <= -2) {
    //         obstacleFlag = 0;
    //         _obstacle1 = 0.0f;
    //         score++;  // Penambahan Skor
    //     }
    // }

    // else  if (random == 6 && (obstacleFlag == 0 || obstacleFlag == 6)) {
    //     obstacleFlag = 6;
    //     _obstacle1 -= obstacleSpeed1;
    //     //Obstacle Left
    //     glColor3d(0.4f, 0.4f, 0.4f);
    //     glPushMatrix();
    //     glTranslatef(0.0f, _obstacle1, 0.0f);
    //     glBegin(GL_POLYGON); // Memulai penggambaran poligon
    //     glVertex3f(-0.9f, 1.0f, 0.0f); // Titik 1
    //     glVertex3f(-0.1f, 1.2f, 0.0f); // Titik 2
    //     glVertex3f(0.0f, 1.0f, 0.0f); // Titik 3
    //     glVertex3f(0.0f, 0.8f, 0.0f); // Titik 4
    //     glVertex3f(-1.0f, 0.9f, 0.0f); // Titik 5
    //     glVertex3f(-1.0f, 0.9f, 0.0f); // Titik 6
    //     glEnd(); //
    //     glPopMatrix();

    //     if (_obstacle1 <= -2) {
    //         obstacleFlag = 0;
    //         _obstacle1 = 0.0f;
    //         score++;
    //     }
    // }
    // else if (random == 7 && (obstacleFlag == 0 || obstacleFlag == 7)) {
    //     obstacleFlag = 7;
    //     _obstacle1 -= obstacleSpeed1;
    //     //Obstacle Right
    //     glColor3d(0.4f, 0.4f, 0.4f);
    //     glPushMatrix();
    //     glTranslatef(0.0f, _obstacle1, 0.0f);
    //     glBegin(GL_POLYGON); // Memulai penggambaran poligon
    //     glVertex3f(0.9f, 1.0f, 0.0f); // Titik 1
    //     glVertex3f(0.1f, 1.2f, 0.0f); // Titik 2
    //     glVertex3f(0.0f, 1.0f, 0.0f); // Titik 3
    //     glVertex3f(0.0f, 0.8f, 0.0f); // Titik 4
    //     glVertex3f(1.0f, 0.9f, 0.0f); // Titik 5
    //     glVertex3f(1.0f, 0.9f, 0.0f); // Titik 6
    //     glEnd(); //
    //     glPopMatrix();

    //     if (_obstacle1 <= -2) {
    //         obstacleFlag = 0;
    //         _obstacle1 = 0.0f;
    //         score++;
    //     }
    // }

    // Tabrakan di Sisi
    if (_move <= -0.83) {
        _move = -0.83;
    }
    else if (_move >= 0.83) {
        _move = 0.83;
    }

    // Tabrakan dengan Penghalang di Sisi Kiri
    if ((_move > -1.0f && _move < 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 1) {
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			// Pengurangan Skor
    }
    else if ((_move < 1.0f && _move > 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 2) {
        // Tabrakan dengan Penghalang di Sisi Kanan
        glutDisplayFunc(drawScene);
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			// Pengurangan Skor
    }
    else if ((_move > 0.4f || _move < -0.4f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 3) {
        // Tabrakan dengan Penghalang di Sisi Tengah
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			// Pengurangan Skor
    }
    // else if ((_move < 0.1f && _move > 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 4) {
    //     // Tabrakan dengan Penghalang di Sisi Kanan
    //     glutDisplayFunc(drawScene);
    //     Sleep(150);
    //     healthCount--;
    //     obstacleFlag = 0;
    //     _obstacle1 = 0.0f;			// Pengurangan Skor
    // }
    // else if ((_move < 0.0f && _move > -0.4f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 5) {
    //     // Tabrakan dengan Penghalang di Sisi kiri kecil
    //     glutDisplayFunc(drawScene);
    //     Sleep(150);
    //     healthCount--;
    //     obstacleFlag = 0;
    //     _obstacle1 = 0.0f;			// Pengurangan Skor
    // }
    // else if ((_move > -1.0f && _move < 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 6) {
    //     Sleep(150);
    //     healthCount--;
    //     obstacleFlag = 0;
    //     _obstacle1 = 0.0f;			// Pengurangan Skor
    // }
    // else if ((_move < 1.0f && _move > 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 7) {
    //     // Tabrakan dengan Penghalang di Sisi Kanan
    //     glutDisplayFunc(drawScene);
    //     Sleep(150);
    //     healthCount--;
    //     obstacleFlag = 0;
    //     _obstacle1 = 0.0f;			// Pengurangan Skor
    // }


    glutSwapBuffers();
}

void update(int value) {
    glutPostRedisplay(); // Memberitahu GLUT bahwa tampilan telah berubah

    glutTimerFunc(10, update, 0); // Memberitahu GLUT untuk memanggil fungsi update lagi dalam 10 milidetik
}


int main(int argc, char** argv) {
    int opt;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(370, 700);
    glutCreateWindow("space");
    glutDisplayFunc(drawScene);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(10, update, 0);
    glutMainLoop();
    return 0;
}