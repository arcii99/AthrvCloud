//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define variables
#define WIDTH 10
#define HEIGHT 5
#define COLORS 4

// define colors
#define RESET      "\033[0m"
#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CYAN       "\033[36m"
#define WHITE      "\033[37m"
#define BOLDBLACK  "\033[1m\033[30m"
#define BOLDRED    "\033[1m\033[31m"
#define BOLDGREEN  "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE   "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN   "\033[1m\033[36m"
#define BOLDWHITE  "\033[1m\033[37m"

// define functions
void create_bitmap(int bitmap[HEIGHT][WIDTH], int colors);
void print_bitmap(int bitmap[HEIGHT][WIDTH]);

int main() {
  // set the random seed
  srand(time(0));
  
  // create a bitmap
  int bitmap[HEIGHT][WIDTH] = {0};
  create_bitmap(bitmap, COLORS);
  
  // print the bitmap
  print_bitmap(bitmap);
  
  return 0;
}

void create_bitmap(int bitmap[HEIGHT][WIDTH], int colors) {
  // loop through the bitmap and set random colors
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      bitmap[i][j] = rand() % colors;
    }
  }
}

void print_bitmap(int bitmap[HEIGHT][WIDTH]) {
  // loop through the bitmap and print the colors
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      switch (bitmap[i][j]) {
        case 0:
          printf(BOLDBLACK "██" RESET);
          break;
        case 1:
          printf(BOLDRED "██" RESET);
          break;
        case 2:
          printf(BOLDGREEN "██" RESET);
          break;
        case 3:
          printf(BOLDYELLOW "██" RESET);
          break;
        default:
          printf("  ");
      }
    }
    printf("\n");
  }
}