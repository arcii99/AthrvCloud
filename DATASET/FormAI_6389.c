//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  
  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the given paragraph as fast and accurate as possible.\n");
  
  //Paragraph to be typed
  char paragraph[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
  
  //Variables for time calculation
  time_t start_time, end_time;
  
  //User input for typing
  char input[200];
  
  printf("%s\n",paragraph);
  time(&start_time); //Start timer
  
  fgets(input,sizeof(input),stdin); //Get user input
  
  time(&end_time); //Stop timer
  
  double time_taken = difftime(end_time,start_time); //Calculation of time taken
  
  printf("Time taken: %.2lf seconds\n",time_taken);
  
  //Counting number of correct and incorrect characters typed
  int correct=0, incorrect=0;
  
  for(int i=0; i<sizeof(paragraph)-1; i++){
    if(paragraph[i] == input[i])
      correct++;
    else
      incorrect++;
  }
  
  printf("Number of correct characters: %d\nNumber of incorrect characters: %d\n", correct, incorrect);
  
  //Speed Calculation
  double speed = (double) correct / time_taken * 60;
  
  printf("Your typing speed is: %.2lf words per minute.\n",speed);
  
  if(speed > 60)
    printf("Great job! You're super fast!\n");
  else if(speed > 40)
    printf("Good job! You have a decent speed.\n");
  else
    printf("You need to improve your typing speed.\n");
  
  return 0;
}