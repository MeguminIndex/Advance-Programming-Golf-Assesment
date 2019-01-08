#pragma once
#include "GameObject.h"
class GolfBall : public GameObject
{
	static int ballIndexCnt;

public:

	int ballID;
	bool finishedCurrentHole;
	vec3 lastPos;

	int index;
	void Reset();

	GolfBall(){
		index = ballIndexCnt++; Reset();
		_isSphere = true;
		finishedCurrentHole = false;

		SetDrawMode(DrawMode::Solid);//sets the golfballs draw mode
	}

};

