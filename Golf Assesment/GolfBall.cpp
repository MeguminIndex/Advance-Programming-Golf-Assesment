#include "GolfBall.h"

int GolfBall::ballIndexCnt = 0;



void GolfBall::Reset()
{
	//set velocity to zero
	SetVelocity(0.0f);

	//work out rack position
	if (index == 0)
	{

		SetPosition(0.0, 0.5, 0.0);

		//position(1) = 0.5;
		//position(0) = 0.0;
		return;
	}

	float radi = GetRadius();

	static const float sep = (radi *3.0f);
	static const float rowSep = (radi * 2.5f);
	int row = 1;
	int rowIndex = index;
	while (rowIndex > row)
	{
		rowIndex -= row;
		row++;
	}

	SetPosition((((row - 1)*sep) / 2.0f) - (sep*(row - rowIndex)), -(rowSep * (row - 1)));

	//position(1) = -(rowSep * (row - 1));
	//position(0) = (((row - 1)*sep) / 2.0f) - (sep*(row - rowIndex));
}



