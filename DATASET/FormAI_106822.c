//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age, lucky_num, fortune_num, n1, n2, n3;
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hi %s, please enter your age: ", name);
    scanf("%d", &age);
    printf("Enter your lucky number: ");
    scanf("%d", &lucky_num);
    
    // Generate fortune number
    srand(time(0));
    n1 = rand() % 10;
    n2 = rand() % 10;
    n3 = rand() % 10;
    fortune_num = (n1 * 100) + (n2 * 10) + n3;
    
    // Determine message based on age and lucky number
    if (age < 18 && lucky_num % 2 == 0)
    {
        printf("\n%s, you may face some challenges in the near future, but with perseverance, you will overcome them.\nYour lucky number %d will bring you abundance, keep working hard!\n", name, lucky_num);
        printf("Your fortune number is %d.\n", fortune_num);
    }
    else if (age < 18 && lucky_num % 2 != 0)
    {
        printf("\n%s, you are a resilient individual and will emerge victorious in any challenges you face.\nYour lucky number %d will bring you prosperity, keep an optimistic outlook!\n", name, lucky_num);
        printf("Your fortune number is %d.\n", fortune_num);
    }
    else if (age >= 18 && lucky_num % 2 == 0)
    {
        printf("\n%s, you are a hard worker and your efforts will pay off soon.\nYour lucky number %d will attract success in your career and personal life, keep working smart!\n", name, lucky_num);
        printf("Your fortune number is %d.\n", fortune_num);
    }
    else if (age >= 18 && lucky_num % 2 != 0)
    {
        printf("\n%s, you have a great personality and people love being around you.\nYour lucky number %d will bring new friendships and connections, keep being yourself!\n", name, lucky_num);
        printf("Your fortune number is %d.\n", fortune_num);
    }
    
    return 0;
}