//Analog pin ZERO
int ledpinblue=8;
int ledpingreen=13;
int ledpinnot=12;
int valuePinZero=0;
int valuePinZero2=0;

int data1;
int ledval;
//Analog pin ONE
int valuePinOne=0;
int valuePinOne2=0;

//Analog pin TWO
int valuePinTwo=0;
int valuePinTwo2=0;

 
void setup()
{
Serial.begin(115200); 

pinMode(ledpinblue, OUTPUT);
pinMode(ledpingreen, OUTPUT); 
}
 
void loop()
{

    

delay(50);
valuePinZero = (analogRead(0)/8);
analogWrite(ledpinblue, valuePinZero); 
if (valuePinZero-valuePinZero2 >=2 || valuePinZero2-valuePinZero >=2) { 
 digitalWrite(ledpinnot, HIGH);
delay(10);
analogWrite(ledpinnot, LOW);
delay(10);
 
MIDI_TX(176,75, valuePinZero);
valuePinZero2 = valuePinZero; 

//delay(100); 
}
 
//controleur ONE
//————————
valuePinOne = (analogRead(1)/8);
analogWrite(ledpinblue, valuePinOne);
if (valuePinOne - valuePinOne2 >=2 || valuePinOne2 - valuePinOne >=2)
{
 digitalWrite(ledpingreen, HIGH);
delay(10);
analogWrite(ledpingreen, LOW);
delay(10);
valuePinOne2 = valuePinOne;
 
MIDI_TX(176,76, valuePinOne);
//delay(100);
}
 
ledval=analogRead(2);
//————————
valuePinTwo = (analogRead(2)/8);
analogWrite(ledpinblue, valuePinTwo);

if (valuePinTwo - valuePinTwo2 >=2 || valuePinTwo2 - valuePinTwo >=2)
{
digitalWrite(ledpinblue, HIGH);
delay(50);
analogWrite(ledpinblue, LOW);
delay(50);


valuePinTwo2 = valuePinTwo;
 
MIDI_TX(176,77, valuePinTwo);
//delay(100);
}
 
}
 
void MIDI_TX(unsigned char MESSAGE, unsigned char DONNEE1, unsigned char DONNEE2) 
{
 
 Serial.write(MESSAGE); 
 Serial.write(DONNEE1);
 Serial.write(DONNEE2);

}
