#include <cstdio>
#include <cstring>
#include "NiceView.h"
#include "Log.h"
#include "GlcdBackground.h"
#include "Display.h"

NiceView::NiceView(
		TemperatureSensor& temperatureSensor,
		AccelerationSensor& accelerationSensor,
		SwitchSensor& flameSensor,
		AlertSensor& alertSensor,
		View *parent)
: View(parent),
  temperatureView(temperatureSensor, Location(7,1), this),
  accelerationView(accelerationSensor,Location(7,3), this),
  alertView(alertSensor,Location(48,5), this),
  flameView(flameSensor,Location(7,6), this)

{
}

void NiceView::Redraw(Display& display)
{
	SendBackgroundImage(display);
	View::Redraw(display);
}

void NiceView::SendBackgroundImage(Display& display)
{
	int i,j,k=0;
	for (i=0;i<8;i++)
		for(j=0;j<128;j++)
		{
			if (GlcdBackgroundImage[k])	// Only additive drawing
				display.WriteBlock(GlcdBackgroundImage[k],i,j);
			k++;
		}
}

void NiceView::ShowDataStrip(Display& display, int row, const char *title, int stripLength, int value)
{
	// Looks like this: [Title]       [setStrip...][...clearedStrip][value]
	const int titleStartX = 7;
	display.Write(Location(titleStartX,row), title);

	char valueAsString[10];
	snprintf(valueAsString,10,"%d",value);
	const int valueWidth = strlen(valueAsString) * 6;

	// [Value] is aligned to the end of the strip space
	const int stripStartX = 36;
	const int stripSpaceEnd = 118;
	const int stripMaxEndX = stripSpaceEnd - valueWidth;
	Location valueLocation(stripMaxEndX+1, row);
	display.Write(valueLocation, valueAsString);

	// [Value] limits the length of the strip
	int maxStripLength = stripMaxEndX - stripStartX;
	if (stripLength > stripMaxEndX-stripStartX)
		stripLength = stripMaxEndX-stripStartX;
	else if (stripLength < 0)
		stripLength = 0;

	display.RepeatPattern(Location(stripStartX, row), 0xFF, stripLength);
	display.RepeatPattern(Location(stripStartX+stripLength+1, row), 0x00, maxStripLength-stripLength);
}
