#ifndef __FUCKER__H__
#define __FUCKER__H__

#include "Character.h"
#include "Fucker.h"

class Fucker : public Character
{


public:

	Fucker(String F, float X, float Y, float A, float B, float W, float H);
	~Fucker();

	bool interactionWithMap(Map& map, float time);
	bool control(float time, Map& map);

	int get_direction();
	void set_direction(int dir);
};


#endif //!__FUCKER__H__