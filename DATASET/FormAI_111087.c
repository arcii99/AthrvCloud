//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>

int main(){
    FILE *filePointer;
    char c;
    int count = 0;

    filePointer = fopen("funnyFile.txt", "r");

    if (filePointer == NULL) {
        printf("Oopsie, I couldn't find the file. Better start looking for it!");
        return 0;
    }

    printf("Welcome to my funny file handling program!\n");
    printf("Here's a joke for you: Why did the tomato turn red? Because it saw the salad dressing!\n");
    printf("Now, let me show you how many times the letter 'l' appears in this file...\n");

    while ((c = fgetc(filePointer)) != EOF) {
        if (c == 'L' || c == 'l') {
            count++;
        }
    }

    printf("The letter 'l' appears %d times in this file! Haha, that's a lot of L's!\n", count);
    printf("Ok, one more joke... Why did the scarecrow win an award? Because it was outstanding in its field!\n");

    fclose(filePointer);

    return 0;
}