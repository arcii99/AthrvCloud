//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LEN 20
#define MAX_ROOMS 10
#define MAX_PASSAGES 20
#define MAX_ITEMS 5

typedef struct {
    char name[MAX_INPUT_LEN];
    char description[100];
}item;

typedef struct{
    char name[MAX_INPUT_LEN];
    char description[100];
    item items[MAX_ITEMS];
    int num_items;
}room;

typedef struct{
    char direction[MAX_INPUT_LEN];
    int origin_room;
    int destination_room;
}passage;

void clear_input();

int main(){
    int current_room = 0;
    int num_rooms = 4;
    int num_passages = 5;
    int i, j, choice, found_item = 0;
    char input[MAX_INPUT_LEN];
    char *p;
    srand(time(NULL));
    
    room rooms[MAX_ROOMS] = {
        {"Kitchen", "A room with a stove and sink. There's a fridge in the corner."},
        {"Bathroom", "There's a toilet and sink in here. Everything looks clean."},
        {"Bedroom", "There's a bed, dresser, and mirror in here. The sheets look freshly washed."},
        {"Living Room", "A cozy room with a couch, TV, and coffee table."},
    };
    
    passage passages[MAX_PASSAGES] = {
        {"north", 0, 1},
        {"east", 0, 3},
        {"west", 1, 3},
        {"south", 2, 0},
        {"east", 2, 1},
    };
    
    rooms[0].num_items = 2;
    strncpy(rooms[0].items[0].name, "key", MAX_INPUT_LEN);
    strncpy(rooms[0].items[0].description, "A small key with a silver handle.", 100);
    strncpy(rooms[0].items[1].name, "note", MAX_INPUT_LEN);
    strncpy(rooms[0].items[1].description, "The note reads: 'The combination is 1432.'", 100);
    
    rooms[1].num_items = 1;
    strncpy(rooms[1].items[0].name, "candle", MAX_INPUT_LEN);
    strncpy(rooms[1].items[0].description, "A small white candle that smells like vanilla.", 100);
    
    printf("Welcome to the game!\n");
    printf("You are in the %s.\n", rooms[current_room].name);
    printf("%s\n", rooms[current_room].description);
    
    while(1){
        printf("What would you like to do?\n");
        printf("[1] Look around\n");
        printf("[2] Move to another room\n");
        printf("[3] Pick up an item\n");
        printf("[4] Use an item\n");
        printf("[5] Quit\n");
        fgets(input, MAX_INPUT_LEN, stdin);
        sscanf(input, "%d", &choice);
        clear_input();
        switch(choice){
            case 1:
                printf("You look around the room.\n");
                printf("%s\n", rooms[current_room].description);
                if(rooms[current_room].num_items > 0){
                    printf("You see the following items: ");
                    for(i=0;i<rooms[current_room].num_items;i++){
                        printf("%s", rooms[current_room].items[i].name);
                        if(i != rooms[current_room].num_items - 1){
                            printf(", ");
                        }
                    }
                    printf("\n");
                }
                break;
            case 2:
                printf("Which direction would you like to move?\n");
                for(i=0;i<num_passages;i++){
                    if(passages[i].origin_room == current_room){
                        printf("%s\n", passages[i].direction);
                    }
                }
                fgets(input, MAX_INPUT_LEN, stdin);
                input[strlen(input)-1] = '\0';
                for(i=0;i<num_passages;i++){
                    if(passages[i].origin_room == current_room && strcmp(passages[i].direction, input) == 0){
                        current_room = passages[i].destination_room;
                        printf("You move to the %s.\n", rooms[current_room].name);
                        printf("%s\n", rooms[current_room].description);
                        break;
                    }
                }
                if(i == num_passages){
                    printf("You can't move that way.\n");
                }
                break;
            case 3:
                found_item = 0;
                printf("Which item would you like to pick up?\n");
                for(i=0;i<rooms[current_room].num_items;i++){
                    printf("%s\n", rooms[current_room].items[i].name);
                }
                fgets(input, MAX_INPUT_LEN, stdin);
                input[strlen(input)-1] = '\0';
                for(i=0;i<rooms[current_room].num_items;i++){
                    if(strcmp(rooms[current_room].items[i].name, input) == 0){
                        found_item = 1;
                        if(rand() % 2 == 0){
                            printf("You picked up the %s.\n", rooms[current_room].items[i].name);
                            rooms[current_room].num_items--;
                            for(j=0;j<MAX_ITEMS;j++){
                                if(rooms[current_room].items[j].name[0] == '\0'){
                                    strncpy(rooms[current_room].items[j].name, input, MAX_INPUT_LEN);
                                    strncpy(rooms[current_room].items[j].description, rooms[current_room].items[i].description, 100);
                                    break;
                                }
                            }
                            break;
                        }
                        else{
                            printf("You try to pick up the %s, but you can't seem to get a grip on it.\n", rooms[current_room].items[i].name);
                            break;
                        }
                    }
                }
                if(found_item == 0){
                    printf("You don't see that item in this room.\n");
                }
                break;
            case 4:
                found_item = 0;
                printf("Which item would you like to use?\n");
                for(i=0;i<MAX_ITEMS;i++){
                    if(rooms[current_room].items[i].name[0] != '\0'){
                        printf("%s\n", rooms[current_room].items[i].name);
                    }
                }
                fgets(input, MAX_INPUT_LEN, stdin);
                input[strlen(input)-1] = '\0';
                for(i=0;i<MAX_ITEMS;i++){
                    if(strcmp(rooms[current_room].items[i].name, input) == 0){
                        found_item = 1;
                        if(strcmp(rooms[current_room].items[i].name, "key") == 0 && current_room == 1){
                            printf("You used the key to unlock the door to the bedroom!\n");
                            passages[2].origin_room = 1;
                            passages[4].destination_room = 3;
                            break;
                        }
                        else if(strcmp(rooms[current_room].items[i].name, "note") == 0 && current_room == 3){
                            printf("You used the note to figure out the combination to the safe!\n");
                            printf("The safe opens and reveals a large diamond inside.\n");
                            return 0;
                        }
                        else{
                            printf("You can't use that item here.\n");
                            break;
                        }
                    }
                }
                if(found_item == 0){
                    printf("You don't have that item in your inventory.\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void clear_input(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}