//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;

    printf("Enter five integers: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    if (a < b && a < c && a < d && a < e) {
        printf("a is the smallest integer! Congratulations, A!\n");
    } else if (b < a && b < c && b < d && b < e) {
        printf("b is the smallest integer! Congratulations, B!\n");
    } else if (c < a && c < b && c < d && c < e) {
        printf("c is the smallest integer! Congratulations, C!\n");
    } else if (d < a && d < b && d < c && d < e) {
        printf("d is the smallest integer! Congratulations, D!\n");
    } else {
        printf("e is the smallest integer! Congratulations, E!\n");
    }

    return 0;
}