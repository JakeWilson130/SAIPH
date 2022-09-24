#pragma once
#include "BaseCommand.h"

class VelocityCommand : public BaseCommand {
	float xVel = 0;
	float yVel = 0;
public:
	float GetxVel()const;
	float GetyVel()const;
	

	void SetxVel(float xVel) ;
	void SetyVel(float yVel) ;
	
	virtual void Execute();

};
