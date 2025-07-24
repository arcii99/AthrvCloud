//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int temp;
  srand((unsigned)time(NULL)); //initialize random number generator

  printf("Welcome to the Medieval Temperature Monitor!\n");

  while(1) { //infinite loop
    printf("The current temperature is: ");
    temp = rand() % 101; //generate random temperature between 0-100
    printf("%d degrees Celsius\n", temp);

    if(temp <= 0) {
      printf("It is freezing outside, knights better bundle up!\n");
    } 
    else if(temp <= 10) {
      printf("Winter is coming, keep warm by the fire!\n");
    } 
    else if(temp <= 20) {
      printf("A brisk fall day, perfect for a hunt!\n");
    }
     else if(temp <= 30) {
      printf("Looks like a pleasant day for a jousting tournament!\n");
    }
    else if(temp <= 40) {
      printf("The sun is beating down, better stay hydrated knights!\n");
    } 
    else if(temp <= 50) {
      printf("It's getting quite warm, protect yourself from the sun!\n");
    }
     else {
      printf("Hot as the flames of a dragon, stay cool inside!\n");
    }

    sleep(2); //wait for two seconds before displaying temperature again
  }

  return 0;
}