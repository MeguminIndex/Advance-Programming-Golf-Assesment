#include "Course.h"



Course::Course()
{
}

Course::~Course()
{
}

void Course::SetupCushions(void)
{
	int ind = 0;

//HOLE ONE
#pragma region Hole ONE

	//left wall
//	cushions[0].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);

	cushions[ind].vertices[0](0) = -TABLE_X ;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
	
	ind++;
	//bottom indall
//	cushions[ind].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = -TABLE_X;
	cushions[ind].vertices[0](1) = TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	//right wll
//	cushions[].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
	
	ind++;
	//top wal
	//cushion[3].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cushions[ind].vertices[0](0) = -TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
	

	

#pragma endregion


#pragma region Hole Two


	ind++;
	cushions[ind].vertices[0](0) = -TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
	

	ind++;
	//bottom all
	//	cushins[1].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = -TABLE_X;
	cushions[ind].vertices[0](1) = TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	//right wll
	//	cushins[2].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
		
	ind++;
	//top wal
	//cushion[3].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cushions[ind].vertices[0](0) = TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = -TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;
			 
	ind++;
	cushions[ind].vertices[0](0) = -TABLE_X;
	cushions[ind].vertices[0](1) = -TABLE_Z;
	cushions[ind].vertices[0](2) = TABLE_Y;
	cushions[ind].vertices[1](0) = -TABLE_X;
	cushions[ind].vertices[1](1) = TABLE_Z;
	cushions[ind].vertices[1](2) = TABLE_Y;




#pragma endregion






	for (int i = 0; i < NUM_CUSHIONS; i++)
	{
		//cushions[i].MakeCentre();
		//cushions[i].MakeNormal();
		cushions[i].SetUpMesh();

		cushions[i].colour = vec3(1,0,1);
		//cushions[i].SetDrawMode(DrawMode::Solid);
	}

	//Hole one positions
	cushions[0].SetScale(vec3(1,3, 1));
	cushions[0].SetPosition(5, 7.4, TABLE_Y);

	cushions[1].SetPosition(5, 5, TABLE_Y);

	cushions[2].SetScale(vec3(1,2,1));
	cushions[2].SetPosition(5, 6.2, TABLE_Y);

	cushions[3].SetScale(vec3(2, 1, 1));
	cushions[3].SetPosition(4.4,9.8, TABLE_Y);

	cushions[4].SetScale(vec3(1.06, 1, 1));
	cushions[4].SetPosition(3.76, 7.4, TABLE_Y);

	cushions[5].SetPosition(2.6 , 9.8, TABLE_Y);

	holes[0].SetPosition(3.6, 9.5, 0.0);


	//hole two positions
	cushions[6].SetScale(vec3(1, 3, 1));
	cushions[6].SetPosition(5, 17.4, TABLE_Y);

	cushions[7].SetPosition(5, 15, TABLE_Y);

	cushions[8].SetScale(vec3(1, 2, 1));
	cushions[8].SetPosition(5, 16.2, TABLE_Y);

	cushions[9].SetScale(vec3(2, 1, 1));
	cushions[9].SetPosition(4.4, 19.8, TABLE_Y);

	cushions[10].SetScale(vec3(1.06, 1, 1));
	cushions[10].SetPosition(3.76, 17.4, TABLE_Y);

	cushions[11].SetPosition(2.6, 19.8, TABLE_Y);

	holes[1].SetPosition(3.6, 19.5, 0.0);
}



void Course::Update(int ms, int playersID)
{
	//check for collisions for each ball
	for (int i = 0; i<NUM_BALLS; i++)
	{
		for (int j = 0; j<NUM_CUSHIONS; j++)
		{
			balls[i].DoPlaneCollision(cushions[j], ms);
		}

		for (int j = (i + 1); j<NUM_BALLS; j++)
		{
			balls[i].DoBallCollision(balls[j]);
		}
	}

	//update all balls
	for (int i = 0; i < NUM_BALLS; i++)
	{
		if (balls[i].ballID == playersID)
		{
			//this is thee local clients ball
			balls[i].Update(ms);

		}
		else
		{
			//this will be used when server sends 
			balls[i].Update(ms);

		}

	}

	//update particles
	//	parts.update(ms);

	//make some new particles
	//vec3 pos(0.0,BALL_RADIUS,0.0);
	//parts.AddParticle(pos);
}


void Course::Update(int ms)
{
	//check for collisions for each ball
	for (int i = 0; i<NUM_BALLS; i++)
	{
		for (int j = 0; j<NUM_CUSHIONS; j++)
		{
			balls[i].DoPlaneCollision(cushions[j],ms);
		}

		for (int j = (i + 1); j<NUM_BALLS; j++)
		{
			balls[i].DoBallCollision(balls[j]);
		}
	}

	//update all balls
	for (int i = 0; i<NUM_BALLS; i++) balls[i].Update(ms);

	//update particles
//	parts.update(ms);

	//make some new particles
	//vec3 pos(0.0,BALL_RADIUS,0.0);
	//parts.AddParticle(pos);
}

bool Course::AnyBallsMoving(void)
{
	//return true if any ball has a non-zero velocity
	for (int i = 0; i<NUM_BALLS; i++)
	{
		vec3 velocity = balls[i].GetVelocity();

		if (velocity(0) != 0.0) return true;
		if (velocity(1) != 0.0) return true;
		if (velocity(2) != 0.0) return true;
	}
	return false;
}

void Course::SetupSceneOne()
{
}
