#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

int mouseX = 0;
int mouseY = 0;

bool showGrid = false; // Flag to control visibility

void init() {
    glClearColor(0.8, 0.8, 0.8, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
}

void drawGrid(int gridsize) {
    // glClear(GL_COLOR_BUFFER_BIT);

    if (showGrid) {
        glMatrixMode(GL_MODELVIEW);  // Switch to the modelview matrix
        glLoadIdentity();  // Load the identity matrix

        glLineWidth(1);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        for (int i = 0; i <= windowHeight; i += gridsize) {
            glBegin(GL_LINES);
            glColor4f(0.0, 0.0, 0.0, 0.7);
            glVertex2i(0, i);
            glVertex2i(windowWidth, i);
            glEnd();
        }

        for (int i = 0; i <= windowWidth; i += gridsize) {
            glBegin(GL_LINES);
            glColor4f(0.0, 0.0, 0.0, 0.7);
            glVertex2i(i, 0);
            glVertex2i(i, windowHeight);
            glEnd();
        }
    }
}

void displayCoordinates(int x, int y) {
    mouseX = x;
    mouseY = windowHeight - y;
}


void home()
{
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan jendela tampilan

    // Mentranslasikan seluruh elemen rumah ke atas
    glPushMatrix();
    glTranslatef(0.0, 0, 0.0); // Sesuaikan parameter kedua (sumbu Y) untuk posisi yang lebih tinggi

    // Menggambar elemen-elemen rumah

    // Menggambar awan di atas kebun
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk awan
    // Lingkaran pertama
    int awan1_x = 120;
    int awan1_y = 550;
    int awan1_radius = 20;
    int awan1_segments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan1_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan1_segments);
        float x = awan1_x + awan1_radius * cosf(theta);
        float y = awan1_y + awan1_radius * sinf(theta);

        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran kedua
    int awan2_x = 150;
    int awan2_y = 545;
    int awan2_radius = 30;
    int awan2_segments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan2_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan2_segments);
        float x = awan2_x + awan2_radius * cosf(theta);
        float y = awan2_y + awan2_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke3
    int awan3_x = 180;
    int awan3_y = 540;
    int awan3_radius = 30;
    int awan3_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan3_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan3_segments);
        float x = awan3_x + awan3_radius * cosf(theta);
        float y = awan3_y + awan3_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();



    // Lingkaran ke4
    int awan_4_x = 400;
    int awan_4_y = 540;
    int awan_4_radius = 60;
    int awan_4_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan_4_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan_4_segments);
        float x = awan_4_x + awan_4_radius * cosf(theta);
        float y = awan_4_y + awan_4_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke5
    int awan5_x = 320;
    int awan5_y = 540;
    int awan5_radius = 40;
    int awan5_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan5_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan5_segments);
        float x = awan5_x + awan5_radius * cosf(theta);
        float y = awan5_y + awan5_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke6
    int awan6_x = 460;
    int awan6_y = 540;
    int awan6_radius = 40;
    int awan6_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan6_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan6_segments);
        float x = awan6_x + awan6_radius * cosf(theta);
        float y = awan6_y + awan6_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke7
    int awan7_x = 650;
    int awan7_y = 540;
    int awan7_radius = 30;
    int awan7_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan7_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan7_segments);
        float x = awan7_x + awan7_radius * cosf(theta);
        float y = awan7_y + awan7_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke8
    int awan8_x = 700;
    int awan8_y = 540;
    int awan8_radius = 40;
    int awan8_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan8_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan8_segments);
        float x = awan8_x + awan8_radius * cosf(theta);
        float y = awan8_y + awan8_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Lingkaran ke9
    int awan9_x = 750;
    int awan9_y = 540;
    int awan9_radius = 60;
    int awan9_segments = 200;
    glBegin(GL_POLYGON);
    for (int i = 0; i < awan9_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(awan9_segments);
        float x = awan9_x + awan9_radius * cosf(theta);
        float y = awan9_y + awan9_radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();



    // Atap
    glColor3f(18.0 / 255.0, 72.0 / 255.0, 107.0 / 255.0); // Warna atap
    glBegin(GL_POLYGON);
    glVertex2i(100, 400);
    glVertex2i(300, 400);
    glVertex2i(350, 325);
    glVertex2i(150, 325);
    glEnd();

    // Puncak Dinding Depan
    glColor3f(15.0 / 255.0, 60.0 / 255.0, 89.0 / 255.0); // Warna puncak dinding depan
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 400);
    glVertex2i(50, 325);
    glVertex2i(150, 325);
    glEnd();

    // Dinding Depan
    glColor3f(55.0 / 255.0, 120.0 / 255.0, 130.0 / 255.0); // Warna dinding depan
    glBegin(GL_POLYGON);
    glVertex2i(50, 325);
    glVertex2i(150, 325);
    glVertex2i(150, 200);
    glVertex2i(50, 200);
    glEnd();

    // Pintu Depan
    glColor3f(0.8, 0.6, 0.4); // Warna coklat muda
    glBegin(GL_POLYGON);
    glVertex2i(75, 275);
    glVertex2i(125, 275);
    glVertex2i(125, 200);
    glVertex2i(75, 200);
    glEnd();

    // Kunci Pintu Depan
    glColor3f(0.3, 0.7, 0.9); // Warna kunci pintu
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2i(85, 235);
    glEnd();

    // Dinding Samping
    glColor3f(120.0 / 255.0, 214.0 / 255.0, 198.0 / 255.0); // Warna dinding samping
    glBegin(GL_POLYGON);
    glVertex2i(150, 325);
    glVertex2i(350, 325);
    glVertex2i(350, 200);
    glVertex2i(150, 200);
    glEnd();

    // Jendela
    glColor3f(0.2, 0.4, 0.8); // Warna jendela
    glBegin(GL_POLYGON);
    glVertex2i(215, 310);
    glVertex2i(275, 310);
    glVertex2i(275, 265);
    glVertex2i(215, 265);
    glEnd();


    // Garis Jendela
    glColor3f(0.1, 0.2, 0.5); // Warna garis jendela
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(245, 310);
    glVertex2i(245, 265);
    glVertex2i(215, 286);
    glVertex2i(275, 286);
    glEnd();


    // Menggambar pohon di sisi kanan taman
    glColor3f(0.3, 0.2, 0.1); // Warna coklat untuk batang pohon
    glBegin(GL_POLYGON);
    glVertex2i(700, 200);   // Sudut kiri bawah batang
    glVertex2i(740, 200);   // Sudut kanan bawah batang
    glVertex2i(740, 300);  // Sudut kanan atas batang
    glVertex2i(700, 300);  // Sudut kiri atas batang
    glEnd();

    glColor3f(0.0, 0.4, 0.0); // Warna hijau untuk daun pohon
    glBegin(GL_POLYGON);
    glVertex2i(660, 260);  // Sudut kiri bawah daun
    glVertex2i(780, 260);  // Sudut kanan bawah daun
    glVertex2i(720, 330);  // Sudut kanan atas daun
    glVertex2i(720, 330);  // Sudut kiri atas daun
    glEnd();

    glColor3f(0.0, 0.4, 0.0); // Warna hijau untuk daun pohon
    glBegin(GL_POLYGON);
    glVertex2i(660, 300);  // Sudut kiri bawah daun
    glVertex2i(780, 300);  // Sudut kanan bawah daun
    glVertex2i(720, 370);  // Sudut kanan atas daun
    glVertex2i(720, 370);  // Sudut kiri atas daun
    glEnd();

    glColor3f(0.0, 0.4, 0.0); // Warna hijau untuk daun pohon
    glBegin(GL_POLYGON);
    glVertex2i(660, 340);  // Sudut kiri bawah daun
    glVertex2i(780, 340);  // Sudut kanan bawah daun
    glVertex2i(720, 410);  // Sudut kanan atas daun
    glVertex2i(720, 410);  // Sudut kiri atas daun
    glEnd();




    // Menggambar cerobong asap di atap
    glColor3f(0.5, 0.5, 0.5); // Warna abu-abu untuk cerobong asap
    glBegin(GL_POLYGON);
    glVertex2i(250, 400);   // Sudut kiri atas cerobong asap
    glVertex2i(250, 425);   // Sudut kanan atas cerobong asap
    glVertex2i(275, 425);   // Sudut kanan bawah cerobong asap
    glVertex2i(275, 400);   // Sudut kiri bawah cerobong asap
    glEnd();


    // Menggambar tempat tidur taman di sisi kanan rumah
    glColor3f(0.3, 0.2, 0.1); // Warna hijau untuk tempat tidur taman
    glBegin(GL_POLYGON);
    glVertex2i(400, 200);  // Sudut kiri bawah tempat tidur taman
    glVertex2i(650, 200);  // Sudut kanan bawah tempat tidur taman
    glVertex2i(650, 350); // Sudut kanan atas tempat tidur taman
    glVertex2i(400, 350); // Sudut kiri atas tempat tidur taman
    glEnd();


    // Menggambar tanaman sayuran di taman
    glColor3f(0.0, 0.4, 0.0); // Warna kemerahan untuk tanaman sayuran
    glPointSize(10);
    glBegin(GL_POINTS);
    // Posisi tanaman sayuran
    glVertex2i(450, 225);
    glVertex2i(450, 250);
    glVertex2i(450, 275);
    glVertex2i(450, 300);
    glVertex2i(450, 325);

    glVertex2i(500, 225);
    glVertex2i(500, 250);
    glVertex2i(500, 275);
    glVertex2i(500, 300);
    glVertex2i(500, 325);

    glVertex2i(550, 225);
    glVertex2i(550, 250);
    glVertex2i(550, 275);
    glVertex2i(550, 300);
    glVertex2i(550, 325);

    glVertex2i(600, 225);
    glVertex2i(600, 250);
    glVertex2i(600, 275);
    glVertex2i(600, 300);
    glVertex2i(600, 325);
    glEnd();

    // Warna abu-abu untuk jalan
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(900, 70); // Sudut kiri bawah jalan (digeser ke bawah)
    glVertex2i(0, 70);   // Sudut kanan bawah jalan (digeser ke bawah)
    glVertex2i(0, 150);    // Sudut kanan atas jalan (digeser ke bawah)
    glVertex2i(900, 150);  // Sudut kiri atas jalan (digeser ke bawah)
    glEnd();

    // Warna abu-abu untuk bentuk
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(75, 200);    // Sudut kiri bawah
    glVertex2i(125, 200);   // Sudut kanan bawah
    glVertex2i(125, 100); // Sudut kanan atas
    glVertex2i(75, 100);  // Sudut kiri atas
    glEnd();

    // burung pertama di atap
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk burung
    glBegin(GL_LINES);
    glVertex2i(200, 490); // Tubuh burung - atas
    glVertex2i(205, 485);

    glVertex2i(205, 485); // Tubuh burung - bawah
    glVertex2i(210, 490);

    glVertex2i(205, 485); // Sayap burung - kiri
    glVertex2i(203, 482);

    glVertex2i(205, 485); // Sayap burung - kanan
    glVertex2i(207, 482);
    glEnd();


    glBegin(GL_LINES); // burung kedua di atap
    glVertex2i(230, 490); // Tubuh burung - atas
    glVertex2i(235, 485);

    glVertex2i(235, 485); // Tubuh burung - bawah
    glVertex2i(240, 490);

    glVertex2i(235, 485); // Sayap burung - kiri
    glVertex2i(233, 482);

    glVertex2i(235, 485); // Sayap burung - kanan
    glVertex2i(237, 482);
    glEnd();


    glBegin(GL_LINES);     // Menggambar burung ketiga di atap
    glVertex2i(215, 500); // Tubuh burung - atas
    glVertex2i(220, 495);

    glVertex2i(220, 495); // Tubuh burung - bawah
    glVertex2i(225, 500);

    glVertex2i(220, 495); // Sayap burung - kiri
    glVertex2i(218, 492);

    glVertex2i(220, 495); // Sayap burung - kanan
    glVertex2i(222, 492);
    glEnd();

    // burung empat
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk burung
    glBegin(GL_LINES);
    glVertex2i(500, 490); // Tubuh burung - atas
    glVertex2i(505, 485);

    glVertex2i(505, 485); // Tubuh burung - bawah
    glVertex2i(510, 490);

    glVertex2i(505, 485); // Sayap burung - kiri
    glVertex2i(503, 482);

    glVertex2i(505, 485); // Sayap burung - kanan
    glVertex2i(507, 482);
    glEnd();


    glBegin(GL_LINES); // burung kelima
    glVertex2i(530, 490); // Tubuh burung - atas
    glVertex2i(535, 485);

    glVertex2i(535, 485); // Tubuh burung - bawah
    glVertex2i(540, 490);

    glVertex2i(535, 485); // Sayap burung - kiri
    glVertex2i(533, 482);

    glVertex2i(535, 485); // Sayap burung - kanan
    glVertex2i(537, 482);
    glEnd();




    // Mengembalikan matriks transformasi asli
    glPopMatrix();

    // Memroses semua rutinitas OpenGL secepat mungkin
    glFlush();
}


void render() {
    home();

    if (showGrid) {
        drawGrid(20); // Draw the grid on top of the house
        // Display coordinates as text
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2i(10, 10);
        std::string text = "Mouse: (" + std::to_string(mouseX) + ", " + std::to_string(mouseY) + ")";
        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }

    glutSwapBuffers(); // Swap the buffers to display the rendered scene
}

void mouseHover(int x, int y) {
    displayCoordinates(x, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'G' || key == 'g') {
        showGrid = !showGrid; // Toggle the flag
        glutPostRedisplay(); // Redraw the scene
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Use double buffering
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("<RUMAH 2D GT>");
    srand(static_cast<unsigned int>(time(nullptr)));
    init();
    glutDisplayFunc(render);
    glutPassiveMotionFunc(mouseHover);
    glutKeyboardFunc(keyboard); // Register the keyboard function
    glutMainLoop();
    return 0;
}