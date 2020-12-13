typedef struct letter{
   int x;
   int y;
   color col; 
}letter;


void safeDraw(int x, int y, color Col) {
  if (x > 31 || x < 0) {
    return;
  }
  if (y > 31 || y < 0) {
    return;
  }
  draw(0, x, y, 0, 0, Col);

}


//x and y are the top left position of a 5*5 square of a letter
void drawA(letter letter_) {
  int x=letter_.x;
  int y=letter_.y;
  int Col=letter_.col;
  safeDraw(x, y + 1, Col);
  delay(1);
  safeDraw(x, y + 2, Col);
  delay(1);
  safeDraw(x, y + 3, Col);
  delay(1);
  safeDraw(x, y + 4, Col);
  delay(1);
  safeDraw(x + 1, y, Col);
  delay(1);
  safeDraw(x + 1, y + 2, Col);
  delay(1);
  safeDraw(x + 2, y, Col);
  delay(1);
  safeDraw(x + 2, y + 2, Col);
  delay(1);
  safeDraw(x + 3, y, Col);
  delay(1);
  safeDraw(x + 3, y + 2, Col);
  delay(1);
  safeDraw(x + 4, y + 1, Col);
  delay(1);
  safeDraw(x + 4, y + 2, Col);
  delay(1);
  safeDraw(x + 4, y + 3, Col);
  delay(1);
  safeDraw(x + 4, y + 4, Col);
  delay(1);
  //total delay 14

}

void drawG(letter letter_) {
  int x=letter_.x;
  int y=letter_.y;
  int Col=letter_.col;
  safeDraw(x, y + 1, Col);
  delay(1);
  safeDraw(x, y + 2, Col);
  delay(1);
  safeDraw(x, y + 3, Col);
  delay(1);
  safeDraw(x, y + 4, Col);
  delay(1);
  safeDraw(x + 1, y, Col);
  delay(1);
  safeDraw(x + 1, y + 4, Col);
  delay(1);
  safeDraw(x + 2, y, Col);
  delay(1);
  safeDraw(x + 2, y + 4, Col);
  delay(1);
  safeDraw(x + 3, y, Col);
  delay(1);
  safeDraw(x + 3, y + 2, Col);
  delay(1);
  safeDraw(x + 3, y + 4, Col);
  delay(1);
  safeDraw(x + 4, y + 2, Col);
  delay(1);
  safeDraw(x + 4, y + 3, Col);
  delay(1);
  safeDraw(x + 4, y + 4, Col);
  delay(1);

}

void drawI(letter letter_) {
  int x=letter_.x;
  int y=letter_.y;
  int Col=letter_.col;
  safeDraw(x + 1, y, Col);
  delay(1);
  safeDraw(x + 1, y + 4, Col);
  delay(1);
  safeDraw(x + 2, y, Col);
  delay(1);
  safeDraw(x + 2, y + 1, Col);
  delay(1);
  safeDraw(x + 2, y + 2, Col);
  delay(1);
  safeDraw(x + 2, y + 3, Col);
  delay(1);
  safeDraw(x + 2, y + 4, Col);
  delay(1);
  safeDraw(x + 3, y, Col);
  delay(1);
  safeDraw(x + 3, y + 4, Col);
  delay(1);
  delay(5);

}

void drawN(letter letter_) {
  int x=letter_.x;
  int y=letter_.y;
  int Col=letter_.col;
  safeDraw(x, y, Col);
  delay(1);
  safeDraw(x, y + 1, Col);
  delay(1);
  safeDraw(x, y + 2, Col);
  delay(1);
  safeDraw(x, y + 3, Col);
  delay(1);
  safeDraw(x, y + 4, Col);
  delay(1);
  safeDraw(x + 1, y + 1, Col);
  delay(1);
  safeDraw(x + 2, y + 2, Col);
  delay(1);
  safeDraw(x + 3, y + 3, Col);
  delay(1);
  safeDraw(x + 4, y, Col);
  delay(1);
  safeDraw(x + 4, y + 1, Col);
  delay(1);
  safeDraw(x + 4, y + 2, Col);
  delay(1);
  safeDraw(x + 4, y + 3, Col);
  delay(1);
  safeDraw(x + 4, y + 4, Col);
  delay(1);
  delay(1);
}

