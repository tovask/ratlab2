#include "CommandHandler.h"
#include "TemperatureSensor.h"
#include "AlertSensor.h"
class UartCommandHandler : public CommandHandler{
	AlertSensor& alertSensor;
	TemperatureSensor& temperatureSensor;
public:
	UartCommandHandler(AlertSensor& alertSensor,  TemperatureSensor& temperatureSensor);
	void Handle(const char command) override;

};
