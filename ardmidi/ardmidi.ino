/*this code can send midi signals via serial communication and with help of using some potentiometer at the analog input you can make a cool modulater  
 for DAW  you use to produce music you have to downlod some simple software for this one is loopmidi and other is hairlessmidi which helps in interfacing between midi signal and arduino serial communication
 hairless midi( https://www.softpedia.com/get/System/System-Miscellaneous/Hairless-MIDI-to-Serial-Bridge.shtml)
 loopmidi(https://www.tobias-erichsen.de/software/loopmidi.html)
for query mail me at  duaanirudh054@gmail.com
 */


// |===============MESSAGE=================|============DONNEE1============|=========DONNEE2==========|
// | 1000 cccc = note off => 128(10) | 0xxx xxxx: hauteur note | 0xxx xxxx: velocity |
// | 1001 cccc = note on => 129(10) | 0xxx xxxx: hauteur note | 0xxx xxxx: velocity|
// | 1110 cccc = pitch bend => 224(10) | 0000 0000: code | 0xxx xxxx: vitesse |
// | 1011 cccc = control change => 176(10) | 0xxx xxxx: numero | 0xxx xxxx: valeur |
// --------------------------------------------------------------------------------------------------
//========================
//Analog pin ZERO
int valuePinZero=0;
int valuePinZero2=0;
 
//Analog pin ONE
int valuePinOne=0;
int valuePinOne2=0;
 
//Analog pin TWO
int valuePinTwo=0;
int valuePinTwo2=0;

 
void setup()
{
Serial.begin(57600); 
 
}
 
void loop()
{
//controleur ZERO

//————————
valuePinZero = (analogRead(0)/8); 
if (valuePinZero-valuePinZero2 >=2 || valuePinZero2-valuePinZero >=2) { 
valuePinZero2 = valuePinZero;
 
MIDI_TX(176,75, valuePinZero); 
//delay(100); 
}
 
//controleur ONE
//————————
valuePinOne = (analogRead(1)/8);

if (valuePinOne - valuePinOne2 >=2 || valuePinOne2 - valuePinOne >=2)
{
 
valuePinOne2 = valuePinOne;
 
MIDI_TX(176,76, valuePinOne);
//delay(100);
}
 
//controleur TWO
//————————
valuePinTwo = (analogRead(2)/8);
if (valuePinTwo - valuePinTwo2 >=2 || valuePinTwo2 - valuePinTwo >=2)
{
 
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
