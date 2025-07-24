//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int num = rand() % 10;
  
  if (num == 0) {
    printf("The moon landing was faked!\n");
  } else if (num == 1) {
    printf("The government is hiding alien life from us.\n");
  } else if (num == 2) {
    printf("The CIA is controlling our thoughts through our phones.\n");
  } else if (num == 3) {
    printf("The Illuminati controls all major world events.\n");
  } else if (num == 4) {
    printf("Chemtrails are being used to control the population.\n");
  } else if (num == 5) {
    printf("The world is flat!\n");
  } else if (num == 6) {
    printf("Bigfoot is real and is in cahoots with the government.\n");
  } else if (num == 7) {
    printf("The pyramids were built by aliens.\n");
  } else if (num == 8) {
    printf("The Loch Ness Monster is a government experiment gone wrong.\n");
  } else {
    printf("The Bermuda Triangle is a portal to another dimension.\n");
  }
  
  return 0;
}