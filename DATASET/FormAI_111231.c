//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 16

void generatePassword(char password[MAX_LENGTH+1]) {

    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "@#$%&!^";

    const char* sets[] = {lowercase, uppercase, digits, special};
    const int num_sets = sizeof(sets)/sizeof(*sets);

    srand((unsigned int)time(NULL));

    int i = 0;
    int set_index;

    for(i = 0; i < MAX_LENGTH; ++i) {
        
        set_index = rand() % num_sets;
        const char* selected_set = sets[set_index];
        int random_char_index = rand() % (int)(sizeof(selected_set)-1);
        password[i] = selected_set[random_char_index];
    }

    password[MAX_LENGTH] = '\0';
}

int main(void) {

    char password[MAX_LENGTH+1] = {0};

    generatePassword(password);

    printf("Generated password: %s\n", password);

    return 0;
}