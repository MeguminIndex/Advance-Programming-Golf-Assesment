#pragma once
#include "GameObject.h"
class GolfBall : public GameObject
{
	static int ballIndexCnt;

public:



	int index;
	void Reset();

	GolfBall(){
		index = ballIndexCnt++; Reset();
		_isSphere = true;

		SetDrawMode(DrawMode::Solid);//sets the golfballs draw mode
	}

};

