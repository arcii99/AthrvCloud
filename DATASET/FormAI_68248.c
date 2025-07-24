//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>

int recursive(int number) {
    if (number == 0) {
        return 0;
    } else {
        return number + recursive(number - 1);
    }
}

int main() {
    int num;
    
    printf("Input a number: ");
    scanf("%d", &num);
    
    printf("The result of the recursive function is: %d\n", recursive(num));
    
    return 0;
}