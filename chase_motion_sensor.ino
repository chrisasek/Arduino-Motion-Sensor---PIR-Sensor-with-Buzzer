/*  Chase
 * Motion Detection 
 * PIR sensor tester
 */
 
int buzz = 8;                // choose the pin for the buzz
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
