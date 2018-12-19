#pragma once

#include"stdafx.h"

#include "Transform.h"
#include<glut.h>

//An object which will be rendered on screen, inherts transform because it will have a position and generally be able to move

enum DrawMode {Solid,Wireframe};

class GameObject : public Transform
{

private:
	//for Spheres
	DrawMode drawMode;

	vec3 scale;

	float radius = 0.05f;

	//for other objects
	
	vec3	centre;
	vec3	normal;

	void MakeNormal(void);
	void MakeCentre(void);



	void DrawSphere();
	void DrawRectangle();
	void DrawPolygon();

public:

	GameObject() {
		colour = vec3(1.0f, 1.0f, 1.0f);
		_isSphere = false;
		scale = vec3(1, 1, 1);
	//	size = vec3(radius/2);
		drawMode = DrawMode::Wireframe;
	}

	vec3	vertices[2];
	vec3 colour;//object colour
	
	//vec3 size;

	bool _isSphere = false;

	//drawmode get/set
	void SetDrawMode(DrawMode mode) { drawMode = mode; };
	DrawMode GetDrawMode() { return drawMode; };

	//radius gte/set
	void SetRadius(float newRadius) { radius = newRadius; };
	float GetRadius() { return radius; };
	
	void SetScale(vec3 newscale);
	vec3 GetScale() { return scale; };

	vec3 GetNormal() { return normal; };

	void SetUpMesh() { MakeNormal(); MakeCentre(); };



	void DoPlaneCollision(GameObject &c);
	void DoBallCollision(GameObject &b);
	void UpdateObject(int deltaTime);

	bool HasHitPlane(GameObject &c);
	bool HasHitBall(GameObject &b);

	void HitPlane(GameObject &c);
	void HitBall(GameObject &b);

	bool AABB_CollisionDetection(GameObject other);

	void Draw();//draw object at somepoint







};

