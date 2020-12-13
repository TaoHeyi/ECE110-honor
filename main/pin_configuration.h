void pin_configuration(){

pinMode (2, INPUT); // BottomUp 1
pinMode (3, INPUT); // BottomRight 1
pinMode (4, INPUT); // BottomDown 1
pinMode (5, INPUT); // BottomLeft 1
pinMode (6, INPUT); // BottomStart 1
pinMode (7, INPUT); // BottomEnd 1

//player2
pinMode(12,OUTPUT);
//player1
pinMode(11,OUTPUT);
//reset
pinMode(8,OUTPUT);

digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);

// Reset
digitalWrite(8,HIGH);
delayMicroseconds(50);

digitalWrite(11,HIGH);
digitalWrite(12,HIGH);

delayMicroseconds(50);



//pin 12 is used as player 2 get shot signal
digitalWrite(12,LOW);
//pin 11 is used as player 1 get shot signal
digitalWrite(11,LOW);
//pin 8 is used as reset signal
delayMicroseconds(50);
digitalWrite(8,LOW);


}
