#pragma once
#include"vecmath.h"

//this will be inherited by all objects which have a position in the world
class Transform
{
private:
	vec3 position;
	vec3 velocity;

	float mass = 0.1f;
	float velThreshold = 0.01;

	float gCoeffRestitution = 0.5f;//restitution (bouncyness)
	float gCoeffFriction = 0.03f;//friction
	float gGravityAccn = 9.8f; //gravity

public:
	Transform();
	~Transform();

	void SetPosition(vec3 newPos);
	void SetPosition(float x = 0, float y = 0, float z = 0);
	vec3 GetPosition() { return position; };

	void SetVelocity(vec3 newVelocity) { velocity = newVelocity; };
	vec3 GetVelocity() { return velocity; };

	void SetRestitution(float restitution) { gCoeffRestitution = restitution; };
	float GetRestitution() { return gCoeffRestitution; };

	void SetGravity(float gravity) { gGravityAccn = gravity; };
	float GetGravity() { return gGravityAccn; };

	void SetFriction(float friction) { gCoeffFriction = friction; };
	float GetFriction() { return gCoeffFriction; };

	void SetMass(float newMass) { mass = newMass; };
	float GetMass() { return mass; };


	//applying movement
	void ApplyImpulse(vec3 imp);
	void ApplyFrictionForce(int deltaTime);

	void Update(int deltaTime);

	

	


};

