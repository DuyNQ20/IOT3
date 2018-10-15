const int input = 2;
int output = 13;
int state = 0;
int val = 0;
void setup() 
{
  Serial.begin(9600);//Mở cổng Serial ở mức 9600
  
  pinMode (2, INPUT);
  pinMode (13, OUTPUT);
  
}
 
void loop() 
{

  val = digitalRead(input);
  if (val == 0)
  {
   digitalWrite (output, LOW);
  }
  else{
  digitalWrite (output, HIGH);
       }
}
