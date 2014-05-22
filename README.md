criterium
=========
Here is a block diagram for the piece.



                        +-------------+ +-------------+            
                        |             | |             |            
                        |             | |             |            
                        |   Arduino   | |    Motor    |            
                        |  Mega 2560  +-+  Controller |            
                        |             | |             |            
    Light +--+ BJT +----+             | |             |     Stepper
                        |             | |             +---+  Motor 
                        +----+-----+--+ +-------------+            
                             |     |                               
                             +     +                               
                   Hall Effect    Hall Effect                      
                    Sensor 1      Sensor 2                        

Magnets inside the acrylic chain ring trigger Hall Effect Sensor 2 (the other sensor is for backup). Hall effect sensors raise intterupts and increment a counter. Every main loop, the arduino checks if the counter was incremented and if it was, it makes the stepper take two steps and turn on the light.

### Power
Power comes from the USB cable that is connected to a 5 watts wall charger. The arduino doesn't behave correctly when using a power block (something must be broken on the board), but works fine with the USB power.

### Wiring
The two hall effect sensors, the motor and the light can be disconnected from the rest of the electronics by disconnecting them inside the blue box. Sensor 1 is already disconnected. Sensor 2 is connected with a servo plug that is labeled SENSOR 2. The light and the stepper cables are bundled in the grey ethernet cable. The cables that have brown ends are for th light (with the plug labeled LIGHT). The ones with the white ends are for the stepper. If you go up the ones with the white head, they eventually change color to the colors of the ethernet cable. Here is the mapping with the colors of the motor on the other end.

* orange -> red
* orange-white -> yellow
* blue -> grey
* blue-white -> green

The motor plug is also labeled (MOTOR).

### Changing the light
Incadescent light bulbs sold for MagLight work best. The power is fed directly from the board to the light and is switched on/off using a BJT connected to a digital pin. Using the bulb that is meant for a flashlight is probably best because the circuit uses the 3V on the board, which is the same as what 2 AA batteries would give you. The bulb can easily be changed because it simply rests on the servo plug with one of its connector (the bottom one) blocked.

### Troubleshooting
The only problem I have experienced so far is the motor behaving strangely. If this happens, first check that the wiring inside the box (the 4 white wires) are well connected to the servo sockets. This has resolved the issue for me every single time. I have solidifed them wit tape for now, but a more complete solution would be to soder male-to-male connectors to the end of the white wires which would hold them more thightly inside the servo plug. 
