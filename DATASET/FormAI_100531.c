//FormAI DATASET v1.0 Category: System boot optimizer ; Style: invasive
#include <stdio.h>

int main(){
    printf("WARNING! This is an invasive program that will modify your system boot settings.\n");
    printf("Are you sure you want to continue? Enter Y or N: ");
    char input;
    scanf("%c", &input);

    if(input == 'N' || input == 'n'){
        printf("Aborting...\n");
        return 0;
    }

    printf("Proceeding with system boot optimization...\n");

    // Some code to optimize system boot sequence
    printf("Boot optimization complete!\n");

    printf("WARNING! This program has made changes to your system boot settings.\n");
    printf("To revert to original settings, please contact your system administrator.\n");

    return 0;
}