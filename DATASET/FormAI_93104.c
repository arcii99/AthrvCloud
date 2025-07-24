//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = { "The Government",
                    "The Illuminati",
                    "The Freemasons",
                    "The Alien Agenda",
                    "The New World Order",
                    "The Reptilian Overlords",
                    "The Deep State",
                    "The Rothschild Family",
                    "The Bilderberg Group",
                    "The Global Elite"
                  };
                  
char* actions[] = { "is controlling the media",
                    "is manipulating the economy",
                    "is spreading mind control through social media",
                    "is hiding the truth about the moon landing",
                    "is creating a fake spread of COVID-19 to control the population",
                    "is covering up the existence of extraterrestrial life",
                    "is manipulating the stock market",
                    "is behind every major tragedy",
                    "is responsible for the rise of AI",
                    "is trying to create a one-world government"
                  };

char* reasons[] = { "to maintain their power",
                    "to create a new world order",
                    "to usher in the apocalypse",
                    "to gain access to unlimited power and wealth",
                    "to enslave humanity",
                    "to create a utopian society for the elite",
                    "to prevent a global catastrophe",
                    "to protect the earth from a cosmic threat",
                    "to preserve the legacy of their bloodline",
                    "to pave the way for a new era of human evolution"
                  };

void generate_conspiracy()
{
    int s_length = sizeof(subjects)/sizeof(subjects[0]);
    int a_length = sizeof(actions)/sizeof(actions[0]);
    int r_length = sizeof(reasons)/sizeof(reasons[0]);
    int rand_s = rand() % s_length;
    int rand_a = rand() % a_length;
    int rand_r = rand() % r_length;
    printf("Did you know that %s %s %s!\n", subjects[rand_s], actions[rand_a], reasons[rand_r]);
}

int main()
{
    srand(time(NULL));
    printf("Welcome to The Random Conspiracy Theory Generator\n");
    printf("----TYPE \"exit\" TO LEAVE THE PROGRAM----\n");
    char user_input[10];
    while (1)
    {
        printf("Hit ENTER for a new Conspiracy Theory: ");
        fgets(user_input, 10, stdin);
        if (user_input[0] == 'e' && user_input[1] == 'x' && user_input[2] == 'i' && user_input[3] == 't')
        {
            printf("Goodbye!\n");
            break;
        }
        generate_conspiracy();
    }
    return 0;
}