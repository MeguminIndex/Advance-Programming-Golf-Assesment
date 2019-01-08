#include "GolfHole.h"

void GolfHole::DoBallCollision(GolfBall& b)
{	
	//if collision returns false exit function early
	if (!HasHitBall(b))
		return;

	//update the bool variable used to identify
	//the completion status of the current hole
	b.finishedCurrentHole = true;

}
