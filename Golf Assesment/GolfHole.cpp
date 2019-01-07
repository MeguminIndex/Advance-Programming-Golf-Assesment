#include "GolfHole.h"

void GolfHole::DoBallCollision(GolfBall& b)
{	
	if (!HasHitBall(b))
		return;


	b.finishedCurrentHole = true;

}
