#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

//Drawing a 7 rosette
class Point2{
    public:
        float x,y;
        void set(float dx, float dy){x=dx; y=dy;}
        void set(Point2& p){x=p.x; y=p.y;}
        Point2(float xx, float yy){x=xx; y=yy;}
        Point2(){x=y=0;}
};
Point2 CP; //current position
void moveToPoint2(Point2 p)
{
    CP.set(p);	
}
void lineToPoint2(Point2 p)
{


	glBegin(GL_LINES);
		glVertex2f(CP.x, CP.y);
		glVertex2f(p.x, p.y);
	glEnd();
	//glFlush();
	CP.set(p);
	//std::cout<<"new CP("<<CP.x<<","<<CP.y<<")\n";

}

void moveTo(float x, float y)
{
	Point2 p=Point2(x, y);
	moveToPoint2(p);
}

void lineTo(float x, float y)
{
	Point2 p=Point2(x, y);
	lineToPoint2(p);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{      
	if(n < 3) return; 		// not enough sides
	double angle = rotAngle*3.14159265/180;  // initial angle
	double angleInc = 2 * 3.14159265 /n;     //angle increment 
	moveTo(radius + cx, cy);
    for (int i=1;i<4;i++) //connect each vertex to the ith next vertex
    {
        for(int k = 0; k < n; k++)  // repeat n times
        {
            angle +=i*angleInc; //Connect vertex to the ith vertex.
            lineTo(radius*cos(angle)+cx, radius*sin(angle)+cy);		
        
	}
        
    }
    
  

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
	gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	ngon(7, 0.0f, 0.0f, 2.0f, 0.0f);
	glFlush();		                 // send all output to display 
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 640);     // set window size
	glutInitWindowPosition(300, 250); // set window position on screen
	glutCreateWindow("n-gon"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}





