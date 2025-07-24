//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // create an array of fortunes
  char *fortunes[10] = {"You will succeed in your endeavors.", "An unexpected surprise is headed your way.",
                        "You will meet someone special soon.", "Your hard work will pay off.",
                        "A new opportunity is around the corner.", "Your persistence will lead to success.",
                        "Your creativity will be admired by others.", "Good things come to those who wait.",
                        "Your kindness will positively impact someone's life.", "You will learn an important life lesson."};
  
  // pre-generate a random number
  srand(time(NULL));
  int random_index = rand() % 10;

  // print the fortune
  printf("Your fortune for today is: %s\n", fortunes[random_index]);

  return 0;
}