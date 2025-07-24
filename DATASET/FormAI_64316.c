//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
    int size, i, j, count1 = 0, count2 = 1, num = 1;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);
    for(i = size; i >= 1; i--){
        for(j = 1; j <= i; j++){
            printf(" ");
        }
        for(j = 1; j <= count1; j++){
            printf("%d", num++);
        }
        count1 += count2;
        count2++;
        printf("\n");
    }

    count1 -= 2;
    count2 -= 2;

    for(i = 1; i <= size; i++){
        for(j = 1; j <= i; j++){
            printf(" ");
        }
    
        for(j = 1; j <= count1; j++){
            printf("%d", num++);
        }

        count1 -= count2;
        count2--;
        printf("\n");
    }

    return 0;
}