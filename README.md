# batteryStatus
check the battery on Roversa

```
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
