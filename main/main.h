

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//define color
typedef uint16_t color;

//define player
typedef struct{
    int x;       //x position
    int y;       //y position
    int moveX;   //x movement
    int moveY;   //y movement
    int UP;      //UP bottom
    int LEFT;    //LEFT bottom
    int RIGHT;   //RIGHT bottom
    int DOWN;    //DOWN bottom
    int HP;      
    int HP_LOSE;     
    color mycolor;  
    int BE_UP;      //bottom UP enable  
    int BE_RIGHT;    //bottom RIGHT enable
    int BE_LEFT;     //bottom LEFT enable
    int BE_DOWN;     //bottom DOWN enable
    int heavy_usage;
    int light_usage;
    double thunder_counter;
    int r;                  //thunder position
}player;

//define bomb
typedef struct{
  int x;
  int y;
  int active;
  int counter;
}heavyBomb1;

typedef struct{
  int x;
  int y;
  int active; 
  int counter; 
}heavyBomb2;

typedef struct{
  int x;
  int y;
  int active;
  int counter;
}lightBomb1;

typedef struct{
  int x;
  int y;
  int active;  
  int counter;
}lightBomb2;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//pixel 0
//circle 1
//rec   2
//line 3
//screen 4

void draw (uint8_t T, uint8_t X, uint8_t Y, uint8_t SizeX, uint8_t SizeY, uint16_t Col){
    int delaytime = 200;   //Total Time = delay*8
  
    Serial.write(254);
    Serial.write(X);
    Serial.write(Y);
    Serial.write(SizeX);
    Serial.write(SizeY);
    Serial.write(Col/256);
    Serial.write(Col%256);
    Serial.write(T);
    delayMicroseconds(delaytime);

}

void drawRec0(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint16_t Col){
  for(int xx=X1;xx<=X2;xx++){
      draw(0,xx,Y1,0,0,Col);  
  }
  for(int yy=Y1+1;yy<=Y2;yy++){
      draw(0,X2,yy,0,0,Col);
  }
  for(int xx=X2-1;xx>=X1;xx--){
      draw(0,xx,Y2,0,0,Col);  
  }
  for(int yy=Y2-1;yy>Y1;yy--){
      draw(0,X1,yy,0,0,Col);
  }
}

void drawRec1(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint16_t Col){
  if(X1>X2 || Y1>Y2){return;}
  else{
     drawRec0(X1,Y1,X2,Y2,Col);
     drawRec1(X1+1,Y1+1,X2-1,Y2-1,Col);
  }
  
}



void reset(){
    draw(4, 0,0,0,0,ColD);
    
}


//Ram Uesage
#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else // __ARM__
extern char *__brkval;
#endif // __arm__

