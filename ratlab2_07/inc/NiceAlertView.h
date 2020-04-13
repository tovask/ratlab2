#ifndef NiceAlertView_H
#define NiceAlertView_H
#include "ObservingView.h"
#include "Display.h"
class AlertSensor;

class NiceAlertView: public ObservingView
{
	// View-bol orokol Display referenciat, igy tudja ertesiteni!
	// Observer a TemperatureSensor szamara
public:
	NiceAlertView(AlertSensor& sensor, Location location, View *parent);

	virtual void Redraw(Display& display) override;

private:
	AlertSensor& sensor;
	Location location;
};

#endif // NiceAlertView_H
