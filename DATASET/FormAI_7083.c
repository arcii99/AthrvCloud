//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

// Let's declare our curiosity
int why()
{
    return 42; // always the answer, but why?
}

int main()
{
    int a, b, c, d, e, f, g, h, i;

    // Let's start with some randomness
    printf("Please enter 9 random integers: \n");
    scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);

    // Some curious operations
    int result = ((((a + b) * c) / d) - e) % (f * g - h) + i;

    // Let's print the input and the result
    printf("\nYou entered: %d, %d, %d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g, h, i);
    printf("The result of this curious arithmetic: %d\n", result);

    // But wait, why did we do this?
    printf("\nWhy did we perform this curious arithmetic?\n");
    printf("We wanted to showcase that even the simplest arithmetic operations can hold surprising results!\n");

    // Finally, let's return our curiosity
    return why();
}