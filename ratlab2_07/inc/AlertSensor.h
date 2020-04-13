#ifndef AlertSensor_H
#define AlertSensor_H
#include "Sensor.h"
#include "TemperatureSensor.h"
#include "AccelerationSensor.h"
class AlertSensor : public Sensor
{
	TemperatureSensor& temperatureSensor;
	AccelerationSensor& accelerationSensor;
	int referenceTemperature;
	bool wasAlarm;
public:
	AlertSensor(TemperatureSensor& tempSensor,AccelerationSensor& accSensor );

	bool IsAlarm() const;
	int GetReferenceTemperature() const;
	void SetReferenceTemperature(int newReferenceTemperature);
	virtual void Poll() override;
};
#endif
