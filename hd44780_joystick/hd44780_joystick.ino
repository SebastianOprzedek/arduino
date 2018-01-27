#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i = 0;
bool changed = true;
char firstLineTemplate[16] = " Inzynier       ";
char secondLineTemplate[16] = "sie bawi :)     ";
char firstLine[16] = "";
char secondLine[16] = "";
int analogX = 0;
int analogY = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.display();
  Serial.begin(9600); 
  pinMode(8, INPUT);
}

void loop() {  
  if(changed){
    setLines(i);
    write();
    delay(100);
    changed = false;
  }
  else{    
    readValues();
    updateIndex();
  }
}

void readValues(){
  analogX = analogRead(0);  
  analogY = analogRead(1);
  Serial.println(analogX);
  Serial.println(analogY);
}

void setLines(int counter){
  for(int j=0; j<(16-counter); j++){
    firstLine[counter+j] = firstLineTemplate[j];
    secondLine[counter+j] = secondLineTemplate[j];
  }  
  for(int j=0; j<counter; j++){
    firstLine[j] = firstLineTemplate[16-counter+j];
    secondLine[j] = secondLineTemplate[16-counter+j];
  } 
}

void updateIndex(){
  if(analogX > 750){   
    i+=1; 
    changed = true;
  }
  else if(analogX <= 250){
    i-=1;
    changed = true;
  }
  if(i>=16) i=0;  
  if(i<0) i=14;  
}

void write(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
}

