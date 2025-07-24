//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, rand_num;
   char *conspiracy[10] = {"The moon landing was faked", "The government controls the weather", "Aliens are living among us", "Elvis is still alive", "The world is flat", "The Illuminati control everything", "9/11 was an inside job", "COVID-19 was created in a lab", "The Holocaust was a hoax", "Chemtrails are poisoning us"};
   char *evidence[5] = {"A friend of a friend who works for the government said so", "There's a YouTube video about it", "It's on a conspiracy theory website", "I saw it on a Facebook post", "A person on a forum claimed it to be true"};
   char *source[5] = {"The CIA", "The Vatican", "The Free Masons", "The New World Order", "The Reptilian Elite"};
    
   // Generate random seed
   srand(time(NULL));
    
   printf("Here's a conspiracy theory for you: ");
   rand_num = rand() % 10;
   printf("%s \n", conspiracy[rand_num]);
    
   printf("And here's some evidence to back it up: \n");
   for(i = 0; i < 5; i++) {
       rand_num = rand() % 5;
       printf("- %s \n", evidence[rand_num]);
   }
    
   printf("And the source of the conspiracy is: ");
   rand_num = rand() % 5;
   printf("%s\n", source[rand_num]);
    
   return 0;
}