#ifndef __FUCKER__H__
#define __FUCKER__H__

#include "Character.h"

class Fucker : public Character
{

public:

	Fucker(String F, float X, float Y, float A, float B, float W, float H);
	~Fucker();

	void interactionWithMap(Map& map, float time);
	void control(float time, int dir);



};


#endif //!__FUCKER__H__