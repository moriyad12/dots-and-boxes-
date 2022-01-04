#ifndef GAME_MOVEMENTS_H_INCLUDED
#define GAME_MOVEMENTS_H_INCLUDED



void checking_score(int n, char a[n][n]);

void undo(int n, char a[n][n]);
void redo(int n, char a[n][n]);
void save(int fileNum, int score, int score_a, int score_b, int p, int u, int continuing, int n, char a[n][n], int m_a, int m_b, int checker, char q, int b);
void load(int fileNum);
void playing_c(int n, char a[n][n]);
void playing(int n, char a[n][n]);
void making_grid(int m);
void start_game();
void the_game();

#endif // GAME_MOVEMENTS_H_INCLUDED
