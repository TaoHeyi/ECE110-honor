

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perform_bottom_actions(player* player1, player* player2, heavyBomb1* heavyBombList1, heavyBomb2* heavyBombList2, lightBomb1* lightBombList1, lightBomb2* lightBombList2){
  //player 1 bottom
  //UP
  if (player1->UP==1 && (!player1->BE_UP)
      && player1->heavy_usage < HEAVY_BOMB_NUM)
  {
    
    for(int i=0; i<HEAVY_BOMB_NUM;i++){
        if(heavyBombList1[i].active==0){
              heavyBombList1[i] = {player1->x, player1->y + 3, 1,0};
              player1->BE_UP = BE_UP_MAX;
              player1->heavy_usage++; 
              break;
        }    
    }

  }

  //RIGHT
  if (player1->RIGHT==1 && (!player1->BE_RIGHT)
      && player1->light_usage < LIGHT_BOMB_NUM)
  {
    for(int i=0; i<LIGHT_BOMB_NUM;i++){
        if(lightBombList1[i].active==0){
              lightBombList1[i] = {player1->x, player1->y + 2, 1,0};
              player1->BE_RIGHT = BE_RIGHT_MAX;
              player1->light_usage++; 
              break;
        }    
    }
  }

  //LEFT
  if (player1->LEFT==1 && (!player1->BE_LEFT))
  {  
     //feed random num generator
     srand(player1->x*player2->y-player1->y+player2->x);
     player1->r=randomGenerator();
     player1->BE_LEFT=BE_LEFT_MAX;
     player1->thunder_counter=thunder_counter_max;   
  }
  
  //DOWN
  if (player1->DOWN==1 && (!player1->BE_DOWN))
  {  
     player1->BE_DOWN=BE_DOWN_MAX;
     player1->mycolor=64000; 
     player1->HP_LOSE=5000;
  }

  //player 2 bottom
  //UP
  if (player2->UP == 1 && (!player2->BE_UP)
      && player2->heavy_usage < HEAVY_BOMB_NUM)
  {
    for(int i=0; i<HEAVY_BOMB_NUM;i++){
        if(heavyBombList2[i].active==0){
              heavyBombList2[i] = {player2->x, player2->y - 3, 1,0};
              player2->BE_UP = BE_UP_MAX;
              player2->heavy_usage++; 
              break;
        }    
    }
  }

  //RIGHT
  if (player2->RIGHT == 1 && (!player2->BE_RIGHT)
      && player2->light_usage < LIGHT_BOMB_NUM)
  {
    for(int i=0; i<LIGHT_BOMB_NUM;i++){
        if(lightBombList2[i].active==0){
              lightBombList2[i] = {player2->x, player2->y - 2, 1,0};
              player2->BE_RIGHT = BE_RIGHT_MAX;
              player2->light_usage++; 
              break;
        }    
    }
  }

  //LEFT
  if (player2->LEFT == 1 &&(!player2->BE_LEFT)) {
     srand(player1->x*player2->y-player1->y+player2->x);
     player2->r=randomGenerator();
     player2->BE_LEFT=BE_LEFT_MAX;
     player2->thunder_counter=thunder_counter_max; 

  }     
     
  
  //DOWN
  if (player2->DOWN==1 && (!player2->BE_DOWN))
  {  
     player2->BE_DOWN=BE_DOWN_MAX;
     player2->mycolor=650;
     player2->HP_LOSE=5000;
  }
}


void perform_player_movement(player* player1, player* player2,int* player1_counter){
  if(*player1_counter==0){
  //player 1 movement
  if ((player1->moveX == -1) && (player1->x < 30)) {
    draw(1, player1->x, player1->y, 1, 0, ColD);
    player1->x++;
    draw(1, player1->x, player1->y, 1, 0, player1->mycolor);
  }
  if ((player1->moveX == 1) && (player1->x > 1)) {
    draw(1, player1->x, player1->y, 1, 0, ColD);
    player1->x--;
    draw(1, player1->x, player1->y, 1, 0, player1->mycolor);
  }
  if ((player1->moveY == 1) && (player1->y < 14)) {
    draw(1, player1->x, player1->y, 1, 0, ColD);
    player1->y++;
    draw(1, player1->x, player1->y, 1, 0, player1->mycolor);
  }
  if ((player1->moveY == -1) && (player1->y > 1)) {
    draw(1, player1->x, player1->y, 1, 0, ColD);
    player1->y--;
    draw(1, player1->x, player1->y, 1, 0, player1->mycolor);
  }
  *player1_counter=PLAYER1_COUNTER_MAX;
  }
  //player 2 movement
  if ((player2->moveX == 1) && (player2->x < 30)) {
    draw(1, player2->x, player2->y, 1, 0, ColD);
    player2->x++;
    draw(1, player2->x, player2->y, 1, 0, player2->mycolor);
  }
  if ((player2->moveX == -1) && (player2->x > 1)) {
    draw(1, player2->x, player2->y, 1, 0, ColD);
    player2->x--;
    draw(1, player2->x, player2->y, 1, 0, player2->mycolor);
  }
  if ((player2->moveY == -1) && (player2->y < 30)) {
    draw(1, player2->x, player2->y, 1, 0, ColD);
    player2->y++;
    draw(1, player2->x, player2->y, 1, 0, player2->mycolor);
  }
  if ((player2->moveY == 1) && (player2->y > 17)) {
    draw(1, player2->x, player2->y, 1, 0, ColD);
    player2->y--;
    draw(1, player2->x, player2->y, 1, 0, player2->mycolor);
  }
  
}


