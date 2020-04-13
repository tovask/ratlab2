#include "DebugView.h"
#include "Display.h"
#include "Log.h"

DebugView::DebugView(
		TemperatureSensor& temperatureSensor,
		AccelerationSensor& accelerationSensor,
		UartCommandSensor& uartCommandSensor,
		AlertSensor& alertSensor,
		View *parent)
: View(parent), temperatureView(temperatureSensor, Location(0,0), this),
  accelerationView(accelerationSensor, Location(0,1), this),
  alertView(alertSensor, Location(0,2), this),
  uartCommandView(uartCommandSensor, Location(0,4), this)
{
}
