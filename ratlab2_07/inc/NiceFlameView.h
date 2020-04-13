#ifndef NiceFlameView_H
#define NiceFlameView_H
#include "ObservingView.h"
#include "Display.h"
class SwitchSensor;

class NiceFlameView: public ObservingView
{
public:
	NiceFlameView(SwitchSensor & sensor, Location location,
			View *parent);

	virtual void Redraw(Display& display) override;

private:
	SwitchSensor & sensor;
	Location location;
};

#endif // NiceFlameView_H
