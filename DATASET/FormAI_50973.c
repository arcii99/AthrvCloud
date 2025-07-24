//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 0;
    printf("Enter a number: ");
    fflush(stdout);
    if(scanf("%d", &x) != 1){
        perror("Error: Invalid input");
        exit(EXIT_FAILURE);
    }
    
    if(x < 0 || x > 100){
        printf("Error: Input must be between 0 and 100\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Congratulations! Your input is within the acceptable range.\n");
    return 0;
}