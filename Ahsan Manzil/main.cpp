#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<cstdio>

# define PI           3.14159265358979323846
using namespace std;


bool day = true , night = false,isRaining = false;
bool isStopped = false;
bool isSound = false;


void handleKeypress(unsigned char key, int x, int y);
void handleMouse(int button, int state, int x, int y);
void SpecialInput(int key, int x, int y);
void update(int value);
void Idle();
void display();


void scene();
void river();
void riverSideRoadGrass();
void rain();
void road();
void roadStripe();
void field();
void hill();
void hillLong();
void circle();
void roadStripe();
void car1();
void Cloud();
void scene();
void sky();
void moon();
void tree();
void sound();
void sound1();
void nullsound();
void build();



GLfloat i=0;
GLfloat cloudMovement = 0.0f;
GLfloat cloudMovement2 = 0.0f;
GLfloat rainMovementX = 0.0f;
GLfloat rainMovementY = 0.0f;
GLfloat car1Position = 0.0f;
GLfloat car1Speed = 0.05f;
GLfloat boatM3 = 0.0f;
GLfloat boatM4 = 0.0f;
GLfloat boatM5 = 0.0f;
GLfloat position =0.0f;














void Idle(){
    glutPostRedisplay();
}

////////////////////////////////////////////////////// SOUND
void sound()
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void nullsound()
{
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

/////////////////////////////////////////////////////  DNR
void dayt(int a)
{
    day=true;
    night=false;
    isRaining = false;
}
void nightt(int b)
{
    day=false;
    night=true;
    isRaining = false;

}
void raind(int c)
{
    night=false;
    day=true;
    isRaining = true;

}

void rainn(int d)
{
    day=false;
    night=true;
    isRaining = true;

}

/////////////////////////////////////////////////////////////  KEYBOARD

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {


    case 'n':
        night = true;
        day = false;
    break;
    case 'd':
        night = false;
        day = true;
    break;

    case 'r':
        if(isRaining)
        {
            if(!isSound)
            {
                nullsound();

            }
            else{}

            isRaining = false;
        }
        else
        {
            isRaining = true;
            sound();
        }
    break;

    case 'a':
    day=true;
        glutTimerFunc(3000,nightt,0);
        glutTimerFunc(6000,dayt,3000);
        glutTimerFunc(9000,raind,6000);
        glutTimerFunc(12000,rainn,9000);
        glutTimerFunc(15000,nightt,12000);
        glutTimerFunc(18000,dayt,15000);
        glutTimerFunc(21000,raind,18000);
        glutTimerFunc(24000,rainn,21000);





    break;
    }

    glutPostRedisplay();

}

/////////////////////////////////////////////////////////////  MOUSE(ANIMATION PLAY/PAUSE)

void handleMouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON)
        {

            isStopped = false;
        }
        if (button == GLUT_RIGHT_BUTTON)
        {
            isStopped = true;
        }
	glutPostRedisplay();

}

////////////////////////////////////////////////////// KEYBOARD (CAR SPEED)

void SpecialInput(int key, int x, int y){
    switch(key)
    {
        case GLUT_KEY_UP:

        if(car1Speed<=2)
        {
            car1Speed += 0.02;

        }
        break;
        case GLUT_KEY_DOWN:

         if(car1Speed>=0.02)
        {
            car1Speed -= 0.02;

        }
        break;
    }
glutPostRedisplay();
}

////////////////////////////////////////////////////  OBJECT MOVEMENT

