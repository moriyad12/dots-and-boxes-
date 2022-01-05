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

extern struct movements {
  char player;
  int row_1;
  int row_2;
  int column_1;
  int column_2;
  char movement;
};
struct movements game_movements[60];

void print(int n, char a[n][n]) {
  static int u = 0;
  int x = 1;
  system("cls");

  if (n == 5)
    printf(MAG "\t\t\t\t\t   %d   %d   %d\n", 1, 2, 3);
  else printf("\t\t\t\t\t   %d   %d   %d   %d   %d   %d\n", 1, 2, 3, 4, 5, 6);
  for (int i = 0; i < n; i++) {
    printf("\t\t\t\t\t");
    if (i % 2 == 0) {
      printf(MAG "%d "
        KNRM, x);
      x++;
    } else printf(". ");
    for (int j = 0; j < n; j++)
     { if(i==(game_movements[continuing - 1].row_1 + game_movements[continuing - 1].row_2 - 2)&&j==(game_movements[continuing - 1].column_1 + game_movements[continuing - 1].column_2 - 2)&&game_movements[continuing - 1].player=='a')
        {
           if(a[i][j]=='|')
             printf(KRED" %c "KNRM, a[i][j]);
            else
                printf(KRED"%c"KNRM, a[i][j]);
        }
        else if(i==(game_movements[continuing - 1].row_1 + game_movements[continuing - 1].row_2 - 2)&&j==(game_movements[continuing - 1].column_1 + game_movements[continuing - 1].column_2 - 2)&&game_movements[continuing - 1].player=='b')
         {
             if(a[i][j]=='|')
             printf(KGRN" %c "KNRM, a[i][j]);
            else
                printf(KGRN"%c"KNRM, a[i][j]);

        }
         else if(i%2==1&&j%2==1&&a[i][j]=='a')
                  printf(KRED"%c"KNRM, a[i][j]);
        else if(i%2==1&&j%2==1&&a[i][j]=='b')
                  printf(KGRN"%c"KNRM, a[i][j]);
          else if(j%2==0)
                  printf(" %c ", a[i][j]);
         else
            printf("%c", a[i][j]);
     }
    if (i < n - 1)
      printf("\n");
  }
  printf(BLU "\n                                          palyer %c round\n", q);
  if (b == 0) {
    printf(KRED "\nscore of player a is %d", score_a);
    printf(KGRN "                                                    score of player b is %d\n", score_b);
    printf(KRED "The player a played %d times", m_a);
    printf(KGRN "                                               The player b played %d times\n", m_b);
  } else {
    printf(KRED "\nscore of player a is %d", score_a);
    printf(KGRN "                                                    score of computer is %d\n", score_b);
    printf(KRED "The player a played %d times", m_a);
    printf(KGRN "                                               The computer played %d times\n", m_b);
  }
  printf(BLU "The remaining movements : %.0f\n"
    KNRM, pow(n, 2) / 2 - 1 - m_a - m_b);
  if (u != 0)
    time_dif();
  u++;

  return;

}
