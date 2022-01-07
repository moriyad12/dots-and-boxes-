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



extern time_t t1;
int score_a = 0;
int score_b = 0;
int checker = 1;
int continuing = 0;
int m_a = 0, m_b = 0;
int u = 0;
int b = 0;
int p;
int score = 0;
int n;
char q = 'a';

char game[5][5] = {
  {
    '\0'
  }
}, game_[11][11] = {
  {
    '\0'
  }
};
struct movements {
  char player;
  int row_1;
  int row_2;
  int column_1;
  int column_2;
  char movement;
};
struct movements game_movements[60];
struct {
  char name;
  int score__;
  int color;
}
player1 = {
    'a',
    0,
    'red'
  },
  player2 = {
    'b',
    0,
    'blue'
  };
struct top {
  char name[20];
  int scoore;
};
struct top top10[10];



void checking_score(int n, char a[n][n]) {
  p = u;
  u = 0;
  for (int i = 0; i <= n - 2; i = i + 2) {
    for (int j = 1; j <= n - 1; j = j + 2) {
      if (a[i][j] ==(char)196 && a[i + 2][j] == (char)196) {
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

  } else {
    score_b += u - p;
  }
  if (q == 'a')
    m_a++;
  else m_b++;

  if (score - score_a - score_b == 0) {
    if (q == 'a')
      q = 'b';
    else q = 'a';
  }
  score = score_a + score_b;
  game_movements[continuing].player = q;
  return;
}


void save(int fileNum, int score, int score_a, int score_b, int p, int u, int continuing, int n, char a[n][n], int m_a, int m_b, int checker, char q, int b) {
  FILE * s = NULL;
  if (fileNum == 1) {
    s = fopen("game1.txt", "w");
  } else if (fileNum == 2) {
    s = fopen("game2.txt", "w");
  } else if (fileNum == 3) {
    s = fopen("game3.txt", "w");
  }
  fprintf(s, "%d\n", n);
  fprintf(s, "%d\n", score);
  fprintf(s, "%d\n", score_a);
  fprintf(s, "%d\n", score_b);
  fprintf(s, "%d\n", p);
  fprintf(s, "%d\n", u);
  fprintf(s, "%d\n", continuing);
  fprintf(s, "%d\n", m_a);
  fprintf(s, "%d\n", m_b);
  fprintf(s, "%d\n", checker);
  fprintf(s, "%d\n", b);
  fprintf(s, "%d\n", q);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fprintf(s, "%d\n", a[i][j]);
    }
  }
  fclose(s);
}
void load(int fileNum) {
  FILE * s;
  if (fileNum == 1) {
    s = fopen("game1.txt", "r");
  } else if (fileNum == 2) {
    s = fopen("game2.txt", "r");
  } else if (fileNum == 3) {
    s = fopen("game3.txt", "r");
  }
  rewind(s);
  fscanf(s, "%d\n", & n);
  fscanf(s, "%d\n", & score);
  fscanf(s, "%d\n", & score_a);
  fscanf(s, "%d\n", & score_b);
  fscanf(s, "%d\n", & p);
  fscanf(s, "%d\n", & u);
  fscanf(s, "%d\n", & continuing);
  fscanf(s, "%d\n", & m_a);
  fscanf(s, "%d\n", & m_b);
  fscanf(s, "%d\n", & checker);
  fscanf(s, "%d\n", & b);
  fscanf(s, "%d\n", & q);
  if (n == 5) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        fscanf(s, "%d\n", & game[i][j]);

      }
    }
  }
  if (n == 11) {
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        fscanf(s, "%d\n", & game_[i][j]);

      }
    }
  }
  fclose(s);
}
