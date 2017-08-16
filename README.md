# Arduino-Motion-Sensor---PIR-Sensor-with-Buzzer
Simple Arduino motion sensor using PIR sensor and buzzer.


## How PIRs Work by lady ada
PIR sensors are more complicated than many of the other sensors explained in these tutorials (like photocells, FSRs and tilt switches) because there are multiple variables that affect the sensors input and output. To begin explaining how a basic sensor works, we'll use this rather nice diagram
The PIR sensor itself has two slots in it, each slot is made of a special material that is sensitive to IR. The lens used here is not really doing much and so we see that the two slots can 'see' out past some distance (basically the sensitivity of the sensor). When the sensor is idle, both slots detect the same amount of IR, the ambient amount radiated from the room or walls or outdoors. When a warm body like a human or animal passes by, it first intercepts one half of the PIR sensor, which causes a positive differential change between the two halves. When the warm body leaves the sensing area, the reverse happens, whereby the sensor generates a negative differential change. These change pulses are what is detected.


### Here is the connection details

### PIR Connection
* GND pin to Arduino Ground
* VCC pin to Arduino 5v
* OUT pin to any Arduino digital pin of yourchoice(pin 8 in this tutorial)

### BUZZER connection
* +ve to any Arduino digital pin of your choice(pin 8 in this tutorial)
* -ve to Arduino Ground

### Arduino Code
```Arduino
/*  Chase
 * Motion Detection 
 * PIR sensor tester
 */
 
int buzz = 8;                // choose the pin for the buzzer
int inputPin = 2;               // choose the input pin (for PIR sensor)
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}

void play_tone() {
    tone(buzz, 988, 1000);
    delay(2500);
    tone(buzz, 1047, 1000);
    delay(2500);
}


void loop(){
  val = digitalRead(inputPin);  // read input value
  if(val == HIGH){   // check if the input is HIGH
      Serial.println("Motion detected!");
      play_tone();  // play Buzzer
  }else(
    noTone(buzz);
    Serial.println("Motion ended!");
  }
}


```