void perform_bomb_movement(player* player1, player* player2, heavyBomb1* heavyBombList1, heavyBomb2* heavyBombList2, lightBomb1* lightBombList1, lightBomb2* lightBombList2){
  
  //heavy bomb movement & HP decrement//
  for (int i = 0; i < HEAVY_BOMB_NUM; i++){
      if (heavyBombList1[i].active == 1) {
         if(heavyBombList1[i].counter==0){
            //update bomb location
            heavyBombList1[i].y++;
            //bomb disappear if touch edge
            if (heavyBombList1[i].y > 32) {
              heavyBombList1[i].active = 0;
              player1->heavy_usage--;
            }
            //draw bomb
            else {
              draw(0, heavyBombList1[i].x, heavyBombList1[i].y, 0, 0, ColY);
              draw(3, heavyBombList1[i].x - 1, heavyBombList1[i].y - 1, heavyBombList1[i].x + 1, heavyBombList1[i].y - 1, ColY);
            }
            //clear bomb trace
            draw(0, heavyBombList1[i].x, heavyBombList1[i].y - 1, 0, 0, ColD);
            draw(3, heavyBombList1[i].x - 1, heavyBombList1[i].y - 2, heavyBombList1[i].x + 1, heavyBombList1[i].y - 2, ColD);
            
            if_player2_shot_heavy(player2, player1,heavyBombList1+i);
              
            heavyBombList1[i].counter=HEAVY_BOMB_COUNTER;
         }
         else{heavyBombList1[i].counter--;}
      }
  
      if (heavyBombList2[i].active == 1) {
          if(heavyBombList2[i].counter==0){
            //update bomb location
            heavyBombList2[i].y--;
            //bomb disappear if touch edge
            if (heavyBombList2[i].y < 0) {
              heavyBombList2[i].active = 0;
              player2->heavy_usage--;
            }
            //draw bomb
            else {
              draw(0, heavyBombList2[i].x, heavyBombList2[i].y, 0, 0, ColG);
              draw(3, heavyBombList2[i].x - 1, heavyBombList2[i].y + 1, heavyBombList2[i].x + 1, heavyBombList2[i].y + 1, ColG);
            }
            //clear bomb trace
            draw(0, heavyBombList2[i].x, heavyBombList2[i].y + 1, 0, 0, ColD);
            draw(3, heavyBombList2[i].x - 1, heavyBombList2[i].y + 2, heavyBombList2[i].x + 1, heavyBombList2[i].y + 2, ColD);
      
           if_player1_shot_heavy(player1, player2,heavyBombList2+i);
    
            heavyBombList2[i].counter=HEAVY_BOMB_COUNTER;
          }
          else{heavyBombList2[i].counter--;}

      }
  }


  //light bomb movement & HP decrement//
  for (int i = 0; i < LIGHT_BOMB_NUM; i++)
  {
    if (lightBombList1[i].active == 1) {
      if(lightBombList1[i].counter==0){
          //update bomb location
          lightBombList1[i].y++;
          //bomb disappear if touch edge
          if (lightBombList1[i].y > 32) {
            lightBombList1[i].active = 0;
            player1->light_usage--;
          }
          //draw bomb
          else {
            draw(0, lightBombList1[i].x, lightBombList1[i].y, 0, 0, ColY);
          }
          //clear bomb trace
          draw(0, lightBombList1[i].x, lightBombList1[i].y - 1, 0, 0, ColD);
    
            if_player2_shot_light(player2, player1,lightBombList1+i);
           
          lightBombList1[i].counter=LIGHT_BOMB_COUNTER;
      }
      else{lightBombList1[i].counter--;}

    }
    if (lightBombList2[i].active == 1) {
       if(lightBombList2[i].counter==0){
          //update bomb location
          lightBombList2[i].y--;
          //bomb disappear if touch edge
          if (lightBombList2[i].y < 0) {
            lightBombList2[i].active = 0;
            player2->light_usage--;
          }
          //draw bomb
          else {
            draw(0, lightBombList2[i].x, lightBombList2[i].y, 0, 0, ColG);
          }
          //clear bomb trace
          draw(0, lightBombList2[i].x, lightBombList2[i].y + 1, 0, 0, ColD);
    
          if_player1_shot_light(player1, player2,lightBombList2+i);
  
          lightBombList2[i].counter=LIGHT_BOMB_COUNTER;
       }
       else{lightBombList2[i].counter--;}
    }

  }
    
}
