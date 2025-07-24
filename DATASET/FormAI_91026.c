//FormAI DATASET v1.0 Category: Image Editor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#define MAX_PLAYERS 4
#define IMAGE_SIZE 10


// define image data structure
struct ImageEditor{
  int image[IMAGE_SIZE][IMAGE_SIZE];
};


// global variables
struct ImageEditor image;
pthread_barrier_t barrier;
pthread_mutex_t mutex;
bool turn[MAX_PLAYERS] = {0};
int currentPlayer = 0;


// function to initialize the image data structure
void initImage(){
  for(int i = 0; i < IMAGE_SIZE; i++){
    for(int j = 0; j < IMAGE_SIZE; j++){
      image.image[i][j] = 0;
    }
  }
}


// function to display the image
void displayImage(){
  printf("\nImage:\n");
  for(int i = 0; i < IMAGE_SIZE; i++){
    for(int j = 0; j < IMAGE_SIZE; j++){
      printf("%d ", image.image[i][j]);
    }
    printf("\n");
  }
}


// function to modify image pixel
void modifyPixel(int row, int col, int value){
  pthread_mutex_lock(&mutex);
  image.image[row][col] = value;
  pthread_mutex_unlock(&mutex);
}


// function to get image pixel value
int getPixelValue(int row, int col){
  pthread_mutex_lock(&mutex);
  int value = image.image[row][col];
  pthread_mutex_unlock(&mutex);
  return value;
}


// function executed by each player thread
void* playerThread(void *arg){
  int playerNum = *(int*)arg;
  int row, col, value;
  
  while(true){
    // wait for turn
    pthread_barrier_wait(&barrier);
    
    if(turn[playerNum]){
      printf("\nPlayer %d's turn:\n", playerNum);
      printf("Enter row: ");
      scanf("%d", &row);
      printf("Enter column: ");
      scanf("%d", &col);
      printf("Enter value: ");
      scanf("%d", &value);
      
      modifyPixel(row, col, value);
      displayImage();
      
      // switch turn
      pthread_mutex_lock(&mutex);
      turn[playerNum] = false;
      currentPlayer = (currentPlayer + 1) % MAX_PLAYERS;
      turn[currentPlayer] = true;
      pthread_mutex_unlock(&mutex);
    }

    // check if game over
    int pixelSum = 0, totalPixels = IMAGE_SIZE*IMAGE_SIZE;
    for(int i = 0; i < IMAGE_SIZE; i++){
      for(int j = 0; j < IMAGE_SIZE; j++){
        pixelSum += getPixelValue(i, j);
      }
    }

    if(pixelSum == totalPixels){
      printf("\nGame over! All pixels have been modified.\n");
      exit(0);
    }
  }
}


// main function
int main(){
  pthread_t threads[MAX_PLAYERS];
  int playerNums[MAX_PLAYERS] = {0, 1, 2, 3};

  // initialize mutex and barrier
  pthread_mutex_init(&mutex, NULL);
  pthread_barrier_init(&barrier, NULL, MAX_PLAYERS);

  // initialize image data structure
  initImage();

  // set initial turn to first player
  turn[currentPlayer] = true;

  // create player threads
  for(int i = 0; i < MAX_PLAYERS; i++){
    pthread_create(&threads[i], NULL, playerThread, (void*)&playerNums[i]);
  }

  // wait for threads to finish
  for(int i = 0; i < MAX_PLAYERS; i++){
    pthread_join(threads[i], NULL);
  }

  return 0;
}