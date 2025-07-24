//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// function to check for intrusion
int check_intrusion(int curr_val, int prev_val, int deviation) {
    int diff = abs(curr_val - prev_val);
    if (diff > deviation) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    // initialize with some random value
    int prev_val = 100;
    int curr_val;
    int deviation = 5; // set the deviation limit

    // run the program for 50 iterations
    for (int i = 0; i < 50; i++) {
        printf("Enter the current value: ");
        scanf("%d", &curr_val);

        // check for intrusion
        if (check_intrusion(curr_val, prev_val, deviation)) {
            printf("ALERT! Intrusion detected.\n");
        }

        // update the previous value
        prev_val = curr_val;
    }

    return 0;
}