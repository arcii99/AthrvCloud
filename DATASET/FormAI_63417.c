//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
    system("clear||cls");
}

void wait(int seconds) {
    int milliseconds = seconds * 1000;
    clock_t start_time = clock();

    while(clock() < start_time + milliseconds);
}

void print_dialogue(char *message) {
    printf("%s\n", message);
    wait(2);
}

void print_action(char *message) {
    printf("[*] %s\n", message);
    wait(1);
}

int main() {
    clear_screen();

    char name[20];
    printf("Welcome, traveler! What is your name?\n");
    scanf("%s", name);
    wait(1);
    printf("Nice to meet you, %s!\n", name);
    wait(1);

    print_dialogue("You have boarded your spacecraft and are ready to embark on an adventure through the galaxy.");

    int choice;
    printf("Which planet would you like to visit first?\n");
    printf("1. Andromeda\n");
    printf("2. Orion\n");
    scanf("%d", &choice);

    if(choice == 1) {
        print_action("Preparing for hyperspace jump to Andromeda.");
        wait(2);
        print_action("Hyperspace jump successful. You have arrived on Andromeda.");
        wait(1);
        print_dialogue("As you explore the planet, you come across a group of friendly aliens who offer to show you their civilization.");
        wait(1);
        print_dialogue("After spending some time with the aliens, you learn about their advanced technology and culture.");
        wait(1);
        print_dialogue("You leave Andromeda with new knowledge and a deeper appreciation for the diversity of life in the galaxy.");
    }

    else if(choice == 2) {
        print_action("Preparing for hyperspace jump to Orion.");
        wait(2);
        print_action("Hyperspace jump successful. You have arrived on Orion.");
        wait(1);
        print_dialogue("As you explore the planet, you come across a group of hostile aliens who attack you on sight.");
        wait(1);
        print_dialogue("You defend yourself with your spacecraft's weapons and manage to escape, but with significant damage to your ship.");
        wait(1);
        printf("[*] Ship health: 50%%\n");
        wait(1);
        print_dialogue("With your damaged ship, you are forced to make repairs and return to your home planet for repairs.");
    }

    else {
        print_dialogue("Sorry, that is not a valid choice.");
        return 1;
    }

    clear_screen();
    print_dialogue("Thank you for playing Space Adventure! Until next time, traveler.");

    return 0;
}