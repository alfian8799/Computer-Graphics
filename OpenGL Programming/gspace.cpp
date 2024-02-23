
#include <GL\glut.h>
#include<math.h>
#include<string>
#include <time.h>
#include <sstream>

using namespace std;

void update(int);
float speed = 0.0f;
int healthCount = 10;
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

//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawScene() {

    srand(time(NULL));

    glColor3ub(255, 0, 0); // change color to red
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    _stars -= 0.001f;

    // Game Over and Score Display
    if (healthCount == 0) {
        // Game Over
        glColor3d(1, 1, 0);
        stringstream convert; // stringstream used for the conversion
        string text = "Game Over";//string which will contain the result
        text = convert.str();
        drawText(text.data(), text.size(), -0.3f, 0.5f);

        convert << score;
        text = "Score: " + convert.str();//string which will contain the score
        drawText(text.data(), text.size(), -0.21f, 0.4f);

        _obstacle1 == 0.0f;
        obstacleSpeed1 = 0.0f;
        _stars = 0.0f;
        speed = 0.0f;
        _move = 0.0f;
    }
    else {
        glColor3d(1, 1, 0);
        string text;//string which will contain the result
        stringstream convert; // stringstream used for the conversion
        convert << score;//add the value of Number to the characters in the stream
        text = convert.str();
        drawText(text.data(), text.size(), 0.0f, 0.4f);
    }


    // Stars
    glColor3d(1, 1, 1);
    glPointSize(3);
    glPushMatrix();
    glTranslatef(0.0f, _stars, 0.0f);
    glBegin(GL_POINTS);
    glVertex3f(0.5f, 1.99f, 0.0f);
    glVertex3f(-0.97f, 1.97f, 0.0f); //
    glVertex3f(0.1f, 1.977f, 0.0f);
    glVertex3f(0.7f, 1.97f, 0.0f);
    glVertex3f(-0.9f, 1.92f, 0.0f); //
    glVertex3f(-0.6f, 1.92f, 0.0f);
    glVertex3f(0.97f, 1.86f, 0.0f);
    glVertex3f(-0.2f, 1.82f, 0.0f);
    glVertex3f(0.55f, 1.83f, 0.0f);
    glVertex3f(-0.87f, 1.80f, 0.0f);

    float incre = 0.24f;
    for (int i = 0; i < 20; i++) {
        glVertex3f(0.5f, 1.99f - incre, 0.0f);
        glVertex3f(-0.97f, 1.97f - incre, 0.0f); //
        glVertex3f(0.1f, 1.977f - incre, 0.0f);
        glVertex3f(0.7f, 1.97f - incre, 0.0f);
        glVertex3f(-0.9f, 1.92f - incre, 0.0f); //
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


    if (obstacleFlag == 0) {
        random = rand() % 3 + 1;
    }
    if (random == 1 && (obstacleFlag == 0 || obstacleFlag == 1)) {
        obstacleFlag = 1;
        _obstacle1 -= obstacleSpeed1;
        //Obstacle Left
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
            score++;					//Increment of Score
        }
    }
    else if (random == 2 && (obstacleFlag == 0 || obstacleFlag == 2)) {
        obstacleFlag = 2;
        _obstacle1 -= obstacleSpeed1;
        //Obstacle Right
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
            score++;					//Increment of Score
        }
    }
    else if (random == 3 && (obstacleFlag == 0 || obstacleFlag == 3)) {
        obstacleFlag = 3;
        _obstacle1 -= obstacleSpeed1;
        //Obstacle Middle
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
            score++;					//Increment of Score
        }

    }


    // if (healthCount == 3) {
    //     //Health Bar
    //     glColor3d(1, 0, 0);
    //     glPushMatrix();
    //     glTranslatef(0.0f, 0.0f, 0.0f);
    //     glBegin(GL_QUADS);
    //     glVertex3f(0.96f, 0.96f, 0.0f);
    //     glVertex3f(0.91f, 0.96f, 0.0f);
    //     glVertex3f(0.91f, 0.90f, 0.0f);
    //     glVertex3f(0.96f, 0.90f, 0.0f);

    //     glVertex3f(0.88f, 0.96f, 0.0f);
    //     glVertex3f(0.83f, 0.96f, 0.0f);
    //     glVertex3f(0.83f, 0.90f, 0.0f);
    //     glVertex3f(0.88f, 0.90f, 0.0f);

    //     glVertex3f(0.80f, 0.96f, 0.0f);
    //     glVertex3f(0.75f, 0.96f, 0.0f);
    //     glVertex3f(0.75f, 0.90f, 0.0f);
    //     glVertex3f(0.80f, 0.90f, 0.0f);
    //     glEnd();
    //     glPopMatrix();
    // }
    // else if (healthCount == 2) {
    //     glColor3d(1, 0, 0);
    //     glPushMatrix();
    //     glTranslatef(0.0f, 0.0f, 0.0f);
    //     glBegin(GL_QUADS);
    //     glVertex3f(0.96f, 0.97f, 0.0f);
    //     glVertex3f(0.91f, 0.97f, 0.0f);
    //     glVertex3f(0.91f, 0.91f, 0.0f);
    //     glVertex3f(0.96f, 0.91f, 0.0f);

    //     glVertex3f(0.88f, 0.97f, 0.0f);
    //     glVertex3f(0.83f, 0.97f, 0.0f);
    //     glVertex3f(0.83f, 0.91f, 0.0f);
    //     glVertex3f(0.88f, 0.91f, 0.0f);
    //     glEnd();
    //     glPopMatrix();
    // }
    // else if (healthCount == 1) {
    //     glColor3d(1, 0, 0);
    //     glPushMatrix();
    //     glTranslatef(0.0f, 0.0f, 0.0f);
    //     glBegin(GL_QUADS);
    //     glVertex3f(0.96f, 0.97f, 0.0f);
    //     glVertex3f(0.91f, 0.97f, 0.0f);
    //     glVertex3f(0.91f, 0.91f, 0.0f);
    //     glVertex3f(0.96f, 0.91f, 0.0f);
    //     glEnd();
    //     glPopMatrix();
    // }


    // Player
    glColor3d(1, 0, 0);
    glPushMatrix();
    _move += speed;
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glColor3d(0, 0.4, 1);
    glVertex3f(0.0f, -0.63f, 0.0f);
    glVertex3f(0.0f, -0.63f, 0.0f);
    glVertex3f(0.17f, -0.7f, 0.0f);
    glVertex3f(-0.17f, -0.7f, 0.0f);

    glColor3d(0, 0, 0.3);
    glVertex3f(-0.1f, -0.6f, 0.0f);
    glVertex3f(0.1f, -0.6f, 0.0f);
    glVertex3f(0.1f, -0.75f, 0.0f);
    glVertex3f(-0.1f, -0.75f, 0.0f);

    glColor3d(0.6, 0, 0);
    glVertex3f(0.0f, -0.55f, 0.0f);
    glVertex3f(0.0f, -0.55f, 0.0f);
    glVertex3f(0.05f, -0.60f, 0.0f);
    glVertex3f(-0.05f, -0.60f, 0.0f);

    glEnd();
    glPopMatrix();

    // Side Collision
    if (_move <= -0.83) {
        _move = -0.83;
    }
    else if (_move >= 0.83) {
        _move = 0.83;
    }

    //Obstacle Collision Left Bar
    if ((_move > -1.0f && _move < 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 1) {
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			// Decrement of Score
    }
    else if ((_move < 1.0f && _move > 0.0f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 2) {
        //Obstacle Collision Right Bar
        glutDisplayFunc(drawScene);
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			// Decrement of Score
    }
    else if ((_move > 0.4f || _move < -0.4f) && (_obstacle1 < -1.45f && _obstacle1 > -1.8f) && random == 3) {
        //Obstacle Collision Middle Bar
        Sleep(150);
        healthCount--;
        obstacleFlag = 0;
        _obstacle1 = 0.0f;			//Decrement of Score
    }

    glutSwapBuffers();
}

void update(int value) {

    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(10, update, 0); //Notify GLUT to call update again in 20 milliseconds
}

int main(int argc, char** argv) {
    int opt;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(370, 700);
    glutCreateWindow("");
    //glutInitWindowPosition(0, 1000);
    //gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(drawScene);
    glutSpecialFunc(specialKeys); //Special Key Handler
    glutTimerFunc(10, update, 0); //Add a timer
    glutMainLoop();
    return 0;
}