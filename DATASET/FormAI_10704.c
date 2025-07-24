//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void print_shocked(char* text) {
    printf("\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        delay(50);
    }
    printf("\n");
}

void game_over() {
    print_shocked("GAME OVER!");
    exit(0);
}

int main() {
    print_shocked("You wake up in a dark, musty room. Your head aches, and you can't remember how you got here.");
    print_shocked("Do you (1) try to open the door or (2) look for a way out of the window?");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        print_shocked("The door won't budge. You try with all your might, but it just won't open.");
        print_shocked("Do you (1) keep trying or (2) search the room for clues?");
        scanf("%d", &choice);
        
        if (choice == 1) {
            print_shocked("You keep trying the door, but it's no use. Eventually, you tire out and slump to the ground in defeat.");
            game_over();
        }
        else if (choice == 2) {
            print_shocked("You start searching the room. There's not much here - just a bed, a nightstand, and a small window high up on the wall.");
            print_shocked("Do you (1) search the nightstand or (2) try to climb out the window?");
            scanf("%d", &choice);
            
            if (choice == 1) {
                print_shocked("You open the drawer of the nightstand and find a small key.");
                print_shocked("Do you (1) try the key on the door or (2) try to reach the window with the key?");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    print_shocked("You try the key on the door, and it unlocks with a satisfying click.");
                    print_shocked("Congratulations! You've escaped the room!");
                    exit(0);
                }
                else if (choice == 2) {
                    print_shocked("You try to reach the window with the key, but it's too high up to reach.");
                    game_over();
                }
            }
            else if (choice == 2) {
                print_shocked("You try to climb out the window, but it's too small and high up to get through.");
                game_over();
            }
        }
    }
    else if (choice == 2) {
        print_shocked("You try to open the window, but it's sealed shut.");
        print_shocked("Do you (1) keep trying or (2) look for a way out of the door?");
        scanf("%d", &choice);
        
        if (choice == 1) {
            print_shocked("No matter how hard you try, the window won't budge.");
            game_over();
        }
        else if (choice == 2) {
            print_shocked("You head towards the door, but it won't open.");
            print_shocked("Do you (1) keep trying or (2) look for a way to unlock it?");
            scanf("%d", &choice);
            
            if (choice == 1) {
                print_shocked("You spend a long time trying to open the door, but it won't budge.");
                game_over();
            }
            else if (choice == 2) {
                print_shocked("You search the room for a key, and find one hidden under the bed.");
                print_shocked("Do you (1) try the key on the door or (2) try to break the window with the key?");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    print_shocked("You try the key on the door, and it unlocks with a satisfying click.");
                    print_shocked("Congratulations! You've escaped the room!");
                    exit(0);
                }
                else if (choice == 2) {
                    print_shocked("You try to break the window with the key, but it just bounces off the glass.");
                    game_over();
                }
            }
        }
    }
    
    return 0;
}