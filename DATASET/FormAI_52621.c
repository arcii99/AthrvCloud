//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int weather = rand() % 4 + 1; // Random weather from 1 to 4

   switch (weather) {
      case 1:
         printf("It is a clear and sunny day. The birds are chirping and people are out enjoying the warm weather.\n");
         break;
      case 2:
         printf("Dark clouds loom overhead. The wind is starting to pick up and people rush to get inside before the rain starts.\n");
         break;
      case 3:
         printf("A heavy fog has settled over the land. It's hard to see more than a few feet in front of you and people move cautiously.\n");
         break;
      case 4:
         printf("Thunder echoes in the distance. The sky is dark and foreboding, warning of an upcoming storm.\n");
         break;
   }

    return 0;
}