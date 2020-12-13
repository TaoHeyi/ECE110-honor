
////////////////////////////////////////////////////////////////////////////////////////////////////
//pixel 0
//circle 1
//rec   2
//line 3
//screen 4




void print_welcome_message(){
    reset();
   
    drawRec0(1,25,5,29,ColY);

    drawRec0(26,25,30,29,ColY);
    
    return;
}


void game_ready(player* player1, player* player2){
    //pin configuration
     pin_configuration();
    //initialize players
    *player1={15, 1, 0, 0, 0, 0, 0, 0, 3, 0,  ColR, 0, 0, 0, 0, -99};
    *player2 = {15, 30, 0, 0, 0, 0, 0, 0, 3, 0, ColB, 0, 0, 0, 0, -99};
    player1->BE_UP=BE_UP_MAX;
    player2->BE_UP=BE_UP_MAX;

  
   // Startup
    print_welcome_message();      
      int player1_is_ready=0;
      int player2_is_ready=0;
      int ship1 = 1;
      int ship2 = 0;
     #define counterTime 200
      int counter = 200;
      int8_t slitmove1 = 1;
      int8_t slitmove2 = 1;
      int8_t player1enable=0;
      int8_t player2enable =0;
      #define ShotColor 2016

      delay(1000);
      draw(1,10,ship1,1,0,ColR);
      draw(1,21,ship2,1,0,ColB);
      for(int i = 1; i < 16; i++){
          if(i<11){
          draw(1,10,ship1,1,0,0);
          draw(1,21,ship2,1,0,0);
          ship1 = ship1+1;
          ship2 = ship2+1;
          draw(1,10,ship1,1,0,ColR);
          draw(1,21,ship2,1,0,ColB);
          }
// Big Sense of Animation

                if ((i==6)||(i==15)){ draw(3,6,i,8,i,ShotColor); draw(3,12,i,14,i,ShotColor); 
                               draw(3,17,i,19,i,ShotColor); draw(3,23,i,25,i,ShotColor);    }
                       
                if (((i>6)&&(i<9))||((i>11)&&(i<15))){
                  draw(0,6,i,0,0,ShotColor); draw(0,14,i,0,0,ShotColor); draw(0,17,i,0,0,ShotColor); draw(0,25,i,0,0,ShotColor);}
                delay(50);
      }
//Loop 
    while(1){
      delay(1);
      counter--;
      if (counter == counterTime/2){
          draw(1,10,ship1,1,0,0);
          draw(1,21,ship2,1,0,0);
          ship1 = ship1+slitmove1;
          ship2 = ship2+slitmove2;
          draw(1,10,ship1,1,0,ColR);
          draw(1,21,ship2,1,0,ColB);
          slitmove1 = slitmove1 *(-1);
      }
       if (counter==0){
          draw(1,10,ship1,1,0,0);
          draw(1,21,ship2,1,0,0);
          ship1 = ship1+slitmove1;
          ship2 = ship2+slitmove2;
          draw(1,10,ship1,1,0,ColR);
          draw(1,21,ship2,1,0,ColB);
          slitmove2 = (-1)*slitmove2;
          counter = counterTime;
      } 
      joysticksIO(player1,player2);
      if(!player1_is_ready){
         if(player1->UP==1){
            drawRec1(2,26,4,28,ColR);
            player1enable =1;   
         }
      }
      if(!player2_is_ready){
         if(player2->UP==1){
            drawRec1(27,26,29,28,ColB);
            player2enable =1;
         }
      }
      //Detect and Fly Away Part
       if((player1enable)&&(ship1<34)){
                if(ship1==20){draw(5,6,6,10,10,0);}
            draw(1,10,ship1,1,0,0);
            ship1 ++;
            draw(1,10,ship1,1,0,ColR);  
            delay((34-ship1)*3);           
            if(ship1>=34){player1_is_ready=1;}     
        }     

          if((player2enable)&&(ship2<34)){
                if(ship2==20){draw(5,16,6,10,10,0);}
            draw(1,21,ship2,1,0,0);
            ship2 ++;
            draw(1,21,ship2,1,0,ColB);  
            if(ship2>=34){player2_is_ready=1;}
            delay((34-ship2)*3);                
        }     
      if(player1_is_ready && player2_is_ready){
        break;
      }
    }
   
    delay(1000);
}






