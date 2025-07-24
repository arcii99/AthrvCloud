//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh boy, do I have a treat for you!\n");
    FILE *file_pointer;
    char filename[30];
    int num;

    printf("What's the name of the file you want to create? ");
    scanf("%s", filename);
    file_pointer = fopen(filename, "w");

    if (file_pointer == NULL) {
        printf("Oops, there was an error creating the file :(\n");
        return 1;
    }

    printf("Great, now what number do you want to write to the file? ");
    scanf("%d", &num);
    fprintf(file_pointer, "%d", num);

    printf("Phew, that was intense. But wait, there's more!\n");

    fclose(file_pointer);

    file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        printf("Uh oh, there was an issue opening the file.\n");
        return 1;
    }

    printf("Ok, now I'm going to read from the file. Hold onto your socks...\n");

    fscanf(file_pointer, "%d", &num);
    printf("The number in the file is : %d\n", num);

    printf("Ta da! Wasn't that amazing?\n");

    fclose(file_pointer);

    return 0;
}