//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int sides,rolls;
    
    printf("Enter the number of sides: ");
    scanf("%d", &sides);
    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);
    
    int results[rolls];
    int sum = 0;
    
    printf("\nRolling a %d-sided die %d times:\n\n", sides, rolls);
    for(int i=0; i<rolls; i++) {
        int roll = rand()%sides + 1;
        printf("Roll %d: %d\n", i+1, roll);
        results[i] = roll;
        sum += roll;
    }
    
    float average = (float)sum/rolls;
    float variance = 0;
    
    for(int i=0; i<rolls; i++) {
        variance += ((float)results[i] - average)*((float)results[i] - average);
    }
    variance /= rolls;
    float stdev = sqrt(variance);
    
    printf("\nResults:\n");
    for(int i=0; i<rolls; i++) {
        printf("%d ", results[i]);
    }
    printf("\n\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Variance: %.2f\n", variance);
    printf("Standard deviation: %.2f", stdev);
    
    return 0;
}