void update(int value){

    if(!isStopped)
    {
        cloudMovement += 0.002f;
    if(cloudMovement>=1.9)
    {
        cloudMovement = -1.6f;
    }

    cloudMovement2 += 0.002f;
    if(cloudMovement2>=2.9)
    {
        cloudMovement2 = -2.6;
    }

    if(car1Position>=2)
        {car1Position = -1.5;}

    car1Position+=car1Speed;


    boatM4 += .03;
    if(boatM4>=1.9f)
    {
        boatM4 = -1.5f;
    }

    boatM5 -= 0.015;
    if(boatM5<=-1.0)
    {
        boatM5 = +1.9;
    }





    i+=2;


    rainMovementX  -=0.002f;
    rainMovementY -=0.009f;

    if(rainMovementX<1.0f)
    {
        rainMovementX = 0.0f;
    }

    if(rainMovementY<-1.0f)
    {
        rainMovementY = 0.0f;
    }

    }



	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

/////////////////////////////////////////////////  STATIC OBJECT

void riverSideRoadGrass()
{
    glBegin(GL_QUADS); //field

    if(night)
    {
        glColor3f(0.223, 0.584, 0.156);
    }
    else
    {
        glColor3f(0.435, 0.839, 0.360);
    }

    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();
}


void rain()
{

    int i=0,j=0;
    float x,y;
    x=-1.0f;
    y=2.0f;

    while(j<=100)
    {
        x = -1.0f;
        while(i<=100)
        {
            glBegin(GL_LINES);
            glColor3f(0.313, 0.560, 0.713);
            glVertex2f(x,y);
            glVertex2f(x-0.02f,y-0.07f);
            glEnd();

            x=x+0.05f;
            i++;
        }
        y = y-0.07f;
        j++;
        i=0;
    }


}

void circle(float a, float b, float c, float m, float n, float o)
{
    int i;

	GLfloat x=a; GLfloat y=b; GLfloat radius =c;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(m,n,o);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void roadStripe()
{
    //ROAD

    glBegin(GL_QUADS);
    glColor3f(0.270, 0.270, 0.270);
    glVertex2f(-1,.3);
    glVertex2f(-1,.1);
    glVertex2f(1,.1);
    glVertex2f(1,.3);
    glEnd();

    //Grass
    glBegin(GL_QUADS);
    glColor3f(0.435, 0.839, 0.360);
    glVertex2f(-1,.6);
    glVertex2f(-1,.3);
    glVertex2f(1,.3);
    glVertex2f(1,.6);
    glEnd();



    //ROAD LINE
    glBegin(GL_QUADS);
    glColor3f(0.917, 0.749, 0.211);

    glVertex2f(-1,.21);
    glVertex2f(-1,.19);
    glVertex2f(-.75,.19);
    glVertex2f(-.75,.21);

    glVertex2f(-.5,.21);
    glVertex2f(-.5,.19);
    glVertex2f(-.25,.19);
    glVertex2f(-.25,.21);


    glVertex2f(0,.21);
    glVertex2f(.0,.19);
    glVertex2f(.25,.19);
    glVertex2f(.25,.21);

    glVertex2f(.5,.21);
    glVertex2f(.5,.19);
    glVertex2f(.75,.19);
    glVertex2f(.75,.21);

    glEnd();
}

void build()
{
    // Rectangle
    glBegin(GL_POLYGON);
    glColor3f(0.690, 0.270, 0.270);
    glVertex2f(-0.85,0.095);
    glVertex2f(-0.85,0.45);
    glVertex2f(0.85,0.45);
    glVertex2f(0.85,0.095);

    glEnd();

    if(day)
    {


//  Door B1
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);


//  Door B2
    glTranslatef(0.1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door B3
    glTranslatef(0.2,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door B4
    glTranslatef(0.3,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

// Door B5
    glTranslatef(0.45,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();

// Door B6
    glTranslatef(0.55,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();
    ///////////////////////////////////

//   Door T1
    glTranslatef(0,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door T2
    glTranslatef(0.1,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();
//  Door T3
    glTranslatef(0.2,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door T4
    glTranslatef(0.3,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

// Door T5
    glTranslatef(0.45,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();

// Door T6
    glTranslatef(0.55,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();


//  Top bar 1
    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.85,0.45);
    glVertex2f(-0.85,0.46);
    glVertex2f(0.85,0.46);
    glVertex2f(0.85,0.45);

    glEnd();

//  Top bar 2
    glBegin(GL_POLYGON);
    glColor3f(0.690, 0.270, 0.270);
    glVertex2f(-0.85,0.46);
    glVertex2f(-0.85,0.47);
    glVertex2f(0.85,0.47);
    glVertex2f(0.85,0.46);

    glEnd();

//  Top bar 3
    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.85,0.47);
    glVertex2f(-0.85,0.48);
    glVertex2f(0.85,0.48);
    glVertex2f(0.85,0.47);

    glEnd();





// Pillar 1
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();

//  Pillar 2
    glTranslatef(0.25,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();




////////////////////////////////////////////////////////////////////
//Mirror

//Door B1
    glTranslatef(-0.44,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door B2
    glTranslatef(-0.54,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door B3
    glTranslatef(-0.64,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door B4
    glTranslatef(-0.74,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

// Door B5
    glTranslatef(-0.89,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();

// Door B6
    glTranslatef(-0.99,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();
    ///////////////////////////////////

//   Door T1
    glTranslatef(-0.44,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door T2
    glTranslatef(-0.54,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();
//  Door T3
    glTranslatef(-0.64,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

//  Door T4
    glTranslatef(-0.74,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.286, 0.152, 0.152);
    glLoadIdentity();

// Door T5
    glTranslatef(-0.89,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();

// Door T6
    glTranslatef(-0.99,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.878, 0.423, 0.423);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.878, 0.423, 0.423);
    glLoadIdentity();








// Pillar 1
    glTranslatef(-1.19,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

//  Pillar 2
    glTranslatef(-1.44,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Pillar 3

    glTranslatef(-0.45,0.03,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Pillar 4
    glTranslatef(-0.75,0.03,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Dome

    glBegin(GL_POLYGON);
    glColor3f(0.690, 0.270, 0.270);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.45);
    glVertex2f(0.10,0.45);
    glVertex2f(0.10,0.55);

    glEnd();
    circle(0,0.55,0.1,0.690, 0.270, 0.270);

    circle(0,0.6,0.08,0.690, 0.270, 0.270);

    circle(0,0.67,0.02,0.690, 0.270, 0.270);

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.01,0.72);
    glVertex2f(-0.01,0.69);
    glVertex2f(0.01,0.69);
    glVertex2f(0.01,0.72);
    glEnd();

// lines

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.45);
    glVertex2f(-0.09,0.45);
    glVertex2f(-0.09,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.09,0.55);
    glVertex2f(0.09,0.45);
    glVertex2f(0.1,0.45);
    glVertex2f(0.1,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.54);
    glVertex2f(0.10,0.54);
    glVertex2f(0.10,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.08,0.55);
    glVertex2f(-0.08,0.48);
    glVertex2f(-0.07,0.48);
    glVertex2f(-0.07,0.55);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.06,0.55);
    glVertex2f(-0.06,0.48);
    glVertex2f(-0.05,0.48);
    glVertex2f(-0.05,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.02,0.55);
    glVertex2f(-0.02,0.48);
    glVertex2f(-0.01,0.48);
    glVertex2f(-0.01,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.01,0.55);
    glVertex2f(0.01,0.48);
    glVertex2f(0.02,0.48);
    glVertex2f(0.02,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.05,0.55);
    glVertex2f(0.05,0.48);
    glVertex2f(0.06,0.48);
    glVertex2f(0.06,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.07,0.55);
    glVertex2f(0.07,0.48);
    glVertex2f(0.08,0.48);
    glVertex2f(0.08,0.55);

    glEnd();


//  Stairs

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.27);
    glVertex2f(-0.11,0.26);
    glVertex2f(0.12,0.26);
    glVertex2f(0.12,0.27);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.26);
    glVertex2f(-0.11,0.25);
    glVertex2f(0.12,0.25);
    glVertex2f(0.12,0.26);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.25);
    glVertex2f(-0.11,0.24);
    glVertex2f(0.12,0.24);
    glVertex2f(0.12,0.25);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.24);
    glVertex2f(-0.11,0.23);
    glVertex2f(0.12,0.23);
    glVertex2f(0.12,0.24);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.23);
    glVertex2f(-0.11,0.22);
    glVertex2f(0.12,0.22);
    glVertex2f(0.12,0.23);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.22);
    glVertex2f(-0.11,0.21);
    glVertex2f(0.12,0.21);
    glVertex2f(0.12,0.22);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.21);
    glVertex2f(-0.11,0.2);
    glVertex2f(0.12,0.2);
    glVertex2f(0.12,0.21);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.2);
    glVertex2f(-0.11,0.19);
    glVertex2f(0.12,0.19);
    glVertex2f(0.12,0.2);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.19);
    glVertex2f(-0.11,0.18);
    glVertex2f(0.12,0.18);
    glVertex2f(0.12,0.19);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.12,0.18);
    glVertex2f(-0.12,0.17);
    glVertex2f(0.13,0.17);
    glVertex2f(0.13,0.18);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.13,0.17);
    glVertex2f(-0.13,0.16);
    glVertex2f(0.14,0.16);
    glVertex2f(0.14,0.17);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.14,0.16);
    glVertex2f(-0.14,0.15);
    glVertex2f(0.15,0.15);
    glVertex2f(0.15,0.16);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.15,0.15);
    glVertex2f(-0.15,0.14);
    glVertex2f(0.16,0.14);
    glVertex2f(0.16,0.15);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.16,0.14);
    glVertex2f(-0.16,0.13);
    glVertex2f(0.17,0.13);
    glVertex2f(0.17,0.14);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.17,0.13);
    glVertex2f(-0.17,0.14);
    glVertex2f(0.18,0.14);
    glVertex2f(0.18,0.13);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.18,0.12);
    glVertex2f(-0.18,0.13);
    glVertex2f(0.19,0.13);
    glVertex2f(0.19,0.12);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.19,0.11);
    glVertex2f(-0.19,0.12);
    glVertex2f(0.20,0.12);
    glVertex2f(0.20,0.11);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.20,0.1);
    glVertex2f(-0.20,0.11);
    glVertex2f(0.21,0.11);
    glVertex2f(0.21,0.1);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.21,0.09);
    glVertex2f(-0.21,0.1);
    glVertex2f(0.22,0.1);
    glVertex2f(0.22,0.09);

    glEnd();

// Big doors

    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(-0.05,0.4);
    glVertex2f(-0.05,0.27);
    glVertex2f(0.05,0.27);
    glVertex2f(0.05,0.4);
    glEnd();
    circle(0,0.4,0.05,0.286, 0.152, 0.152);

    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(0.06,0.4);
    glVertex2f(0.06,0.27);
    glVertex2f(0.1,0.27);
    glVertex2f(0.1,0.4);
    glEnd();
    circle(0.08,0.4,0.02,0.286, 0.152, 0.152);


    glBegin(GL_POLYGON);
    glColor3f(0.286, 0.152, 0.152);
    glVertex2f(-0.1,0.4);
    glVertex2f(-0.1,0.27);
    glVertex2f(-0.06,0.27);
    glVertex2f(-0.06,0.4);
    glEnd();
    circle(-0.08,0.4,0.02,0.286, 0.152, 0.152);

}


if(night)
{
    //  Door B1
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);


//  Door B2
    glTranslatef(0.1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door B3
    glTranslatef(0.2,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door B4
    glTranslatef(0.3,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

// Door B5
    glTranslatef(0.45,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();

// Door B6
    glTranslatef(0.55,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();
    ///////////////////////////////////

//   Door T1
    glTranslatef(0,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door T2
    glTranslatef(0.1,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();
//  Door T3
    glTranslatef(0.2,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door T4
    glTranslatef(0.3,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

// Door T5
    glTranslatef(0.45,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();

// Door T6
    glTranslatef(0.55,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();


//  Top bar 1
    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.85,0.45);
    glVertex2f(-0.85,0.46);
    glVertex2f(0.85,0.46);
    glVertex2f(0.85,0.45);

    glEnd();

//  Top bar 2
    glBegin(GL_POLYGON);
    glColor3f(0.690, 0.270, 0.270);
    glVertex2f(-0.85,0.46);
    glVertex2f(-0.85,0.47);
    glVertex2f(0.85,0.47);
    glVertex2f(0.85,0.46);

    glEnd();

//  Top bar 3
    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.85,0.47);
    glVertex2f(-0.85,0.48);
    glVertex2f(0.85,0.48);
    glVertex2f(0.85,0.47);

    glEnd();





// Pillar 1
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();

//  Pillar 2
    glTranslatef(0.25,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();




////////////////////////////////////////////////////////////////////
//Mirror

//Door B1
    glTranslatef(-0.44,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door B2
    glTranslatef(-0.54,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door B3
    glTranslatef(-0.64,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door B4
    glTranslatef(-0.74,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

// Door B5
    glTranslatef(-0.89,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();

// Door B6
    glTranslatef(-0.99,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();
    ///////////////////////////////////

//   Door T1
    glTranslatef(-0.44,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);
    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door T2
    glTranslatef(-0.54,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();
//  Door T3
    glTranslatef(-0.64,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

//  Door T4
    glTranslatef(-0.74,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0.870, 0.874, 0.345);
    glLoadIdentity();

// Door T5
    glTranslatef(-0.89,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0,0,0);
    glLoadIdentity();

// Door T6
    glTranslatef(-0.99,0.18,0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.2,0.095);
    glVertex2f(0.2,0.2);
    glVertex2f(0.25,0.2);
    glVertex2f(0.25,0.095);

    glEnd();
    circle(0.225,0.2,0.025,0, 0, 0);
    glLoadIdentity();








// Pillar 1
    glTranslatef(-1.19,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

//  Pillar 2
    glTranslatef(-1.44,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);


    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Pillar 3

    glTranslatef(-0.45,0.03,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Pillar 4
    glTranslatef(-0.75,0.03,0);
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.58,0.095);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.62,0.095);

    glEnd();
    circle(0.6,0.48,0.025,0.545, 0.215, 0.215);



    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.215, 0.215);
    glVertex2f(0.595,0.095);
    glVertex2f(0.595,0.52);
    glVertex2f(0.605,0.52);
    glVertex2f(0.605,0.095);

    glEnd();
    glLoadIdentity();

// Dome

    glBegin(GL_POLYGON);
    glColor3f(0.690, 0.270, 0.270);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.45);
    glVertex2f(0.10,0.45);
    glVertex2f(0.10,0.55);

    glEnd();
    circle(0,0.55,0.1,0.690, 0.270, 0.270);

    circle(0,0.6,0.08,0.690, 0.270, 0.270);

    circle(0,0.67,0.02,0.690, 0.270, 0.270);

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.01,0.72);
    glVertex2f(-0.01,0.69);
    glVertex2f(0.01,0.69);
    glVertex2f(0.01,0.72);
    glEnd();

// lines

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.45);
    glVertex2f(-0.09,0.45);
    glVertex2f(-0.09,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.09,0.55);
    glVertex2f(0.09,0.45);
    glVertex2f(0.1,0.45);
    glVertex2f(0.1,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.1,0.54);
    glVertex2f(0.10,0.54);
    glVertex2f(0.10,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.08,0.55);
    glVertex2f(-0.08,0.48);
    glVertex2f(-0.07,0.48);
    glVertex2f(-0.07,0.55);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.06,0.55);
    glVertex2f(-0.06,0.48);
    glVertex2f(-0.05,0.48);
    glVertex2f(-0.05,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.02,0.55);
    glVertex2f(-0.02,0.48);
    glVertex2f(-0.01,0.48);
    glVertex2f(-0.01,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.01,0.55);
    glVertex2f(0.01,0.48);
    glVertex2f(0.02,0.48);
    glVertex2f(0.02,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.05,0.55);
    glVertex2f(0.05,0.48);
    glVertex2f(0.06,0.48);
    glVertex2f(0.06,0.55);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.07,0.55);
    glVertex2f(0.07,0.48);
    glVertex2f(0.08,0.48);
    glVertex2f(0.08,0.55);

    glEnd();


//  Stairs

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.27);
    glVertex2f(-0.11,0.26);
    glVertex2f(0.12,0.26);
    glVertex2f(0.12,0.27);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.26);
    glVertex2f(-0.11,0.25);
    glVertex2f(0.12,0.25);
    glVertex2f(0.12,0.26);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.25);
    glVertex2f(-0.11,0.24);
    glVertex2f(0.12,0.24);
    glVertex2f(0.12,0.25);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.24);
    glVertex2f(-0.11,0.23);
    glVertex2f(0.12,0.23);
    glVertex2f(0.12,0.24);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.23);
    glVertex2f(-0.11,0.22);
    glVertex2f(0.12,0.22);
    glVertex2f(0.12,0.23);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.22);
    glVertex2f(-0.11,0.21);
    glVertex2f(0.12,0.21);
    glVertex2f(0.12,0.22);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.21);
    glVertex2f(-0.11,0.2);
    glVertex2f(0.12,0.2);
    glVertex2f(0.12,0.21);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.11,0.2);
    glVertex2f(-0.11,0.19);
    glVertex2f(0.12,0.19);
    glVertex2f(0.12,0.2);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.11,0.19);
    glVertex2f(-0.11,0.18);
    glVertex2f(0.12,0.18);
    glVertex2f(0.12,0.19);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.12,0.18);
    glVertex2f(-0.12,0.17);
    glVertex2f(0.13,0.17);
    glVertex2f(0.13,0.18);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.13,0.17);
    glVertex2f(-0.13,0.16);
    glVertex2f(0.14,0.16);
    glVertex2f(0.14,0.17);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.14,0.16);
    glVertex2f(-0.14,0.15);
    glVertex2f(0.15,0.15);
    glVertex2f(0.15,0.16);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.15,0.15);
    glVertex2f(-0.15,0.14);
    glVertex2f(0.16,0.14);
    glVertex2f(0.16,0.15);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.16,0.14);
    glVertex2f(-0.16,0.13);
    glVertex2f(0.17,0.13);
    glVertex2f(0.17,0.14);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.17,0.13);
    glVertex2f(-0.17,0.14);
    glVertex2f(0.18,0.14);
    glVertex2f(0.18,0.13);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.18,0.12);
    glVertex2f(-0.18,0.13);
    glVertex2f(0.19,0.13);
    glVertex2f(0.19,0.12);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.19,0.11);
    glVertex2f(-0.19,0.12);
    glVertex2f(0.20,0.12);
    glVertex2f(0.20,0.11);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.886, 0.811, 0.811);
    glVertex2f(-0.20,0.1);
    glVertex2f(-0.20,0.11);
    glVertex2f(0.21,0.11);
    glVertex2f(0.21,0.1);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-0.21,0.09);
    glVertex2f(-0.21,0.1);
    glVertex2f(0.22,0.1);
    glVertex2f(0.22,0.09);

    glEnd();

