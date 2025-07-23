#include <Wire.h>
#include <Adafruit_INA219.h>


#define RED_PIN 2
#define GREEN_PIN 3
#define WHITE_PIN 4
#define OUTPUT_CTRL_PIN 5
#define BUTTON_PIN 13
#define SHUNT_CONDUCTANCE 10 // 0.100 Ohm

#define DEBOUNCER_THRESHOLD 100
#define MAX_CURRENT 100
#define MIN_WHITE_LIGHT 50

#define STATE_INIT  0
#define STATE_RUN  1
#define STATE_ERROR  2

#define LED_ON 0
#define LED_OFF 1

#define OUTPUT_ON 0
#define OUTPUT_OFF 1

Adafruit_INA219 ina219;
long last_time;
int counter;
int state = STATE_INIT;
int debouncer_counter;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(WHITE_PIN, OUTPUT);
  pinMode(OUTPUT_CTRL_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RED_PIN, LED_ON);
  digitalWrite(GREEN_PIN, LED_ON);
  digitalWrite(WHITE_PIN, LED_ON);
  digitalWrite(OUTPUT_CTRL_PIN, OUTPUT_OFF);

  if (! ina219.begin()) {
    while (1) { delay(10); }
  }
  ina219.setCalibration_16V_400mA();

  digitalWrite(RED_PIN, LED_OFF);
  digitalWrite(GREEN_PIN, LED_OFF);
  digitalWrite(WHITE_PIN, LED_OFF);

  // init
  counter = 0;
  last_time = millis();
  state = STATE_INIT;
  debouncer_counter = 0;

}

void read_button_and_change_state(int next_state){
  if(digitalRead(BUTTON_PIN)==0){
    debouncer_counter++;
  }else{
    if (debouncer_counter > DEBOUNCER_THRESHOLD) {
      state = next_state;
    }
    debouncer_counter = 0;
  }
}

void state_init(){
  digitalWrite(RED_PIN, LED_ON);
  digitalWrite(GREEN_PIN, LED_OFF);
  digitalWrite(WHITE_PIN, LED_OFF);
  digitalWrite(OUTPUT_CTRL_PIN, OUTPUT_OFF);
  
  read_button_and_change_state(STATE_RUN);

}

void state_run(){
  float shuntvoltage = 0;
  int current_mA = 0;

  digitalWrite(RED_PIN, LED_OFF);
  digitalWrite(GREEN_PIN, LED_ON);
  digitalWrite(OUTPUT_CTRL_PIN, OUTPUT_ON);

  shuntvoltage = ina219.getShuntVoltage_mV();
  current_mA = int(shuntvoltage * SHUNT_CONDUCTANCE);

  // prevent short cut
  if (current_mA >= MAX_CURRENT){
    state = STATE_ERROR;
    counter = 0;
    return;
  }

  counter += max(current_mA>>4, 1);
  if (counter < MIN_WHITE_LIGHT){
    digitalWrite(WHITE_PIN, LED_ON);
  }else{
    digitalWrite(WHITE_PIN, LED_OFF);
    if (counter > 3000){
      counter = 0;
    }
  }

  read_button_and_change_state(STATE_INIT);
}

void state_error(){
  digitalWrite(GREEN_PIN, LED_OFF);
  digitalWrite(WHITE_PIN, LED_OFF);
  digitalWrite(OUTPUT_CTRL_PIN, OUTPUT_OFF);

  int red_light_state = (counter >> 7) & 1;
  digitalWrite(RED_PIN, red_light_state);


  read_button_and_change_state(STATE_RUN);

  counter++;
  delay(1);

}

void loop() {
  switch(state){
    case STATE_INIT:
      state_init();
      break;
    case STATE_RUN:
      state_run();
      break;
    case STATE_ERROR:
      state_error();
      break;
    default:
      state = STATE_INIT;
  }
}
