//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aye Aye Captain, ready to parse some JSON!
int main() {
    printf("Ahoy, ye scallywags! Let's parse some JSON and find some hidden treasure!\n");

    // Let's start with some example JSON
    char json[500] = "{\n\t\"fruits\": [\n\t\t\"apple\",\n\t\t\"banana\",\n\t\t\"orange\"\n\t],\n\t\"numbers\": {\n\t\t\"one\": 1,\n\t\t\"two\": 2,\n\t\t\"three\": 3\n\t},\n\t\"boolean\": true\n}";

    // Ahoy mateys! Let's find out what's inside this JSON!
    char *token = strtok(json, "{[,\":]} \n\t"); // Tokenizing JSON

    while (token != NULL) {
        if (strcmp(token, "fruits") == 0) { // Arrr! We found some delicious fruits!
            printf("Arrr mateys, we have found some juicy fruits! Here they be:\n");
            token = strtok(NULL, "{[,\":]} \n\t"); // Getting the opening bracket of fruits array

            while (token != NULL) {
                if (strcmp(token, "}") == 0) { // Brace yourselves, we're done with the fruits!
                    printf("Arrr mateys, we've collected all the fruits we could find!\n");
                    break;
                }
                if (strcmp(token, ",") != 0) { // We only care about the individual fruits, not the commas!
                    printf("- %s\n", token);
                }
                token = strtok(NULL, "{[,\":]} \n\t"); // Getting next element of fruits array
            }
        }
        if (strcmp(token, "numbers") == 0) { // Ahoy! Let's find out what those numbers be!
            printf("Ahoy mateys! We've stumbled upon some numbers! Let's take a closer look:\n");
            token = strtok(NULL, "{[,\":]} \n\t"); // Getting the opening bracket of numbers object

            while (token != NULL) {
                if (strcmp(token, "one") == 0) { // Arrr! We found the first number!
                    printf("- The first number be: %s\n", strtok(NULL, "{[,\":]} \n\t"));
                }
                if (strcmp(token, "two") == 0) { // Arrr! We found another number!
                    printf("- The second number be: %s\n", strtok(NULL, "{[,\":]} \n\t"));
                }
                if (strcmp(token, "three") == 0) { // Arrr! We found the last number!
                    printf("- The third number be: %s\n", strtok(NULL, "{[,\":]} \n\t"));
                    printf("Arrr mateys, we've finished counting the numbers!\n");
                    break;
                }
                token = strtok(NULL, "{[,\":]} \n\t"); // Getting next property of the numbers object
            }
        }
        if (strcmp(token, "boolean") == 0) { // Ahoy! We found a boolean value!
            printf("Avast ye scallywags! We've found a boolean value, and it be: %s\n", strtok(NULL, "{[,\":]} \n\t"));
        }
        token = strtok(NULL, "{[,\":]} \n\t"); // Getting next property of the original object
    }

    printf("Arrr mateys, we've finished parsing the JSON! Now let's go find that treasure!\n");
    return 0; // The End!
}