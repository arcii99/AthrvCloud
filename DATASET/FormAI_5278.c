//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Define conspiracy theories
    char theories[10][100] = {
        "The moon landing was staged by the government",
        "The Illuminati controls the world's governments",
        "9/11 was an inside job",
        "The Earth is flat",
        "Chemtrails are being used for mind control",
        "The government controls the weather",
        "Aliens have been visiting Earth for centuries",
        "The Titanic didn't sink, it was her sister ship",
        "The cure for cancer exists but is being hidden by pharmaceutical companies",
        "The world will end in 2022"};

    // Define conspiracy theory 'evidence'
    char evidence[5][100] = {
        "I saw it on the internet",
        "My friend's cousin's uncle's dog told me",
        "It just makes sense, you know?",
        "I read it in a book",
        "My dreams told me so"};

    // Define conspiracy theory 'targets'
    char targets[5][100] = {
        "The government",
        "Globalists",
        "The elite",
        "Big pharma",
        "The media"};

    // Generate random conspiracy theory
    int r_theory = rand() % 10;
    int r_evidence = rand() % 5;
    int r_targets = rand() % 5;

    // Print random conspiracy theory
    printf("Conspiracy Theory: %s\n", theories[r_theory]);
    printf("Evidence: %s\n", evidence[r_evidence]);
    printf("Targets: %s\n", targets[r_targets]);

    return 0;
}