//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inventory[20][20]; //Inventory to store collected items
int inventory_count = 0; //Count of collected items

void print_separator() {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void print_inventory() {
    printf("\nInventory:\n");
    for(int i=0; i<inventory_count; i++) {
        printf("%s\n", inventory[i]);
    }
}

void get_input(char* input, int size) {
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0; //Remove trailing newline character
}

int main() {
    char name[20];
    printf("Welcome to Ephemeral Adventure Game!\n");
    printf("What's your name?\n");
    get_input(name, 20);
    
    printf("\nHi, %s! Let's begin your adventure.\n", name);
    printf("\nYou find yourself in the middle of a forest. There are three paths in front of you.\n");
    
    while(1) {
        print_separator();
        printf("Which path will you take? (left, middle, right)\n");
        char choice[10];
        get_input(choice, 10);
        
        if(strcmp(choice, "left")==0) {
            printf("\nYou've chosen the left path.\n");
            printf("You come across a river. You can either swim or find a bridge.\n");
            while(1) {
                print_separator();
                printf("What will you do? (swim, find bridge)\n");
                get_input(choice, 10);
                if(strcmp(choice, "swim")==0) {
                    printf("\nYou try to swim across the river and get swept away by strong currents. You drown and die.\n");
                    return 0;
                }
                else if(strcmp(choice, "find bridge")==0) {
                    printf("\nYou find a bridge and cross the river safely.\n");
                    break;
                }
                else {
                    printf("\nI don't understand your choice.\n");
                }
            }
            printf("\nYou come across a hut. Do you want to enter? (yes, no)\n");
            while(1) {
                print_separator();
                get_input(choice, 10);
                if(strcmp(choice, "yes")==0) {
                    printf("\nYou enter the hut and find a key.\n");
                    strcpy(inventory[inventory_count], "key");
                    inventory_count++;
                    break;
                }
                else if(strcmp(choice, "no")==0) {
                    printf("\nYou walk past the hut.\n");
                    break;
                }
                else {
                    printf("\nI don't understand your choice.\n");
                }
            }
            printf("\nYou continue on the left path.\n");
        }
        else if(strcmp(choice, "middle")==0) {
            printf("\nYou've chosen the middle path.\n");
            printf("You come across a tree with apples. Do you want to eat one? (yes, no)\n");
            while(1) {
                print_separator();
                get_input(choice, 10);
                if(strcmp(choice, "yes")==0) {
                    printf("\nYou eat an apple and feel better.\n");
                    break;
                }
                else if(strcmp(choice, "no")==0) {
                    printf("\nYou walk past the tree.\n");
                    break;
                }
                else {
                    printf("\nI don't understand your choice.\n");
                }
            }
            printf("\nThe path leads to a dead end. You turn back and choose a different path.\n");
        }
        else if(strcmp(choice, "right")==0) {
            printf("\nYou've chosen the right path.\n");
            printf("You come across a cave. Do you want to enter? (yes, no)\n");
            while(1) {
                print_separator();
                get_input(choice, 10);
                if(strcmp(choice, "yes")==0) {
                    if(inventory_count == 0) {
                        printf("\nYou don't have anything to light your way. You stumble in darkness and get lost. You die.\n");
                        return 0;
                    }
                    else {
                        printf("\nYou enter the cave and find a treasure chest. You use the key to unlock it.\nInside, you find a map that leads to a hidden treasure.\n");
                        for(int i=0; i<inventory_count; i++) {
                            if(strcmp(inventory[i], "key") == 0) {
                                strcpy(inventory[i], "");
                                break;
                            }
                        }
                        break;
                    }
                }
                else if(strcmp(choice, "no")==0) {
                    printf("\nYou walk past the cave.\n");
                    break;
                }
                else {
                    printf("\nI don't understand your choice.\n");
                }
            }
            printf("\nYou continue on the right path.\n");
        }
        else {
            printf("\nI don't understand your choice.\n");
        }
        
        printf("\nDo you want to check your inventory? (yes, no)\n");
        while(1) {
            print_separator();
            get_input(choice, 10);
            if(strcmp(choice, "yes")==0) {
                print_inventory();
                break;
            }
            else if(strcmp(choice, "no")==0) {
                break;
            }
            else {
                printf("\nI don't understand your choice.\n");
            }
        }
        
        printf("\nDo you want to continue your adventure? (yes, no)\n");
        while(1) {
            print_separator();
            get_input(choice, 10);
            if(strcmp(choice, "yes")==0) {
                break;
            }
            else if(strcmp(choice, "no")==0) {
                printf("\nThanks for playing, %s! Goodbye.\n", name);
                return 0;
            }
            else {
                printf("\nI don't understand your choice.\n");
            }
        }
    }
    
    return 0;
}