int out1 = 4, out2=5, out3=6, out4=7, out5=8, out6=9, out7=10, out8=11;		//initiate output pin numbers

int potIn= A0; 	//Initiate input pin number
int input,tens,ones; 	// initiate some variables needed for the porgram
int mappedValue=0;

void setup() 	// Setup the ports according to their purpose
{
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  pinMode(out8, OUTPUT);
  
  pinMode(potIn, INPUT);
}


void display(int tens, int ones) //Simple function to control the CD4511 given the tens and ones
{
  digitalWrite(out1, bitRead(ones,0));
  digitalWrite(out2, bitRead(ones,1));
  digitalWrite(out3, bitRead(ones,2));
  digitalWrite(out4, bitRead(ones,3));
  digitalWrite(out5, bitRead(tens,0));
  digitalWrite(out6, bitRead(tens,1));
  digitalWrite(out7, bitRead(tens,2));
  digitalWrite(out8, bitRead(tens,3));
}

void loop() // This is where the program will be executed
{
  input = analogRead(potIn); // Read the pot signal
  mappedValue= map(input,0,1023,0,99); // map the pot signal from 0-99
  tens = mappedValue/10; //seperate tens
  ones = mappedValue %10; // seperate ones
  
  display (tens,ones);
  delay(100);
}
  