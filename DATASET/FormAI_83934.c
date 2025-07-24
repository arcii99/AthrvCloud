//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random conspiracy theory
char* generate_conspiracy() {
    // array of conspiracy theories
    char* theories[] = {"The moon landing was a hoax!",
                        "The government is controlling our thoughts with chemtrails!",
                        "The Illuminati is behind world events!",
                        "Vaccines cause autism!",
                        "The earth is flat!",
                        "9/11 was an inside job!",
                        "Aliens exist and the government is hiding it!"};

    // generate a random index
    srand(time(NULL));
    int index = rand() % 7;

    // allocate enough memory for the theory and copy it into a new string variable
    char* theory = malloc(sizeof(char) * (strlen(theories[index]) + 1));
    strcpy(theory, theories[index]);

    return theory;
}

int main() {
    printf("~~~ C Random Conspiracy Theory Generator ~~~\n\n");

    // print 10 random conspiracy theories
    for(int i = 0; i < 10; i++) {
        char* theory = generate_conspiracy();
        printf("%d. %s\n", i+1, theory);
        free(theory);
    }

    printf("\nStay woke!\n");

    return 0;
}