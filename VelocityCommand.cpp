#include "VelocityCommand.h"
#include "BaseCommand.h"

float VelocityCommand::GetxVel() const{


	return xVel;


}
float VelocityCommand::GetyVel() const{


	return yVel;


}
void VelocityCommand::SetxVel(float mxVel) {


	xVel=mxVel;


}
void VelocityCommand::SetyVel(float myVel)  {


	yVel = myVel;


}
void VelocityCommand::Execute() {

	BaseCommand::GetShip()->SetVelocity(GetxVel(), GetyVel());

}