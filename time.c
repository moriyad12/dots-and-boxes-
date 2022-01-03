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
#include "playing.h"
#include "making_grid.h"
#include "start_game.h"
#include "the_game.h"



time_t t1;
char q ;


void time_dif() {
  time_t t2 = time(0);
  time_t p, o;
  p = t2 - t1;
  o = (t2 - t1) / 60;
  p = p % 60;
  printf(MAG "The time %d : %d\n"
    KNRM, (int) o, (int) p);

}
