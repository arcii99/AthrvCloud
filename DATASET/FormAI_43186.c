//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int n=2;
    
    while (1) {
        int prime=1;
        for (int i=2; i<n; i++) {
            if (n%i==0) {
                prime=0;
                break;
            }
        }
        if (prime) {
            printf("%d, ", n);
        }
        n++;
    }

    return 0;
}