// Big doors

    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(-0.05,0.4);
    glVertex2f(-0.05,0.27);
    glVertex2f(0.05,0.27);
    glVertex2f(0.05,0.4);
    glEnd();
    circle(0,0.4,0.05,0.870, 0.874, 0.345);

    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(0.06,0.4);
    glVertex2f(0.06,0.27);
    glVertex2f(0.1,0.27);
    glVertex2f(0.1,0.4);
    glEnd();
    circle(0.08,0.4,0.02,0.870, 0.874, 0.345);


    glBegin(GL_POLYGON);
    glColor3f(0.870, 0.874, 0.345);
    glVertex2f(-0.1,0.4);
    glVertex2f(-0.1,0.27);
    glVertex2f(-0.06,0.27);
    glVertex2f(-0.06,0.4);
    glEnd();
    circle(-0.08,0.4,0.02,0.870, 0.874, 0.345);

}
}






void car1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.780, 0.101, 0.188); //body
    glVertex2f(-.04,.2);
    glVertex2f(-.02,0);
    glVertex2f(.7,0);
    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glEnd();

    glBegin(GL_POLYGON); //window body
    glVertex2f(.2,.3);
    glVertex2f(0,.2);
    glVertex2f(.55,.2);
    glVertex2f(.4,.3);
    glEnd();

    glBegin(GL_POLYGON);//window
    glColor3f(0,0,0);
    glVertex2f(.2,.28);
    glVertex2f(0.04,.2);
    glVertex2f(.51,.2);
    glVertex2f(.4,.28);
    glEnd();

    glBegin(GL_TRIANGLES);//lights

    if(night)
    {
        glColor3f(1,1,1);
    }
    if(day)
    {
        glColor3f(0,0,0);
    }
    glVertex2f(.7,.15);
    glVertex2f(.6,.2);
    glVertex2f(.6,.15);
    glEnd();

    //wheels
    circle(.13,0,.1,0, 0, 0);
    circle(.55,0,.1,0, 0, 0);

}




