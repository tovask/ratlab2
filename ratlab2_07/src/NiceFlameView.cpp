#include "NiceFlameView.h"
#include "SwitchSensor.h"
#include "Log.h"
#include "NiceView.h"

NiceFlameView::NiceFlameView(SwitchSensor& sensor, Location location,
		View *parent)
: ObservingView(sensor, parent), sensor(sensor), location(location)
{
}

void NiceFlameView::Redraw(Display& display)
{
	if(sensor.IsOn())
		display.WriteChar(location, ' ');
	else
		display.WriteChar(location, 130);

}

