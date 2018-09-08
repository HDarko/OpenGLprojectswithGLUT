#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Draw the Sierpinski Gasket that requires the endpoints of outmost triangle,number of dots
//and size of dots.
struct GLintPoint{
	GLfloat x, y;
};

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
 {
   glClearColor(0.7,0.7,0.7,0.0);       // set white background color
    glColor3f(0.0f, 0.0f, 1.0f);
glPointSize(4.0);          // set the drawing color		       // a ‘dot’ is 4 by 4 pixels
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
//<<<<<<<<<<<<<<<<<<<<< DrawD);ot >>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<<< Sierpinski >>>>>>>>>>>>>>>>>
int Sierpiski2(GLfloat xend,GLfloat yend,float dotsize,int dotcount) 
    
{
    glPointSize(dotsize);
    //If the endpont chosen isnt the far enough then stop
    if ((xend<300))
    {return 0;}
   
	GLintPoint T[3]= {{10,10},{300,30},{xend,yend}};
	
	int index = random()%3;         // 0, 1, or 2 equally likely 
	GLintPoint point = T[index]; 	 // initial point 
	drawDot(point.x, point.y);     // draw initial point 
	for(int i = 0; i < dotcount; i++)  // draw chosen dots
	{
        if (i%3)
        {
            glColor3f(0.741f, 0.718f, 0.420f);
        }
        else
        {
             glColor3f(1.000f, 0.498f, 0.314f);
        }
	
		 index = random()%3; 	
		 point.x = (point.x + T[index].x) / 2;
		 point.y = (point.y + T[index].y) / 2;
		 drawDot(point.x,point.y);  
	};
	glFlush(); 
    return 0;
}

void callSier()
{
 Sierpiski2(500,300,4.0,1000);
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640,480);    // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Sierpinski"); // open the screen window
	glutDisplayFunc(callSier);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}