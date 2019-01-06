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

	

	//ball balls[NUM_BALLS];]
	std::map<int, GolfBall> playerBalls;

	GolfBall balls[NUM_BALLS];
	//cushion cushions[NUM_CUSHIONS];
	GameObject cushions[NUM_CUSHIONS];

	GolfHole holes[NUM_HOLES];

//	particleSet parts;

	void SetupCushions(void);
	void Update(int ms, int playersID);
	void Update(int ms);
	bool AnyBallsMoving(void);
	
	void SetupSceneOne();

};

