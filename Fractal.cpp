#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Draw the Fractal with the Gasket function

struct GLintPoint{
	GLfloat x, y;
};

//<<<<<<<<<<<<<<<<<<<<<<< myInit functions>>>>>>>>>>>>>>>>>>>>

 void setWorldWindow(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top)
 {
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
     
 }



 void myInit(void)
 {
     glClearColor(0.7,0.7,0.7,0.0);       // background color is white
     glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
 	  glPointSize(4.0);		          // a 'dot' is 2 by 2 pixels
     setWorldWindow(-320,320,-240,240);
  
}


void setViewport(GLint left,GLint right,GLint bottom,GLint top)
{
    glViewport(left,right,bottom,top);
}

//<<<<<<<<<<<<<<<<<<<<< DrawDot >>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<<< Sierpinski >>>>>>>>>>>>>>>>>
int Sierpiski2(float dotsize,int dotcount) 
    
{
    glPointSize(dotsize);
    //If the endpont chosen isnt the far enough then stop
   // if ((xend<300))
   // {return 0;}
   
	GLintPoint T[3]= {{120,-120},{0,0},{-120,-120}};
	
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
   glPushMatrix();
   glBegin(GL_LINES);
    //Drawing x-axis and y-axis.
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2i(-320,0);
   glVertex2i(320,0);
   glVertex2i(0,240);
   glVertex2i(0,-240);
   glEnd();
    //Drawing Fractal
  for(int count=0;count<6;count++)
  {
      Sierpiski2(2.0,1000);
      glRotated(72.0,0.0,0.0,1.0);
  }
  glPopMatrix();  
 
 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640,480);    // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Fractal"); // open the screen window
	glutDisplayFunc(callSier);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}