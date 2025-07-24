//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct config {
  char name[100];
  char value[100];
};

typedef struct config Config;

// Function to read values from configuration file
int read_config(Config config_array[], int config_size, const char* filename) {
  FILE* file = fopen(filename, "r");
  if(file == NULL) {
    printf("Error: Unable to open the configuration file!\n");
    return -1;
  }

  char line[256];
  int i = 0;
  while(fgets(line, sizeof(line), file)) {
    char* ptr = strchr(line, '=');
    if(ptr != NULL) {
      *ptr++ = '\0';
      strcpy(config_array[i].name, line);
      strcpy(config_array[i].value, ptr);
      i++;
    }
  }

  fclose(file);
  if(i != config_size) {
    printf("Error: Invalid number of configuration parameters in the file!\n");
    return -1;
  }

  return 0;
}

// Function to update values in the configuration file
int update_config(Config config_array[], int config_size, const char* filename) {
  FILE* file = fopen(filename, "r+");
  if(file == NULL) {
    printf("Error: Unable to open the configuration file!\n");
    return -1;
  }

  char line[256];
  int i = 0;
  while(fgets(line, sizeof(line), file)) {
    char* ptr = strchr(line, '=');
    if(ptr != NULL) {
      *ptr++ = '\0';
      if(strcmp(config_array[i].name, line) == 0) {
        fseek(file, -(strlen(line) + strlen(config_array[i].value) + 1), SEEK_CUR);
        fprintf(file, "%s=%s\n", line, config_array[i].value);
        i++;
      }
    }
  }

  fclose(file);
  if(i != config_size) {
    printf("Error: Invalid number of configuration parameters in the file!\n");
    return -1;
  }

  return 0;
}

// Function to print the current configuration
void print_config(Config config_array[], int config_size) {
  printf("Current configuration:\n");
  for(int i = 0; i < config_size; i++) {
    printf("%s=%s\n", config_array[i].name, config_array[i].value);
  }
}

int main() {
  Config config_array[3];
  int config_size = 3;

  if(read_config(config_array, config_size, "example_config.txt") == -1) {
    return -1;
  }

  printf("Initial "); 
  print_config(config_array, config_size);

  bool running = true;
  while(running) {
    printf("What do you want to do?\n1. Update a configuration parameter\n2. Print the current configuration\n3. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the parameter name to update: ");
        char name[100];
        scanf("%s", name);
        printf("Enter the new value: ");
        char value[100];
        scanf("%s", value);
        for(int i = 0; i < config_size; i++) {
          if(strcmp(config_array[i].name, name) == 0) {
            strcpy(config_array[i].value, value);
            printf("Updated successfully!\n");
            break;
          }
        }
        if(update_config(config_array, config_size, "example_config.txt") == -1) {
          return -1;
        }
        break;
      case 2:
        print_config(config_array, config_size);
        break;
      case 3:
        printf("Exiting...\n");
        running = false;
        break;
      default:
        printf("Invalid choice! Please enter a number between 1 and 3.\n");
        break;
    }
  }

  return 0;
}