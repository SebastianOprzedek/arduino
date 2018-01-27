int val = 0;
int i = 1;
int inPin = 12;
int outPin = 13;
boolean light = false;
boolean running = false;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
 pinMode(outPin, OUTPUT);
 pinMode(inPin, INPUT);
}

void loop() {
  if(i==50) i=1;
  if(i==1){
    Serial.println("running:");
    Serial.println(running);
    Serial.println("light:");
    Serial.println(light);
    if(light && running)
      digitalWrite(outPin, HIGH);
    else
      digitalWrite(outPin, LOW);
    light = !light;
  }
  val = digitalRead(inPin);
  if(val == HIGH){
    running = !running;
    if(light && running)
      digitalWrite(outPin, HIGH);
    else
      digitalWrite(outPin, LOW);
    delay(200);      
    i=0;    
  }
  i++;
  Serial.println(String(i) + "  " + String(running) + "  " + String(light));
}