void road()
{
    roadStripe();
    //ROAD DIVIDER

    glBegin(GL_QUADS);
    glColor3f(0.435, 0.839, 0.360);
    glVertex2f(-1,.1);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,.1);
    glEnd();

    //END OF ROAD DIVIDER
    glTranslatef(0,-.3,0);
    roadStripe();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(car1Position,0,0);
    glTranslatef(-.8,-.05,0);
    glScalef(.4,.3,1);
    car1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();


    ////////////////////

  //LAMP
 float xLamp= -0.8f; float yLamp = -0.01f;

    for(int i =0;i<=9;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(0.525, 0.372, 0.133);
        glVertex2f(xLamp,yLamp+0.04);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp+0.01,yLamp+0.1);
        glVertex2f(xLamp+0.01,yLamp+0.04);


        glColor3f(0,0,0);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp,yLamp+0.09);
        glVertex2f(xLamp+0.03,yLamp+0.09);
        glVertex2f(xLamp+0.03,yLamp+0.1);

        glEnd();

        glBegin(GL_POLYGON);

        if(night)
        {
            glColor3f(1,1,1);
        }
        else
        {
            glColor3f(0.337, 0.345, 0.333);
        }

        glVertex2f(xLamp+0.02,yLamp+.09);
        glVertex2f(xLamp+0.01,yLamp+0.07);
        glVertex2f(xLamp+0.03,yLamp+0.07);
        glVertex2f(xLamp+0.02,yLamp+.09);

        glEnd();

        xLamp = xLamp+.2;

    }


}
void hill()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();

    glScalef(.7,.7,1);
    glTranslatef(.2,0,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();
    glLoadIdentity();
}
void hillLong()
{
    float x=-1.3;
    for(int i=0;i<10;i++)
    {
        glTranslatef(x,.6,0);
        hill();
        glLoadIdentity();
        x+=.25;
    }
}