void game_start(player player1, player player2){
    //TODO: INSERT YOUR CODE HERE
    delay(1000);
    reset();
    delay(100);
    draw(1,player1.x,player1.y,1,0,player1.mycolor);
    draw(1,player2.x,player2.y,1,0,player2.mycolor);
    for (int g = 3;g>0;g--){
        draw(3,0,15,31,15,ColR);
        draw(3,0,16,31,16,ColB);
        delay(500);
        draw(3,0,15,31,15,0);
        draw(3,0,16,31,16,0);
        delay(500);
    }
    draw(3,0,15,31,15,ColR);
    draw(3,0,16,31,16,ColB);
    delay(500);
    for (int i = 0;i<=31;i++){
        draw(0,(31-i),15,0,0,0);
        draw(0,i,16,0,0,0);
        delay((1/exp(i/4))*30);
    }
    
}




void game_player1_wins(player player1, player player2){
    //TODO: INSERT YOUR CODE HERE
    delay(5);
    draw(1,player2.x,player2.y,1,0,player2.mycolor);
    draw(1,player2.x,player2.y,2,0,player2.mycolor);
    delay(500);
    draw(1,player2.x,player2.y,3,0,player2.mycolor);
    delay(500);
    draw(1,player2.x,player2.y,1,0,0);
    int enable=0;
    int delaytime = 100;
    randomSeed(player2.x);
    int blow1x=random(0,31);
    int blow1y=random(16,31);
    int blow2x=random(0,31);
    int blow2y=random(16,31);
    
    draw(1,blow1x,blow1y,1,0,player2.mycolor+100);
    draw(1,blow2x,blow2y,1,0,player2.mycolor-100);
    
    for(int len=3;len<50;len++){
        //Main Blow
        draw(1,player2.x,player2.y,len,0,player2.mycolor);
        draw(1,player2.x,player2.y,len-1,0,0);
        // Sub Blow
        draw(1,blow1x,blow1y,len-1,0,player2.mycolor+100);
        draw(1,blow1x,blow1y,len-2,0,0);
        draw(1,blow2x,blow2y,len-1,0,player2.mycolor-100);
        draw(1,blow2x,blow2y,len-2,0,0);
        // Remain Red
        draw(1,player1.x,player1.y,1,0,player1.mycolor);
        delay(delaytime);
        //Faster
        if(1){delaytime = delaytime - 1;}
        //Blinking Part
        if((len%4 == 0) && (len<20)){  enable = 3; }
        if(enable>1){draw(1,player2.x,player2.y,1,0,player2.mycolor);   enable--;}
        if(enable == 1){draw(1,player2.x,player2.y,1,0,0); enable = 0; }
    }
    draw(1,player2.x,player2.y,1,0,0);
    int diffx = player1.x-16;
    int diffy = player1.y-16;
    while (diffx<0){
        draw(1,player1.x,player1.y,1,0,0);
        player1.x++;
        diffx++;
        draw(1,player1.x,player1.y,1,0,player1.mycolor);
        delay(50);
    }
    while(diffx>0){
        draw(1,player1.x,player1.y,1,0,0);
        player1.x--;
        diffx--;
        draw(1,player1.x,player1.y,1,0,player1.mycolor);
        delay(50);
    }
    while(diffy!=0){
        draw(1,player1.x,player1.y,1,0,0);
        player1.y++;
        diffy++;
        draw(1,player1.x,player1.y,1,0,player1.mycolor);
        delay(50);
    }
    int counter=8;
    while(counter>0){
        counter--;
        draw(0,player1.x-3,player1.y+4,0,0,player1.mycolor+128);
        draw(0,player1.x+4,player1.y-4,0,0,player1.mycolor-128);
        draw(0,player1.x+5,player1.y-3,0,0,player1.mycolor+128);
        draw(0,player1.x-5,player1.y-7,0,0,player1.mycolor+128);
        delay(200);
        draw(0,player1.x-3,player1.y+4,0,0,0);
        draw(0,player1.x+4,player1.y-4,0,0,0);
        draw(0,player1.x+5,player1.y-3,0,0,0);
        draw(0,player1.x-5,player1.y-7,0,0,0);
        delay(200);
    }
    
}

