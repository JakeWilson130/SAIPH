#pragma once
#include "Ship.h"
#include <vector>
#include "BaseCommand.h"




class MotherShip :public Ship{
	void Process(float _time);
	void CleanUp();
	std::vector<Ship*> MotherShip::sVec;
	
	std::vector<BaseCommand*> MotherShip::vecBC;
public:
	

	MotherShip(const Ship& motherShip);

	void AddShadow(Ship* shadow);

	void Heartbeat(float _delta);
	~MotherShip();
	

};