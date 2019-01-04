#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "HPart.h"
#include <vector>

//#include "custom particle class HPart.h
using namespace std;

const int screenWidth{640};
const int screenHeight{640};


//Infor for Pipe
//Number of particles generated in scene
const int numParticles=1500;

//Array containing the particles
Particle blackHole[numParticles];


//
//Array for cutting the particle system
GLfloat radChange[numParticles];

//angle of roation around the center
GLfloat angle[numParticles];
//radius from center
GLfloat radius[numParticles];
//speed of each particle
GLfloat speed[numParticles];

//force applied to particle
float force=1.0f;

//largest angle for shooting particle
float angleMax=40.0f;
//Cut the particle system
GLfloat scatter=0.0f;
//Distance from the center of screen.Controlled by keyboard
GLfloat radiusoffset=0;

//Value to increase particle vibration
GLfloat sp;


const GLfloat GRAVITY = -0.05f;
const GLfloat baselineYSpeed = 4.0f;
const GLfloat maxYSpeed = 4.0f;


//Used to control speed of particles
//GLfloat slowDown=0.005f;

 



void PipeInit()
{
    //Initialization
   
   for (int i=0;i<numParticles;i++)
    {
       //Angle for each particle
        angle[i]=(GLfloat)(rand()%628)/100.0f;
       //A raduis from the center
        radius[i]=screenWidth/2+((GLfloat)(rand()%100+500));
       
       //blackHole is the array containing particles
        blackHole[i].update((GLfloat)sin(angle[i])*radius[i]/10,(GLfloat)cos(angle[i])*radius[i]/10);
       
       blackHole[i].initial((GLfloat)sin(angle[i])*radius[i]/10,(GLfloat)cos(angle[i])*radius[i]/10);
       
       //Set the colour of the particle
        blackHole[i].red=(rand() / (float)RAND_MAX);
        blackHole[i].green=(rand() / (float)RAND_MAX);;
        blackHole[i].blue=(rand() / (float)RAND_MAX);;
       
       //Set the speed of each particle in an outside array
        speed[i] = 1.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(5.0f-1.0f)));
    
       //Change in the radius from center for the particle
         radChange[i]=5.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(20.0f-5.0f)));
    
        
       
      
        
    }
   
        
}

void Pipe()
{
    
    glBegin(GL_POINTS);
  
    //For each particle
    for (int i=0;i<numParticles;i++)
    {
         //increase the gravity to affect the force from Fire()
         blackHole[i].gravity+=0.00005;
        
        //Either vibrations of particle remain the same or is increased by user
        speed[i]=sp;
        blackHole[i].Fire(angle[i],speed[i]);
        
          //Find the particle's color
        glColor3f(blackHole[i].red,blackHole[i].blue,blackHole[i].green);
         
        //reset angle if it goes beyond max value else increase it
        if (angle[i]>angleMax)
        {
        angle[i]=(GLfloat)(rand()%628)/100.0f;
        }
        else
        {
        
            angle[i]+=10.05f;
               
        }
        if (blackHole[i].age>70)
        {
            //this cuts the particle sytem in half based on user input
            blackHole[i].updateby(cos(radChange[i]*scatter),tan(-radChange[i]*scatter));
        }
        
       
        
        //Draw the particle at its position though it can be affected by force and radiusoffest values
        glVertex2f(blackHole[i].xLoc*force+radiusoffset,blackHole[i].yLoc*force+radiusoffset);
        
        
    }
    glEnd();
    

}



    



 



//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
	glClearColor(0.0,0.0,0.0,0.0);       // set white background color
	glColor3f(1.0f, 0.0f, 0.0f);          // set the drawing color 
 	glPointSize(4.0);		       // a pointer is 4 by 4 pixels

	// sets up coordinate system for window form (0,0) to (639, 479)
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	//gluOrtho2D(0.0, 640.0, -640.0, 640.0);
     gluOrtho2D(-640.0, 640.0, -640, 640.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
    //DrawRose();
    //BlackHoleInit();
    
   Pipe();
 
	
	glutSwapBuffers();		                 // send all output to display 
    
}
//k then cut with c

void movePipe(unsigned char theKey, int mouseX,int mouseY)
{
    switch(theKey)
    {
        case'd':
            radiusoffset+=50;
            break;
            
        case'a':
            radiusoffset-=50;
            break;
        case'r':
             radiusoffset=0;
            force=1;
            angleMax=40.0f;
            scatter=0.0f;
            sp=1.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(5.0f-1.0f)));
             break;
        case'f':
            force+=0.20f;
            break;
        case's':
            force-=0.20f;
            break;
        case 'e':
            angleMax+=80.0f;
            break;
        case 'c':
            scatter+=0.10f;
            break;
          case 'k':
            sp+=0.10f;
            break;
         
         
      
    
         
        
    }
    
  
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
     
     
    
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight);     // set window size
	glutInitWindowPosition(300, 250); // set window position on screen
    PipeInit();
    //FireworkFireInit(200,0);
	glutCreateWindow("Petals"); 
    glutKeyboardFunc(movePipe);// open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
    glutIdleFunc(myDisplay);
	myInit();  
    cout<<"Instructions:"<<endl;
     cout<<"Press d to move top-right"<<endl;
     cout<<"Press a to move left"<<endl;
     cout<<"Press s to shrink horizontaly"<<endl;
       cout<<"Press f to expand horizontally "<<endl;
       cout<<"Press k to increase vibration:"<<endl;
       cout<<"Press l to lower or inverse vibration:"<<endl;
    cout<<"Press r to reset to pipe:"<<endl;
       cout<<"Press c to cut:"<<endl;
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;	
}


