#include "MotherShip.h"
#include "BaseCommand.h"
#include "VelocityCommand.h"
#include "HeadingCommand.h"
#include "../View/ViewManager.h"


MotherShip::MotherShip(const Ship& _copy) : Ship(_copy) {

}

MotherShip::~MotherShip() {

	for (size_t i = 0; i < sVec.size(); i++)
	{
		ViewManager::GetInstance().RemoveObject(sVec[i]);
		delete sVec[i];
	}
	sVec.clear();
	CleanUp();
	
}
void MotherShip::AddShadow(Ship* shadow) {


	sVec.push_back(shadow);


	

}
void MotherShip::Heartbeat(float _delta){

	Ship::Heartbeat(_delta);

	if (GetAfterburnerFlag() == true)
	{
		Process(_delta);
	/*	VelocityCommand* MSVelo;
		HeadingCommand* MSHead;*/
		//created delay
		float delay = .05;

		for (size_t i = 0; i < sVec.size(); i++)
		{
			

			sVec[i]->Heartbeat(_delta);

			VelocityCommand* vCom = new VelocityCommand();
		
			vCom->SetxVel(MotherShip::GetXVelocity());
			vCom->SetyVel(MotherShip::GetYVelocity());
			vCom->SetDelay(delay);
			vCom->SetShip(sVec[i]);
			HeadingCommand* hCom = new HeadingCommand();
			
			hCom->SetHeading(MotherShip::GetHeading());
			hCom->SetDelay(delay);
			hCom->SetShip(sVec[i]);
			vecBC.push_back(vCom);
			vecBC.push_back(hCom);

			delay += .05;

			
		}
		Process(_delta);
		
	}
	else
	{
		CleanUp();
	}

}
void MotherShip::Process(float _time) {
	
	
		for (int i = vecBC.size() - 1; i >= 0; i--)
	{
		if (vecBC[i]->GetDelay() <= 0)
		{
			
			vecBC[i]->Execute();
			delete vecBC[i];
			vecBC.erase(vecBC.begin() += i);
			
		}
		else
		{
			vecBC[i]->SetDelay(vecBC[i]->GetDelay() - _time);

		}
	}


}
void MotherShip::CleanUp(){

	for (size_t i = 0; i < vecBC.size(); i++)
	{
		
		delete vecBC[i];
		
	}
	vecBC.clear();

	for (size_t i = 0; i < sVec.size(); i++)
	{
		sVec[i]->SetVelocity(0,0);
		sVec[i]->SetHeading(MotherShip::GetHeading());
		sVec[i]->SetPosition(MotherShip::GetPosition());
	}
}