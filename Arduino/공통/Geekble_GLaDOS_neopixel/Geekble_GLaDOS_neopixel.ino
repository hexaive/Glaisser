/*[Geekble X 메이커창작과] : GLaDOS_Glados_Main Code */
int cmd;
int move_g = 5;
int flage = 0;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        9
#define PIN1        8                                                                                                                                                                                               

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8// Popular NeoPixel ring size
#define NUMPIXELS1 22

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 400 // Time (in milliseconds) to pause between pixels

void setup() {
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels1.begin(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 110, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
  pixels1.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
}

void loop() {
  flage = digitalRead(10);
  for(int i=0; i<NUMPIXELS1; i++){
    if(flage == 1){
      pixels1.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    else if(flage == 0){
      pixels1.setPixelColor(i, pixels.Color(255, 255, 255));
    }

    pixels1.show();   // Send the updated pixel colors to the hardware.

    delay(50); // Pause before next pass through loop
  }
  delay(500);
  pixels1.clear();
  
}
