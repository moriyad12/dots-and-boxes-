#include <stdio.h>

#include <string.h>

#include <math.h>

#include <stdlib.h>

#include <time.h>


#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define MAG "\x1B[35m"
#define BLU "\x1B[34m"
#include "game_movements.h"
#include "time.h"
#include "sort.h"
#include "print.h"
#include "undo_redo.h"
#include "playing_c.h"
#include "making_grid.h"
#include "start_game.h"
#include "the_game.h"

extern int n;
extern int b;
extern time_t t1;
extern char game[5][5] , game_[11][11] ;

extern struct top {
  char name[20];
  int scoore;
};
struct top top10[10];


void the_game(){
system("cls");
  printf(KRED "                                           Dots & boxes Game\n");
  printf(KGRN "                                           To start game press 0\n                                           To load game press 1\n");
  printf("                                           To see top 10 players press 2\n                                           To exit press 3\n"
    KNRM);
  int x;
  scanf("%d", & x);
  while (1) {
    if (x > -1 && x < 4)
      break;
    else {
      printf("Invalid value\n");
      scanf("%d", & x);
    }
  }
  if (x == 0)
    start_game();
  else if (x == 1) {

    printf(BLU "File 1 press 1\t File 2 press 2\t File 3 press 3\n");
    int file_num;
    scanf("%d", & file_num);
    load(file_num);
    printf("%d", n);
    if (b == 0) {
      if (n == 5) { t1=time(0);
        print(n, game);
        playing(n, game);
      } else {t1=time(0);
        print(n, game_);
        playing(n, game_);
      }
    } else {
      if (n == 5) {t1=time(0);
        print(n, game);
        playing_c(n, game);
      } else {t1=time(0);
        print(n, game_);

        playing_c(n, game_);
      }
    }

  } else  if(x==2) {
    loadtop();
    printf(MAG "top 10\n");
    for (int i = 0; i < 10; i++) {
      printf("%s %d\n", top10[i].name, top10[i].scoore);
    }
  }
}
