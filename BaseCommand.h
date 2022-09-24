#pragma once
#include "Ship.h"


 class BaseCommand {
 public:
	 Ship* ship = NULL;
	float delay = 0;
	 

	Ship* GetShip() const;
	float GetDelay() const;


	void SetShip(Ship* ship);
	void SetDelay(float delay);
	virtual void Execute() = 0;






};