void game_player2_wins(player player1, player player2){
    delay(5);
    draw(1,player1.x,player1.y,1,0,player1.mycolor);
    draw(1,player1.x,player1.y,2,0,player1.mycolor);
    delay(500);
    draw(1,player1.x,player1.y,3,0,player1.mycolor);
    delay(500);
    draw(1,player1.x,player1.y,1,0,0);
    int enable=0;
    int delaytime = 100;
    randomSeed(player1.x);
    int blow1x=random(0,31);
    int blow1y=random(16,31);
    int blow2x=random(0,31);
    int blow2y=random(16,31);
    
    draw(1,blow1x,blow1y,1,0,player1.mycolor+100);
    draw(1,blow2x,blow2y,1,0,player1.mycolor-100);
    
    for(int len=3;len<50;len++){
        //Main Blow
        draw(1,player1.x,player1.y,len,0,player1.mycolor);
        draw(1,player1.x,player1.y,len-1,0,0);
        // Sub Blow
        draw(1,blow1x,blow1y,len-1,0,player1.mycolor+100);
        draw(1,blow1x,blow1y,len-2,0,0);
        draw(1,blow2x,blow2y,len-1,0,player1.mycolor-100);
        draw(1,blow2x,blow2y,len-2,0,0);
        // Remain Red
        draw(1,player2.x,player2.y,1,0,player2.mycolor);
        delay(delaytime);
        //Faster
        if(1){delaytime = delaytime - 1;}
        //Blinking Part
        if((len%4 == 0) && (len<20)){  enable = 3; }
        if(enable>1){draw(1,player1.x,player1.y,1,0,player1.mycolor);   enable--;}
        if(enable == 1){draw(1,player1.x,player1.y,1,0,0); enable = 0; }
    }
    draw(1,player1.x,player1.y,1,0,0);
    int diffx = player2.x-16;
    int diffy = player2.y-16;
    while (diffx<0){
        draw(1,player2.x,player2.y,1,0,0);
        player2.x++;
        diffx++;
        draw(1,player2.x,player2.y,1,0,player2.mycolor);
        delay(50);
    }
    while(diffx>0){
        draw(1,player2.x,player2.y,1,0,0);
        player2.x--;
        diffx--;
        draw(1,player2.x,player2.y,1,0,player2.mycolor);
        delay(50);
    }
    while(diffy!=0){
        draw(1,player2.x,player2.y,1,0,0);
        player2.y--;
        diffy--;
        draw(1,player2.x,player2.y,1,0,player2.mycolor);
        delay(50);
    }

    int counter=8;
    while(counter>0){
        counter--;
        draw(0,player2.x-3,player2.y+4,0,0,player2.mycolor+128);
        draw(0,player2.x+4,player2.y-4,0,0,player2.mycolor-128);
        draw(0,player2.x+5,player2.y-3,0,0,player2.mycolor+128);
        draw(0,player2.x-5,player2.y-7,0,0,player2.mycolor+128);
        delay(200);
        draw(0,player2.x-3,player2.y+4,0,0,0);
        draw(0,player2.x+4,player2.y-4,0,0,0);
        draw(0,player2.x+5,player2.y-3,0,0,0);
        draw(0,player2.x-5,player2.y-7,0,0,0);
        delay(200);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////
