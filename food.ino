#include <LiquidCrystal.h>

#include <dht.h>   // include dht sensor library
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

dht DHT;

float t=0;

float h=0;

#define DHT11_PIN 13

#define LDR_PIN A1

#define MQ3_PIN A0

char data = 0;

int ldr_read = 0;

int gas_read = 0;

const int ledPin=12;
void setup() 

{  
  pinMode(ledPin, OUTPUT);    
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print(" --WELCOME TO--");

  lcd.setCursor(0,1);

  lcd.print(" -FOOD MONITOR-");

  Serial.begin(9600);

   delay(5000);
 

  
 }


void loop()

{

  lcd.clear();

  ldr_read = analogRead(LDR_PIN);
  Serial.print("Light-");
   Serial.println(ldr_read);
   ldr_read=ldr_read-50;
  if(ldr_read>=100)
  {
    ldr_read=100;
  }
   
  lcd.setCursor(0,0);

  lcd.print("L.E-");

  lcd.setCursor(4,0);

  lcd.print(ldr_read);


 

  lcd.setCursor(0,1);

  lcd.print("GAS-");

  gas_read = analogRead(MQ3_PIN);
   
  Serial.print("Gas =   ");
  Serial.println(gas_read);
  gas_read = gas_read-70;
  int gas1=gas_read;
  if(gas_read >=100)
  {
    gas_read=100;
  }
  lcd.setCursor(4,1);

  lcd.print(gas_read);
  
  int chk = DHT.read11(DHT11_PIN);

  Serial.print("Temperature = ");

  t = DHT.temperature;

  //lcd.clear();

  lcd.setCursor(8,0);

  lcd.print("Tem-");


 

  lcd.setCursor(12,0);

  lcd.print(t);

  Serial.println(t);


 

  Serial.print("Humidity = ");

  h = DHT.humidity;

  lcd.setCursor(8,1);

  lcd.print("Hum-");

  lcd.setCursor(12,1);

  lcd.print(h);

  Serial.println(h);

   delay(3000);
   if(gas_read>=100)
  {
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bad FOOD Conditn");
    lcd.setCursor(4,1);
    lcd.print("Gas-");
    lcd.setCursor(8,1);
    lcd.print(gas_read);
    delay(2000);
  }
  else if(ldr_read>=100){
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bad FOOD Conditn");
    lcd.setCursor(4,1);
    lcd.print("L.E-");
    lcd.setCursor(8,1);
    lcd.print(ldr_read);
    delay(2000);
  } 
    else if(t>=45){
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bad FOOD Conditn");
    lcd.setCursor(4,1);
    lcd.print("Tem-");
    lcd.setCursor(8,1);
    lcd.print(t);
    delay(2000);
  }
   else if(h>=100){
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bad FOOD Conditn");
    lcd.setCursor(4,1);
    lcd.print("Hum-");
    lcd.setCursor(8,1);
    lcd.print(h);
    delay(2000);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
 

  
   delay(2000);
}
