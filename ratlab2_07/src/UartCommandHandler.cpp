#include "UartCommandHandler.h"
	UartCommandHandler::UartCommandHandler(AlertSensor& aSensor,  TemperatureSensor& tSensor):
	alertSensor(aSensor),
	temperatureSensor(tSensor){

	}
	void UartCommandHandler::Handle(const char command){
if(command == 't'){
	int temp = temperatureSensor.GetLastTemperature();
	alertSensor.SetReferenceTemperature(temp);
}
	}
