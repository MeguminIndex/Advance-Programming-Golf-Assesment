#include "GameObject.h"



void GameObject::MakeNormal(void)
{
	//can do this in 2d
	vec3 temp = vertices[1] - vertices[0];
	normal(0) = temp(1);
	normal(1) = -temp(0);
	normal.Normalise();
}

void GameObject::MakeCentre(void)
{
	centre = vertices[0];
	centre += vertices[1];
	centre /= 2.0;
}




void GameObject::DrawSphere()
{
	vec3 pos = GetPosition();
	
	glPushMatrix();
	glTranslatef(0 - pos(0),0- pos(2),0- pos(1));
	if(drawMode == DrawMode::Solid)
	glutSolidSphere(GetRadius(), 32, 32);
	else
	glutWireSphere(GetRadius(), 12, 12);
	
	glPopMatrix();
	glColor3f(0.0, 0.0, 1.0);

}

void GameObject::DrawRectangle()
{

	vec3 position = GetPosition();

	glBegin(GL_LINE_LOOP);
	glVertex3f(vertices[0](0) - position(0), -vertices[0](2) +0.10f - position(2), vertices[0](1) - position(1));
	glVertex3f(vertices[0](0) - position(0), vertices[0](2) + 0.10f - position(2), vertices[0](1) - position(1));
	glVertex3f(vertices[1](0) - position(0), vertices[1](2) + 0.10f - position(2), vertices[1](1) - position(1));
	glVertex3f(vertices[1](0) - position(0), -vertices[1](2) + 0.10f - position(2), vertices[1](1) - position(1));
	glEnd();



}

void GameObject::DrawPolygon()
{
}


void GameObject::Draw()
{
	glColor3f(colour.elem[0], colour.elem[1], colour.elem[2]);

	if (_isSphere)
		DrawSphere();
	else
		DrawRectangle();
}

void GameObject::DoBallCollision(GameObject &b)
{
	if (HasHitBall(b)) HitBall(b);
}

void GameObject::SetScale(vec3 newscale)
{

	//if ( newscale(0) >! 0 || newscale(1) >! 0 || newscale(2) >! 0 )
	//{
	//	std::cout << "Call to Set and objects scale was attempted and aborted" << std::endl;

	//}

	//before setting new scale divde verticies by current scale
	//then multiply by new scale and set new scale value

	int n = sizeof(vertices) / sizeof(*vertices);

	for (int i = 0; i < n; i++)
	{
		vertices[i](0) /= scale(0);
		vertices[i](1) /= scale(1);
		vertices[i](2) /= scale(2);

		vertices[i](0) *= newscale(0);
		vertices[i](1) *= newscale(1);
		vertices[i](2) *= newscale(2);
	}

	scale = newscale;

}

void GameObject::DoPlaneCollision(GameObject &b, float dT)
{
	if (AABB_CollisionDetection(b)) HitPlane(b,dT);
}

void GameObject::UpdateObject(int deltaTime)
{
	//pass through deltaTime to transform update function
	Update(deltaTime);
}

bool GameObject::HasHitPlane(GameObject &c) 
{
	//vec3 vel = GetVelocity();

	////if moving away from plane, cannot hit
	//if (vel.Dot(c.GetNormal()) >= 0.0) return false;

	////if in front of plane, then have not hit
	//vec3 relPos = GetPosition() - c.vertices[0];
	//double sep = relPos.Dot(c.normal);
	//if (sep > radius) return false;
	//return true;



	vec3 vel = GetVelocity();
	
	//if moving away from plane, cannot hit
	if (vel.Dot(c.GetNormal()) >= 0.0) return false;

	//if in front of plane, then have not hit


	vec3 relPos = (vec3(0, 0, 0) - GetPosition()) - (c.vertices[0] - c.GetPosition());
	double sep = relPos.Dot(c.normal);
	if (sep > radius) return false;



	return true;




}

bool GameObject::HasHitBall(GameObject &b) 
{
	//work out relative position of ball from other ball,
	//distance between balls
	//and relative velocity
	vec3 relPosn = GetPosition() - b.GetPosition();
	float dist = (float)relPosn.Magnitude();
	vec3 relPosnNorm = relPosn.Normalised();
	vec3 relVelocity = GetVelocity() - b.GetVelocity();

	//if moving apart, cannot have hit
	if (relVelocity.Dot(relPosnNorm) >= 0.0) return false;
	//if distnce is more than sum of radii, have not hit
	if (dist > (radius + b.radius)) return false;
	return true;
}

