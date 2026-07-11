#define LED_PIN 4
const int inc_button=18;
const int dec_button=5;

const int frequency=5000;
const int resolution=8;

int brightness=0;

bool incCurrent=HIGH;
bool incPrevious=HIGH;

bool decCurrent=HIGH;
bool decPrevious=HIGH;

void setup() {
  pinMode(inc_button, INPUT_PULLUP);
  pinMode(dec_button, INPUT_PULLUP);

  ledcAttach(LED_PIN, frequency, resolution);
  ledcWrite(LED_PIN, brightness);

}

void loop() {
  incCurrent=digitalRead(inc_button);
  decCurrent=digitalRead(dec_button);

  if(incPrevious==HIGH && incCurrent==LOW)
  {
    brightness+=25.5;
    if(brightness>255)
      brightness=255;
    
    ledcWrite(LED_PIN, brightness);
    delay(30);
  }

  if(decPrevious==HIGH && decCurrent==LOW)
  {
    brightness-=25.5;
    if(brightness<0)
      brightness=0;

    ledcWrite(LED_PIN, brightness);
    delay(30);
  }

  incPrevious=incCurrent;
  decPrevious=decCurrent;
}
