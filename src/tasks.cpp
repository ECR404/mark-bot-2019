#include "main.h"
#include "tasks.h"

void handleLift(void* master)
{
    okapi::Motor liftMotorLeft(-1);
    okapi::Motor liftMotorRight(7);
    okapi::MotorGroup liftGroup({liftMotorLeft, liftMotorRight});

    pros::ADIDigitalIn stopButton(8);

    while(true)
    {
        if(ControllerButton(ControllerDigital::up).isPressed())
			liftGroup.moveVoltage(12000);
		else if(ControllerButton(ControllerDigital::down).isPressed())
			liftGroup.moveVoltage(-12000);
		else if(stopButton.get_value() == 1 && !(okapi::Controller*)master.getDigital(ControllerDigital::up))
			liftGroup.moveVoltage(-12000);
		else
			liftGroup.moveVelocity(0);
    }
}