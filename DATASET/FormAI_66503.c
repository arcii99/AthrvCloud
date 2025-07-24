//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_line(int n, char symbol);
void generate_fortune();

int main()
{
    srand(time(NULL));
    generate_fortune();
    return 0;
}

void draw_line(int n, char symbol)
{
    for (int i=0; i<n; i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}

void generate_fortune()
{
    char names[10][20] = {"Emily", "Jacob", "Sophia", "William", "Emma", "Michael", "Madison", "Ethan", "Ava", "Daniel"};
    char fortunes[10][100] = {"You will find love in the most unexpected place.",
                            "Your career will take a turn for the better.",
                            "A new opportunity will arise, take it!",
                            "Your creative juices will be flowing, embrace it!",
                            "Do not worry about the future, it is full of possibilities.",
                            "A long lost friend will reach out to you.",
                            "Money is coming your way, spend it wisely.",
                            "Take a break from your routine, it will do you good.",
                            "Your family will be your source of strength.",
                            "Your inner beauty will shine through and attract others."};
    int person_index = rand() % 10;
    int fortune_index = rand() % 10;
    char person[20];
    char fortune[100];
    sprintf(person, "%s,", names[person_index]);
    sprintf(fortune, "%s", fortunes[fortune_index]);
    draw_line(50, '-');
    printf("%s here is your fortune for the day:\n\n", person);
    printf("%s\n", fortune);
    draw_line(50, '-');
}