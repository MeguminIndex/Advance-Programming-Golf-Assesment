#pragma once
#include "GameObject.h"
#include "GolfBall.h"

class GolfHole : public GameObject
{
//what should this class do

//detect if a golfball is in the hole? (only the server should be able to do this.)


public:
	GolfHole()
	{
		_isSphere = true;
		SetDrawMode(DrawMode::Solid);
		colour = vec3(1,1,0.6);
	};
	~GolfHole()
	{

	};

	void DoBallCollision(GolfBall &b);



};

