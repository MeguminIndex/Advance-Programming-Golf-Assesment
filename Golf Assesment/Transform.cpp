#include "Transform.h"

void Transform::SetPosition(vec3 newPos)
{
	position = newPos;
}

void Transform::SetPosition(float x, float y, float z)
{
	position.elem[0] = x;
	position.elem[1] = y;
	position.elem[2] = z;
}


void Transform::ApplyImpulse(vec3 imp)
{
	velocity = imp;
}

void Transform::ApplyFrictionForce(int deltaTime)
{
	if (velocity.Magnitude() <= 0.0) return;

	//accelaration is opposite to direction of motion
	vec3 accelaration = vec3(0,0,0) -velocity.Normalised();
	//friction force = constant * mg
	//F=Ma, so accelaration = force/mass = constant*g
	accelaration *= (gCoeffFriction * gGravityAccn);
	//integrate velocity : find change in velocity
	vec3 velocityChange = ((accelaration * deltaTime) / 1000.0f);
	//cap magnitude of change in velocity to remove integration errors
	if (velocityChange.Magnitude() > velocity.Magnitude()) velocity = 0.0;
	else velocity += velocityChange;
}

void Transform::Update(int deltaTime)
{
	//apply friction
	ApplyFrictionForce(deltaTime);
	//integrate position
	position += ((velocity * deltaTime) / 1000.0f);
	//set small velocities to zero
	if (velocity.Magnitude() < velThreshold) velocity = 0.0;

	//std::cout << "X: " << position(0) << "Z: " <<  position(1) <<std::endl;

}


void Transform::UpdateNetworked(int deltaTime, vec3 lastPos, vec3 lastVel)
{
	position = lastPos;
	velocity = lastVel;

	//apply friction
	ApplyFrictionForce(deltaTime);
	//integrate position
	position += ((velocity * deltaTime) / 1000.0f);
	//set small velocities to zero
	if (velocity.Magnitude() < velThreshold) velocity = 0.0;

	std::cout << "X: " << position(0) << "Z: " << position(1) << std::endl;

}


void Transform::ApplyGravity()
{
}
