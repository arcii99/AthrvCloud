//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>

int main(){
    printf("Welcome to the funniest text processing program ever!\n");

    char input[100];
    char output[100] = {0};

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0'; // removing the newline character

    int length = strlen(input);

    for(int i = 0; i < length; i++){
        if(i % 2 == 0){ // even position
            output[i] = input[i];
        } else { // odd position
            output[i] = input[i] - 32; // converting lowercase to uppercase
        }
    }

    printf("Your sentence has been transformed to: %s\n", output);
    printf("Isn't that hilarious? Oh wait, there's more...\n");

    char keyword[10];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    char *ptr = strstr(output, keyword); // searching for the keyword in the transformed sentence
    if(ptr != NULL){ // keyword found
        int index = ptr - output; // finding the index of the keyword in the transformed sentence
        printf("Haha, I found your keyword at index %d!\n", index);
    } else { // keyword not found
        printf("Sorry, I couldn't find your keyword. You'll have to try again!\n");
    }

    printf("Well, that concludes this hilarious program. Thanks for trying it out!\n");
    return 0;
}