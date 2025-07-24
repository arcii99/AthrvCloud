//FormAI DATASET v1.0 Category: Funny ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the joke program!\n");
    printf("Today we're going to generate some silly jokes.\n");

    //setup punchlines and jokes
    char *punchline1 = "Because he wanted to see time fly!";
    char *joke1 = "Why did the physicist bring a clock to the lab?";

    char *punchline2 = "Because she wanted to see the water QWERTY!";
    char *joke2 = "Why did the computer scientist go scuba diving?";

    char *punchline3 = "Press F to pay respects.";
    char *joke3 = "Why did the gamer buy a flower shop?";

    char *punchline4 = "Because he wanted to get a byte to eat!";
    char *joke4 = "Why did the computer eat his homework?";

    //generate random number for joke selection
    int rand_num = rand() % 4 + 1;

    switch(rand_num){
        case 1:
            printf("%s\n", joke1);
            printf("%s\n", punchline1);
            break;
        case 2:
            printf("%s\n", joke2);
            printf("%s\n", punchline2);
            break;
        case 3:
            printf("%s\n", joke3);
            printf("%s\n", punchline3);
            break;
        case 4:
            printf("%s\n", joke4);
            printf("%s\n", punchline4);
            break;
        default:
            printf("Something went wrong, try again later.\n");
    }

    return 0;
}