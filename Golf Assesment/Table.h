#pragma once

#include "GolfBall.h"


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
#define NUM_CUSHIONS	(3)		
#define MAX_PARTICLES	(200)


class Table
{
public:
	Table();
	~Table();

	

	//ball balls[NUM_BALLS];
	GolfBall balls[NUM_BALLS];
	//cushion cushions[NUM_CUSHIONS];
	GameObject cushions[NUM_CUSHIONS];

//	particleSet parts;

	void SetupCushions(void);
	void Update(int ms);
	bool AnyBallsMoving(void);
	

};

