#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
//mathfunction.cpp
/*This function draws a dot plot of function f(x) with OpenGL
The dots will scale properly on window of width W and height H
glut is used as learning tool */

const int screenWidth=640;
const int screenHeight=480;
 void myInit(void)
 {
	glClearColor(1.0,1.0,1.0,0.0);       // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color 
 	glPointSize(4.0);		       // a ‘dot’ is 4 by 4 pixels

	// sets up coordinate system for window form (0,0) to (639, 479)
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

GLdouble f(GLdouble x)
{
    //f(x) = e|-x|cos (2πx), 
    return exp(-fabs(x))* cos(2* 3.14159265*x);
}
//My function to draw f(x) to the screen.
void mathfDraw(GLdouble minX, GLdouble maxX, GLdouble minY, GLdouble maxY)
{
    //First determine how dots are drawn on screen.
    //determine offset and scale from where graph will
    //be in real world or windo vs viewport which we are
    //rendering to.
    GLdouble xOffset=(-minX*(screenWidth/(maxX-minX)));
    GLdouble xScale=screenWidth/(maxX-minX);
    
    GLdouble yScale=screenHeight/2;
    GLdouble yOffset=(-minY*(screenWidth/(maxY-minY)));
    
	glBegin(GL_POINTS);
//drawing dots to represent Big Dipper
          // draw f(x) = e|-x|cos (2πx), 
    for(GLdouble x=minX;x<maxX;x+=0.005)
    {
        glVertex2i(xScale*x+xOffset,yScale*f(x)+yOffset);
    }
    glEnd();
    glFlush();
    
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
    mathfDraw(1.0,3.0,-1.0,1.0);
              
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth,screenHeight);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Mathfunction.cpp"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}