int freeMemory() {
char top;
#ifdef __arm__
return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
return &top - __brkval;
#else // __arm__
return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif // __arm__
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//unused
/*
void game_player1_wins(player player1, player player2){
    //TODO: INSERT YOUR CODE HERE
    
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    for(a=23;a<=31;a++)
    {
        draw(0,31,a,0,0,ColR);
    }
    draw(0,30,31,0,0,ColR);
    draw(0,29,30,0,0,ColR);
    draw(0,28,29,0,0,ColR);
    draw(0,29,28,0,0,ColR);
    draw(0,30,27,0,0,ColR);
    draw(0,27,30,0,0,ColR);
    draw(0,26,31,0,0,ColR);
    draw(0,25,31,0,0,ColR);
    for(b=25;b<=31;b++)
    {
        draw(0,25,b,0,0,ColR);
    }
    for(b=25;b<=31;b++)
    {
        draw(0,25,b,0,0,ColR);
    }
    for(c=27;c<=23;c++)
    {
        draw(0,c,25,0,0,ColR);
    }
    for(d=29;d<=31;d++)
    {
        draw(0,21,d,0,0,ColR);
    }
    draw(0,20,28,0,0,ColR);
    draw(0,20,27,0,0,ColR);
    draw(0,19,26,0,0,ColR);
    draw(0,19,25,0,0,ColR);
    for(e=26;e<=28;e++)
    {
        draw(0,18,d,0,0,ColR);
    }
    for(f=26;f<=28;f++)
    {
        draw(0,17,f,0,0,ColR);
    }
    draw(0,16,26,0,0,ColR);
    draw(0,16,25,0,0,ColR);
    draw(0,15,27,0,0,ColR);
    draw(0,15,28,0,0,ColR);
    for(g=29;g<=31;g++)
    {
        draw(0,13,g,0,0,ColR);
    }
    for(h=8;h<=12;h++)
    {
        draw(0,h,31,0,0,ColR);
    }
    for(i=25;i<=31;i++)
    {
        draw(0,10,i,0,0,ColR);
    }
    for(h=8;h<=12;h++)
    {
        draw(0,h,25,0,0,ColR);
    }
    for(j=25;j<=31;j++)
    {
        draw(0,6,j,0,0,ColR);
    }
    for(k=25;k<=31;k++)
    {
        draw(0,2,k,0,0,ColR);
    }
    draw(0,5,30,0,0,ColR);
    draw(0,4,29,0,0,ColR);
    draw(0,4,28,0,0,ColR);
    draw(0,4,27,0,0,ColR);
    draw(0,3,26,0,0,ColR);
    
}

void game_player2_wins(player player1, player player2){
    //TODO: INSERT YOUR CODE HERE
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    for(a=0;a<=6;a++)
    {
        draw(0,0,a,0,0,ColB);
    }
    draw(0,1,0,0,0,ColB);
    draw(0,2,1,0,0,ColB);
    draw(0,3,2,0,0,ColB);
    draw(0,2,3,0,0,ColB);
    draw(0,1,4,0,0,ColB);
    draw(0,4,1,0,0,ColB);
    draw(0,5,0,0,0,ColB);
    draw(0,6,0,0,0,ColB);
    draw(0,7,0,0,0,ColB);
    draw(0,8,1,0,0,ColB);
    draw(0,8,2,0,0,ColB);
    draw(0,7,3,0,0,ColB);
    draw(0,6,4,0,0,ColB);
    draw(0,5,4,0,0,ColB);
    draw(0,4,5,0,0,ColB);
    draw(0,4,6,0,0,ColB);
    for(b=5;b<=8;b++)
    {
        draw(0,b,6,0,0,ColB);
    }
    draw(0,10,0,0,0,ColB);
    draw(0,10,1,0,0,ColB);
    draw(0,10,2,0,0,ColB);
    draw(0,11,3,0,0,ColB);
    draw(0,11,4,0,0,ColB);
    draw(0,12,5,0,0,ColB);
    draw(0,12,6,0,0,ColB);
    for(c=3;c<=5;c++)
    {
        draw(0,13,c,0,0,ColB);
    }
    for(d=3;d<=5;d++)
    {
        draw(0,14,d,0,0,ColB);
    }
    draw(0,15,5,0,0,ColB);
    draw(0,15,6,0,0,ColB);
    draw(0,16,3,0,0,ColB);
    draw(0,16,4,0,0,ColB);
    for(e=0;e<=2;e++)
    {
        draw(0,17,e,0,0,ColB);
    }
    for(f=19;f<=23;f++)
    {
        draw(0,f,0,0,0,ColB);
    }
    for(g=0;g<=6;f++)
    {
        draw(0,21,g,0,0,ColB);
    }
    for(h=19;h<=24;h++)
    {
        draw(0,h,6,0,0,ColB);
    }
    for(i=0;i<=6;f++)
    {
        draw(0,25,i,0,0,ColB);
    }
    for(j=0;j<=6;j++)
    {
        draw(0,29,0,0,0,ColB);
    }
    draw(0,26,1,0,0,ColB);
    draw(0,27,2,0,0,ColB);
    draw(0,27,3,0,0,ColB);
    draw(0,27,4,0,0,ColB);
    draw(0,28,5,0,0,ColB);
    
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////

             
