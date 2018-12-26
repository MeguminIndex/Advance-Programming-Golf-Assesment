// Pool Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include<glut.h>
#include<math.h>

#include"simulation.h"
#include"Table.h"


int playersID = 0;;


int strokes = 0;



Table gTable;

//cue variables
float gCueAngle = 0.0;
float gCuePower = 0.25;
bool gCueControl[4] = {false,false,false,false};
float gCueAngleSpeed = 2.0f; //radians per second
float gCuePowerSpeed = 0.25f;
float gCuePowerMax = 0.75;
float gCuePowerMin = 0.1;
float gCueBallFactor = 8.0;
bool gDoCue = true;

//camera variables
vec3 gCamPos(2.0,4.0,1.9);
vec3 gCamLookAt(-2.0, 0.5, 0.3);
bool gCamRotate = true;
float gCamRotSpeed = 1.6;
float gCamMoveSpeed = 2.5;
bool gCamL = false;
bool gCamR = false;
bool gCamU = false;
bool gCamD = false;
bool gCamZin = false;
bool gCamZout = false;

// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly =0.0f;

// XZ position of the camera
float x = 0.0f, z = 5.0f, y = 1.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;



//rendering options
#define DRAW_SOLID	(0)

void DoCamera(int ms)
{
	static const vec3 up(0.0,1.0,0.0);



	if(gCamRotate)
	{
		if(gCamL)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localL = up.Cross(camDir);
			vec3 inc = (localL* ((gCamRotSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir + inc;
		}
		if(gCamR)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = up.Cross(camDir);
			vec3 inc = (localR* ((gCamRotSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir - inc;
		}
		if(gCamU)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir + inc;
		}
		if(gCamD)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamLookAt = gCamPos + camDir - inc;
		}		
	}
	else
	{
		if(gCamL)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localL = up.Cross(camDir);
			vec3 inc = (localL* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamR)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 inc = (localR* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamU)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localUp = localR.Cross(camDir);
			vec3 inc = (localUp* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
		if(gCamD)
		{
			vec3 camDir = (gCamLookAt - gCamPos).Normalised();
			vec3 localR = camDir.Cross(up);
			vec3 localDown = camDir.Cross(localR);
			vec3 inc = (localDown* ((gCamMoveSpeed*ms)/1000.0) );
			gCamPos += inc;
			gCamLookAt += inc;
		}
	}

	if(gCamZin)
	{
		vec3 camDir = (gCamLookAt - gCamPos).Normalised();
		vec3 inc = (camDir* ((gCamMoveSpeed*ms)/1000.0) );
		gCamPos += inc;
		gCamLookAt += inc;
	}
	if(gCamZout)
	{
		vec3 camDir = (gCamLookAt - gCamPos).Normalised();
		vec3 inc = (camDir* ((gCamMoveSpeed*ms)/1000.0) );
		gCamPos -= inc;
		gCamLookAt -= inc;
	}

	std::cout << " Cam X: "<< gCamPos(0)<<" Cam Y: " << gCamPos(1)<< " Cam Z: " << gCamPos(2) << std::endl;
	std::cout << " Cam Look X: " << gCamLookAt(0) << " Cam Look Y: " << gCamLookAt(1) << " Cam Look Z: " << gCamLookAt(2) << std::endl;
}


void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}



void drawBitmapText(char* string, float x, float y, float z, float r = 1, float g =1, float b = 1)
{
	int j = strlen(string);

	glRasterPos3f(x, y, z);
	glColor3f(r, g, b);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}


	

}




void RenderScene(void) {
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set camera
	glLoadIdentity();

	vec3 ballPos = gTable.balls[playersID].GetPosition();

	/*gluLookAt(ballPos(1), ballPos(2) + 2,ballPos(0),
 (ballPos(1) + 0.0f) + gCamLookAt(0), (ballPos(2) + -0.0f) + gCamLookAt(1), ballPos(0) + gCamLookAt(2),0.0f,1.0f,0.0f);
*/

	if (deltaMove)
		computePos(deltaMove);

	// Set the camera
	gluLookAt(x, y, z,
		x + lx, y, z + lz,
		0.0f, 1.0f, 0.0f);


	// Draw ground
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, -1.10f,-100.0f);
	glVertex3f(-100.0f, -1.10f, 100.0f);
	glVertex3f( 100.0f, -1.10f, 100.0f);
	glVertex3f( 100.0f, -1.10f,-100.0f);
	glEnd();


	//draw the ball
	//glColor3f(1.0,1.0,1.0);
	for(int i=0;i<NUM_BALLS;i++)
	{
		//vec3 colour = gTable.balls[i].colour;

		//glColor3f(colour.elem[0],colour.elem[1],colour.elem[2]);

		//vec3 position = gTable.balls[i].GetPosition();

		//glPushMatrix();
		//glTranslatef(position(0), position(2),position(1));
		//#if DRAW_SOLID
		//glutSolidSphere(gTable.balls[i].radius,32,32);
		//#else
		//glutWireSphere(gTable.balls[i].GetRadius(),12,12);
		//#endif
		//glPopMatrix();
		////glColor3f(0.0,0.0,1.0);

		gTable.balls[i].Draw();

		
	}
	glColor3f(1.0,1.0,1.0);

	

	//draw the table
	for(int i=0;i<NUM_CUSHIONS;i++)
	{	
	/*	vec3 position = gTable.cushions[i].GetPosition();

		glBegin(GL_LINE_LOOP);
		glVertex3f (gTable.cushions[i].vertices[0](0) - position(0), 0.0 - position(2), gTable.cushions[i].vertices[0](1) - position(1));
		glVertex3f (gTable.cushions[i].vertices[0](0) - position(0), 0.1 - position(2), gTable.cushions[i].vertices[0](1) - position(1));
		glVertex3f (gTable.cushions[i].vertices[1](0) - position(0), 0.1 - position(2), gTable.cushions[i].vertices[1](1) - position(1));
		glVertex3f (gTable.cushions[i].vertices[1](0) - position(0), 0.0 - position(2), gTable.cushions[i].vertices[1](1) - position(1));
		glEnd();*/


		gTable.cushions[i].Draw();

	}

	
	

	//for(int i=0;i<gTable.parts.num;i++)
	//{

	//	GLfloat test = (GLfloat)(rand() % 100) / 100;
	//	std::cout << test << std::endl;
	//	//glColor3f(1.0, 1.0, 1.0);
	//	glColor3f(((GLfloat)(rand() % 100)/100), ((GLfloat)(rand() % 100) / 100), ((GLfloat)(rand() % 100) / 100));
	//	glPushMatrix();
	//	glTranslatef(gTable.parts.particles[i]->position(0),gTable.parts.particles[i]->position(1),gTable.parts.particles[i]->position(2));
	//	#if DRAW_SOLID
	//	glutSolidSphere(1.022f,32,32);
	//	#else
	//	glutWireSphere(1.022f,12,12);
	//	#endif
	//	glPopMatrix();		
	//}
	/*
	glBegin(GL_LINE_LOOP);
	glVertex3f (TABLE_X, 0.0, -TABLE_Z);
	glVertex3f (TABLE_X, 0.1, -TABLE_Z);
	glVertex3f (TABLE_X, 0.1, TABLE_Z);
	glVertex3f (TABLE_X, 0.0, TABLE_Z);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f (TABLE_X, 0.0, -TABLE_Z);
	glVertex3f (TABLE_X, 0.1, -TABLE_Z);
	glVertex3f (-TABLE_X, 0.1, -TABLE_Z);
	glVertex3f (-TABLE_X, 0.0, -TABLE_Z);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f (TABLE_X, 0.0, TABLE_Z);
	glVertex3f (TABLE_X, 0.1, TABLE_Z);
	glVertex3f (-TABLE_X, 0.1, TABLE_Z);
	glVertex3f (-TABLE_X, 0.0, TABLE_Z);
	glEnd();
	*/

	//draw the cue
	if(gDoCue)
	{
		vec3 position = gTable.balls[0].GetPosition();

		glBegin(GL_LINES);
		float cuex = sin(gCueAngle) * gCuePower;
		float cuez = cos(gCueAngle) * gCuePower;
		glColor3f(1.0,0.0,0.0);
		glVertex3f (0-position(0),0 -position(2),0- position(1));
		glVertex3f (0-(position(0)+cuex),0- position(2),0- (position(1)+cuez));
		glColor3f(1.0,1.0,1.0);
		glEnd();
	}

	//glPopMatrix();


	//UI

	//unsigned char string[] = "The quick god jumps over the lazy brown fox.";
	//float w;
	//w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);

	//glRasterPos2f(0., 0.);

	//float x = .5; /* Centre in the middle of the window */
	//glRasterPos2f(x - (float)w / 2, 0.);

	//glColor3f(1.0, 0.0, 0.0);

	//int len = strlen(string);
	//for (i = 0; i < len; i++) {
	//	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string);
	//}


	glDisable(GL_DEPTH_TEST);

	

	//Texte(0, 12, "Hey !");
	//drawGuiBackground();

	char buffer[20];

	sprintf(buffer,"Strokes: %d", strokes);
	//string mystring = std::to_string(strokes);

	drawBitmapText(buffer, x+lx, y+0.25f, z +lz, 0, 1, 0);

	glFlush();
	glutSwapBuffers();
}

