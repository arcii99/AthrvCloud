//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This function will check if there is a string match between the given string and the forbidden string.
 If there is a string match, it will return 1, otherwise it will return 0. */

int check_for_string_match(char *forbiddenString, char *inputString){

    if (strstr(inputString, forbiddenString) != NULL) {
        return 1;
    }

    return 0;
}

int main(){

    char *forbiddenStrings[] = {"rm -rf", "sudo", "wget", "curl", "rm", "system", "perl"};

    printf("Enter the command you want to execute (without sudo): ");

    char command[1000];
    fgets(command, sizeof(command), stdin);

    // Remove newline character from command input
    command[strcspn(command, "\n")] = '\0';

    // Check for string match with forbidden strings
    for (int i = 0; i < sizeof(forbiddenStrings)/sizeof(forbiddenStrings[0]); i++){
        if (check_for_string_match(forbiddenStrings[i], command)) {
            printf("Error: Command contains forbidden string '%s'\n", forbiddenStrings[i]);
            return 1;
        } 
    }

    printf("Command executed successfully!\n");

    return 0;
}