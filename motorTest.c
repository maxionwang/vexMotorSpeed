#pragma config(Sensor,	dgtl1,	quadEncoder,	sensorQuadEncoder)
#pragma config(Sensor,	dgtl3,	redLED,		sensorLEDtoVCC)
#pragma config(Sensor,	dgtl4,	grnLED,		sensorLEDtoVCC)
#pragma config(Motor,	port1,	motor1,		tmotorVex393_HBridge, openLoop)
int rps = 1400;
int testTime = 2;

task main() {
	turnLEDOff(redLED);
	turnLEDOff(grnLED);

  SensorValue[quadEncoder] = 0;
	motor[motor1] = 127;
	wait(testTime);
	motor[motor1] = 0;

	if(SensorValue[quadEncoder]<rps*testTime){
		turnLEDOn(redLED);
	}
	else {
		turnLEDOn(grnLED);
	}

}
