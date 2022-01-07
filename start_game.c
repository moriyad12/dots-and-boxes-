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




void start_game() {
  int x, m, y = 1;
  system("cls");
  printf(KRED "                                           begginer press 0\n                                           expert press1\n"
    KNRM);
  scanf("%d", & x);
  while (1) {
    if (x > -1 && x < 2) {
      y = 0;
      if (x == 0)
        m = 2;
      if (x == 1)
        m = 5;
      break;
    } else {
      printf("invalid value\n");
      scanf("%d", & x);
    }
  }
  making_grid(m);
}
