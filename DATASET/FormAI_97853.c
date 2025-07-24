//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

// Rooms struct
typedef struct {
  char* name;
  char* exits[4];
  char* items[MAX_ITEMS];
} Room;

// Item struct
typedef struct {
  char* name;
  char* description;
  int can_pickup;
} Item;

// Function prototypes
void initialize_rooms();
void initialize_items();
int get_room_index(char* room);
int get_item_index(char* item);
void print_room_description(int room_index);
void print_inventory();
void pickup_item(char* item);
void drop_item(char* item);

// Global variables
Room rooms[5];
Item items[4];
int current_room = 0;
char* inventory[MAX_ITEMS];
int num_items = 0;

int main() {
  initialize_rooms();
  initialize_items();
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself in a dark and creepy room...\n");
  print_room_description(current_room);

  // Main game loop
  while (1) {
    char input[50];
    printf("> ");
    fgets(input, 50, stdin);
    if (strcmp(input, "quit\n") == 0) {
      printf("Thanks for playing!\n");
      return 0;
    } else if (strcmp(input, "inventory\n") == 0) {
      print_inventory();
    } else if (strncmp(input, "pickup ", 7) == 0) {
      char* item = input + 7;
      item[strlen(item) - 1] = '\0';
      pickup_item(item);
    } else if (strncmp(input, "drop ", 5) == 0) {
      char* item = input + 5;
      item[strlen(item) - 1] = '\0';
      drop_item(item);
    } else {
      int exit_index = -1;
      for (int i = 0; i < 4; i++) {
        if (strcmp(input, rooms[current_room].exits[i]) == 0) {
          exit_index = i;
          break;
        }
      }
      if (exit_index != -1) {
        current_room = get_room_index(rooms[current_room].exits[exit_index]);
        print_room_description(current_room);
      } else {
        printf("Invalid command\n");
      }
    }
  }

  return 0;
}

// Initialize the rooms
void initialize_rooms() {
  rooms[0].name = "Creepy Room";
  rooms[0].exits[0] = "North Hallway";
  rooms[0].items[0] = "Flashlight";
  rooms[0].items[1] = "Rope";

  rooms[1].name = "North Hallway";
  rooms[1].exits[0] = "Creepy Room";
  rooms[1].exits[1] = "Haunted Room";
  rooms[1].items[0] = "Key";
  rooms[1].items[1] = "Lockpick";

  rooms[2].name = "Haunted Room";
  rooms[2].exits[0] = "North Hallway";
  rooms[2].items[0] = "Ghosts";
}

// Initialize the items
void initialize_items() {
  items[0].name = "Flashlight";
  items[0].description = "A small flashlight that emits a weak beam of light";
  items[0].can_pickup = 1;

  items[1].name = "Rope";
  items[1].description = "A long, coarse rope that can be used to climb";
  items[1].can_pickup = 1;

  items[2].name = "Key";
  items[2].description = "A rusty old key that seems to fit in a lock";
  items[2].can_pickup = 1;

  items[3].name = "Lockpick";
  items[3].description = "A thin metal rod that can be used to pick locks";
  items[3].can_pickup = 1;
}

// Returns the index of the given room
int get_room_index(char* room) {
  for (int i = 0; i < 3; i++) {
    if (strcmp(room, rooms[i].name) == 0) {
      return i;
    }
  }
  return -1;
}

// Returns the index of the given item
int get_item_index(char* item) {
  for (int i = 0; i < 4; i++) {
    if (strcmp(item, items[i].name) == 0) {
      return i;
    }
  }
  return -1;
}

// Prints the description of the current room
void print_room_description(int room_index) {
  printf("You are in the %s\n", rooms[room_index].name);
  printf("Possible exits: ");
  for (int i = 0; i < 4; i++) {
    if (rooms[room_index].exits[i] != NULL) {
      printf("%s ", rooms[room_index].exits[i]);
    }
  }
  printf("\n");
  printf("Items: ");
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (rooms[room_index].items[i] != NULL) {
      printf("%s ", rooms[room_index].items[i]);
    }
  }
  printf("\n");
}

// Prints the player's inventory
void print_inventory() {
  if (num_items == 0) {
    printf("You have no items\n");
  } else {
    printf("You have: ");
    for (int i = 0; i < num_items; i++) {
      printf("%s ", inventory[i]);
    }
    printf("\n");
  }
}

// Attempts to pick up the given item
void pickup_item(char* item) {
  int item_index = get_item_index(item);
  if (item_index == -1) {
    printf("That item does not exist\n");
  } else if (!items[item_index].can_pickup) {
    printf("You cannot pick up that item\n");
  } else {
    if (num_items == MAX_ITEMS) {
      printf("Your inventory is full\n");
    } else {
      inventory[num_items] = item;
      num_items++;
      printf("You picked up %s\n", item);
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item, rooms[current_room].items[i]) == 0) {
          rooms[current_room].items[i] = NULL;
        }
      }
    }
  }
}

// Attempts to drop the given item
void drop_item(char* item) {
  int item_index = -1;
  for (int i = 0; i < num_items; i++) {
    if (strcmp(item, inventory[i]) == 0) {
      item_index = i;
      break;
    }
  }
  if (item_index == -1) {
    printf("You do not have that item\n");
  } else {
    inventory[item_index] = NULL;
    num_items--;
    printf("You dropped %s\n", item);
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (rooms[current_room].items[i] == NULL) {
        rooms[current_room].items[i] = item;
        break;
      }
    }
  }
}