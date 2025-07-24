//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
    int n, rows, cols, spaces, num;
    printf("I am a curious chatbot and I want to print a unique pattern! How many rows do you want in the pattern? ");
    scanf("%d", &n);

    for(rows=1; rows<=n; rows++) {
        num = rows;
        for(spaces=n-rows; spaces>=1; spaces--) {
            printf(" ");
        }
        for(cols=1; cols<=rows; cols++) {
            printf("%d", num);
            num++;
        }
        num--;
        num--;
        for(cols=1; cols<rows; cols++) {
            printf("%d", num);
            num--;
        }
        printf("\n");
    }

    for(rows=n-1; rows>=1; rows--) {
        num = rows;
        for(spaces=n-rows; spaces>=1; spaces--) {
            printf(" ");
        }
        for(cols=1; cols<=rows; cols++) {
            printf("%d", num);
            num++;
        }
        num--;
        num--;
        for(cols=1; cols<rows; cols++) {
            printf("%d", num);
            num--;
        }
        printf("\n");
    }

    printf("There you go! I hope you liked the pattern.\n");
    return 0;
}