void Cloud()
{

    GLfloat x=.0f; GLfloat y=.8f; GLfloat radius =.1f;
	int i;
	int triangleAmount  = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.686, 0.866, 0.933);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x = -0.1;
	y = .82;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x = 0.0;
	y = .85;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x = 0.1;
	y = .82;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



	x = 0.0;
	y = .75;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void tree()
{
    float vTree = -0.95f;
    float zTree = 0.55f;

    float vTree2 = vTree+.05f;
    float zTree2 = zTree -.05f;

        glBegin(GL_QUADS);
        glColor3f(0.482, 0.215, 0.078);
        glVertex2f(vTree,zTree+.15);
        glVertex2f(vTree,zTree);
        glVertex2f(vTree+.005,zTree);
        glVertex2f(vTree+.005,zTree+.15);

        glVertex2f(vTree2,zTree2+.15);
        glVertex2f(vTree2,zTree2);
        glVertex2f(vTree2+.005,zTree2);
        glVertex2f(vTree2+.005,zTree2+.15);


        glEnd();
        vTree = vTree + .0025;
        vTree2 = vTree2 + .0025;
        glBegin(GL_TRIANGLES);
        glColor3f(0.250, 0.529, 0.070);

        glVertex2f(vTree,zTree+.18);
        glVertex2f(vTree-.03,zTree+.12);
        glVertex2f(vTree+.03,zTree+.12);

        glVertex2f(vTree,zTree+.14);
        glVertex2f(vTree-.03,zTree+.08);
        glVertex2f(vTree+.03,zTree+.08);


        glVertex2f(vTree2,zTree2+.18);
        glVertex2f(vTree2-.03,zTree2+.12);
        glVertex2f(vTree2+.03,zTree2+.12);

        glVertex2f(vTree2,zTree2+.14);
        glVertex2f(vTree2-.03,zTree2+.08);
        glVertex2f(vTree2+.03,zTree2+.08);

        glEnd();

        vTree = vTree+0.3;
        vTree2 = vTree2 + 0.3;

}


