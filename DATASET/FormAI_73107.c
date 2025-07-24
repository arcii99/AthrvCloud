//FormAI DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_OPTIONS 5
#define MAX_CHOICES 10

typedef struct {
    char* text;
    int outcomes[MAX_CHOICES];
    int num_choices;
} Option;

typedef struct {
    char* text;
    Option options[MAX_OPTIONS];
    int num_options;
} Room;

// Function declarations
void print_options(Option* options, int num_options);
void print_choices(Room* room);
int get_choice(Room* room);
void print_outcome(Room* room, int outcome);

// Main function
int main() {
    // Initialize the rooms of the haunted mansion
    Room rooms[] = {
        { "Foyer", 
          { { "Go through the front door", { 1 }, 1 },
            { "Explore the coat closet", { 2 }, 1 },
            { "Check the mail slots", { 3 }, 1 },
            { "Descend the staircase", { 4 }, 1 }
          },
          4
        },
        { "Coat Closet",
          { { "Check the coats", { 0 }, 1 },
            { "Return to the foyer", { 0 }, 1 }
          },
          2
        },
        { "Mail Slots",
          { { "Open letter from deceased owner", { 5 }, 1 },
            { "Return to the foyer", { 0 }, 1 }
          },
          2
        },
        { "Staircase",
          { { "Go up the stairs", { 6 }, 1 },
            { "Go down the stairs", { 7 }, 1 },
            { "Return to the foyer", { 0 }, 1 }
          },
          3
        },
        { "Upper Landing",
          { { "Enter bedroom", { 8 }, 1 },
            { "Enter bathroom", { 9 }, 1 },
            { "Return to staircase", { 3 }, 1 }
          },
          3
        },
        { "Study",
          { { "Search desk", { 10 }, 1 },
            { "Return to upper landing", { 4 }, 1 }
          },
          2
        },
        { "Attic",
          { { "Search treasure chest", { 11 }, 1 },
            { "Return to lower level", { 3 }, 1 }
          },
          2
        },
        { "Basement",
          { { "Find exit", { 12 }, 1 },
            { "Return to staircase", { 3 }, 1 }
          },
          2
        },
        { "Bedroom",
          { { "Find key", { 13 }, 1 },
            { "Search closet", { 14 }, 1 },
            { "Return to upper landing", { 4 }, 1 }
          },
          3
        },
        { "Bathroom",
          { { "Search medicine cabinet", { 15 }, 1 },
            { "Return to upper landing", { 4 }, 1 }
          },
          2
        },
        { "Desk",
          { { "Read journal", { 16 }, 1 },
            { "Return to study", { 5 }, 1 }
          },
          2
        },
        { "Treasure Chest",
          { { "Find map", { 17 }, 1 },
            { "Return to attic", { 6 }, 1 }
          },
          2
        },
        { "Exit",
          { { "Congratulations! You have escaped the haunted mansion!", { -1 }, 1 } },
          1
        },
        { "Key",
          { { "Unlock the door to the exit", { 12 }, 1 } },
          1
        },
        { "Closet",
          { { "Find dress shoes", { 18 }, 1 },
            { "Return to bedroom", { 8 }, 1 }
          },
          2
        },
        { "Medicine Cabinet",
          { { "Find healing potion", { 19 }, 1 },
            { "Return to bathroom", { 9 }, 1 }
          },
          2
        },
        { "Journal",
          { { "Notes reveal secret passage", { 20 }, 1 },
            { "Return to study", { 5 }, 1 }
          },
          2
        },
        { "Map",
          { { "Use map to find hidden staircase", { 21 }, 1 },
            { "Return to attic", { 6 }, 1 }
          },
          2
        },
        { "Dress Shoes",
          { { "Find key hidden in heel", { 13 }, 1 },
            { "Return to closet", { 14 }, 1 }
          },
          2
        },
        { "Healing Potion",
          { { "Drink potion and gain strength", { 22 }, 1 },
            { "Return to medicine cabinet", { 15 }, 1 }
          },
          2
        },
        { "Secret Passage",
          { { "Climb down to the basement for an alternate exit", { 12 }, 1 },
            { "Return to study", { 5 }, 1 }
          },
          2
        },
        { "Hidden Staircase",
          { { "Descend staircase to escape", { 12 }, 1 },
            { "Return to attic", { 6 }, 1 }
          },
          2
        },
        { "Strength Boost",
          { { "Use renewed strength to break down door", { -1 }, 1 } },
          1
        },
        { "Key in Heel",
          { { "Unlock door to escape", { -1 }, 1 } },
          1
        },
        { "Alternate Exit",
          { { "Congratulations! You have escaped the haunted mansion!", { -1 }, 1 } },
          1
        },
    };

    // Start the game in the foyer
    Room* current_room = &rooms[0];

    // Loop until the player escapes or quits
    while (true) {
        // Print the room's description and available options
        printf("%s\n", current_room->text);
        print_choices(current_room);

        // Get the player's choice
        int choice = get_choice(current_room);

        // Print the outcome and update the current room
        print_outcome(current_room, current_room->options[choice].outcomes[0]);
        if (current_room->options[choice].outcomes[0] == -1) {
            break;
        }
        current_room = &rooms[current_room->options[choice].outcomes[0]];
    }

    return 0;
}

// Prints a list of options to the console.
void print_options(Option* options, int num_options) {
    for (int i = 0; i < num_options; i++) {
        printf("%d. %s\n", i + 1, options[i].text);
    }
}

// Prints a list of choices for the current room to the console.
void print_choices(Room* room) {
    printf("Choose one of the following actions:\n");
    print_options(room->options, room->num_options);
}

// Gets the player's choice from the console.
int get_choice(Room* room) {
    int choice;
    do {
        printf("> ");
        scanf("%d", &choice);
        choice--;
    } while (choice < 0 || choice >= room->num_options);
    return choice;
}

// Prints the outcome of the player's choice to the console.
void print_outcome(Room* room, int outcome) {
    if (outcome < 0) {
        return;
    }
    printf("%s\n", room->options[outcome].text);
}