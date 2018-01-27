#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i = 0;
char firstLineTemplate[16] = " Inzynier       ";
char secondLineTemplate[16] = "sie bawi :)     ";
char firstLine[16] = "";
char secondLine[16] = "";

void setup() {
  lcd.begin(16, 2);
  lcd.display();
  Serial.begin(9600); 
}

void loop() {
  setLines(i);
  Serial.print(i);
  write();
  delay(700);
  updateCounter();
}

void setLines(int counter){
  for(int j=0; j<(15-counter); j++){
    firstLine[counter+j] = firstLineTemplate[j];
    secondLine[counter+j] = secondLineTemplate[j];
  }  
  for(int j=0; j<counter; j++){
    firstLine[j] = firstLineTemplate[15-counter+j];
    secondLine[j] = secondLineTemplate[15-counter+j];
  }  
  Serial.println(firstLine);
  Serial.println(secondLine);
}

void updateCounter(){
  i+=2;
  if(i>=15) i=0; 
}

void write(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
}

