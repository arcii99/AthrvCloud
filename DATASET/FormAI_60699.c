//FormAI DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>

int main()
{
    int num, i, sum=0;

    printf("Enter a positive integer: ");
    scanf("%d",&num);

    if(num<=0){
        printf("Invalid input!");
        return 0;
    }
    
    for(i=1;i<num;i++){
        if(num%i==0)
            sum+=i;
    }

    if(sum==num){
        printf("%d is a Perfect number\n",num);
    }
    else{
        printf("%d is not a Perfect number\n",num);
    }
    
    return 0;
}