// FUNCTION



void field()
{
    glBegin(GL_QUADS); //field

    if(night)
    {
        glColor3f(0.223, 0.584, 0.156);
    }
    else
    {
        glColor3f(0.435, 0.839, 0.360);
    }


    glVertex2f(-1,.6);
    glVertex2f(-1,.24);
    glVertex2f(1,.24);
    glVertex2f(1,.6);
    glEnd(); //field Ends


/////////////////////////////////
    //elements







/////////////////////////trees
    glTranslatef(0,-.05,0);
    tree();
    glLoadIdentity();

    glTranslatef(.7,-.08,0);
    tree();
    glLoadIdentity();

    glTranslatef(1.5,-.2,0);
    tree();
    glLoadIdentity();

    glTranslatef(1.85,-.02,0);
    tree();
    glLoadIdentity();
}



void sky()
{

    if(day)
    {
        circle(0.25,0.84,0.09, 1, 0.733, 0.2);//sun
    }
    if(night)
    {
        glTranslatef(-.2,.35,0);
        glScalef(.7,.7,1);
        moon();
        glLoadIdentity();
    }

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.3,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(.7,.4,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();


    //
    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.3,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(.7,.4,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();


}





/////////////////////////////////////////////////////////////



void river()
{
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.886, 0.968); //Water color
    if(night)
    {
        glColor3f(0.133, 0.207, 0.211);
    }

    glVertex2f(-1,-.3);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.3);
    glEnd();

}




