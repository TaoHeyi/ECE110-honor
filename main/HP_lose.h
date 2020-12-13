


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int if_player1_shot_heavy (player* player1, player* player2, heavyBomb2* heavyBomb){
    if(heavyBomb->active==0){return 0;}
    if(player1->HP_LOSE!=0){return 0;}
    if(abs(player1->x-heavyBomb->x)<=2){
        if(player1->y-heavyBomb->y==-1){
          player1->HP_LOSE=INVINCIBLE_FRAME;
          player1->HP--; 
          heavyBomb->active=0;
          draw(1,heavyBomb->x,heavyBomb->y+1,1,0,ColD);  
          player2->heavy_usage--;
          digitalWrite(11, HIGH);
          delayMicroseconds(50);
          return 1;
        }
    }
    else{return 0;}
    
}

int if_player2_shot_heavy (player* player2, player* player1,heavyBomb1* heavyBomb){
    if(heavyBomb->active==0){return 0;}
     if(player2->HP_LOSE!=0){return 0;}
    if(abs(player2->x-heavyBomb->x)<=2){
        if(player2->y-heavyBomb->y==1){
          player2->HP_LOSE=INVINCIBLE_FRAME;
          player2->HP--;
          heavyBomb->active=0;
          draw(1,heavyBomb->x,heavyBomb->y-1,1,0,ColD); 
          player1->heavy_usage--;
          digitalWrite(12,HIGH);
          delayMicroseconds(50);
          return 1;
          }
    }
    else{return 0;}
}


int if_player1_shot_light (player* player1, player* player2, lightBomb2* lightBomb){
    if(lightBomb->active==0){return 0;}
     if(player1->HP_LOSE!=0){return 0;}
    if(abs(player1->x-lightBomb->x)<=1){
        if(player1->y-lightBomb->y==-1){
            player1->HP_LOSE = INVINCIBLE_FRAME;
            player1->HP--;
            lightBomb->active=0;
            draw(0,lightBomb->x,lightBomb->y,0,0,ColD);
            player2->light_usage--;
           digitalWrite(11,HIGH);
           delayMicroseconds(50);
            return 1;
        }
    }
    else{return 0;}
}


int if_player2_shot_light (player* player2, player* player1, lightBomb1* lightBomb){
    if(lightBomb->active==0){return 0;}
     if(player2->HP_LOSE!=0){return 0;}
    if(abs(player2->x-lightBomb->x)<=1){
        if(player2->y-lightBomb->y==1){
            player2->HP_LOSE = INVINCIBLE_FRAME;
            player2->HP--;
            lightBomb->active=0;
            draw(0,lightBomb->x,lightBomb->y,0,0,ColD);
            player1->light_usage--;
           digitalWrite(12,HIGH);
           delayMicroseconds(50);
            return 1;
        }
    }
    else{return 0;}
}

int if_player1_thunder(player* player1, player* player2){
   if(player1->HP_LOSE!=0){return 0;}
    if(abs(player1->x-player2->r)<=2){
         player1->HP_LOSE = INVINCIBLE_FRAME;
        player1->HP--;
        digitalWrite(11,HIGH);
        return 1;
    }
    return 0;
}

int if_player2_thunder(player* player1, player* player2){
   if(player2->HP_LOSE!=0){return 0;}
    if(abs(player2->x-player1->r)<=2){
        player2->HP_LOSE = INVINCIBLE_FRAME;
        player2->HP--;
        digitalWrite(12,HIGH);
        return 1;
    }
    return 0;
}

//generate a int between 1 and 31
int randomGenerator(){
    
    int r = 1+rand()%30;
    return r;
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
