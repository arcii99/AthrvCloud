//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
  printf("Please wait while we analyze the Wi-Fi signals...\n");

  // Let's create a fake signal strength variable for fun
  int signal_strength = rand() % 30 + 70;

  printf("Wi-Fi signal strength: %d%%\n", signal_strength);
  printf("Analyzing...\n");

  if(signal_strength < 50){
    printf("Oh no! The Wi-Fi signal is weak. Time to call the internet provider...\n");
  }
  else if(signal_strength >= 50 && signal_strength < 70){
    printf("The Wi-Fi signal seems to be okay, but can be better. Try resetting the router!\n");
  }
  else if(signal_strength >= 70 && signal_strength < 90){
    printf("The Wi-Fi signal is strong! You can stream your favorite shows without buffering now!\n");
  }
  else{
    printf("WOW! The Wi-Fi signal is SUPER strong! Time to invite your entire neighborhood for a Wi-Fi party!\n");
  }

  printf("Thanks for using Wi-Fi Signal Strength Analyzer. Have a good day!\n");

  return 0;
}