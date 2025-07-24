//FormAI DATASET v1.0 Category: System boot optimizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random seed

    // generate a random virus name
    char virus[25];
    char virus_prefix[7][15] = {"Zombie", "Mutant", "Toxic", "Radioactive", "Nuclear", "Decaying", "Infected"};
    char virus_suffix[7][15] = {"Virus", "Infection", "Plague", "Pandemic", "Outbreak", "Epidemic", "Contagion"};
    sprintf(virus, "%s %s", virus_prefix[rand() % 7], virus_suffix[rand() % 7]);

    // infecting system messages
    char messages[5][50] = {"Infecting network drivers... Done!", "Injecting executable files... Done!", "Overwriting system files... Done!", "Tampering with system registry... Done!", "Corrupting boot sector... Done!"};

    int i;
    for (i = 0; i < 5; i++) {
        printf("%s\n", messages[i]);
        sleep(2); // simulate processing time
    }

    printf("System boot optimizer successfully infected your system with %s!\n", virus);

    // randomize optimizations
    int optimization_1 = (rand() % 3) + 1; // choose from 1 to 3
    int optimization_2 = (rand() % 3) + 1;

    printf("Applying optimization %d...\n", optimization_1);
    sleep(2); // simulate processing time
    printf("Applying optimization %d...\n", optimization_2);
    sleep(2);

    printf("System boot optimizer has finished optimizing your system!\n");
    return 0;
}