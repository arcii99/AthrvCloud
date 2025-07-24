//FormAI DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>

int main()
{
    int love = 1;
    int heartbeats[1000];
    int total_heartbeats = 0;
    
    printf("I hear your heartbeats...\n");
    while (love) {
        for (int i = 0; i < 1000; i++) {
            heartbeats[i] = i + 1;
            total_heartbeats += heartbeats[i];
        }
        printf("Together our hearts beat as one,\nTotal heartbeats: %d\n", total_heartbeats);
        
        /* DSP magic to filter out noise and amplify love */
        for (int i = 0; i < 1000; i++) {
            if (heartbeats[i] % 2 == 0) {
                heartbeats[i] *= 2;
            }
            else {
                heartbeats[i] -= 1;
            }
        }
        
        /* Check if love is still strong */
        if (total_heartbeats > 100000) {
            printf("Our love is strong and true,\nThe signal is clear and pure.\n");
        }
        else if (total_heartbeats > 50000 && total_heartbeats <= 100000) {
            printf("Our love is growing every day,\nAnd our signal is getting stronger each way.\n");
        }
        else if (total_heartbeats > 25000 && total_heartbeats <= 50000) {
            printf("Our love is still young, but it's growing fast,\nAnd the signal shows it's built to last.\n");
        }
        else {
            printf("Our love is still in its infancy,\nBut the signal shows that it's filled with potency.\n");
        }
        
        /* Ask for user input to check if love is still strong */
        char input[5];
        printf("Do you love me too? (y/n): ");
        scanf("%s", input);
        if (input[0] == 'n') {
            printf("Our signal grows weaker by the minute,\nIt's time for us to end it now and stop this spin it.\n");
            love = 0;
        }
        else {
            printf("Our signal grows stronger with each passing moment,\nOur love will always be a true endearment.\n");
        }
    }
    
    return 0;
}