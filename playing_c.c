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
extern struct top {
  char name[20];
  int scoore;
};
struct top top10[10];


void playing_c(int n, char a[n][n]) {
  int x, y, z, w, m, v;
  static int n_undo = 0;

  while (continuing < (pow(n, 2) / 2) - 1) {
    if (q == 'a') {

      printf(BLU "\nPlease enter rows of two points and columns of two points\n");
      printf("To Undo press 10\t\tTo Redo press 20\nTo Save press 30\nTo Start a new game press 40\n"
        KNRM);
      scanf("%d", & x);
      if (x == 30) {
        printf(BLU "File 1 press 1\t File 2 press 2\t File 3 press 3\n");
        int file_num;
        scanf("%d", & file_num);
        save(file_num, score, score_a, score_b, p, u, continuing, n, a, m_a, m_b, checker, q, b);
        printf("game saved\n"
          KNRM);

      }
      if (x==40){

score_a = 0;
score_b = 0;
checker = 1;
continuing = 0;
m_a = 0, m_b = 0;
u = 0;
b = 0;
p;
score = 0;

 q = 'a';

char game[5][5] = {
  {
    '\0'
  }
}, game_[11][11] = {
  {
    '\0'
  }
};

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
        the_game();
    }


      if (x == 10) {
        if (continuing != 0) {
          undo(n, a);
          n_undo++;
          while (q == 'b') {
            undo(n, a);
            n_undo++;
          }
        } else printf(MAG "Not available undo"
          KNRM);
      } else if (x == 20) {
        if (n_undo != 0) {
          redo(n, a);
          n_undo--;
          while (q == 'b') {
            redo(n, a);
            n_undo--;
          }
        } else printf(MAG "Not available redo"
          KNRM);
      } else {
        n_undo = 0;
        scanf("%d\n%d\n%d", & y, & z, & w);
        if (x <= n && x > 0 && y <= n && y > 0 & z <= n && z > 0 & w <= n && w > 0) {
          m = x + y - 2;
          v = z + w - 2;
          if ((x == y || z == w) && x <= (n / 2 + 1) && y <= (n / 2 + 1) && z <= (n / 2 + 1) && w <= (n / 2 + 1) && (abs(x - y) == 1 || abs(z - w) == 1)) {
            if (x == y) {
              if (a[m][v] != (char)196) {
                game_movements[continuing].player = q;
                game_movements[continuing].row_1 = x;
                game_movements[continuing].row_2 = y;
                game_movements[continuing].column_1 = z;
                game_movements[continuing].column_2 = w;
                game_movements[continuing].movement = 196;

                a[m][v] = 196;
                continuing++;

                checking_score(n, a);
                print(n, a);

              } else {
                printf(MAG "These points were previously selected\n"
                  KNRM);
              }

            } else {
              if (a[m][v] != '|') {
                game_movements[continuing].player = q;
                game_movements[continuing].row_1 = x;
                game_movements[continuing].row_2 = y;
                game_movements[continuing].column_1 = z;
                game_movements[continuing].column_2 = w;
                game_movements[continuing].movement = '|';
                a[m][v] = '|';
                continuing++;
                checking_score(n, a);
                print(n, a);
              } else {
                printf(MAG "These points were previously selected\n"
                  KNRM);
              }
            }
          } else {
            printf(MAG "Not valid points,please enter valid points\n"
              KNRM);
          }
        } else printf(MAG "Not valid value\n"
          KNRM);
      }
    }
    if (q == 'b' && x != 10 && x != 20) {
      int b = 0;
      for (int i = 0; i < n; i = i + 2) {
        for (int j = 1; j < n; j = j + 2) {
          if (a[i][j] == '\0') {
            a[i][j] = 196;
            game_movements[continuing].player = q;
            game_movements[continuing].row_1 = (i + 2) / 2;
            game_movements[continuing].row_2 = (i + 2) / 2;
            game_movements[continuing].column_1 = (j + 2) / 2;
            game_movements[continuing].column_2 = (j + 2) / 2 + 1;
            game_movements[continuing].movement = 196;
            continuing++;
            checking_score(n, a);
            print(n, a);

            b = 1;
            break;
          }
        }
        if (b == 1)
          break;
      }
      if (b == 0) {
        b = 0;
        for (int i = 1; i < n; i = i + 2) {
          for (int j = 0; j < n; j = j + 2) {
            if (a[i][j] == '\0') {
              a[i][j] = '|';
              game_movements[continuing].player = q;
              game_movements[continuing].row_1 = (i + 2) / 2;
              game_movements[continuing].row_2 = (i + 2) / 2 + 1;
              game_movements[continuing].column_1 = (j + 2) / 2;
              game_movements[continuing].column_2 = (j + 2) / 2;
              game_movements[continuing].movement = '|';
              continuing++;
              checking_score(n, a);
              print(n, a);

              b = 1;
              break;
            }
          }
          if (b == 1)
            break;
        }
      }
    }
  }
  if (score_a > score_b)
    {printf(KRED "Player a has won\n"
      KNRM);
      printf("Please enter name of the winner"
      KNRM);
    loadtop();
    for (int i = 0; i < 10; i++) {
      if (top10[i].scoore == 0) {
        scanf("%s", top10[i].name);
        top10[i].scoore += score_a;
        break;
      }
    }
    savetop();
    loadtop();
    for (int j = 0; j < 10; j++) {
      printf(MAG "%s %d\n", top10[j].name, top10[j].scoore);}}
  else if (score_a < score_b)
    printf(KGRN "Computer has won\n"
      KNRM);
  else
    printf(BLU "No winner\n"
      KNRM);
  printf(BLU "\nThe game ended"
    KNRM);
    printf("\nTo return to menu press 1\n"
    KNRM);
     int s = 0;
  scanf("%d", & s);
  if (s == 1)
    {score_a = 0;
score_b = 0;
checker = 1;
continuing = 0;
m_a = 0, m_b = 0;
u = 0;
b = 0;
p;
score = 0;

 q = 'a';
 main();}
  return;
}
