#define FREEGLUT_STATIC

#include <cmath>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string.h>
#include <iomanip>
#include <chrono>

#include <Game.hpp>

#define M_PI        3.14159265358979323846
#define onii        using
#define oniichan    using
#define suki        std::cout
#define hentai      std::endl
#define chan        namespace
#define mendokusai  std::chrono

oniichan suki;
oniichan hentai;
onii chan mendokusai;

Game *main_game;

int WIN_SIZE[] = {1280, 720};

const GLfloat light0_position[] = { 10.0f, 5.0f, 0.0f, 1.0f };
const GLfloat light1_position[] = { -10.0f, 5.0f, 0.0f, 1.0f };
const GLfloat light_ambient[]   = { 0.0f, 0.0f, 0.0f, 0.f };
const GLfloat light_diffuse[]   = { 1.0f, 1.0f, 1.0f, 0.5f };
const GLfloat light_specular[]  = { 1.0f, 1.0f, 1.0f, 0.3f };

const GLfloat mat_ambient[]     = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]     = { 0.8f, 0.8f, 0.8f, 0.3f };
const GLfloat mat_specular[]    = { 1.0f, 1.0f, 1.0f, 0.2f };

void initGL() {
    glClearColor(0., .5, 0.5, 1.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    main_game = new Game();
}

void handleKeyPress(unsigned char key, int x, int y){
    main_game->keyboardPressCallback(key, x, y);
}
void handleKeyRelease(unsigned char key, int x, int y){
    main_game->keyboardReleaseCallback(key, x, y);
}
void handleReshape(int new_w, int new_h){
    main_game->reshapeCallback(new_w, new_h);
}
void handleMousePosition(int mouse_x, int mouse_y){
    main_game->passiveMouseCallback(mouse_x, mouse_y);
}
void display(){
    main_game->update();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_SIZE[0], WIN_SIZE[1]);
    glutCreateWindow("fuck mee");
    glutIgnoreKeyRepeat(0); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
    initGL();

    // callbacks
    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyRelease);
    glutReshapeFunc(handleReshape);
    glutPassiveMotionFunc(handleMousePosition);

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop(); 
    return 0;
} 

