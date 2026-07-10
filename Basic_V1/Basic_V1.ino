#define LED_PIN 4

//PWM configuration
const int frequency=5000; //5kHz
const int resolution=8; //8-bit resolution(0-255)

void setup()
{
  ledcAttach(LED_PIN, frequency, resolution);

  //Set LED brightness to 50%
  ledcWrite(LED_PIN, 128);
}

void loop()
{

}
