

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//bomblist initialization
void bombList_init(heavyBomb1* heavyBombList1, heavyBomb2* heavyBombList2, lightBomb1* lightBombList1, lightBomb2* lightBombList2){
  for (int i = 0; i < HEAVY_BOMB_NUM; i++) {
    heavyBombList1[i] = {32, 32, 0};
    heavyBombList2[i] = { -1, -1, 0};
  }
  for (int i = 0; i < LIGHT_BOMB_NUM; i++) {
    lightBombList1[i] = {32, 32, 0};
    lightBombList2[i] = { -1, -1, 0};
  } 
}

//update counter (maybe trigger thunder hurt)
void counter_update(player* player1, player* player2){
  //All Counter Process
  if (player1->BE_UP != 0) {
    player1->BE_UP--;
  }
  if (player2->BE_UP != 0) {
    player2->BE_UP--;
  }
  if (player1->BE_RIGHT != 0) {
    player1->BE_RIGHT--;
  }
  if (player2->BE_RIGHT != 0) {
    player2->BE_RIGHT--;
  }
  if (player1->BE_LEFT != 0) {
    player1->BE_LEFT--;
  }
  if (player2->BE_LEFT != 0){
    player2->BE_LEFT--;
  }
  if (player1->BE_DOWN != 0) {
    player1->BE_DOWN--;
    if(player1->BE_DOWN == BE_DOWN_MAX/2){
      player1->mycolor=ColR;
      player1->HP_LOSE=0;
      draw(1,player1->x,player1->y,1,0,player1->mycolor);
    }
  }
  if (player2->BE_DOWN != 0){
    player2->BE_DOWN--;
    if(player2->BE_DOWN == BE_DOWN_MAX/2){
      player2->mycolor=ColB;
      player2->HP_LOSE=0;
      draw(1,player2->x,player2->y,1,0,player2->mycolor);
    }
  }

  if (player1->HP_LOSE != 0 && player1->HP_LOSE<1000) {
    player1->HP_LOSE--;
    draw(1,player1->x,player1->y,1,0,ColD);
    draw(1,player1->x,player1->y,1,0,player1->mycolor);
   
  }
  if (player2->HP_LOSE != 0 && player2->HP_LOSE<1000) {
    player2->HP_LOSE--;
    draw(1,player2->x,player2->y,1,0,ColD);
    draw(1,player2->x,player2->y,1,0,player2->mycolor);
  }
  if(player1->thunder_counter!=0){
    if(player1->thunder_counter>50){player1->thunder_counter-=2;}
    if(player1->thunder_counter<=50) {
       if(player1->thunder_counter==20){ 
           draw(3,player1->r-1,31,player1->r+1,16,ColD);      
        }
        if(player1->thunder_counter==50){
           draw(3,player1->r-1,31,player1->r+1,16,ColY);
           //thunder: HP decrement
           if_player2_thunder(player1, player2);
               
        }
        player1->thunder_counter-=2;
    }
  }
  if(player2->thunder_counter!=0){
    if(player2->thunder_counter>50){player2->thunder_counter-=2;}
    if(player2->thunder_counter<=50) {
       if(player2->thunder_counter==20){
          draw(3,player2->r-1,0,player2->r+1,16,ColD);
       }
       if(player2->thunder_counter==50){
          draw(3,player2->r-1,0,player2->r+1,16,ColG);
          //thunder: HP decrement
          if_player1_thunder(player1, player2);
    
          
      }
      player2->thunder_counter-=2;
    }   
  }
}
