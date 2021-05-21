#ifndef __PLAYER__H__
#define __PLAYER__H__

#include "Character.h"
#include "map.h"



class Player : public Character
{
private:

	int score;


public:

	Player(String F, float X, float Y, float A, float B, float W, float H);
	~Player();

	bool interactionWithMap(Map& map, float time);
	bool control(float time, Map& map, float& CurrentFrame);
	int getScore();
	void setSpeed(float Speed);

};


#endif //!__PLAYER__H__

