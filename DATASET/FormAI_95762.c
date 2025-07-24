//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>

int main() {
    int n; 
    scanf("%d", &n);

    int notes[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int num_notes = sizeof(notes)/sizeof(notes[0]);
    int amount[num_notes];

    for(int i = num_notes - 1; i >= 0; i--) {
        amount[i] = n / notes[i];
        n = n % notes[i];
    }

    printf("Minimum number of notes needed:\n");
    for(int i = num_notes - 1; i >= 0; i--) {
        if(amount[i] > 0) {
            printf("%d x %d\n", notes[i], amount[i]);
        }
    }
    return 0;
}