void SpecKeyboardFunc(int key, int x, int y) 
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
		{
			gCueControl[0] = true;
			break;
		}
		case GLUT_KEY_RIGHT:
		{
			gCueControl[1] = true;
			break;
		}
		case GLUT_KEY_UP:
		{
			gCueControl[2] = true;
			break;
		}
		case GLUT_KEY_DOWN:
		{
			gCueControl[3] = true;
			break;
		}
	}
}

void SpecKeyboardUpFunc(int key, int x, int y) 
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
		{
			gCueControl[0] = false;
			break;
		}
		case GLUT_KEY_RIGHT:
		{
			gCueControl[1] = false;
			break;
		}
		case GLUT_KEY_UP:
		{
			gCueControl[2] = false;
			break;
		}
		case GLUT_KEY_DOWN:
		{
			gCueControl[3] = false;
			break;
		}
	}
}

void KeyboardFunc(unsigned char key, int x, int y) 
{
	switch(key)
	{
	case ('w'): deltaMove = 0.5f; break;
	case ('s'): deltaMove = -0.5f; break;


	case(13):
		{
			if(gDoCue)
			{
				strokes += 1;

				vec3 imp(	(-sin(gCueAngle) * gCuePower * gCueBallFactor),
							(-cos(gCueAngle) * gCuePower * gCueBallFactor),0.0f);
				gTable.balls[0].ApplyImpulse(imp);				
			}
			break;
		}
	case(27):
		{
			for(int i=0;i<NUM_BALLS;i++)
			{
				gTable.balls[i].Reset();

				
			}
			break;
		}
	case(32):
		{
			gCamRotate = false;
			break;
		}
	//case('z'):
	//	{
	//		gCamL = true;
	//		break;
	//	}
	//case('c'):
	//	{
	//		gCamR = true;
	//		break;
	//	}
	//case('s'):
	//	{
	//		gCamU = true;
	//		break;
	//	}
	//case('x'):
	//	{
	//		gCamD = true;
	//		break;
	//	}
	//case('f'):
	//	{
	//		gCamZin = true;
	//		break;
	//	}
	//case('v'):
	//	{
	//		gCamZout = true;
	//		break;
	//	}
	}

}

