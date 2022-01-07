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


extern struct top {
  char name[20];
  int scoore;
};
struct top top10[10];
void sort() {
  int i, j;
  struct top temp;
  for (i = 0; i < 10; i++) {
    for (j = i + 1; j < 10; j++) {
      if (top10[i].scoore < top10[j].scoore) {
        temp = top10[i];
        top10[i] = top10[j];
        top10[j] = temp;
      }
    }
  }
}
void savetop() {
  FILE * c;
  c = fopen("top.txt", "w");
  for (int i = 0; i < 10; i++) {
    fprintf(c, "%s\n", top10[i].name);
    fprintf(c, "%d\n", top10[i].scoore);
  }
  fclose(c);
}
void loadtop() {
  for (int i = 0; i < 10; i++)
    top10[i].scoore = 0;
  FILE * c;
  char name[20];
  c = fopen("top.txt", "r");
  rewind(c);
  for (int i = 0; i < 10; i++) {
    fscanf(c, "%s\n", name);
    fscanf(c, "%d\n", & top10[i].scoore);
    memcpy(top10[i].name, name, 20);
    sort();

  }
  fclose(c);
  return;
}
