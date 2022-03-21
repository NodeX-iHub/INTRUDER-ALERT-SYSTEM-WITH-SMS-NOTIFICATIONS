#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins

int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trig = 3;
int echo = 2;

int pir = 7;
int pir_status;
int led = 5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(led,OUTPUT);
lcd.begin(16, 2); // Set the display to 16 columns and 2 rows

pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pir_status = digitalRead (pir);

  if (pir_status == HIGH)
{
 Serial.println("AT+CMGF=1");
delay(1000);
 Serial.println("AT+CMGS=\"+2347062182313\"\r");
delay(1000);
Serial.println("INTRUDER DETECTED"); //replace X with any phone number eg. 08133339988
delay(1000);
Serial.println((char)26);
delay(1000);
Serial.println();

delay(1000);

   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(1000);
   digitalWrite(trig, LOW);
  delay (2);
  digitalWrite(trig, HIGH);
  delay (10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo,HIGH);
  int distance = (duration*0.034)/2;
  lcd.clear();
  lcd.print("INTRUDER ALERT");
    lcd.setCursor(0,1);
    lcd.print("DIST REMAIN");
    lcd.setCursor(12,1);
    lcd.print(distance);
    delay(1000);
  Serial.println(distance);
  
  lcd.setCursor(14,1);
  lcd.print("cm");
}
}
