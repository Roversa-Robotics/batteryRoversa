#include "MicroBit.h"
#include "batteryRoversa.h"

extern MicroBit uBit;

int roundFloat(float value) {
  return (int)(value * 100 + 0.5);
}

//get the battery voltage from voltage divider (2x 100kOhm res), return a float value with 2 decimal places
float batteryVoltage() {
  uBit.display.disable();
  float measuredVBat = uBit.io.P3.getAnalogValue();
  measuredVBat = (measuredVBat*2.0f*3.3f)/1024.0f;
  int measuredVBatInt = roundFloat(measuredVBat);
  uBit.display.enable();
  return (float)measuredVBatInt/100;
}

//converts the float battery voltage into ManagedString
ManagedString batteryVoltageString() {
  float measuredVBat = batteryVoltage();
  int stringVBat = roundFloat(measuredVBat);
  ManagedString fullStringBat = stringVBat;
  ManagedString decimalPlace = ".";
  ManagedString finalStringBat = fullStringBat.charAt(0) + decimalPlace + fullStringBat.charAt(1) + fullStringBat.charAt(2);
  return finalStringBat;
}

//send ManagedStrings to denote thresholds for battery level
ManagedString batteryCheck() {
  float battery = batteryVoltage();
  if (battery < BAT_LOW) {
    ManagedString BL = "BAT_LOW";
    return BL;
  }
  else if (battery >= BAT_LOW && battery < BAT_OK) {
    ManagedString BC ="BAT_CHG";
    return BC;
  } 
  else if (battery >= BAT_OK && battery <= BAT_MAX) {
    ManagedString BO ="BAT_OK!";
    return BO;
  }
  else {
    ManagedString BB = "BAT_BAD";
    return BB;
  }
}