int green = 2;
int amber = 3; //I don't have a yellow LED so I'm using a blue one in the physical model
int red = 4;

int crossbut = 6; //button input

void setup() {
  pinMode (green, OUTPUT);
  pinMode (amber, OUTPUT);
  pinMode (red, OUTPUT); //setting up the traffic lights 

  digitalWrite (green, LOW);
  digitalWrite (amber, LOW);
  digitalWrite (red, LOW); 

  pinMode (crossbut, INPUT); //setting up button input

  Serial.begin(9600);

}

void loop() {
  digitalWrite (red, LOW);//basic traffic light motion setup
  digitalWrite(amber, LOW);
  digitalWrite (green, HIGH);
  Serial.println("GREEN");
  greenlight(); //calls function greenlight
 

  digitalWrite (green, LOW);
  digitalWrite (amber, HIGH);
  Serial.println("AMBER");
  delay(1000);

  digitalWrite (amber, LOW);
  digitalWrite (red, HIGH);
  Serial.println("RED");
  delay(6000);

  digitalWrite (amber, HIGH);
  digitalWrite (red, HIGH);
  
  Serial.println("RED/AMBER");
  delay(1000);



}

void greenlight(){
  
  for (int i=1; 1<10; i++){
    int state = digitalRead(crossbut);

    if (state == 1) {
      Serial.print("CROSSING");
      delay (5000);
      return; //when the button is pressed, displays 'CROSSING' on serial monitor then returns to the traffic light loop
    }
  }
}
