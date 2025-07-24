//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Define the global variables for the positions of the two animals
int rabbit_position = 0;
int turtle_position = 0;

// Define the functions for the two animals to move
void *rabbit_move(void *arg){
  while(rabbit_position < 50){
    // Print the current position of the rabbit
    printf("Rabbit's Current Position: %d\n", rabbit_position);
    // Increment the position of the rabbit by 2
    rabbit_position += 2;
    // Sleep for a random number of seconds between 1 to 3 seconds
    int sleep_time = rand() % 3 + 1;
    sleep(sleep_time);
  }
  // Exit the thread when the rabbit reaches the finishing line
  pthread_exit(NULL);
}


void *turtle_move(void *arg){
  while(turtle_position < 50){
    // Print the current position of the turtle
    printf("Turtle's Current Position: %d\n", turtle_position);
    // Increment the position of the turtle by 1
    turtle_position += 1;
    // Sleep for a random number of seconds between 2 to 5 seconds
    int sleep_time = rand() % 4 + 2;
    sleep(sleep_time);
  }
  // Exit the thread when the turtle reaches the finishing line
  pthread_exit(NULL);
}

int main(){
  // Declare the two threads for the rabbit and the turtle
  pthread_t rabbit_thread, turtle_thread;
  
  // Initialize the random number generator
  srand(time(NULL));
  
  // Create the threads for the rabbit and the turtle
  pthread_create(&rabbit_thread, NULL, rabbit_move, NULL);
  pthread_create(&turtle_thread, NULL, turtle_move, NULL);
  
  // Wait for the threads to finish their tasks
  pthread_join(rabbit_thread, NULL);
  pthread_join(turtle_thread, NULL);
  
  // Determine the winner of the race and print the result
  if(rabbit_position >= 50 && turtle_position >= 50){
    printf("It's a tie!\n");
  }else if(rabbit_position >= 50){
    printf("The Rabbit Wins!\n");
  }else{
    printf("The Turtle Wins!\n");
  }
  
  return 0;
}