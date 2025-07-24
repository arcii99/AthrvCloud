//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include<stdio.h>
#include<math.h>

int main(){
    int num,i;
    printf("Enter the number till which prime numbers are to be generated:\n");
    scanf("%d",&num);
    printf("The prime numbers are:\n");

    // generating prime numbers
    for(i=2;i<=num;i++){
        int flag=1;

        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }

        if(flag==1){
            printf("%d ",i);
        }
    }

    return 0;
}