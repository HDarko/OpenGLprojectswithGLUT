#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
//Create a checkerboard of a given size on OpenGL

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

void Checkerboard(int size)
{
    //Build a 8x8 checker board with squares of size n
    for (int row=0;row<8;row++)
    {
        for(int col=0;col<8;col++)
        {
            if((col+row)%2==0)
               //Define colours from 0-255 in (r,g,b)
            {
               glColor3ub(72, 209, 204);   
            }
            else
            {
                glColor3ub(220, 20, 60);   
            }
            //Draw each unit square
            glRecti(row*size,col*size,(row+1)*size,(col+1)*size);
        }
            glEnd();
            glFlush();
               
        }
}

    
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen 
    Checkerboard(60);
              
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth,screenHeight);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Checkerboard"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}

