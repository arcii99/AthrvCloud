//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>

int main(){
    int y = 100;
    char x[50] = "Energy Booster!";
    int count = 0;
    
    for(int i = 0; i < y; i++){
        if(i % 2 == 0){
            printf("%s \n", x);
        } else{
            printf("Code Fun! \n");
        }

        if(i == 25){
            printf("Halfway there! \n");
        }

        if(i == 74){
            printf("Almost there! \n");
        }

        if(i == y - 1){
            printf("Code complete! \n");
        }

        count++;
    }

    printf("Total lines of code: %d", count);

    return 0;
}