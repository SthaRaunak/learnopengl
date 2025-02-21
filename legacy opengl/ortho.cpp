// g++ main.cpp -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION  -o app
#include <GLUT/glut.h>

void display();
void reshape(int, int);
void timer(int);

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
};

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // color mode for api how color will be specified in program i.e in RGB form

    // GLUT DOUBLE makes it so we have a front and back buffer so we don't see the drawing happening in real time (flashing) distorts the image when back buffer has completed drawing it is swaped to front and again back buffer is used for drawing
    //  GLUT_SINGLE is the opposite of GLUT_DOUBLE

    // glut helps create window ireespective of platform
    glutInitWindowPosition(200, 100); // initializes postion of window
    glutInitWindowSize(500, 500);     // width and hegiht of window

    glutCreateWindow("Window 1"); // creates window with text of window

    glutDisplayFunc(display); // this will register display calbback to above window
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();

    // exectuion loop
    glutMainLoop();
    return 0;
}

float x_position = -10.0; // global variable
int statePos = 1;         // 1 for right

// display callback function
void display()
{
    // glClearColor(1.0, 1.0, 1.0, 1.0); // rgba
    glClear(GL_COLOR_BUFFER_BIT); // clear the frame buffer on memory
    glLoadIdentity();             // resets the matrisx transformation from previous buffer

    // glPointSize(10.0); // pixels
    

    // draw
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0); //set the color of polygon
    glVertex2f(x_position, 1.0);        // top left
    glColor3f(1.0,0.0,1.0); //set the color of polygon
    glVertex2f(x_position, -1.0);       // bottom left
    glColor3f(0.0,1.0,0.0); //set the color of polygon
    glVertex2f(x_position + 2.0, -1.0); // bottom right
    glColor3f(0.0,0.0,1.0); //set the color of polygon
    glVertex2f(x_position + 2.0, 1.0);  // top right
    glEnd();

    // glFlush(); // flush the buffer to screen onyl for single buffer
    glutSwapBuffers();
}

// reshape callback function called by api intialy & whenever window is resized
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // (x,y) relative to bottom left corner then widht and height of window

    // default matrix is model view matrix

    glMatrixMode(GL_PROJECTION);  // switch to projection matrix
    glLoadIdentity();             // reset the projection matrix
    gluOrtho2D(-10, 10, -10, 10); // set the orthographic projection (look it up)
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();                // calls the display function i.e it will get called 60 times per second
    glutTimerFunc(1000 / 60, timer, 0); // 60 times per second 60fps

    switch (statePos)
    {
    case 1:
        if (x_position < 8)
        {
            x_position += 0.30;
        }
        else
        {
            statePos = -1;
        }
        break;
    case -1:
        if (x_position > -10)
        {
            x_position -= 0.30;
        }
        else
        {
            statePos = 1;
        }
        break;
    }
}
