#include "NiceAccelerationView.h"
#include "AccelerationSensor.h"
#include "Log.h"
#include "NiceView.h"

NiceAccelerationView::NiceAccelerationView(AccelerationSensor& sensor, Location location,
		View *parent)
: ObservingView(sensor, parent), sensor(sensor), location(location)
{
}

void NiceAccelerationView::Redraw(Display& display)
{
	int currentAcceleration = sensor.GetMaxTilt();
	int stripLength = currentAcceleration*2;
	NiceView::ShowDataStrip(display, location.y, "Tilt", stripLength, currentAcceleration);
}

