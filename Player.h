#ifndef __PLAYER__H__
#define __PLAYER__H__

#include "Character.h"
#include "map.h"

class Player : public Character
{
	//
	//private:
	//
	//	int playerScore;
	//	bool isShoot;

public:

	Player(String F, float X, float Y, float A, float B, float W, float H);
	~Player();

	bool interactionWithMap(Map& map, float time);
	bool control(float time, float& CurrentFrame, Map& map);

};


#endif __PLAYER__H__

