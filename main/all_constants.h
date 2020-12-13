#include <stdlib.h>
#include <time.h>

#define ColW 65535 //white
#define ColR 63488 //red
#define ColG 2016 //green
#define ColB 31 //blue
#define ColD 0 //dark
#define ColY 38020 //yellow

#define INVINCIBLE_FRAME 50

//define heavy and light bomb capacity
#define HEAVY_BOMB_NUM 2
#define LIGHT_BOMB_NUM 5

//define heavy and light bomb speed
#define HEAVY_BOMB_COUNTER 7
#define LIGHT_BOMB_COUNTER 4

//define bottom enable counter upper bound: leaving time for actions
//bottom enable: 0 means active
#define BE_UP_MAX 50
#define BE_RIGHT_MAX 30
#define BE_LEFT_MAX 500
#define BE_DOWN_MAX 2000

//INVINCIBLE_FRAME period after shot
#define INVINCIBLE_FRAME 50

//thunder counter
#define thunder_counter_max 100;

//player1 movement counter
#define PLAYER1_COUNTER_MAX 5;
