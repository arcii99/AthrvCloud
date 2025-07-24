//FormAI DATASET v1.0 Category: Browser Plugin ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the input string
#define MAX_LENGTH 1000

// Define the structure for the browser plugin
struct CBrowserPlugin {
    char name[50];
    char website[100];
    int downloads;
};

// Main function
int main() {
    // Declare variables
    char input[MAX_LENGTH];
    int choice, num_plugins, i;
    struct CBrowserPlugin plugin_list[MAX_LENGTH];

    // Display welcome message
    printf("Welcome to C Browser Plugin Example Program!\n");

    // Display menu options
    printf("\nPlease select an option:\n");
    printf("1. Add a plugin\n");
    printf("2. Delete a plugin\n");
    printf("3. Display all plugins\n");
    printf("4. Quit\n");

    // Loop through menu options until user chooses to quit
    do {
        printf("\nEnter your choice (1-4): ");
        fgets(input, MAX_LENGTH, stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                // Add a plugin
                printf("\nAdd a plugin\n");
                printf("Enter the name of the plugin: ");
                fgets(plugin_list[num_plugins].name, sizeof(plugin_list[num_plugins].name), stdin);
                plugin_list[num_plugins].name[strlen(plugin_list[num_plugins].name)-1] = '\0';
                printf("Enter the website link of the plugin: ");
                fgets(plugin_list[num_plugins].website, sizeof(plugin_list[num_plugins].website), stdin);
                plugin_list[num_plugins].website[strlen(plugin_list[num_plugins].website)-1] = '\0';
                plugin_list[num_plugins].downloads = 0;
                printf("The plugin has been successfully added.\n");
                num_plugins++;
                break;
            case 2:
                // Delete a plugin
                printf("\nDelete a plugin\n");
                printf("Enter the name of the plugin to be deleted: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strlen(input)-1] = '\0';
                for (i=0; i<num_plugins; i++) {
                    if (strcmp(plugin_list[i].name, input) == 0) {
                        for (; i<num_plugins-1; i++) {
                            plugin_list[i] = plugin_list[i+1];
                        }
                        num_plugins--;
                        printf("The plugin has been successfully deleted.\n");
                        break;
                    }
                }
                if (i == num_plugins) {
                    printf("The plugin cannot be found.\n");
                }
                break;
            case 3:
                // Display all plugins
                printf("\nPlugin List:\n");
                for (i=0; i<num_plugins; i++) {
                    printf("Name: %s\n", plugin_list[i].name);
                    printf("Website Link: %s\n", plugin_list[i].website);
                    printf("Downloads: %d\n", plugin_list[i].downloads);
                    printf("\n");
                }
                break;
            case 4:
                // Quit
                printf("\nThank you for using the C Browser Plugin Example Program!\n");
                break;
            default:
                // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}