void KeyboardUpFunc(unsigned char key, int x, int y) 
{
	switch(key)
	{
	case ('w'):
	case ('s'): deltaMove = 0; break;


	//case(32):
	//	{
	//		gCamRotate = true;
	//		break;
	//	}
	//case('z'):
	//	{
	//		gCamL = false;
	//		break;
	//	}
	//case('c'):
	//	{
	//		gCamR = false;
	//		break;
	//	}
	//case('s'):
	//	{
	//		gCamU = false;
	//		break;
	//	}
	//case('x'):
	//	{
	//		gCamD = false;
	//		break;
	//	}
	//case('f'):
	//	{
	//		gCamZin = false;
	//		break;
	//	}
	//case('v'):
	//	{
	//		gCamZout = false;
	//		break;
	//	}
	case('j'):
	{
		std::cout << "J pressed" << std::endl;
		gTable.cushions[0].SetScale(vec3(2));
		break;
	}
	}
}




void MouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}



void ChangeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,0.2,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0,0.7,2.1, 0.0,0.0,0.0, 0.0f,1.0f,0.0f);
	gluLookAt(gCamPos(0),gCamPos(1),gCamPos(2),gCamLookAt(0),gCamLookAt(1),gCamLookAt(2),0.0f,1.0f,0.0f);
}

void InitLights(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat light_ambient[] = { 2.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}

void UpdateScene(int ms) 
{
	if(gTable.AnyBallsMoving()==false) gDoCue = true;
	else gDoCue = false;

	if(gDoCue)
	{
		if(gCueControl[0]) gCueAngle -= ((gCueAngleSpeed * ms)/1000);
		if(gCueControl[1]) gCueAngle += ((gCueAngleSpeed * ms)/1000);
		if (gCueAngle <0.0) gCueAngle += TWO_PI;
		if (gCueAngle >TWO_PI) gCueAngle -= TWO_PI;

		if(gCueControl[2]) gCuePower += ((gCuePowerSpeed * ms)/1000);
		if(gCueControl[3]) gCuePower -= ((gCuePowerSpeed * ms)/1000);
		if(gCuePower > gCuePowerMax) gCuePower = gCuePowerMax;
		if(gCuePower < gCuePowerMin) gCuePower = gCuePowerMin;
	}

	//DoCamera(ms);

	gTable.Update(ms);

	glutTimerFunc(SIM_UPDATE_MS, UpdateScene, SIM_UPDATE_MS);
	glutPostRedisplay();
}

int _tmain(int argc, _TCHAR* argv[])
{
	gTable.SetupCushions();

	glutInit(&argc, ((char **)argv));
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,700);
	//glutFullScreen();
	glutCreateWindow("Advance Programming Golf");
	#if DRAW_SOLID
	InitLights();
	#endif
	glutDisplayFunc(RenderScene);
	glutTimerFunc(SIM_UPDATE_MS, UpdateScene, SIM_UPDATE_MS);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RenderScene);
	
	



	//gCamLookAt = vec3(-9.0, 1.0, -8.0);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecKeyboardFunc);
	glutSpecialUpFunc(SpecKeyboardUpFunc);

	glutMouseFunc(MouseButton);
	glutMotionFunc(mouseMove);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();




}
