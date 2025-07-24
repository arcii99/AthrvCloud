//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *conspiracy_theories[] = { "The moon landing was faked",
                                  "The earth is flat",
                                  "Chemtrails are controlling us",
                                  "The Illuminati controls the world",
                                  "9/11 was an inside job",
                                  "The government is hiding evidence of extraterrestrial life",
                                  "The New World Order is taking over",
                                  "COVID-19 was created in a lab",
                                  "Elites are drinking children's blood for immortality",
                                  "Aliens live among us",
                                  "The world is controlled by reptilian beings",
                                  "Vaccines are being used for mind control",
                                  "The Bermuda Triangle is a portal to another dimension",
                                  "Bigfoot is real and being hidden by the government",
                                  "Area 51 is a secret government facility where they study aliens",
                                  "The Denver International Airport is hiding an underground city",
                                  "The apocalypse is coming and the government is preparing for it",
                                  "The Titanic was sunk on purpose",
                                  "Paul McCartney is dead and was replaced by a look-alike",
                                  "The Holocaust never happened" };
                                  
  int num_theories = sizeof(conspiracy_theories) / sizeof(char*);
  
  srand(time(NULL));
  
  printf("Welcome to the C Random Conspiracy Theory Generator!\n\n");
  
  while (1) {
    printf("Press enter to generate a random conspiracy theory or 'q' to quit\n");
    
    char input = getchar();
    
    if (input == 'q') {
      break;
    }
    
    int random_index = rand() % num_theories;
    
    printf("Your random conspiracy theory is: %s\n\n", conspiracy_theories[random_index]);
    
    // Consume remaining input after pressing enter
    while (getchar() != '\n');
  }
  
  return 0;
}