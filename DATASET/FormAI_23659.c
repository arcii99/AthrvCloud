//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include<stdio.h>

void cheer(int n) {
    if(n == 0) {
        printf("Yay! Let's celebrate!\n");
        return;
    }
    printf("We are so happy, we can't stop the glee!\n");
    cheer(n - 1);
}

int main() {
    printf("How many cheers do we want to give? ");
    int n;
    scanf("%d", &n);
    cheer(n);
    return 0;
}