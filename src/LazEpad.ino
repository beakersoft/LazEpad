#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define MUTE 4

int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  pinMode (MUTE, INPUT_PULLUP);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  Keyboard.begin();
  
  display.setCursor(0, 0);
  display.println("Hello World!");
  display.display();

}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(MUTE);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    // increment the button counter
    counter++;
    
    // send the key out to windows
    display.clearDisplay();
  display.setCursor(0, 0);
  display.println("You hit mute");
  display.println(counter);
  display.println("Times");
  display.display();

    
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
  
}
