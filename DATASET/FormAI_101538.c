//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));
    int stock_values[10];
    char companies[10][20] = {"Microsoft", "Google", "Facebook", "Tesla", "Apple", "Amazon", "Intel", "Nvidia", "IBM", "HP"};
    int i, j, days;
    int gain[10] = {0};

    for(i = 0; i < 10; i++){
        stock_values[i] = rand() % 100 + 50;
        printf("%s : $%d\n", companies[i], stock_values[i]);
    }

    printf("\n");

    for(days = 1; days <= 7; days++){
        for(i = 0; i < 10; i++){
            int change = rand() % 21 - 10;
            gain[i] += change;
            int new_value = stock_values[i] + gain[i];
            if(new_value > 0){
                stock_values[i] = new_value;
                printf("%s : $%d [", companies[i], stock_values[i]);
                if(change > 0){
                    printf("+");
                }
                printf("%d]\n", change);
            }else{
                printf("%s has gone bankrupt.\n", companies[i]);
            }
        }
        printf("\n");

        if(days == 7){
            break;
        }else{
            printf("*****DAY %d*****\n", days);
        }
    }

    return 0;
}