#include "NiceAlertView.h"
#include "AlertSensor.h"
#include "Log.h"

NiceAlertView::NiceAlertView(AlertSensor& sensor, Location location,
		View *parent) :
		ObservingView(sensor, parent), sensor(sensor), location(location) {
}

void NiceAlertView::Redraw(Display& display) {
	if (sensor.IsAlarm())
		display.Write(location, "A L A R M");
	else
		display.Write(location, "         ");

}