void moon()
{
    circle(0.5,0.6,0.08, 1,1,1);//moon
}





void boat()
{
    glBegin(GL_POLYGON);
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.06,0);
    glVertex2f(0.075,0);
    glVertex2f(0.075,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.08,0);
    glVertex2f(0.125,0);
    glVertex2f(.08,0.1);

    glEnd();

    if(night)
    {
        //LIGHT

        glBegin(GL_TRIANGLES);
        glColor3f(0.968, 0.968, 0.788);

        glVertex2f(0.19,-0.01);
        glVertex2f(0.28,-0.02);
        glVertex2f(0.27,-0.05);

        glEnd();

        //END OF LIGHT

    }



}

void boat2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.11,0);
    glVertex2f(0.095,0);
    glVertex2f(0.095,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.09,0);
    glVertex2f(0.045,0);
    glVertex2f(.09,0.1);

    glEnd();
    if(night)
    {
//LIGHT

    glBegin(GL_TRIANGLES);
    glColor3f(0.968, 0.968, 0.788);

    glVertex2f(0.01,-0.01);
    glVertex2f(-0.1,-0.02);
    glVertex2f(-0.08,-0.05);

    glEnd();

    //END OF LIGHT
    }
}




void windmill()
{
//VILLAGE MILL

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(.1,.47);
    glVertex2f(.1,.32);
    glVertex2f(.11,.32);
    glVertex2f(.11,.47);


    glEnd();

//ANIMATION

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack,
    glTranslatef(0.105,.47,0.0);
    glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
    glBegin(GL_TRIANGLES);
    glColor3f(0.188, 0.188, 0.188);

    glVertex2f(.0,.0);
    glVertex2f(.02,.11);
    glVertex2f(.04,.12);

    glVertex2f(.0,.0);
    glVertex2f(-.02,-.11);
    glVertex2f(-.04,-.12);

    glVertex2f(.0,.0);
    glVertex2f(-.11,.02);
    glVertex2f(-.12,.04);


    glVertex2f(.0,.0);
    glVertex2f(.11,-.02);
    glVertex2f(.12,-.04);









    glEnd();
    glPopMatrix();//glPopMatrix pops the top matrix off the stack
    //i=i+.1=.2


//ANIMATION END

//CIRCLE OF FAN
    GLfloat xMoon=0.105f; GLfloat  yMoon=.47f; GLfloat moonRadius =.02f;
    GLfloat moonTwicePi = 2.0f * PI;
    int moonTriangleAmount = 20;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.188, 0.188, 0.188);
            glVertex2f(xMoon, yMoon); // center of circle
            for(int i = 0; i <= moonTriangleAmount;i++) {
                glVertex2f(
                        xMoon + (moonRadius * cos(i *  moonTwicePi /moonTriangleAmount )),
                    yMoon + (moonRadius * sin(i * moonTwicePi / moonTriangleAmount))
                );
            }
        glEnd();

    //CIRCLE OF FAN

}

