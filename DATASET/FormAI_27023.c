//FormAI DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include <stdio.h>

#define MAX_STARTUP_ITEMS 50

typedef struct {
  char *name;
  int priority;
} StartupItem;

StartupItem startupItems[MAX_STARTUP_ITEMS];

void addStartupItem(char *name, int priority) {
  // check if there's still space in the array
  if (sizeof(startupItems) / sizeof(startupItems[0]) == MAX_STARTUP_ITEMS) {
    printf("Maximum number of startup items reached. Cannot add %s.\n", name);
    return;
  }

  // create the new StartupItem
  StartupItem newItem;
  newItem.name = name;
  newItem.priority = priority;

  // find the right position to insert the new item, based on priority
  int insertionIndex = 0;
  while (insertionIndex < MAX_STARTUP_ITEMS && startupItems[insertionIndex].priority > priority) {
    insertionIndex++;
  }

  // shift the existing items to make room for the new item
  for (int i = MAX_STARTUP_ITEMS - 1; i > insertionIndex; i--) {
    startupItems[i] = startupItems[i - 1];
  }

  // insert the new item
  startupItems[insertionIndex] = newItem;
}

void printStartupItems() {
  printf("Startup items:\n");
  for (int i = 0; i < sizeof(startupItems) / sizeof(startupItems[0]); i++) {
    printf("%d. %s\n", i + 1, startupItems[i].name);
  }
}

int main() {
  addStartupItem("MyApp", 10);
  addStartupItem("Chrome", 5);
  addStartupItem("Skype", 8);
  addStartupItem("Dropbox", 3);
  addStartupItem("Explorer", 7);

  printStartupItems();

  return 0;
}