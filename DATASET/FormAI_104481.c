//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <time.h>

void print_conspiracy() {
  char *theories[] = {"The moon landing was faked by the government.",
                      "Aliens have been living among us for decades.",
                      "The Illuminati control the world's governments.",
                      "The government is putting chemicals in the water to control us.",
                      "9/11 was an inside job.",
                      "The government is hiding evidence of Bigfoot.",
                      "Elvis Presley faked his death and is living in hiding.",
                      "The CIA is behind the rise of ISIS.",
                      "The Earth is flat and the government is hiding it from us.",
                      "The Bermuda Triangle is a portal to another dimension.",
                      "Area 51 is holding extraterrestrial technology.",
                      "The government is behind the spread of diseases to control the population.",
                      "The Titanic was sunk on purpose for insurance fraud."};
  
  int size = sizeof(theories) / sizeof(*theories);
  int index = rand() % size;
  printf("%s\n", theories[index]);
}

int main() {
  time_t t;
  srand((unsigned) time(&t)); // seeding the random number generator

  printf("Welcome to the Random Conspiracy Theory Generator!\n");
  printf("Press any key to generate a theory or Q to quit.\n");

  char input;
  while (1) {
    input = getchar();
    if (input == 'Q' || input == 'q') {
      break;
    }
    print_conspiracy(); // generating random conspiracy theory
    printf("\nPress any key to generate another theory or Q to quit.\n");
  }

  printf("Thank you for using the Random Conspiracy Theory Generator!\n");
  return 0;
}