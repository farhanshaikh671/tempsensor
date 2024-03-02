#define DELAY_LOW 250
#define DELAY_HIGH 500

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int dacVal = analogRead(A0);
  float analogVoltage = (dacVal * 5.0) / 1023; // 0 - 1023 --> 0 - 5v
  float temp = (analogVoltage / 10) * 1000; // LM35 adds 10mV every degree rise in temperature
  
  // Blink LED based on analog voltage
  if (temp < 30) {
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(DELAY_LOW);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(DELAY_LOW);
  } 
  else if (temp > 30) {
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(DELAY_HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(DELAY_HIGH);
  }
}

