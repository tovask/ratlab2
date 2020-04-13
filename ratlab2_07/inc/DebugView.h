#ifndef DEBUGVIEW_H
#define DEBUGVIEW_H
#include "View.h"
#include "DebugTemperatureView.h"
#include "DebugAccelerationView.h"
#include "DebugUartCommandView.h"
#include "DebugAlertView.h"

class DebugView : public View
{
public:
	DebugView(
			TemperatureSensor& temperatureSensor,
			AccelerationSensor& accelerationSensor,
			UartCommandSensor& uartCommandSensor,
			AlertSensor& alertSensor,
			View *parent);

private:
	DebugTemperatureView temperatureView;
	DebugAccelerationView accelerationView;
	DebugUartCommandView uartCommandView;
	DebugAlertView alertView;
};

#endif // DEBUGVIEW_H
