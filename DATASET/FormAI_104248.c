//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding the random number generator
    int x = rand() % 100;
    int y = rand() % 100;
    int z = 0;

    printf("x = %d, y = %d\n", x, y);

    // perform addition
    printf("Performing addition...\n");
    z = x + y;
    printf("%d + %d = %d\n", x, y, z);

    // perform subtraction
    printf("Performing subtraction...\n");
    z = x - y;
    printf("%d - %d = %d\n", x, y, z);

    // perform multiplication
    printf("Performing multiplication...\n");
    z = x * y;
    printf("%d * %d = %d\n", x, y, z);

    // perform division
    if (y == 0) {
        printf("Cannot divide %d by zero!\n", x);
    } else {
        printf("Performing division...\n");
        z = x / y;
        printf("%d / %d = %d\n", x, y, z);
    }

    return 0;
}