#ifndef __FUCKER__H__
#define __FUCKER__H__

#include "Character.h"

class Fucker : public Character
{

public:

	Fucker(String F, float X, float Y, float A, float B, float W, float H);
	~Fucker();

	bool interactionWithMap(Map& map, float time);
	bool control(float time, int dir, Map& map);



};


#endif //!__FUCKER__H__