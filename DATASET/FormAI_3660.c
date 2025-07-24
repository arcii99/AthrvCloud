//FormAI DATASET v1.0 Category: Browser Plugin ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define our plugin function */
int my_plugin(char *input) {
  if (strcmp(input, "example") == 0) {
    printf("This is an example plugin for our C browser!\n");
    return 1;
  }
  return 0;
}

/* Define our plugin hook */
int (*plugin_fn)(char *) = &my_plugin;

/* Define our plugin registration function */
void register_plugin(int (*fn)(char *)) {
  plugin_fn = fn;
  printf("Plugin registered successfully!\n");
}

/* Define our main function */
int main() {
  /* Register our plugin */
  register_plugin(&my_plugin);

  /* Ask the user for input */
  printf("Enter a command: ");
  char input[100];
  scanf("%s", input);

  /* Call the plugin function */
  int result = plugin_fn(input);

  /* Handle the result */
  if (!result) {
    printf("Command not recognized.\n");
  }

  return 0;
}