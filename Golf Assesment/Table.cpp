#include "Table.h"



Table::Table()
{
}

Table::~Table()
{
}

void Table::SetupCushions(void)
{

	//left wall

//	cushions[0].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);

	cushions[0].vertices[0](0) = -TABLE_X ;
	cushions[0].vertices[0](1) = -TABLE_Z;
	cushions[0].vertices[0](2) = TABLE_Y;
	cushions[0].vertices[1](0) = -TABLE_X;
	cushions[0].vertices[1](1) = TABLE_Z;
	cushions[0].vertices[1](2) = TABLE_Y;

	//bottom wall
//	cushions[1].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[1].vertices[0](0) = -TABLE_X;
	cushions[1].vertices[0](1) = TABLE_Z;
	cushions[1].vertices[0](2) = TABLE_Y;
	cushions[1].vertices[1](0) = TABLE_X;
	cushions[1].vertices[1](1) = TABLE_Z;
	cushions[1].vertices[1](2) = TABLE_Y;


	//right wall
//	cushions[2].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[2].vertices[0](0) = TABLE_X;
	cushions[2].vertices[0](1) = TABLE_Z;
	cushions[2].vertices[0](2) = TABLE_Y;
	cushions[2].vertices[1](0) = TABLE_X;
	cushions[2].vertices[1](1) = -TABLE_Z;
	cushions[2].vertices[1](2) = TABLE_Y;

	//top wall
	//cushions[3].size = vec3(TABLE_X, TABLE_Z, TABLE_Y);
	cushions[3].vertices[0](0) = TABLE_X;
	cushions[3].vertices[0](1) = -TABLE_Z;
	cushions[3].vertices[0](2) = TABLE_Y;
	cushions[3].vertices[1](0) = -TABLE_X;
	cushions[3].vertices[1](1) = -TABLE_Z;
	cushions[3].vertices[1](2) = TABLE_Y;


	cushions[4].vertices[0](0) = TABLE_X;
	cushions[4].vertices[0](1) = -TABLE_Z;
	cushions[4].vertices[0](2) = TABLE_Y;
	cushions[4].vertices[1](0) = -TABLE_X;
	cushions[4].vertices[1](1) = -TABLE_Z;
	cushions[4].vertices[1](2) = TABLE_Y;


	cushions[5].vertices[0](0) = -TABLE_X;
	cushions[5].vertices[0](1) = -TABLE_Z;
	cushions[5].vertices[0](2) = TABLE_Y;
	cushions[5].vertices[1](0) = -TABLE_X;
	cushions[5].vertices[1](1) = TABLE_Z;
	cushions[5].vertices[1](2) = TABLE_Y;


	for (int i = 0; i < NUM_CUSHIONS; i++)
	{
		//cushions[i].MakeCentre();
		//cushions[i].MakeNormal();
		cushions[i].SetUpMesh();
	}

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

}




void Table::Update(int ms)
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

bool Table::AnyBallsMoving(void)
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

void Table::SetupSceneOne()
{
}
