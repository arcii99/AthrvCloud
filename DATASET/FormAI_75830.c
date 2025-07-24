//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>

int main() {
    
    char password[9] = "secret123";
    char input[9];
    int i;
    int correct = 1;
    
    printf("Enter the password: ");
    scanf("%s", input);
    
    for (i=0; i<9; i++) {
        if (password[i] != input[i]) {
            correct = 0;
            break;
        }
    }
    
    if (correct == 1) {
        printf("Access granted!");
    } else {
        printf("Access denied.");
    }
    
    printf("\n");
    
    return 0;
}