#ifndef NICEVIEW_H
#define NICEVIEW_H
#include "View.h"
#include "NiceTemperatureView.h"
#include "NiceAccelerationView.h"
#include "NiceAlertView.h"
#include "NiceFlameView.h"
class SwitchSensor;

class NiceView : public View
{
public:
	NiceView(
			TemperatureSensor& temperatureSensor,
			AccelerationSensor& accelerationSensor,
			SwitchSensor& flameSensor,
			AlertSensor& alertSensor,
			View *parent);

	virtual void Redraw(Display& display) override;

	static void ShowDataStrip(Display& display, int row, const char *title, int stripLength, int value);

private:
	NiceTemperatureView temperatureView;
	NiceAccelerationView accelerationView;
	NiceFlameView flameView;
	NiceAlertView alertView;
	void SendBackgroundImage(Display& display);
};

#endif // NICEVIEW_H
