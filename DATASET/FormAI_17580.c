//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

void countDown(int num)
{
   if (num == 0) {
      printf("Blast Off!\n");
   } else {
      printf("%d...\n", num);
      countDown(num-1);
   }
}

int main()
{
    printf("Enter a positive integer to start the countdown: ");
    int num;
    scanf("%d", &num);

    if (num < 0) {
        printf("Negative numbers not allowed.\n");
        return 1;
    }

    printf("Starting countdown...\n");
    countDown(num);

    return 0;
}