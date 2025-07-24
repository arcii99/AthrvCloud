//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include<stdio.h> 

int main(){ 

int num=0,den=0,result=0;

//Taking user input

printf("Enter the numerator value:");
scanf("%d",&num);
printf("Enter the denominator value:");
scanf("%d",&den);

//Handling divide by zero error

if(den==0){
    printf("Error: Denominator can't be zero");
}else{
    //Normal division operation
    result=num/den;
    printf("%d/%d = %d",num,den,result);
} 

return 0;  
}