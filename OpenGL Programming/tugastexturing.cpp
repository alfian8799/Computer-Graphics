#include "imageloader.h"
#include <GL/glut.h>
#include <string>
#include <filesystem>

using namespace std;

GLuint _textureId; //The id of the texture
GLfloat z_pos = 0.0f;
string scriptDir;

const char* path(string filename) { // relative to absolute path
    string filePath = scriptDir + "\\" + filename;
    return filePath.c_str();
}

GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGB,
        image->width, image->height,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        image->pixels);
    return textureId;
};

void init() {
    // isi sesuai dengan nomer 7 di modul pdf, ketik sendiri
    Glfloat lightPosotion[]

        // trus bagian yg ini👇 biarin itu yg path() nya
        // beda gak kaya yg di modul, kudu gitu, dah gw coba.
        // jangan lupa file bmp nya harus ada di folder yg sama
        // dengan file cpp ini, nama filenya sesuaikan
        Image* image = loadBMP(path("flower.bmp"));
    _textureId = loadTexture(image);
}

void mydisplay() {
    // isi sesuai dengan nomer 8 di modul pdf, ketik sendiri

    glDisable(GL_TEXTURE_2D); // baris yg ini di modul typo
    // 👆 yg gw tulis ini udh bener
    glutSwapBuffers();

    // jadi ntar kalo udah, di run, screenshot kode ama
    // output gambarnya, trus buat nomer 9 ama 10 tuh ubah
    // kode yg bagian ini, mydisplay(), cek yg glTexCoord2f
    // ama yg glVertex2f itu angkanya beda2. trus ntar screenshot lagi
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    scriptDir = std::filesystem::path(argv[0]).parent_path().string();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Tugas Texturing");
    init();
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}
