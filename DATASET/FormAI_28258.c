//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); //set seed for random number generator

    float val = 100.0; //starting value
    float volatility = 0.1; //random fluctuation range
    float max_gain = 0.5; //maximum possible daily gain
    float max_loss = -0.2; //maximum possible daily loss

    printf("Starting value: $%0.2f\n", val);

    for(int i=1; i<=365; i++){
        float daily_change = (float)rand()/(float)(RAND_MAX/volatility);
        if(daily_change > max_gain) daily_change = max_gain;
        else if(daily_change < max_loss) daily_change = max_loss;

        float new_val = val + (val * daily_change);
        printf("Day %d: $%0.2f (%0.2f%% change)\n", i, new_val, (new_val-val)/val*100.0);
        val = new_val;
    }

    printf("Final value: $%0.2f\n", val);
    return 0;
}