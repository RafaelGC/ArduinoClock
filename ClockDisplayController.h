#ifndef CLOCKDISPLAYCONTROLLER_H
#define CLOCKDISPLAYCONTROLLER_H

#include "Chrono.h"

class TwoDigitNumber;
class BCDDecoder;

class ClockDisplayController {
private:
	int mostSignificantHourPin, lessSignificantHourPin, mostSignificantMinutePin, lessSignificantMinutePin, currentPin;
	Chrono displayChrono, blinkChrono;

	char mode;
  bool on;

	bool hourOn, minuteOn;
	inline void manageBlink();
	inline void updateNumber(const TwoDigitNumber &hour, const TwoDigitNumber &minute, BCDDecoder &decoder);
  int nextPin();
  
public:
	static const char NORMAL = 0, HOUR_BLINK = 1, MINUTE_BLINK = 2, OFF = 3;

	ClockDisplayController(int mostSignificantHourPin, int lessSignificantHourPin, int mostSignificantMinutePin, int lessSignificantMinutePin);
	
	void update(const TwoDigitNumber &hour, const TwoDigitNumber &minute, BCDDecoder &decoder);
	void setMode(char mode);
        
        void turnOn();
        void turnOff();
        void switchDisplay();

};

#endif
