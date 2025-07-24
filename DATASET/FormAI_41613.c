//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peacefulPrint(int num);

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    peacefulPrint(x);
    return 0;
}

void peacefulPrint(int num) {
    if(num == 0) {
        printf("The world is a peaceful place.\n");
        return;
    } else if (num < 0) {
        printf("Error: Negative number entered.\n");
        return;
    } else {
        for(int i=0; i<num; i++) {
            printf("Peace ");
        }
        peacefulPrint(num-1);
    }
}