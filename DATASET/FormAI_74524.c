//FormAI DATASET v1.0 Category: Pattern printing ; Style: irregular
#include<stdio.h>

int main(){
    int row = 1, space = 3, star = 1;
    while(row <= 6){
        int temp = space;
        while(temp){
            printf(" ");
            temp--;
        }
        if(row == 1 || row == 6){
            for(int i = 1; i <= 5; i++){
                printf("*");
            }
        }else{
            printf("*");
            int temp2 = star;
            while(temp2){
                printf(" ");
                temp2--;
            }
            printf("*");
            star += 2;
        }
        printf("\n");
        if(row <= 2){
            space--;
        }else{
            space++;
        }
        row++;
    }
    return 0;
}