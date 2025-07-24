//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
/* 
The Lazy Scheduler: 
A humorous take on a task scheduler in C.
*/

#include <stdio.h>

void do_homework() {
  printf("Oh no, another homework assignment... Let me just take a nap first.\n");
  sleep(5); // Takes a nap for 5 seconds.    
  printf("Alright, let's get started...\n");
  // Does the homework.
}

void play_video_games() {
  printf("Might as well take a break and play some video games...\n");
  for (int i = 0; i < 30; i++) {
    printf("Playing video games...\n");  
    sleep(1); // Takes a break for 1 second.
  }
  printf("Alright, that was fun. Back to work...\n");
}

void watch_tv() {
  printf("Just going to relax and watch some TV...\n");
  for (int i = 0; i < 60; i++) {
    printf("Watching TV...\n");
    sleep(1); // Takes a break for 1 second.
  }
  printf("Okay, waste of time. Time to be productive.\n");
}

int main() {
  printf("Hello there, I am the Lazy Scheduler! Let me handle your tasks...\n");
  
  /* Scheduling tasks for the day */
  do_homework();
  play_video_games();
  watch_tv();
  do_homework();
  play_video_games();
  do_homework();
  watch_tv();
  play_video_games();
  
  printf("All tasks completed for the day! Time to relax and take a nap.\n");
  sleep(10);

  printf("Oh no! I forgot to schedule a task...\n");
  printf("Well, I'm sure it wasn't important anyways. Back to napping.\n");
  sleep(5);
  printf("Thank you for using the Lazy Scheduler! Come back again soon.\n");

  return 0;
}