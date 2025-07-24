//FormAI DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dice_num, roll_times, result;
    printf("Enter the number of dice: ");
    scanf("%d", &dice_num);
    printf("Enter the number of times to roll: ");
    scanf("%d", &roll_times);
    srand(time(NULL)); // seeds the random number generator with the current time
    for(int i=1; i<= roll_times; i++){
        printf("Roll %d: ", i);
        result = 0;
        for(int j=1; j<=dice_num; j++){
            int roll = rand() % 6 + 1; // generates a random number between 1 and 6
            printf("%d ", roll);
            result += roll;
        }
        printf("= %d\n", result);
    }
    return 0;
}