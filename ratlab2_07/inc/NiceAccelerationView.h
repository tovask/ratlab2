#ifndef NiceAccelerationView_H
#define NiceAccelerationView_H
#include "ObservingView.h"
#include "Display.h"
class AccelerationSensor;

class NiceAccelerationView: public ObservingView
{
public:
	NiceAccelerationView(AccelerationSensor& sensor, Location location,
			View *parent);

	virtual void Redraw(Display& display) override;

private:
	AccelerationSensor& sensor;
	Location location;
};

#endif // NiceAccelerationView_H
