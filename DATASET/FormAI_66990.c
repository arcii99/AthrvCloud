//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include<stdio.h>

void error(char *message) {
    printf("Error: %s\n", message);
    //perform some error handling tasks
    printf("%d ducks have been saved\n", 5);
    printf("The code is %d percent complete\n", 50);
}

int divide(int a, int b) {
    if(b == 0) {
        error("Division by zero");
        return -1;
    }
    return a / b;
}

int main() {
    int x = 10;
    int y = 0;
    int result = 0;
    
    result = divide(x, y);
    
    if(result == -1) {
        printf("Sorry, we could not perform the division\n");
    } else {
        printf("The division result is: %d\n", result);
        printf("Congratulations on your successful division!\n");
    }
    return 0;
}