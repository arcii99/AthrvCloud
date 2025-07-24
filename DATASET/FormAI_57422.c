//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 21 
#define COLS 21

char level[ROWS][COLS] = {
   {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-','+'},
   {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
   {'|', ' ', '-', '-', '-', '-', '|', '-', '-', '|', ' ', '-', '-', '-', '-', '-', '-', '-', '-', ' ','|'},
   {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
   {'|', ' ', '-', '-', '-', '-', '|', ' ', ' ', '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ','|'},
   {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
   {'|', '-', '-', '-', '-', '-', '|', '-', '-', '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ','|'},
   {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
   {'|', ' ', '-', '-', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ','|'},
   {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
   {'+', '-', '-', '-', '-', '-', '-', '-', '-', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+','+'},
};

int Pacman_X = 10;
int Pacman_Y = 7;
char Pacman_Dir = ' ';
int score = 0;

typedef struct Ghost {
   int x;
   int y;
   char dir;
} Ghost;

Ghost Ghost1 = { 10, 10, ' ' };
Ghost Ghost2 = { 10, 11, ' ' };
Ghost Ghost3 = { 10, 12, ' ' };
Ghost Ghost4 = { 10, 13, ' ' };

void Display_Level() {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         printf("%c ", level[i][j]);
      }
      printf("\n");
   }
}

void Display_Score() {
   printf("\nScore: %d\n", score);
}

void Restart() {
   Pacman_X = 10;
   Pacman_Y = 7;
   Pacman_Dir = ' ';
   score = 0;

   Ghost1.x = 10;
   Ghost1.y = 10;
   Ghost1.dir = ' ';

   Ghost2.x = 10;
   Ghost2.y = 11;
   Ghost2.dir = ' ';

   Ghost3.x = 10;
   Ghost3.y = 12;
   Ghost3.dir = ' ';

   Ghost4.x = 10;
   Ghost4.y = 13;
   Ghost4.dir = ' ';

   level[10][7] = 'C';
   level[10][10] = 'g';
   level[10][11] = 'g';
   level[10][12] = 'g';
   level[10][13] = 'g';
}

void Clamp_Position(int* x, int* y) {
   if (*x < 0) {
      *x = ROWS - 2;
   }

   if (*x > ROWS - 2) {
      *x = 0;
   }

   if (*y < 0) {
      *y = COLS - 2;
   }

   if (*y > COLS - 2) {
      *y = 0;
   }
}

void Pacman_Tick() {
   if (toupper(Pacman_Dir) == 'W' || toupper(Pacman_Dir) == 'A' || toupper(Pacman_Dir) == 'S' || toupper(Pacman_Dir) == 'D') {
      int next_X = Pacman_X;
      int next_Y = Pacman_Y;

      if (toupper(Pacman_Dir) == 'W') {
         next_X--;
      }
      else if (toupper(Pacman_Dir) == 'A') {
         next_Y--;
      }
      else if (toupper(Pacman_Dir) == 'S') {
         next_X++;
      }
      else if (toupper(Pacman_Dir) == 'D') {
         next_Y++;
      }

      if (level[next_X][next_Y] == ' ') {
         level[next_X][next_Y] = 'C';
         level[Pacman_X][Pacman_Y] = ' ';

         Pacman_X = next_X;
         Pacman_Y = next_Y;
      }
      else if (level[next_X][next_Y] == '.') {
         level[next_X][next_Y] = 'C';
         level[Pacman_X][Pacman_Y] = ' ';

         Pacman_X = next_X;
         Pacman_Y = next_Y;

         score++;
      }
   }

   Clamp_Position(&Pacman_X, &Pacman_Y);
}

void Ghost_Tick(Ghost* ghost, char target) {
   int next_X = ghost->x;
   int next_Y = ghost->y;

   if (target == 'C') {
      if (Pacman_X < ghost->x) {
         next_X--;
      }
      else if (Pacman_X > ghost->x) {
         next_X++;
      }

      if (Pacman_Y < ghost->y) {
         next_Y--;
      }
      else if (Pacman_Y > ghost->y) {
         next_Y++;
      }
   }
   else {
      if (Pacman_X > ghost->x) {
         next_X--;
      }
      else if (Pacman_X < ghost->x) {
         next_X++;
      }

      if (Pacman_Y > ghost->y) {
         next_Y--;
      }
      else if (Pacman_Y < ghost->y) {
         next_Y++;
      }
   }

   if (level[next_X][next_Y] != '|') {
      ghost->x = next_X;
      ghost->y = next_Y;
   }
   else {
      if (target == 'C') {
         if (Pacman_Y < ghost->y) {
            ghost->x--;
         }
         else if (Pacman_Y > ghost->y) {
            ghost->x++;
         }
      }
      else {
         if (Pacman_Y > ghost->y) {
            ghost->x--;
         }
         else if (Pacman_Y < ghost->y) {
            ghost->x++;
         }
      }
   }

   Clamp_Position(&ghost->x, &ghost->y);
}

void Ghosts_Tick() {
   Ghost_Tick(&Ghost1, 'C');
   Ghost_Tick(&Ghost2, 'C');
   Ghost_Tick(&Ghost3, 'P');
   Ghost_Tick(&Ghost4, 'P');
}

void Move() {
   Pacman_Tick();

   Ghosts_Tick();
}

void Get_Input() {
   printf("\nUse W A S D keys to move Pac-Man. Press Q to quit.\n");

   char input = getchar();

   if (toupper(input) == 'W' || toupper(input) == 'A' || toupper(input) == 'S' || toupper(input) == 'D') {
      Pacman_Dir = input;
   }
   else if (toupper(input) == 'Q') {
      exit(0);
   }

   while (getchar() != '\n');
}

void Update_Level() {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         if (level[i][j] == 'C' || level[i][j] == 'g') {
            level[i][j] = ' ';
         }
         else if (level[i][j] == '|' && rand() % 2 == 0) {
            level[i][j] = '.';
         }
      }
   }

   level[Pacman_X][Pacman_Y] = 'C';
   level[Ghost1.x][Ghost1.y] = 'g';
   level[Ghost2.x][Ghost2.y] = 'g';
   level[Ghost3.x][Ghost3.y] = 'g';
   level[Ghost4.x][Ghost4.y] = 'g';
}

void Update_Game() {
   if (level[Pacman_X][Pacman_Y] == 'g') {
      Restart();
   }

   Update_Level();

   Display_Level();
   Display_Score();
}

int main() {
   srand(time(NULL));

   Restart();

   while (1) {
      Get_Input();

      Move();

      Update_Game();
   }

   return 0;
}