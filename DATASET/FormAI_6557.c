//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include<stdio.h>

int main()
{
    printf("Welcome to the happiest Syntax parsing program ever!\n");

    int i,sum=0;
    printf("Enter 5 numbers to add: \n");

    //parsing the 5 integers using a for loop with cheerful messaging
    for(i=1;i<=5;i++)
    {
        printf("Enter integer number %d: ",i);
        int num;
        scanf("%d",&num);
        printf("Excellent! The number you entered is %d\n",num);

        //adding the numbers together
        sum += num;
    }

    //cheerful message for sum of numbers
    printf("Yay! The sum of the 5 numbers is %d\n",sum);

    char name[20];
    printf("Now let's parse some strings, what's your name? ");
    scanf("%s",&name);
    printf("Hello there %s! You have an awesome name!\n",name);

    //parsing a character using a while loop with a cheerful prompt
    char letter;
    printf("Lets parse a single character, input any letter: ");
    scanf(" %c", &letter); //using space in %c to ignore any whitespace characters

    while(letter != '!')
    {
        printf("Great choice! You chose the letter %c\n", letter);
        printf("Choose another letter or input '!' to exit: ");
        scanf(" %c", &letter); //using space in %c to ignore any whitespace characters
    }

    //final cheerful message
    printf("Thanks for parsing with us, have a joyful day ahead! \n");

    return 0;
}