void drawBigRectangle(letter A,letter N){
   int x0=A.x-1;
   int y0=A.y-1;
   int x1=N.x+5;
   int y1=N.y+5;  
   
   for(int x=x0; x<=x1; x++){
      draw(0,x,y0,0,0,ColY);
      delay(20); 
   }
   for(int y=y0+1; y<=y1; y++){
      draw(0,x1,y,0,0,ColY);
      delay(20);
   }
   for(int x=x1-1; x>=x0; x--){
      draw(0,x,y1,0,0,ColY);
      delay(20); 
   }
   for(int y=y1-1; y>y0; y--){
      draw(0,x0,y,0,0,ColY);
      delay(20);
   }
   
}


void perform_player2_movement(player* player2){
 
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
  
}

void perform_player2_bottom_actions(player* player2, heavyBomb2* heavyBombList2){
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

}

void perform_player2_bomb_movement(player* player2,heavyBomb2* heavyBombList2, letter* A, letter* G, letter* A2, letter* I,letter* N){
  //heavy bomb movement//
  for (int i = 0; i < HEAVY_BOMB_NUM; i++){
      if (heavyBombList2[i].active == 1) {
          if(heavyBombList2[i].counter==0){
            //update bomb location
            heavyBombList2[i].y--;
            //bomb disappear if touch edge
            if (heavyBombList2[i].y <=7) {
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

    
            
           if(heavyBombList2[i].y <=7 && heavyBombList2[i].x >=6 && heavyBombList2[i].x <=12 && G->col!=10000 ){
                G->col=10000;
                drawG(*G);
            }


            if(heavyBombList2[i].y <=7 && heavyBombList2[i].x >=13 && heavyBombList2[i].x <=18 && A2->col!=10000 ){
                A2->col=10000;
                drawA(*A2);
            }
            
            if(heavyBombList2[i].y <=7 && heavyBombList2[i].x >=19 && heavyBombList2[i].x <=24 && I->col!=10000){
                I->col=10000;
                drawI(*I);
            }

            if(heavyBombList2[i].y <=7 && heavyBombList2[i].x >=25 && heavyBombList2[i].x <=30 && N->col!=10000){
                N->col=10000;
                drawN(*N);
            }
            
            heavyBombList2[i].counter=HEAVY_BOMB_COUNTER;
          }
          else{heavyBombList2[i].counter--;}

      }
  }
}



int retry(player* player1, player* player2, heavyBomb2* heavyBombList2) {
  player1->x=33;
  player1->y=33;
  reset();
  
  for (int i = 0; i < HEAVY_BOMB_NUM; i++) {
    heavyBombList2[i] = { -1, -1, 0};
  }
  
  letter A, G, A2, I, N;
  A={1,2,10000};
  G={7,2,20000};
  A2={13,2,60000};
  I={19,2,40000};
  N={25,2,50000};
  drawA(A);
  drawG(G);
  drawA(A2);
  drawI(I);
  drawN(N);
  *player2 = {15, 30, 0, 0, 0, 0, 0, 0, 3, 0, ColB, 0, 0, 0, 0, -99};
  draw(1,player2->x,player2->y,1,0,player2->mycolor);
  while(1){
      delay(5);
      counter_update(player1, player2);
      joysticksIO(player1, player2);  
      perform_player2_movement(player2);
      perform_player2_bottom_actions(player2, heavyBombList2);
      perform_player2_bomb_movement(player1,heavyBombList2, &A, &G, &A2, &I, &N);
      if(G.col==A.col && A2.col==A.col && I.col==A.col && N.col==A.col){break;}
  }
  
  drawBigRectangle(A,N);
  int counter=5;
  while(counter>0){
      counter--;
      A.col+=10000;
      G.col+=10000;
      A2.col+=10000;
      I.col+=10000;
      N.col+=10000;
      drawA(A);
      drawG(G);
      drawA(A2);
      drawI(I);
      drawN(N);
      delay(300);
    }
    reset();
    player1->HP=-99;
    player2->HP=-99;
   return 0;
  
}
