//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include<stdio.h>
#include<math.h> 

int isPrime(int n){   //function to check if number is prime
    int i,m=0,flag=0;  
    m=n/2;  
    for(i=2;i<=m;i++)  
    {  
        if(n%i==0)  //not a prime if divisible by any number other than itself and 1
        {  
            flag=1;  
            break;  
        }  
    }  
    if(flag==0)  
        return 1;  
    else  
        return 0;    
}  

void generatePrime(int start, int end){  //function to generate prime numbers within the given range
    int i,flag;  
    printf("Prime numbers between %d and %d are:\n",start,end);  

    for(i=start;i<=end;i++)  //iterate through the range
    {  
        flag=isPrime(i);  
        if(flag==1)  //if the number is prime, print it
            printf("%d\n",i);  
    }  
}  

int main(){  //main function to take input and call the function to generate primes
    int start, end;  

    printf("Enter lower and upper limits: ");  
    scanf("%d %d",&start,&end);  

    generatePrime(start,end);  

    return 0;  
}