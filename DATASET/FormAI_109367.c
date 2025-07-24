//FormAI DATASET v1.0 Category: Math exercise ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {

    printf("My love, let's solve this math exercise together:\n\n");
    int a, b, c;

    do {
        printf("Please enter a non-negative integer value for a: ");
        scanf("%d",&a);
    } while (a < 0);

    do {
        printf("Please enter a non-negative integer value for b: ");
        scanf("%d",&b);
    } while (b < 0);

    c = sqrt(pow(a,2) + pow(b,2));

    printf("\n\nThe Pythagorean triple is: (%d, %d, %d)\n\n",a,b,c);

    printf("My love, just like the Pythagorean triple, our love is perfectly balanced and complete. Without you, my life equations would be incomplete and meaningless. But with you by my side, I feel invincible and ready to tackle any problem that comes our way.\n");

    return 0;
}