//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    
    time_t now = time(NULL);
    
    srand(now);

    int fortune = rand() % 5;

    switch(fortune) {
        case 0:
            printf("\n%s, a great opportunity awaits you in the near future. Keep your eyes open!\n", name);
            break;
        case 1:
            printf("\n%s, your hard work will pay off soon. Stay focused!\n", name);
            break;
        case 2:
            printf("\n%s, be careful of making impulsive decisions. Take time to think things through.\n", name);
            break;
        case 3:
            printf("\n%s, a new person will enter your life and bring positivity and happiness.\n", name);
            break;
        case 4:
            printf("\n%s, let go of your worries and enjoy the present moment. Everything will fall into place.\n", name);
            break;
        default:
            printf("\n%s, the future is uncertain. Focus on the present and make the most of every opportunity.\n", name);
            break;
    }

    return 0;
}