//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

void curious_print(int n, int k);

int main() {
    int n, k;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter another number: ");
    scanf("%d", &k);
    curious_print(n, k);
    return 0;
}

void curious_print(int n, int k) {
    if(n <= 0) {
        return; // Just keep holding on, we're going home!
    }
    printf("I am printing %d\n", k);
    if(k > 0) {
        curious_print(n, k-1);
    } else {
        printf("I am taking a break for %d seconds...\n", n);
        sleep(n);
        printf("Alright, I'm back! Let's continue printing!\n");
        curious_print(n-1, k);
    }
}