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

	void interactionWithMap(Map& map, float time);
	void control(float time, float& CurrentFrame);

};


#endif __PLAYER__H__

