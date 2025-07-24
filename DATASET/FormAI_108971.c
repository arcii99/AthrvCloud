//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
  int time_limit = 60; // Maximum time limit for the typing test
  time_t start_time, end_time;
  char text[500] = "In a post-apocalyptic world, survival is key. The only way to ensure your survival is to have the skillset to thrive in harsh environments. One such skill is typing speed. Test your typing speed with this program and see if you have what it takes to survive in the new world.";

  printf("\n\nWelcome to the Post-Apocalyptic Typing Speed Test!\n");
  printf("Type the following paragraph without any mistakes:\n\n%s\n\n", text);
  
  printf("Ready? Press any key to start!\n");
  getchar();

  int i = 0, mistakes = 0, typed_chars = 0;
  char c;
  time(&start_time); // Get current time

  while(i<strlen(text)){
    c = getchar();
    if(c == text[i]) {
      i++;
      typed_chars++;
      printf("%c", c);
    }
    else if(c == 10 || c == 13) {
      // Do nothing if Enter is pressed
    }
    else {
      mistakes++;
      printf("\a");   // Sound an alarm
    }
  }

  time(&end_time);  // Get current time
  double time_taken = difftime(end_time, start_time);  // Calculate time taken in seconds
  double speed = (typed_chars/5)/(time_taken/60);  // Calculate the speed in words per minute

  printf("\n\nTime taken: %.2lf seconds\n", time_taken);
  printf("Number of mistakes: %d\n", mistakes);
  printf("Typing speed: %.2lf WPM\n\n", speed);

  if(speed > 50) {
    printf("Great job! You have what it takes to survive in the new world!\n");
  }
  else {
    printf("You need to work on your typing speed. Don't worry, practice makes perfect!\n");
  }

  return 0;
}