//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_num;
    char response[20];
    
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question in your mind and I will tell you the answer.\n");
    printf("Are you ready?\n");
    fgets(response, 20, stdin);
    
    random_num = rand() % 5;
    
    switch(random_num)
    {
        case 0:
            printf("The answer is 'yes', it is definitely a good time to do it.\n");
            break;
        case 1:
            printf("The answer is 'no', it's not a good idea to proceed with your plan.\n");
            break;
        case 2:
            printf("I'm not sure, you might want to wait a little longer before making a decision.\n");
            break;
        case 3:
            printf("The signs are pointing toward 'yes', you have a good chance of success.\n");
            break;
        case 4:
            printf("It is better for you to not go ahead with your plans for now.\n");
            break;
        default:
            printf("Hmm, I'm having trouble connecting with the spirits right now, try asking again later.\n");
            break;
    }
    
    return 0;
}