void GameObject::HitPlane(GameObject &c, float dT)
{
	//reverse velocity component perpendicular to plane 

	vec3 oldVel = GetVelocity();

	double comp = GetVelocity().Dot(c.normal) * (1.0 + GetRestitution());
	vec3 delta = vec3(0,0,0) -(c.normal * comp);
	SetVelocity(GetVelocity() + delta);

	//make some particles
	int n = (rand() % 4) + 3;



	vec3 position = GetPosition() +  ((vec3(0,0,0) - oldVel * dT) / 1000.0f); //hacky and will be buggy at lower frame rates

	SetPosition(position);

	//vec3 pos = GetPosition();
	//vec3 oset(c.normal(0), 0.0, c.normal(1));
	//pos += (oset*radius);
	//for (int i = 0;i < n;i++)
	//{
	//	gTable.parts.AddParticle(pos);
	//}

	/*
		//assume elastic collision
		//find plane normal
		vec2 planeNorm = gPlaneNormal_Left;
		//split velocity into 2 components:
		//find velocity component perpendicular to plane
		vec2 perp = planeNorm*(velocity.Dot(planeNorm));
		//find velocity component parallel to plane
		vec2 parallel = velocity - perp;
		//reverse perpendicular component
		//parallel component is unchanged
		velocity = parallel + (-perp)*gCoeffRestitution;
	*/
}

void GameObject::HitBall(GameObject &b)
{
	//find direction from other ball to this ball
	vec3 relDir = (GetPosition() - b.GetPosition()).Normalised();

	//split velocities into 2 parts:  one component perpendicular, and one parallel to 
	//the collision plane, for both balls
	//(NB the collision plane is defined by the point of contact and the contact normal)
	float perpV = (float)GetVelocity().Dot(relDir);
	float perpV2 = (float)b.GetVelocity().Dot(relDir);
	vec3 parallelV = GetVelocity() - (relDir*perpV);
	vec3 parallelV2 = b.GetVelocity() - (relDir*perpV2);

	//Calculate new perpendicluar components:
	//v1 = (2*m2 / m1+m2)*u2 + ((m1 - m2)/(m1+m2))*u1;
	//v2 = (2*m1 / m1+m2)*u1 + ((m2 - m1)/(m1+m2))*u2;

	float thisMass = GetMass(), otherMass = b.GetMass();

	float sumMass = thisMass + otherMass;
	float perpVNew = (float)((perpV*(thisMass - otherMass)) / sumMass) + (float)((perpV2*(2.0*otherMass)) / sumMass);
	float perpVNew2 = (float)((perpV2*(otherMass - thisMass)) / sumMass) + (float)((perpV*(2.0*thisMass)) / sumMass);

	//find new velocities by adding unchanged parallel component to new perpendicluar component
	SetVelocity(parallelV + (relDir*perpVNew));
	b.SetVelocity(parallelV2 + (relDir*perpVNew2));


	//make some particles
	/*int n = (rand() % 5) + 5;
	vec3 pos(position(0), radius / 2.0, position(1));
	vec3 oset(relDir(0), 0.0, relDir(1));
	pos += (oset*radius);
	for (int i = 0;i < n;i++)
	{
		gTable.parts.AddParticle(pos);
	}*/
}

bool GameObject::AABB_CollisionDetection(GameObject other)
{
	
	
	vec3 size = other.vertices[0] - other.vertices[1];
	size = size.Abs();


	vec3 thisPos = vec3(0, 0, 0) - GetPosition(), thisScale = GetScale();
	vec3 otherPos = other.vertices[0] - other.GetPosition(), otherScale = other.GetScale();



	float thisRight, thisBottom;
	float bottomOther, rightOther;

	thisRight = thisPos(0) + radius;

	thisBottom = thisPos(1) + radius;

	rightOther = otherPos(0) + size(0);

	bottomOther = otherPos(1) + size(1);


	//if state ments return false when this sprite is otside the rect of the sprite being checked against
	if (thisBottom <= otherPos(1) - size(1))
	{
		return false;//if bottom of this is above the top of the other sprite
	}


	if (thisPos(1) - radius >= bottomOther)
	{
		return false;// if top of this is below the bottom of the other sprite
	}

	if (thisRight <= otherPos(0) - size(0))
	{
		return false;//if the right side of this is left of the other sprites left side
	}


	if (thisPos(0) - radius >= rightOther)
	{
		return false;//if this sprite is right of the righ side othe the other sprite
	}


	//gets here if all of the statements are false

	return true;// returns true signifying collision has happened








}

