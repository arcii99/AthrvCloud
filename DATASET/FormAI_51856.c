//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input;
    srand(time(NULL));

    printf("Welcome to the Surrealist Fortune Teller.\n\nThink of your question, and press enter to receive an answer.\n\n");
    
    do {
        printf("Q: ");
        scanf("%c", &input);

        int rand_num = rand() % 9;

        switch (rand_num)
        {
        case 0:
            printf("The answer to your question lies in the shadow of the overturned turtle.\n");
            break;

        case 1:
            printf("The butterfly of fate flaps its wings, causing a hurricane of decisions. Choose wisely.\n");
            break;

        case 2:
            printf("The clock of destiny ticks ever onward. Your time is running out.\n");
            break;

        case 3:
            printf("The goblins who haunt the answers of fate are not kind. Beware their mischief.\n");
            break;

        case 4:
            printf("The tarot cards whisper secrets to those who can hear. Are you listening?\n");
            break;

        case 5:
            printf("The ouija board trembles with spectral anticipation. Are you brave enough to seek its guidance?\n");
            break;

        case 6:
            printf("The stars align in a mysterious pattern. Their message is unclear, but it seems ominous.\n");
            break;

        case 7:
            printf("The tea leaves form a shape you do not recognize. It is an omen of things to come.\n");
            break;

        case 8:
            printf("The crystal ball clouds with visions. The future is never set in stone, but it is always unpredictable.\n");
            break;

        default:
            printf("The spirits are silent. Perhaps they do not wish to answer this question.\n");
            break;
        }

        printf("\nDo you have another question? (y/n) ");
        scanf(" %c", &input);
    } while (input == 'y');

    return 0;
}