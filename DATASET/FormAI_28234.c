//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define ROWS 10
#define COLS 10
#define FRAME_RATE 10

/* Function prototypes */
void generateWeather(int weather[ROWS][COLS]);
void displayWeather(int weather[ROWS][COLS]);

/* Main function */
int main(void) {
  int weather[ROWS][COLS];
  
  while(1) {
    generateWeather(weather);
    displayWeather(weather);
    usleep(1000000/FRAME_RATE);
  }
  
  return 0;
}

/* Function to generate current weather conditions */
void generateWeather(int weather[ROWS][COLS]) {
  int i, j;
  
  for(i=0;i<ROWS;i++) {
    for(j=0;j<COLS;j++) {
      weather[i][j] = rand() % 10; /* Generates a random number between 0 and 9 */
    }
  }
}

/* Function to display weather conditions */
void displayWeather(int weather[ROWS][COLS]) {
  int i, j;
  
  system("cls || clear"); /* Clears the console screen */
  
  printf("Current Weather Conditions\n\n");
  
  for(i=0;i<ROWS;i++) {
    for(j=0;j<COLS;j++) {
      switch(weather[i][j]) {
        case 0:
          printf("  Sunny  ");
          break;
        case 1:
          printf("  Cloudy ");
          break;
        case 2:
          printf("  Rainy  ");
          break;
        case 3:
          printf("  Stormy ");
          break;
        case 4:
          printf("  Snowy  ");
          break;
        case 5:
          printf("  Hail   ");
          break;
        case 6:
          printf("  Foggy  ");
          break;
        case 7:
          printf("  Windy  ");
          break;
        case 8:
          printf("  Dusty  ");
          break;
        case 9:
          printf("  Smoky  ");
          break;
      }
    }
    printf("\n");
  }
}