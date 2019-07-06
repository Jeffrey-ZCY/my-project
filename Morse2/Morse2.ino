#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
    void s_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/

Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morse::w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}

void Morse::s_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*4);
}
Morse morse(13);

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0)//判断是否有输入
  {
    int a=Serial.read();//进行相应的莫尔斯电码输出
      switch (a)
      { 
      case 97: morse.dot();morse.dash();break;
      case 32: morse.s_space();break; 
      case 98: morse.dash();morse.dot();morse.dot();morse.dot();break;
      case 99: morse.dash();morse.dot();morse.dash();morse.dot();break;
      case 100: morse.dash();morse.dot();morse.dot();break;
      case 101: morse.dot();break;
      case 102: morse.dot();morse.dot();morse.dash();morse.dot();break;
      case 103: morse.dash();morse.dash();morse.dot();break;
      case 104: morse.dot();morse.dot();morse.dot();morse.dot();break;
      case 105: morse.dot();morse.dot();break;
      case 106: morse.dot();morse.dash();morse.dash();morse.dash();break;
      case 107: morse.dash();morse.dot();morse.dash();break;
      case 108: morse.dot();morse.dash();morse.dot();morse.dot();break;
      case 109: morse.dash();morse.dash();break;
      case 110: morse.dash();morse.dot();break;
      case 111: morse.dash();morse.dash();morse.dash();break;
      case 112: morse.dot();morse.dash();morse.dash();morse.dot();break;
      case 113: morse.dash();morse.dash();morse.dot();morse.dash();break;
      case 114: morse.dot();morse.dash();morse.dot();break;
      case 115: morse.dot();morse.dot();morse.dot();break;
      case 116: morse.dash();break;
      case 117: morse.dot();morse.dot();morse.dash();break;
      case 118: morse.dot();morse.dot();morse.dot();morse.dash();break;
      case 119: morse.dot();morse.dash();morse.dash();break;
      case 120: morse.dash();morse.dot();morse.dot();morse.dash();break;
      case 121: morse.dash();morse.dot();morse.dash();morse.dash();break;
      case 122: morse.dash();morse.dash();morse.dot();morse.dot();break;
      default: morse.s_space();break;
      }
      morse.c_space();
  }
}
