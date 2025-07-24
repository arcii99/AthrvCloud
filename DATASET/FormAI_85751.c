//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include<stdio.h>

int main(){
    // Declaring variables
    int a = 10, b = 20, c = 30, sum;
    float avg;
    char result;

    // Calculation
    sum = a + b + c;
    avg = sum / 3.0;

    // Result
    if(avg >= 60){
        result = 'A';
    }
    else if(avg >= 50){
        result = 'B';
    }
    else if(avg >= 40){
        result = 'C';
    }
    else{
        result = 'F';
    }

    // Happy message
    printf("Congrats! You have scored %.2f%% and got a grade of %c\n", avg, result);
    printf("You have made your parents proud and yourself satisfied with your achievement.");
    printf("Keep up the good work!");

    return 0;
}