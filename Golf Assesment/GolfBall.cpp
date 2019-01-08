#include "GolfBall.h"


void GolfBall::Reset()
{
	//set velocity to zero
	SetVelocity(0.0f);
	SetPosition(lastPos);

}



