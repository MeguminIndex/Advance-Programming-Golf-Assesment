#include "Course.h"



Course::Course()
{
}

Course::~Course()
{
}

void Course::SetupCourse(void)
{
	int ind = 0;
	

//HOLE ONE
#pragma region Hole ONE

	//left wall
	cWalls[ind].d_Size = vec3(3, 0, 0);

	cWalls[ind].vertices[0](0) = -TABLE_X ;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
	
	ind++;
	//bottom indall
	cWalls[ind].d_Size = vec3(0, 0, 2);
	cWalls[ind].vertices[0](0) = -TABLE_X;
	cWalls[ind].vertices[0](1) = TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	//right wll
	cWalls[ind].d_Size = vec3(3, 0, 0);
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
	
	ind++;
	//top wal
	cWalls[ind].d_Size = vec3(0,0,4);
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
	


	ind++;
	cWalls[ind].d_Size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cWalls[ind].d_Size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cWalls[ind].vertices[0](0) = -TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
	

	

#pragma endregion


#pragma region Hole Two


	ind++;
	cWalls[ind].vertices[0](0) = -TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
	

	ind++;
	//bottom all
	//	cushins[1].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cWalls[ind].vertices[0](0) = -TABLE_X;
	cWalls[ind].vertices[0](1) = TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	//right wll
	//	cushins[2].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
		
	ind++;
	//top wal
	//cushion[3].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cWalls[ind].vertices[0](0) = TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = -TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cWalls[ind].vertices[0](0) = -TABLE_X;
	cWalls[ind].vertices[0](1) = -TABLE_Z;
	cWalls[ind].vertices[0](2) = TABLE_Y;
	cWalls[ind].vertices[1](0) = -TABLE_X;
	cWalls[ind].vertices[1](1) = TABLE_Z;
	cWalls[ind].vertices[1](2) = TABLE_Y;




#pragma endregion



	for (int i = 0; i < NUM_CUSHIONS; i++)
	{
		//cushions[i].MakeCentre();
		//cushions[i].MakeNormal();
		cWalls[i].SetUpMesh();

		cWalls[i].colour = vec3(1,0,1);
		//cushions[i].SetDrawMode(DrawMode::Solid);
	}

	//Hole one positions

	holeStartPos[0] = vec3(5.0, 5.5, 0.0);
	
	cWalls[0].SetScale(vec3(1,3, 1));
	cWalls[0].SetPosition(5, 7.4, TABLE_Y);
	
	cWalls[1].SetPosition(5, 5, TABLE_Y);

	cWalls[2].SetScale(vec3(1,2,1));
	cWalls[2].SetPosition(5, 6.2, TABLE_Y);

	cWalls[3].SetScale(vec3(2, 1, 1));
	cWalls[3].SetPosition(4.4,9.8, TABLE_Y);

	cWalls[4].SetScale(vec3(1.06, 1, 1));
	cWalls[4].SetPosition(3.76, 7.4, TABLE_Y);

	cWalls[5].SetPosition(2.6 , 9.8, TABLE_Y);

	holes[0].SetPosition(4.6, 9.5, 0.0);


	//hole two positions
	holeStartPos[1] = vec3(5.0, 15.5, 0.0);

	cWalls[6].SetScale(vec3(1, 3, 1));
	cWalls[6].SetPosition(5, 17.4, TABLE_Y);

	cWalls[7].SetPosition(5, 15, TABLE_Y);

	cWalls[8].SetScale(vec3(1, 2, 1));
	cWalls[8].SetPosition(5, 16.2, TABLE_Y);

	cWalls[9].SetScale(vec3(2, 1, 1));
	cWalls[9].SetPosition(4.4, 19.8, TABLE_Y);

	cWalls[10].SetScale(vec3(1.06, 1, 1));
	cWalls[10].SetPosition(3.76, 17.4, TABLE_Y);

	cWalls[11].SetPosition(2.6, 19.8, TABLE_Y);

	holes[1].SetPosition(5.1, 19.5, 0.0);




	NextHole();


}



//void Course::Update(int ms, int playersID)
//{
//	//check for collisions for each ball
//	for (int i = 0; i<NUM_BALLS; i++)
//	{
//		for (int j = 0; j<NUM_CUSHIONS; j++)
//		{
//			balls[i].DoPlaneCollision(cushions[j], ms);
//		}
//
//		for (int j = (i + 1); j<NUM_BALLS; j++)
//		{
//			balls[i].DoBallCollision(balls[j]);
//		}
//	}
//
//	//update all balls
//	for (int i = 0; i < NUM_BALLS; i++)
//	{
//		if (balls[i].ballID == playersID)
//		{
//			//this is thee local clients ball
//			balls[i].Update(ms);
//
//		}
//		else
//		{
//			//this will be used when server sends 
//			balls[i].Update(ms);
//
//		}
//
//	}
//
//	//update particles
//	//	parts.update(ms);
//
//	//make some new particles
//	//vec3 pos(0.0,BALL_RADIUS,0.0);
//	//parts.AddParticle(pos);
//}


