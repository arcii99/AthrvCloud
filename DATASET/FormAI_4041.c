//FormAI DATASET v1.0 Category: Date and time ; Style: mathematical
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    time_t currentTime;
    struct tm *localTime;
    int year, month, day, hour, minute, second;
    
    time( &currentTime );
    localTime = localtime( &currentTime );

    year = localTime->tm_year + 1900;
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
    second = localTime->tm_sec;

    printf("Current Date and Time is:%d-%d-%d %d:%d:%d\n",year,month,day,hour,minute,second);
    printf("Enter two numbers to perform mathematical operations\n");
    int num1, num2, choose;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Choose an operation to perform: \n");
    printf("1. Addition \n2. Subtraction \n3. Multiplication\n");
    printf("Your choice: ");
    scanf("%d", &choose);

    switch(choose)
    {
      case 1: printf("Addition result is %d\n", num1+num2);
              break;
      case 2: printf("Subtraction result is %d\n", num1-num2);
              break;
      case 3: printf("Multiplication result is %d\n", num1*num2);
              break;
      default: printf("Invalid choice\n");
    }

    return 0; 
}