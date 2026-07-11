#define LED_PIN 4

const int frequency=5000;
const int resolution=8;


void setup() {
  ledcAttach(LED_PIN, frequency, resolution);

}

void loop() {
  for(int brightness=0; brightness<=255; brightness++)
  {
    ledcWrite(LED_PIN, brightness);
    delay(10);
  }

  for(int brightness=255; brightness>=0; brightness--)
  {
    ledcWrite(LED_PIN, brightness);
    delay(10);
  }
}
