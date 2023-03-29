// пример работы с несколькими лентами
#define LED_PIN    2 //пин ленты 1
#define LED_PIN_1    6 //пин ленты 2
#define LED_PIN_2    7 //пин ленты 3
#define NUMLEDS    270 // количество диодов 

#define LED_INPUT_1 3 //датчик растояния 1
#define LED_INPUT_2 9 //датчик растояния 2
#define LED_INPUT_3 11 //датчик растояния 3

#define COLOR_LENT_1 mRed //цвет лент
#define COLOR_LENT_2 mGreen
#define COLOR_LENT_3 mBlue
#define COLOR_FINISH_1 mRed
#define COLOR_FINISH_2 mGreen
#define COLOR_FINISH_3 mBlue
#define DELAY_FINISH 15000// задержка финального эффекта
#define PIN_LED_HEAD 13

// настройки влияют на обе ленты сразу!
#define COLOR_DEBTH 2   // цветовая глубина: 1, 2, 3 (в байтах)
#include <microLED.h>

microLED<NUMLEDS, LED_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip_1;
microLED<NUMLEDS, LED_PIN_1, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip_2;
microLED<NUMLEDS, LED_PIN_2, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip_3;

int count=0;
int count_1=0;
int count_2=0; 
bool flag=false;
bool flag_1=false;
bool flag_2=false;
void LED_ON(int count,int count_1,int count_2);
void LED_FINISH(int val);
void setup() {
 pinMode(LED_INPUT_1, INPUT_PULLUP);
 pinMode(LED_INPUT_2, INPUT_PULLUP);
 pinMode(LED_INPUT_3, INPUT_PULLUP);
 pinMode(PIN_LED_HEAD, OUTPUT);//пин головы
 digitalWrite(PIN_LED_HEAD,HIGH);//пин головы
  // управляем яркостью
  strip_1.setBrightness(100);
  strip_2.setBrightness(100);
  strip_3.setBrightness(100); 
 pinMode(LED_INPUT_1, INPUT_PULLUP);
 pinMode(LED_INPUT_2, INPUT_PULLUP);
 pinMode(LED_INPUT_3, INPUT_PULLUP);
 pinMode(PIN_LED_HEAD, OUTPUT);//пин головы


  // выводим на ленты
  strip_1.show();
  strip_2.show();
}

void loop() {
  if(digitalRead(LED_INPUT_1)!=LOW){flag=false;}
  if(digitalRead(LED_INPUT_1)!=HIGH&&flag==false){
    count++;
    flag=true;
  }
  if(digitalRead(LED_INPUT_2)!=LOW){flag_1=false;}
  if(digitalRead(LED_INPUT_2)!=HIGH&&flag_1==false){
    count_1++;
    flag_1=true;
  }
  if(digitalRead(LED_INPUT_3)!=LOW){flag_2=false;}
  if(digitalRead(LED_INPUT_3)!=HIGH&&flag_2==false){
    count_2++;
    flag_2=true;
  }
  if(count>=NUMLEDS){
    LED_FINISH(1);
    }
    if(count_1>=NUMLEDS){
    LED_FINISH(2);
    }
    if(count_2>=NUMLEDS){
    LED_FINISH(3);
    }
  
    LED_ON(count,count_1,count_2);
   strip_1.show();
    strip_2.show();
     strip_3.show();
   
    
}
void LED_ON(int count, int count_1,int count_2 ){
  for(int i=NUMLEDS-count;i<NUMLEDS;i++){
    strip_1.leds[i] = COLOR_LENT_1;
    }
    for(int i=NUMLEDS-count_1;i<NUMLEDS;i++){
    strip_2.leds[i] = COLOR_LENT_2;
    }
    for(int i=NUMLEDS-count_2;i<NUMLEDS;i++){
    strip_3.leds[i] = COLOR_LENT_3;
    }
  return;
  }
void LED_FINISH(int val){
    count=0;
    count_1=0;
    count_2=0;
  if(val==1){
    for(int i=0;i<NUMLEDS;i++){
    strip_1.leds[i]=COLOR_FINISH_1;
     strip_2.leds[i]=COLOR_FINISH_1;
      strip_3.leds[i]=COLOR_FINISH_1;
  }}
    if(val==2){
      for(int i=0;i<NUMLEDS;i++){
    strip_1.leds[i]=COLOR_FINISH_2;
     strip_2.leds[i]=COLOR_FINISH_2;
      strip_3.leds[i]=COLOR_FINISH_2;
      }}
    if(val==3){
      for(int i=0;i<NUMLEDS;i++){
    strip_1.leds[i]=COLOR_FINISH_3;
     strip_2.leds[i]=COLOR_FINISH_3;
      strip_3.leds[i]=COLOR_FINISH_3;
     }}
     
   digitalWrite(PIN_LED_HEAD,LOW);//зажигаем голову
 strip_1.show();
    strip_2.show();
     strip_3.show();
   delay(DELAY_FINISH);
   strip_1.clear();
    strip_2.clear();
     strip_3.clear();
     digitalWrite(PIN_LED_HEAD,HIGH);//гасим голову
  
  
  return;
  }
