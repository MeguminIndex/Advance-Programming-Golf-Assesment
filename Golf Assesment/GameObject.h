#pragma once
#include "Transform.h"
#include<glut.h>
//An object which will be rendered on screen, inherts transform because it will have a position and generally be able to move

enum DrawMode {Solid,Wireframe};

class GameObject : public Transform
{

private:
	//for Spheres
	DrawMode drawMode = DrawMode::Wireframe;

	bool _isSphere;
	float radius = 0.0f;

	//for other objects
	vec3	vertices[2];
	vec3	centre;
	vec3	normal;

	void MakeNormal(void);
	void MakeCentre(void);

	void DrawSphere();
	void DrawPolygon();

public:

	vec3 colour;//object colour

	GameObject(bool isSphere = false);
	GameObject();
	~GameObject();

	//drawmode get/set
	void SetDrawMode(DrawMode mode) { drawMode = mode; };
	DrawMode GetDrawMode() { return drawMode; };

	//radius gte/set
	void SetRadius(float newRadius) { radius = newRadius; };
	float GetRadius() { return radius; };

	vec3 GetNormal() { return normal; };

	

	void DoPlaneCollision(GameObject &c);
	void DoBallCollision(GameObject &b);
	void UpdateObject(int deltaTime);

	bool HasHitPlane(GameObject &c);
	bool HasHitBall(GameObject &b);

	void HitPlane(GameObject &c);
	void HitBall(GameObject &b);



	void Draw();//draw object at somepoint







};

