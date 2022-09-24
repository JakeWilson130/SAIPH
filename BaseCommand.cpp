#include "BaseCommand.h"


Ship* BaseCommand::GetShip() const{

	return ship;

}

void BaseCommand::SetShip(Ship* mship) {

	
 ship = mship;


}
float BaseCommand::GetDelay() const{


	return delay;
	 
	 
}
void BaseCommand::SetDelay(float mDelay) {


	delay = mDelay;


}
void Execute() {



}
