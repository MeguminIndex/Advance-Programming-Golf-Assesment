#pragma once

#include "GolfBall.h"
#include "GolfHole.h"

#define TABLE_X			(0.6f) 
#define TABLE_Z			(1.2f)
#define TABLE_Y			(0.1f)
//#define TABLE_X			(0.5f) 
//#define TABLE_Z			(0.5f)
//#define TABLE_Y			(0.1f)
#define BALL_RADIUS		(0.05f)
#define BALL_MASS		(0.1f)
#define TWO_PI			(6.2832f)
#define	SIM_UPDATE_MS	(10)
#define NUM_BALLS		(1)		
#define NUM_CUSHIONS	(12)		
#define MAX_PARTICLES	(200)
#define NUM_HOLES (2)

class Course
{
public:
	Course();
	~Course();

	int currentHole = -1;
	bool courseFinished = false;
	//a dictionary of player balls which can be acces by player ID ~ thinking ahead for multiplayer as each pc will be assigned a unique ID
	std::map<int, GolfBall> playerBalls;

	GameObject cWalls[NUM_CUSHIONS];

	GolfHole holes[NUM_HOLES];
	vec3 holeStartPos[NUM_HOLES];

	void SetupCourse(void);
	void Update(int ms, int playersID);
	void Update(int ms);
	bool AnyBallsMoving(void);
	

	void SetupCourseTwo();


private:

	bool HoleFinished();
	void NextHole();


};

