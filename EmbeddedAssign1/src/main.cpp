#include <Arduino.h>

#define LED1 32
#define LED2 33 
#define LED3 25
#define LED4 26
#define LED5 27
#define LED6 14


int ledPins[] = {LED1, LED2, LED3, LED4, LED5,LED6}; // 定义一个数组，存储LED引脚


void setup() {
  // 设定主角（程序里的变量对应硬件的引脚），引脚功能/作用（输入/输出）
for(int i = 0; i < 6; i++)
pinMode(ledPins[i],OUTPUT);
}
 
void loop() {
  //来回for循环，设置好起止点
for(int i = 0; i < 6; i++ )
  {
    digitalWrite(ledPins[i] , HIGH);
    delay(500);
    digitalWrite(ledPins[i] , LOW);
  }
for(int i = 4;i > 0;i--)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
    }
}