void scene(){


    sky();
    hillLong();
    field();

    glScalef(1,.7,1);
    glTranslatef(0,.05,0);
    road();
    glLoadIdentity();

/////////////////////////////////////////////////

//WIND MILLS
    riverSideRoadGrass();
    glTranslatef(0,-.02,0);
    glScalef(1.0,0.8,0.0);
    glLoadIdentity();

    glScalef(1.0,0.8,0.0);
    glTranslatef(0,-.02,0);
    glLoadIdentity();

    glTranslatef(-1.3,-.6,0);////OUT
    windmill();
    glLoadIdentity();


    glTranslatef(-.9,-.6,0);
    windmill();
    glLoadIdentity();



    glTranslatef(-.3,-.6,0);
    windmill();
    glLoadIdentity();


    glTranslatef(-.0,-.6,0);
    windmill();
    glLoadIdentity();



    glTranslatef(.6,-.6,0);
    windmill();
    glLoadIdentity();

//WIND MILLS

    build();


    river();
    glPushMatrix();

    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(boatM4,0.0,0.0);
    glTranslatef(-0.6,-.5,0);
    glScalef(1.4,1.4,0);
    boat();
    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(boatM3,0.0,0.0);
    glTranslatef(0.2,-.6,0);
    glScalef(1.5,1.5,0);
    boat();
    glLoadIdentity();
    glPopMatrix();



    glPushMatrix();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM5,0.0,0.0);
    glTranslatef(-0.6,-.8,0);
    glScalef(1.7,1.7,0);
    boat2();
    glLoadIdentity();
    glPopMatrix();


    if(isRaining)
    {
        glTranslatef(rainMovementX,rainMovementY,0);
        rain();
        glLoadIdentity();
    }




}
void display(){

    if(night)
    {
        glClearColor(0.164f, 0.180f, 0.239f, 1.0f);
    }
    else
    {
        glClearColor(0.552f, 0.733f, 0.839f, 1.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    scene();

    glFlush();

}
int main(int argc, char** argv){

    cout << "Pause Animation-                Mouse Right Click" << endl;
    cout << "Resume Animation-               Mouse Left Click" << endl;
    cout << "Day-                            Keyboard D" << endl;
    cout << "Night-                          Keyboard N" << endl;
    cout << "Toggle Rain-                    Keyboard R" << endl;
    cout << "Auto change of view             Keyboard A" << endl;
    cout << "Increase Car Speed-             Upper Arrow" << endl;
    cout << "Decrease Car Speed-             Lower Arrow" << endl;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Ahsan Manzil");
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
