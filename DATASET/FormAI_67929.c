//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lantern_charges = 3; // initialize lantern charges to 3

void printDescription() {
    printf("\nYou are standing in front of a haunted house. The house looks like it hasn't been lived in for years. \n");
    printf("You are feeling a bit unsure about whether you should enter or not. You can see a lantern next to the door. \n");
    printf("The door looks like it could be pushed open with a bit of force. You take a deep breath and consider your options. \n\n");
}

void printLanternCharges() {
    printf("You have %d charges left in your lantern. \n", lantern_charges);
}

int getRandomNumber(int min, int max) {
    srand(time(NULL)); // seed with current time
    return (rand() % (max - min + 1)) + min; // generate random number within range
}

void encounterEvent() {
    int event_number = getRandomNumber(1, 3); // generate random event number
    switch(event_number) {
        case 1: 
            printf("You hear a strange noise? Do you want to check it out? (Y/N)\n");
            char response;
            scanf(" %c", &response);
            if(response == 'Y') {
                printf("You cautiously approach the source of the noise. Suddenly, a ghostly figure appears in front of you! \n");
                printf("You quickly run outside back to the street. \n");
                return;
            } else {
                printf("You decide not to check out the noise. It could be dangerous. \n"); 
                return;
            }
        case 2: 
            printf("You see a strange glowing object in the corner of the room. Do you want to investigate? (Y/N)\n");
            char response2;
            scanf(" %c", &response2);
            if(response2 == 'Y') {
                printf("You walk towards the glowing object. Suddenly, it vanishes into thin air! \n");
                printf("That was spooky. \n");
                return;
            } else {
                printf("You decide not to investigate the glowing object. It's probably nothing. \n"); 
                return;
            }
        case 3: 
            printf("You hear someone or something breathing heavily. Do you want to investigate? (Y/N)\n");
            char response3;
            scanf(" %c", &response3);
            if(response3 == 'Y') {
                printf("You slowly move towards the sound. You suddenly realize it's just an old furnace. \n");
                printf("You laugh sheepishly and continue exploring. \n");
                return;
            } else {
                printf("You decide not to investigate the sound. It's probably just an old furnace. \n"); 
                return;
            }
    }
}

void enterHouse() {
    printf("You push the door open with a creak. You step inside, and the door slams shut behind you! \n");
    while(1) {
        if(lantern_charges == 0) {
            printf("Your lantern has run out of charges. You are in complete darkness. You get lost and can't find your way out. You died. \n");
            break;
        } else {
            printLanternCharges();
            printf("You are now inside the house. You hear strange noises all around you. \n");
            printf("What do you want to do? Type 1- Explore, 2- Use Lantern, 3- Exit House\n");
            int decision;
            scanf("%d", &decision);
            switch(decision) {
                case 1: 
                    encounterEvent();
                    break;
                case 2:
                    lantern_charges--;
                    printf("You use up one of your lantern's charges. The house is now a bit better lit. \n");
                    break;
                case 3:
                    printf("You've had enough of this place. You slowly make your way to the front door. \n");
                    printf("You push the door open and run out to the safety of the street. \n");
                    break;
                default:
                    printf("You can only type 1, 2 or 3. Please try again. \n");
            }
        }
    }
}

int main() {
    printDescription();
    enterHouse();
    return 0;
}