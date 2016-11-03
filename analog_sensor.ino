void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  Serial.println(a);
  analogWrite(12,map(a,0,1024,0,255));
  delay(10);
}


 

// # Connection:
// #        Signal output pin  -> Analog pin 0
// #
 
 
void setup()
{
  Serial.begin(9600);     //Set serial baud rate to 9600 bps
}
void loop()
{
  int val;
  val=analogRead(0);      //Read slider value from analog 0
  Serial.println(val,DEC);//Print the value to serial port
  delay(100);
}
