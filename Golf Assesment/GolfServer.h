#pragma once
#include "stdafx.h"
#include "GolfBall.h"


#include <windows.h>
#include <winsock2.h>

class GolfServer
{
public:
	GolfServer();
	~GolfServer();

	
	std::map<int, SOCKET> playerID;









};

