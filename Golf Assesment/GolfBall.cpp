#include "GolfBall.h"

int GolfBall::ballIndexCnt = 0;



void GolfBall::Reset()
{
	//set velocity to zero
	SetVelocity(0.0f);
	SetPosition(lastPos);

}



