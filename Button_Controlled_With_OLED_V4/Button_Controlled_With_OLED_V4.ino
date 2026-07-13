#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//COnfiguring the buttons
#define LED_PIN 4
const int inc_button=18;
const int dec_button=5;

//PWM
const int frequency=5000;
const int resolution=8;

int brightnessPercent=0;
int brightness=0;

//States
bool incCurrent=HIGH;
bool incPrevious=HIGH;

bool decCurrent=HIGH;
bool decPrevious=HIGH;

void updateDisplay()
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.setTextColor(SSD1306_WHITE);

  int percent=brightness*100/255;
  
  display.println("Brightness");

  display.setTextSize(3);
  display.setCursor(35, 30);
  display.print(brightnessPercent);
  display.print("%");

  display.drawRect(10, 54, 108, 8, SSD1306_WHITE);
  int barWidth=brightnessPercent*108/100;
  display.fillRect(10, 54, barWidth, 8, SSD1306_WHITE);

  display.display();

}

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED failed");
    while(true);
  }
  pinMode(inc_button, INPUT_PULLUP);
  pinMode(dec_button, INPUT_PULLUP);

  ledcAttach(LED_PIN, frequency, resolution);
  ledcWrite(LED_PIN, brightness);

  updateDisplay();

}

void loop() {
  incCurrent=digitalRead(inc_button);
  decCurrent=digitalRead(dec_button);

  if(incPrevious==HIGH && incCurrent==LOW)
  {
    delay(30);

    if (digitalRead(inc_button) == LOW)
    {
      brightnessPercent+=10;
      if(brightnessPercent>100)
        brightnessPercent=100;
    
      brightness=brightnessPercent*255/100;
      ledcWrite(LED_PIN, brightness);
      updateDisplay();
    }
  }

  if(decPrevious==HIGH && decCurrent==LOW)
  {
    delay(30);
    if(digitalRead(dec_button) == LOW)
    {
      brightnessPercent-=10;
      if(brightnessPercent<0)
        brightnessPercent=0;
    
      brightness=brightnessPercent*255/100;
      ledcWrite(LED_PIN, brightness);
      updateDisplay();
      delay(30);
    }
  }

  incPrevious=incCurrent;
  decPrevious=decCurrent;

}
