#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

int screenWidth{640};
int screenHeight{640};
//Draw two Archimedian Spirals with one being a flipped upside down version of the other.
using namespace std;





void DrawSpiral()
{
    float PI=3.1415926f;
    float A=7.0f;
    float incre=0.05f;
    glBegin(GL_LINE_STRIP);
     glColor3f(0.0f, 0.5f, 1.0f);
    for(float theta = 0.0f; theta<(40.0f); theta+=incre){
 
        float x = (A*theta)*cos(theta);
        float y = (A*theta)*sin(theta);
 
        glVertex2f(x + (screenWidth/2),y+(screenHeight/2));
        ;
    }
    glEnd();
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_LINE_STRIP);
     for(float theta = 0.0f; theta<(40.0f); theta+=incre){
 
        float x2 = -(A*theta)*cos(theta);
        float y2 = -(A*theta)*sin(theta);
 
        glVertex2f((x2) + (screenWidth/2),(y2) +(screenHeight/2));
        ;
    }
 
 
	glEnd();
} 
    
    
    
    






//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
	glClearColor(1.0,1.0,1.0,0.0);       // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color 
 	glPointSize(4.0);		       // a pointer is 4 by 4 pixels

	// sets up coordinate system for window form (0,0) to (639, 479)
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, -640.0, 640.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

        DrawSpiral();
	glFlush();		                 // send all output to display 
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 640);     // set window size
	glutInitWindowPosition(300, 250); // set window position on screen
	glutCreateWindow("Archimedean Spiral"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}





