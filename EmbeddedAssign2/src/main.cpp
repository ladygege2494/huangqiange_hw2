#include <Arduino.h>

//串口通信实验
//串口助手发送"led_on()"点亮LED,发送"led_off()"熄灭LED,发送led_flash(x)使LED闪烁x次，单片机收到指令后并执行后返回"OK"
//x范围任意

int led = 13;

String myString = ""; //接收串口发送过来的值

String short_String = ""; //存储myString截取后的字符串

String xstr = ""; //存储led_flash(x)的字符串x

String Control_LED[] = {"led_on()", "led_off()", "led_flash(x)"}; //定义字符串数组

int x = 0;//存储led_flash(x)的整数x

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)//如果串口有数据
  {
    myString = Serial.readStringUntil('\n');//读取字符串
    short_String = myString.substring(0, 8);//截取输入字符串myString的前8位字符
    Control_LED[0] = Control_LED[0].substring(0, 8);//截取字符串Control_LED[0]的前8位字符
    Control_LED[1] = Control_LED[1].substring(0, 8);//截取字符串Control_LED[1]的前8位字符
    Control_LED[2] = Control_LED[2].substring(0, 8);//截取字符串Control_LED[2]的前8位字符

    if (myString.length() > 10)
    {
      xstr = myString.substring(10, myString.length() - 1) ; //提取灯的闪烁次数xstr字符串
      x = xstr.toInt();//将字符串xstr转成数字x
    }

    if (short_String.compareTo(Control_LED[0]) == 0)//比较short_String和截取后led_on()是否相同
    {
      Serial.println("ON");
      digitalWrite(led, HIGH);
    }
    else if (short_String.compareTo(Control_LED[1]) == 0)//比较short_String和截取后led_off()是否相同
    {
      Serial.println("OFF");
      digitalWrite(led, LOW);
    }
    else if (short_String.compareTo(Control_LED[2]) == 0 ) //比较short_String和截取后led_flash(x)是否相同
    {
      Serial.println("OK");

      while (x > 0)
      {
        x--;//x为灯的闪烁次数
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      }
    }
  }
}
