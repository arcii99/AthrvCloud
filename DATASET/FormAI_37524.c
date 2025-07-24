//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>

int main() {
   int arrayLength = 7;
   char letters[] = {'B', 'R', 'A', 'V', 'E', '!', '\n'};
   char asciiArt[5][85] = {
       {"____    ____     __  __     ______     ____    __    __   ______   \n"},
       {"\\   \\  /   /    |  |/ /    /  __  \\   /   /   |  |  |  | |   ____|  \n"},
       {" \\   \\/   /     |  ' /    |  |  |  | /   /    |  |__|  | |  |__     \n"},
       {"  \\_    _/      |   <     |  |  |  |/   /     |   __   | |   __|    \n"},
       {"    |  |        |  . \\    |  `--'  /   /___   |  |  |  | |  |____  \n"}
   };

   for (int i = 0; i < 5; i++) {
       for (int j = 0; j < arrayLength; j++) {
           if (asciiArt[i][j] == ' ') {
               printf(" ");
           } else {
               printf("%c", letters[j]);
           }
       }
       printf("%s", asciiArt[i]);
   }

   return 0;
}