//FormAI DATASET v1.0 Category: Funny ; Style: synchronous
#include <stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You entered %d. Let's do some funny calculations!\n", num);
    int sum = 0;
    int product = 1;
    for(int i = 1; i <= num; i++){
        if(i%2==0){
            //if even number
            sum += i;
        }else{
            //if odd number
            product *= i;
        }
    }

    printf("The sum of all even numbers between 1 and %d is %d.\n", num, sum);
    printf("The product of all odd numbers between 1 and %d is %d.\n", num, product);

    //Let's crack a joke
    printf("Why do programmers prefer dark mode?\n");
    printf("Because light attracts bugs!\n");

    //Let's print a funny arrow
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("->\n");
    }

    return 0;
}