#ifndef DebugAlertView_H
#define DebugAlertView_H
#include "ObservingView.h"
#include "Display.h"
class AlertSensor;

class DebugAlertView: public ObservingView
{
	// View-bol orokol Display referenciat, igy tudja ertesiteni!
	// Observer a TemperatureSensor szamara
public:
	DebugAlertView(AlertSensor& sensor, Location location, View *parent);

	virtual void Redraw(Display& display) override;

private:
	AlertSensor& sensor;
	Location location;
};

#endif // DebugAlertView_H
