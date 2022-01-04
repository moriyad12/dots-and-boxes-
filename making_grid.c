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


extern int continuing;
extern int m_a , m_b ;
extern int score_a , score_b , checker ;
extern char q ;
extern int b;
extern int n;
extern int p;
extern int u ;
extern int score;
extern time_t t1;

extern struct movements {
  char player;
  int row_1;
  int row_2;
  int column_1;
  int column_2;
  char movement;
};
struct movements game_movements[60];

extern struct top {
  char name[20];
  int scoore;
};
struct top top10[10];





void making_grid(int m) {
  int n;
  n = 2 * m + 1;
  char game[n][n];
  for (int i = 0; i < n; i = i + 2) {
    for (int j = 0; j < n; j = j + 2) {
      game[i][j] = 254;
    }
  }
  for (int i = 0; i < n; i = i + 2) {
    for (int j = 1; j < n; j = j + 2)
      game[i][j] = '\0';
  }
  for (int i = 1; i < n; i = i + 2) {
    for (int j = 0; j < n; j++)
      game[i][j] = '\0';
  }
  system("cls");
  printf(BLU "                                           Player vs player press 0\n                                           Player vs computer press 1\n"
    KNRM);
  scanf("%d", & b);
  while (1) {
    if (b == 0 || b == 1)
      break;
    else
      printf(BLU "Not valid value\n"
        KNRM);
    scanf("%d", & b);
  }
  t1 = time(0);
  print(n, game);
  if (b == 0) {
    playing(n, game);
  } else {
    playing_c(n, game);
  }
  return;
}
