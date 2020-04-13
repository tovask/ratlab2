#include "DebugAlertView.h"
#include "AlertSensor.h"
#include "Log.h"

DebugAlertView::DebugAlertView(AlertSensor& sensor, Location location,
		View *parent)
: ObservingView(sensor, parent), sensor(sensor), location(location)
{
}

void DebugAlertView::Redraw(Display& display)
{
	if(sensor.IsAlarm())
		display.Write(location, "IsAlert: YES");
		else
			display.Write(location, "IsAlert: NO");
	display.WriteTextAndNumber(Location(location.x+5, location.y+1), "Reference:", sensor.GetReferenceTemperature(), 4);
}


