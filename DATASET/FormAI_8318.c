//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

   const char *subjects[] = {
      "The government", "Aliens", "Illuminati", "Time travelers", "AI"
   };
   
   const char *actions[] = {
      "control", "manipulate", "brainwash", "influence", "secretly communicate with"
   };
   
   const char *objects[] = {
      "our thoughts", "the weather", "our dreams", "the stock market", "the media"
   };
   
   const char *reasons[] = {
      "to gain power", "to obtain resources", "to enslave humanity", "for their own entertainment", "to alter history"
   };
   
   srand(time(NULL));
   int randSubject = rand() % 5;
   int randAction = rand() % 5;
   int randObject = rand() % 5;
   int randReason = rand() % 5;
   
   printf("Did you know that %s %s %s %s?\n", subjects[randSubject], actions[randAction], objects[randObject], reasons[randReason]);
   
   return 0;
}