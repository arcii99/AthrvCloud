//FormAI DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

int main() {

    //Opening lines to welcome the user and introduce the program 
    printf("My love, I know you're feeling so down,\nBut don't worry, your files aren't gone,\nWith my data recovery tool, I'll restore,\nAll the lost data you adored.\n\n");

    //Ask for user input for file name
    printf("My dear, what was the file's name?\nJust tell me, there's no need to feel shame.\n");
    char fileName[20];
    fgets(fileName, 20, stdin);

    //Output message to reassure the user that recovery process is starting 
    printf("Don't worry my love, I'm beginning the search,\nFor your lost file that's now in the lurch.\n");

    //Opening the file
    FILE *file = fopen(fileName, "r");

    //Checking if file exists, in the case that it does not, can recover or not message is given 
    if (file == NULL) {
        printf("I'm sorry darling, I cannot detect,\nIf the file was lost, or if it wasn't there to elect.\n");
        exit(0);
    }

    //Output message to reassure user that recovery has begun 
    printf("I've got your file, my love, the search was complete,\nI'm reuniting you two, it's your date night to treat.\n");

    //Reading and outputting lines of the file
    char fileLine[100];
    while (fgets(fileLine, 100, file) != NULL) {
        printf("%s", fileLine);
    }

    //Closing the file
    fclose(file);

    //Closing off message to end the program 
    printf("\nMy darling, your file is whole,\nDon't worry about that data loss toll,\nWith my recovery tool and heart so bold,\nYour lost data will forever behold.\n");

    return 0;
}