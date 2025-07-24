//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* conspiracy()
{
    char* theories[] = {
        "The earth is flat and the government is hiding it from us",
        "The moon landing was faked by NASA",
        "9/11 was an inside job",
        "Chemtrails are a government plot to control the population",
        "The Illuminati secretly control world events",
        "Aliens have already made contact with the US government",
        "The government is hiding the cure for cancer to make money off treatments",
        "COVID-19 was created in a lab and intentionally released for population control"
    };

    int n = sizeof(theories) / sizeof(theories[0]);
    int index = rand() % n;
    char* theory = malloc(strlen(theories[index]) + 1);
    strcpy(theory, theories[index]);
    return theory;
}

int main()
{
    srand(time(NULL));
    int i;
    for(i = 0; i < 10; i++)
    {
        char* theory = conspiracy();
        printf("%d. %s\n", i+1, theory);
        free(theory);
    }
    return 0;
}