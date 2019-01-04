#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
//Static Particle class
class Particle
{
 public:
     //Location of Particle
    GLfloat xLoc=0.0f;
    GLfloat yLoc=0.0f;
    //Color and alpha of particle
    GLfloat red=0.0f;
	GLfloat blue=1.0f;
	GLfloat green=0.0f;
	GLfloat alpha=1.0f;
    //Size of particle
    GLfloat size=4.0f;
    //Original position
    GLfloat xInitial=0.0f;
    GLfloat yInitial=0.0f;
    //Age of particle
    GLint age=0;
    //Gravity
    GLfloat gravity=0.0f;
    
   
    //Constructor of location and size
    Particle(GLfloat x,GLfloat y, GLfloat si)
        :xLoc{x},yLoc{y},size{si},xInitial{x},yInitial{y}   
        {}
       
    //Default Contructor   
    Particle()
        :xLoc{0.0f},yLoc{0.0f},size{4.0f},xInitial{0.0f},yInitial{0.0f}   
    {}
    
    void Draw()
        {
        // Set the size of the point and draw it
         glPointSize(size);
         glBegin(GL_POINTS);
         // Set the colour and draw the particle
        glColor4f( red, blue, green, alpha );
        glVertex2f(xLoc,yLoc);
 
       glEnd();
          }

    //Update location of particle to exact spot
    void update(int x, int y)
        {
        
         age++;
         //Reset iparticle has expired
         if(age>5000)
         {
         
             xLoc=xInitial;
             yLoc=yInitial;
             age=0;
         }
         else
         {
         xLoc=x;
         yLoc=y;
         }
          
        }
        
        //Set initial position of particle
        void initial(int x, int y)
        {
        xInitial=x;
        yInitial=y; 
        }
        
       //change Particle position by x,y 
     void updateby(GLfloat x, GLfloat y)
        {
      
         age++;
         xLoc+=x;
         yLoc+=y;
     
         
          }
          
          //shoot particle at specific angle and speed
     void Fire(GLfloat angle,GLfloat speed)
        {
        
              age++;
            float xx=(speed*angle)*cos(angle);
            float yy=(speed*angle)*cos(angle);
            //After age of 100, reset the particle
             if(age>700)
             {
                 xLoc=xInitial;
                 yLoc=yInitial;
                 age=0;
                 gravity=0;
             }
             else
             {
             xLoc+=xx-gravity;
             yLoc+=yy-(2*gravity);
             }
         
         
     
         
          }
 
 
 
};