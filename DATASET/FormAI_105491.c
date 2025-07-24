//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>

#define MAX_ROWS 7
#define MAX_COLS 7

char heart[MAX_ROWS][MAX_COLS] = 
{
    {' ', ' ', '*', ' ', ' ', ' ', '*' },
    {' ', '*', ' ', ' ', ' ', '*', ' ' },
    {'*', ' ', ' ', ' ', '*', ' ', ' ' },
    {'*', ' ', ' ', ' ', '*', ' ', ' ' },
    {' ', '*', ' ', ' ', ' ', '*', ' ' },
    {' ', ' ', '*', '*', '*', ' ', ' ' },
    {' ', ' ', ' ', '*', ' ', ' ', ' ' }
};

void print_heart() {
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            printf("%c ", heart[i][j]);
        }
        printf("\n");
    }
}

int main() {
   printf("Hello my love,\n\n");
   printf("I created this ASCII art of a heart just for you\n\n");
   print_heart();
   printf("\n");

   printf("I know I haven't always been the perfect partner,\n");
   printf("but I promise to always be here for you,\n");
   printf("to support and love you, and to make you smile every day.\n\n");

   printf("I hope this little gesture shows you just how much I care for you.\n");
   printf("I love you more every day,\n\n");
   printf("Forever yours,\n");
   printf("Your Valentine\n");
   return 0;
}