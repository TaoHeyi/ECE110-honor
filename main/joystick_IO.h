
#define Stan1x 530
#define Stan1y 513
#define threshold 150


void joysticksIO(player* player1,player* player2){
    
int Sx;
int Sy;
    
//Move and Bottom Control Receive From Player2
uint8_t ReceFromPlayer2 = 0;
uint8_t ReceT = 0;
    

//reset players bottom
player1->UP=0;
player1->LEFT=0;
player1->RIGHT=0;
player1->DOWN=0;
player2->UP = 0;
player2->LEFT = 0;
player2->RIGHT = 0;
player2->DOWN=0;

  
if (Serial.available() > 0) {
    ReceFromPlayer2 = Serial.read();
}

    //Decoding Part
    ReceT = ReceFromPlayer2;
    
                                                                       //First
    if ((ReceT % 2) == 0) {
        player2->moveY = 0;
        ReceT = ReceT / 2;
    }
    else {
        player2->moveY = 1;
        ReceT = (ReceT - 1) / 2;
    }
                                                                    //Second
    if ((ReceT % 2) == 0) {
        ReceT = ReceT / 2;
    }
    else {
        player2->moveY = player2->moveY * (-1);
        ReceT = (ReceT - 1) / 2;
    }
                                                                    //Third
    if ((ReceT % 2) == 0) {
        player2->moveX = 0;
        ReceT = ReceT / 2;
    }
    else {
        player2->moveX = 1;
        ReceT = (ReceT - 1) / 2;
    }
                                                                    //Fourth
    if ((ReceT % 2) == 0) {
        ReceT = ReceT / 2;
    }
    else {
        player2->moveX = player2->moveX * (-1);
        ReceT = (ReceT - 1) / 2;
    }

      if(ReceT == 1){player2->UP = 1;}
      else if(ReceT == 2){player2->RIGHT = 1;}
      else if(ReceT == 4){player2->LEFT = 1;}
      else if(ReceT == 8){player2->DOWN = 1;}

//player1 Read Controller part
Sx = analogRead(A0);
Sy = analogRead(A1);
Sx = Sx - Stan1x;   //Normalize Sx and Sy
Sy = Sy - Stan1y;


//Player1 Control Processing part
if (Sx > threshold)
{
    if (Sy > threshold) {
        player1->moveX = 1;  //X-Right Y-Right
        player1->moveY = 1;
    }
    else if (Sy < (-1) * (threshold)) {
        player1->moveX = 1;  //X-Right  Y-Left
        player1->moveX = -1;
    }
    else {
        player1->moveX = 1;  //0100;                            //X-Right Y-No Move
        player1->moveY = 0;
    }
}

else if (Sx < (-1) * (threshold))
{
    if (Sy > threshold) {
        player1->moveX = -1;  //X-Left Y-Right
        player1->moveY = 1;
    }
    else if (Sy < (-1) * (threshold)) {
        player1->moveX = -1;  //X-Left  Y-Left
        player1->moveY = -1;
    }
    else {
        player1->moveX = -1;  //0100;                            //X-Left Y-No Move
        player1->moveY = 0;
    }
}

else
{
    if (Sy > threshold) {
        player1->moveX = 0;  //X-No Move Y-Right
        player1->moveY = 1;
    }
    else if (Sy < (-1) * (threshold)) {
        player1->moveX = 0;  //X-No Move  Y-Left
        player1->moveY = -1;
    }
    else {
        player1->moveX = 0;  //0100;                            //X-No Move Y-No Move
        player1->moveY = 0;
    }
}

if(digitalRead(2)==LOW){player1->UP=1;}
if(digitalRead(3)==LOW){player1->RIGHT=1;}
if(digitalRead(4)==LOW){player1->DOWN=1;}
if(digitalRead(5)==LOW){player1->LEFT=1;}

    
}
