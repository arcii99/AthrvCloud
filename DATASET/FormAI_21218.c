//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int main(){
    int limit, i, j, flag;
    printf("Enter the upper limit: ");
    scanf("%d", &limit);
    printf("Prime numbers between 2 and %d are: \n",limit);

    for(i=2; i<=limit; i++){
        flag = 1;
        for(j=2; j<=i/2; j++){
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        
        if(flag==1){
            printf("%d\n", i);
        }
    }
    return 0;
}