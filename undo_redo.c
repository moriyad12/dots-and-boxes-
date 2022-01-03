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


extern int continuing;
extern int m_a , m_b ;
extern int score_a , score_b , checker ;
extern char q ;
extern int b;
extern int n;
extern int p;
extern int u ;
extern int score;

extern struct movements {
  char player;
  int row_1;
  int row_2;
  int column_1;
  int column_2;
  char movement;
};
struct movements game_movements[60];


void undo(int n, char a[n][n])

{
  if (game_movements[continuing - 1].player == 'a')
    m_a--;
  else
    m_b--;

  a[game_movements[continuing - 1].row_1 + game_movements[continuing - 1].row_2 - 2][game_movements[continuing - 1].column_1 + game_movements[continuing - 1].column_2 - 2] = '\0';
  q = game_movements[continuing - 1].player;

  continuing--;
  p = u;
  u = 0;

  for (int i = 0; i <= n - 2; i = i + 2) {
    for (int j = 1; j <= n - 1; j = j + 2) {
      if (a[i][j] ==(char) 196 && a[i + 2][j] == (char)196) {
        if (a[i + 1][j - 1] == '|' && a[i + 1][j + 1] == '|') {
          u++;
          if (a[i + 1][j] != 'a' && a[i + 1][j] != 'b') {
            a[i + 1][j] = q;
          }

        } else a[i + 1][j] = '\0';
      } else a[i + 1][j] = '\0';
    }
  }
  if (q == 'a') {
    score_a += u - p;
    score += u - p;
  } else {
    score_b += u - p;
    score += u - p;
  }
  print(n, a);
}
void redo(int n, char a[n][n])

{
  if (q == 'a')
    m_a++;
  else m_b++;
  a[game_movements[continuing].row_1 + game_movements[continuing].row_2 - 2][game_movements[continuing].column_1 + game_movements[continuing].column_2 - 2] = game_movements[continuing].movement;
  q = game_movements[continuing + 1].player;
  continuing++;
  p = u;
  u = 0;
  for (int i = 0; i <= n - 2; i = i + 2) {
    for (int j = 1; j <= n - 1; j = j + 2) {
      if (a[i][j] ==(char) 196 && a[i + 2][j] ==(char) 196) {
        if (a[i + 1][j - 1] == '|' && a[i + 1][j + 1] == '|') {
          u++;
          if (a[i + 1][j] != 'a' && a[i + 1][j] != 'b') {
            a[i + 1][j] = q;
          }
        }
      } else a[i + 1][j] = '\0';
    }
  }
  if (q == 'a') {
    score_a += u - p;
        score += u - p;


  } else {
    score_b += u - p;
        score += u - p;

  }
  print(n, a);

  return;
}
