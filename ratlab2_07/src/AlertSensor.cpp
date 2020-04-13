#include "AlertSensor.h"
#include "Log.h"
#include "ConfigManager.h"

AlertSensor::AlertSensor(TemperatureSensor& tempSensor,
		AccelerationSensor& accSensor) :
		accelerationSensor(accSensor), temperatureSensor(tempSensor) {
	referenceTemperature = tempSensor.GetLastTemperature();
	wasAlarm = false;
}
bool AlertSensor::IsAlarm() const {
	int temp = temperatureSensor.GetLastTemperature();
	int acc = accelerationSensor.GetMaxTilt();
	if (temp > referenceTemperature + ConfigManager::TemperatureAlarmThreshold
			|| acc > ConfigManager::MaxTiltAlarmThreshold) {
		return true;
	}
	return false;
}
int AlertSensor::GetReferenceTemperature() const {
	return referenceTemperature;
}
void AlertSensor::SetReferenceTemperature(int newReferenceTemperature) {
	referenceTemperature = newReferenceTemperature;
}
void AlertSensor::Poll() {
	if (referenceTemperature == TemperatureSensor::InvalidTemperature)
		referenceTemperature = temperatureSensor.GetLastTemperature();
	if (IsAlarm()) {
		if (!wasAlarm){
			notifyObservers();
			LOG << "Alert:1\n\r";
		}
		wasAlarm = true;
	} else {
		if (wasAlarm)
			LOG << "#Alert:0\n\r";
		wasAlarm = false;
	}
}
