#ifndef BATTERYROVERSA_H
#define BATTERYROVERSA_H

#define BAT_LOW     3.4
#define BAT_OK      3.6
#define BAT_MAX     4.7

float batteryVoltage();
ManagedString batteryVoltageString();
ManagedString batteryCheck();

#endif // BATTERYROVERSA_H