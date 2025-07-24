//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void recursiveFunction(int n)
{
    if (n > 0) {
        printf("%d\n", n);
        recursiveFunction(n-1);
        printf("%d\n", n);
    }
}

int main()
{
    printf("Time for some recursion!\n");
    printf("How many times should we run the function?\n");
    int n;
    scanf("%d", &n);
    recursiveFunction(n);
    printf("Done with recursion! Hope you enjoyed it.\n");

    return 0;
}