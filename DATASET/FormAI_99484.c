//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>

int main(){

    int laughter = 0;

    // Let's warm up with some basic math
    int x = 10;
    int y = 20;
    int sum = x + y;
    printf("The sum of %d and %d is %d. Ha Ha!\n", x, y, sum);
    laughter++;

    // Let's try out some scientific notations
    double number = 5.5e5;
    printf("Did you know that %.2e is the scientific notation for %f? Funny, right?\n", number, number);
    laughter++;

    // What about some advanced statistics?
    int data[] = {1, 4, 7, 3, 6, 9};
    int total = 0;
    int i;
    double mean;

    for(i=1; i<=6; i++){
        total += data[i-1];
    }

    mean = (double)total/6;
    printf("The mean of the dataset {1, 4, 7, 3, 6, 9} is %f. Hahaha!\n", mean);
    laughter++;

    // Let's calculate the factorial of a number
    int num = 5;
    int fact = 1;
    for(i=1; i<=num; i++){
        fact *= i;
    }
    printf("The factorial of %d is %d. Hehehe!\n", num, fact);
    laughter++;

    // Finally, let's execute a funny infinite loop
    int count = 0;
    while(1){
        printf("Are you laughing yet? Ha!\n");
        count++;
        if(count == 10){
            break;
        }
    }
    laughter++;

    // Let's check how funny we were
    printf("Total laughter count: %d. That was hilarious!\n", laughter);

    return 0;
}