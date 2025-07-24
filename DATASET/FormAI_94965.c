//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include<stdio.h>

int main(){
    int num, i, prime=1;
    printf("Enter a number: ");
    scanf("%d",&num);

    if(num==2 || num==3){
        printf("%d is a prime number\n",num);
    }
    else if(num%2==0){
        printf("%d is not a prime number\n",num);
        prime=0;
    }
    else{
        for(i=3; i<num; i+=2){
            if(num%i==0){
                printf("%d is not a prime number\n",num);
                prime=0;
                break;
            }
        }
        if(prime){
            printf("%d is a prime number\n",num);
        }
    }
    return 0;
}