void Course::Update(int ms)
{
	

	//check for collisions for each ball
	for (int i = 0; i<NUM_BALLS; i++)
	{
		for (int j = 0; j<NUM_CUSHIONS; j++)
		{
			//balls[i].DoPlaneCollision(cushions[j],ms);
		}

		//lets ignore this for now
		/*for (int j = (i + 1); j<NUM_BALLS; j++)
		{
			balls[i].DoBallCollision(balls[j]);
		}*/
	}

	for (auto & x : playerBalls)
	{

		for (int j = 0; j<NUM_CUSHIONS; j++)
		{
			//balls[i].DoPlaneCollision(cushions[j], ms);
			if(x.second.finishedCurrentHole == false)
			x.second.DoPlaneCollision(cWalls[j], ms);

		}


		
		
	}


	//update all balls
	//for (int i = 0; i<NUM_BALLS; i++) balls[i].Update(ms);

	for (auto & x : playerBalls)
	{
		if (x.second.finishedCurrentHole == false)
			x.second.Update(ms);
	}


	for (auto & x : playerBalls)
	{
		if (x.second.finishedCurrentHole == false)
		holes[currentHole].DoBallCollision(x.second);
		
	}


	if (HoleFinished() == true)
	{
		NextHole();
	}


	//update particles
//	parts.update(ms);

	//make some new particles
	//vec3 pos(0.0,BALL_RADIUS,0.0);
	//parts.AddParticle(pos);
}

bool Course::AnyBallsMoving(void)
{
	//return true if any ball has a non-zero velocity
	/*for (int i = 0; i<NUM_BALLS; i++)
	{
		vec3 velocity = balls[i].GetVelocity();

		if (velocity(0) != 0.0) return true;
		if (velocity(1) != 0.0) return true;
		if (velocity(2) != 0.0) return true;
	}
	return false;*/


	for (auto & balls : playerBalls)
	{
		if (balls.second.finishedCurrentHole == false)
		{
			vec3 velocity = balls.second.GetVelocity();

			if (velocity(0) != 0.0) return true;
			if (velocity(1) != 0.0) return true;
			if (velocity(2) != 0.0) return true;
		}
	}
	return false;

}

void Course::SetupCourseTwo()
{
		int ind = 0;


		//HOLE ONE
#pragma region Hole ONE

		//left wall
		cWalls[ind].d_Size = vec3(3, 0, 0);

		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		//bottom indall
		cWalls[ind].d_Size = vec3(0, 0, 2);
		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		//right wll
		cWalls[ind].d_Size = vec3(3, 0, 0);
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		//top wal
		cWalls[ind].d_Size = vec3(0, 0, 4);
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;



		ind++;
		cWalls[ind].d_Size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		cWalls[ind].d_Size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;




#pragma endregion


#pragma region Hole Two


		ind++;
		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;


		ind++;
		//bottom all
		//	cushins[1].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		//right wll
		//	cushins[2].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		//top wal
		//cushion[3].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		cWalls[ind].vertices[0](0) = TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = -TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;

		ind++;
		cWalls[ind].vertices[0](0) = -TABLE_X;
		cWalls[ind].vertices[0](1) = -TABLE_Z;
		cWalls[ind].vertices[0](2) = TABLE_Y;
		cWalls[ind].vertices[1](0) = -TABLE_X;
		cWalls[ind].vertices[1](1) = TABLE_Z;
		cWalls[ind].vertices[1](2) = TABLE_Y;




#pragma endregion



		for (int i = 0; i < NUM_CUSHIONS; i++)
		{
		
			cWalls[i].SetUpMesh();
			cWalls[i].colour = vec3(1, 0, 1);
			//cushions[i].SetDrawMode(DrawMode::Solid);
		}

		//Hole one positions

		holeStartPos[0] = vec3(17.0, 5.5, 0.0);

		cWalls[0].SetScale(vec3(1, 3, 1));
		cWalls[0].SetPosition(17, 7.4, TABLE_Y);

		cWalls[1].SetPosition(17, 5, TABLE_Y);

		cWalls[2].SetScale(vec3(1, 2, 1));
		cWalls[2].SetPosition(17, 6.2, TABLE_Y);

		cWalls[3].SetScale(vec3(4, 1, 1));
		cWalls[3].SetPosition(15.4, 9.8, TABLE_Y);

		cWalls[4].SetScale(vec3(2.75, 1, 1));
		cWalls[4].SetPosition(14.76, 7.4, TABLE_Y);

		cWalls[5].SetPosition(12.6, 9.8, TABLE_Y);

		holes[0].SetPosition(15.6, 9.8, 0.0);


		//hole two positions
		holeStartPos[1] = vec3(4.5, 19, 0.0);

		cWalls[6].SetScale(vec3(1, 3, 1));
		cWalls[6].SetPosition(5, 17.4, TABLE_Y);

		cWalls[7].SetPosition(5, 15, TABLE_Y);

		cWalls[8].SetScale(vec3(1, 2, 1));
		cWalls[8].SetPosition(5, 16.2, TABLE_Y);

		cWalls[9].SetScale(vec3(2, 1, 1));
		cWalls[9].SetPosition(4.4, 19.8, TABLE_Y);

		cWalls[10].SetScale(vec3(1.06, 1, 1));
		cWalls[10].SetPosition(3.76, 17.4, TABLE_Y);

		cWalls[11].SetPosition(2.6, 19.8, TABLE_Y);

		holes[1].SetPosition(5.0, 15.5, 0.0);




		NextHole();



}

bool Course::HoleFinished()
{

	for (auto & x : playerBalls)
	{
		if (x.second.finishedCurrentHole == false)
			return false;
		
	}

	return true;


}

void Course::NextHole()
{

	currentHole += 1;

	if (currentHole >= NUM_HOLES)
	{
		std::cout << "Game Finished" << std::endl;
		courseFinished = true;
		return;
	}


	for (auto & x : playerBalls)
	{
		x.second.lastPos = holeStartPos[currentHole];
		x.second.Reset();
		x.second.finishedCurrentHole = false;
	}





}
