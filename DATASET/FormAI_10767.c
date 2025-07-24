//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random seed
    
    int rating = rand() % 101; //generate a random rating between 0 and 100
    
    if(rating >= 90) {
        printf("This movie is a must-see!\n");
    } else if(rating >= 70) {
        printf("This movie is worth watching.\n");
    } else if(rating >= 50) {
        printf("This movie is average.\n");
    } else if(rating >= 30) {
        printf("This movie is below average.\n");
    } else {
        printf("This movie is a waste of time.\n");
    }
    
    return 0;
}