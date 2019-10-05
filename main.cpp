/* Alumno: Tomairo Huamanraime Juan Junior */

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <ctime>
using namespace std;

void init(void);
void display(void);
void reshape(int,int);
void curva(int, GLfloat, GLfloat);
void ejes(GLfloat, GLfloat);
void polares(GLfloat, GLfloat);
void circunferencia(float, GLfloat, GLfloat);
void parte2(void);
void colorGrafica(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0); //parametros: rojo, amarillo, azul, el cuarto es el parametro alpha
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glPointSize(2.0);


    /* */

    parte2();


    glPopMatrix(); // reecupera el estado del matriz
    glFlush();
}

void colorGrafica(void){
    int red, green, blue;

    /* Generamos numeros aleatorios para los colores */
    red = rand()%255;
    green = rand()%255;
    blue = rand()%255;

    glColor3ub(red, green, blue);
    cout << "Nuevo Color: " << red << " - " << green << " - " << blue << endl;

}

void parte2(void){

    cout << "Parte 2"  << endl;

    int tamano = 7;
    int N = 2;  // N = {2, 3, 4, ... 10}

    for (int f = -1; f <= 1; f++){
        for (int c = 1; c >=-1; c--){

                glColor3f(0.0, 0.0, 1.0);

                polares(tamano*f, tamano*c);

                colorGrafica();

                curva(N, tamano*f, tamano*c);

                N++;

        }
    }




}

void curva(int N, GLfloat xN, GLfloat yN )
{

    /* Se graficara una grafica polar recibiendo el dato N, y las coordenadas centrales (xN; yN) */
    GLfloat ang, radio, x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/100)
    {
        radio=2*sin(N*ang);
        x = radio * cos(ang);
        y = radio * sin(ang);
        glVertex2f(x+xN,y+yN);
    }
    glEnd();
}

void circunferencia(float radio, GLfloat xN, GLfloat yN)
{
    GLfloat ang,  x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/100)
    {
    x = radio * sin(ang);
    y = radio * cos(ang);
    glVertex2f(x+xN,y+yN);
    }
    glEnd();
}

void polares(GLfloat xN, GLfloat yN)
{
    float x,y,ang;
    glColor3f(0.0,1.0,0.0);
    ejes(xN, yN);



    for(float radio=1.0;radio<3.0;radio+=0.25)
        circunferencia(radio, xN, yN);

    for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/10)
    {
        x = 2.75 * cos(ang);
        y = 2.75 * sin(ang);

        glBegin(GL_LINES);
        glVertex2f(xN,yN);
        glVertex2f(x+xN,y+yN);
        glEnd();

    }

}

void ejes(GLfloat xN, GLfloat yN)
{

    glBegin(GL_LINES);
       glVertex2f(-2.5 + xN,0.0+yN);
       glVertex2f(2.5 + xN,0.0+yN);
       glVertex2f(0 + xN, 2.75+yN);
       glVertex2f(0 + xN,-2.75+yN);
    glEnd();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
