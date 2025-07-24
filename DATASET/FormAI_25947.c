//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    srand(time(NULL));

    // data structure for storing visited URLs
    struct url_visited {
        char url[100];
        bool visited;
    } url_history[50];

    // array of possible surrealist messages
    char* messages[] = {
        "Error: Reality not found.",
        "The browser ate my dreams.",
        "Loading... Oh wait, I forgot to start the engine.",
        "404: The corridor to imagination is under maintenance.",
        "Encryption algorithm malfunction. Mind blown.",
        "Time is an illusion, but this loading bar is real.",
        "The internet is a collective fantasy.",
        "Our reality may be virtual, but this error message isn't.",
        "Error: Lost connection to the matrix.",
        "Infinitely scrolling into the abyss...",
        "The pixies stole the cookies. Please try again later.",
        "Cats have taken over the internet, please stand by.",
        "Loading... Your dreams have been added to the queue.",
        "404: The rabbit hole is currently occupied.",
        "The internet is made of dreams and cat videos.",
        "This is your brain on technology."
    };

    // initialize all URLs as unvisited
    for (int i = 0; i < 50; i++) {
        url_history[i].visited = false;
    }

    // main loop for user interactions
    while (true) {
        char user_input[100];

        // prompt user for URL
        printf("Enter a URL: ");
        fgets(user_input, 100, stdin);
        strtok(user_input, "\n");

        // check if URL has been visited before
        bool visited_before = false;
        for (int i = 0; i < 50; i++) {
            if (strcmp(user_input, url_history[i].url) == 0) {
                visited_before = true;
                if (url_history[i].visited) {
                    // if URL has been visited and marked as visited before, display a surreal message
                    printf("%s\n", messages[rand() % 16]);
                } else {
                    // if URL has been visited but not marked as visited before, mark it as visited
                    url_history[i].visited = true;
                }
                break;
            } else if (url_history[i].visited == false) {
                // if URL has not been visited before and there is no more space in the data structure, display a surreal message
                strcpy(url_history[i].url, user_input);
                printf("Connecting to %s...\n", user_input);
                printf("%s\n", messages[rand() % 16]);
                break;
            }
        }

        // if all URLs have been visited before, display a surreal message
        if (!visited_before) {
            printf("%s\n", messages[rand() % 16]);
        }
    }

    return 0;
}