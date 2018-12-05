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
	glTranslatef(pos(0), pos(2), pos(1));
	if(drawMode == DrawMode::Solid)
	glutSolidSphere(GetRadius(), 32, 32);
	else
	glutWireSphere(GetRadius(), 12, 12);
	
	glPopMatrix();
	glColor3f(0.0, 0.0, 1.0);

}

void GameObject::DrawPolygon()
{
}



void GameObject::Draw()
{
	if (_isSphere)
		DrawSphere();
	else
		DrawPolygon();
}

void GameObject::DoBallCollision(GameObject &b)
{
	if (HasHitBall(b)) HitBall(b);
}

void GameObject::DoPlaneCollision(GameObject &b)
{
	if (HasHitPlane(b)) HitPlane(b);
}

void GameObject::UpdateObject(int deltaTime)
{
	//pass through deltaTime to transform update function
	Update(deltaTime);
}

bool GameObject::HasHitPlane(GameObject &c) 
{

	vec3 vel = GetVelocity();
	
	//if moving away from plane, cannot hit
	if (vel.Dot(c.GetNormal()) >= 0.0) return false;

	//if in front of plane, then have not hit
	vec3 relPos = GetPosition() - c.vertices[0];
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

void GameObject::HitPlane(GameObject &c)
{
	//reverse velocity component perpendicular to plane  
	double comp = GetVelocity().Dot(c.normal) * (1.0 + GetRestitution());
	vec3 delta = vec3(0,0,0) -(c.normal * comp);
	SetVelocity(GetVelocity() + delta);

	//make some particles
	int n = (rand() % 4) + 3;


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

