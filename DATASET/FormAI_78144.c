//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Function for generating random numbers 
int generateRandom(int lower, int upper) 
{ 
  int num = (rand() % 
  (upper - lower + 1)) + lower; 
  return num; 
} 

// Main function 
int main() 
{ 
  // Initializing variables 
  int index = 0, numSentences = 0, flag = 1; 
  char topic[50]; 
  char topics[5][50] = {"The Moon Landing", "Area 51", "9/11 Attacks", "CIA Assassinations", "Alien Life Forms"}; 
  char subjects[20][50] = {
    "Elvis Presley Lives in Cuba", 
    "The Earth is Flat", 
    "Michael Jackson is an Alien", 
    "The Government is Controlled by Lizard People", 
    "The Illuminati Control the World", 
    "The Moon is a Hologram", 
    "The Loch Ness Monster is Real", 
    "The Titanic Never Sank", 
    "Time Travel is Possible", 
    "The Bermuda Triangle Swallows Ships and Planes", 
    "Bigfoot is a Government Experiment", 
    "Chemtrails Control Weather Patterns", 
    "The Government is Hiding the Cure for Cancer", 
    "Pearl Harbor Attack was an Inside Job", 
    "The Holocaust Never Happened", 
    "The Queen of England is a Reptilian", 
    "The Pyramids Were Built by Aliens", 
    "The JFK Assassination Was A Conspiracy", 
    "The Beatles Never Wrote Their Own Music", 
    "The Government is Tracking Your Every Move"
  }; 

  // Creating seed for random number 
  srand(time(0)); 

  // Prompting user for topic 
  printf("Welcome to the Conspiracy Theory Generator!\n"); 
  printf("Please enter a topic for your conspiracy theory: "); 
  fgets(topic, 50, stdin); 

  // Generating random number of sentences for conspiracy theory 
  numSentences = generateRandom(5, 15); 

  // Printing topic and conspiracy theory 
  printf("\n%s CONSPIRACY THEORY: \n", topic); 
  while (flag) { 
    printf("%s ", subjects[index]); 
    index++; 
    if (index == numSentences) { 
      flag = 0; 
    } 
  } 

  return 0; 
}