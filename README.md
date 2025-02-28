# batteryRoversa
Check the battery on Roversa!

Simple library for obtaining the battery voltage of Roversa using [codal-microbit-v2](https://github.com/lancaster-university/microbit-v2-samples). This reads the analog value on PIN3 which is the voltage at a voltage divider of two 100k resistors from the battery source, a 4.7V 400mAh LiPo battery. You may get inaccurate readings if the micro:bit USB port is connected while in the robot. These values will change whether you are charging and whether or not the power button is on/off. The readings are meant to be used when the robot is not connected to another device and is operating directly off of the battery.

To use the library, add:
`#include "batteryRoversa.h"`
to **main.cpp** to read voltage of battery on Roversa.

For example in **main.cpp**:

```cpp
#include "MicroBit.h"
#include "batteryRoversa.h"

MicroBit uBit;

main(){
    uBit.init();
    while(1){
        ManagedString BC = batteryCheck();
        uBit.display.scroll(BC);
        uBit.sleep(2000);
        ManagedString BV = batteryVoltageString();
        uBit.display.scroll(BV);
        uBit.sleep(2000);
    }
}
```

`batteryVoltage();`

Returns a float with 2 decimals representing the voltage of the battery. This is converted from the voltage divider value.

`batteryVoltageString();`

Returns a `ManagedString` of the battery voltage to be used on the display or elsewhere

`batteryCheck();`

Returns a `ManagedString` relating to thresholds set in **batteryRoversa.h**. These can be used to help quickly define ranges and thresholds for the battery.

- `BAT_LOW` is returned if the battery voltage is below BAT_LOW or 3.4 V. This signals the battery needs to be charged and is below normal operating voltage.

- `BAT_CHG` is returned if the battery is is greater or equal to BAT_LOW and below BAT_OK or between 3.4 V and 3.6 V.

- `BAT_OK!` is returned if the battery is greater or equal to BAT_OK and below or equal to BAT_MAX or in the normal operating voltage range, 3.6 V and 4.7 V.

- `BAT_BAD` is returned if the battery is outside of these ranges. If the micro:bit is plugged into the USB directly, it will read ~5V because the PIN 3 is reading high, causing this error
