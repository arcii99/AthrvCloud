//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("dreamworld.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *greeting = "Welcome to the dreamworld!";

    fputs(greeting, fp);

    fclose(fp);

    printf("You have entered the dreamworld. Let's explore!\n");

    fp = fopen("dreamworld.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        printf("%s\n", line);
    }

    fclose(fp);

    printf("As you explore the dreamworld, you realize that the reality is stranger than your wildest dreams...\n");

    fp = fopen("dreamworld.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *dream = "I am flying on a banana peel!";

    fputs(dream, fp);

    fclose(fp);

    printf("You can do anything in the dreamworld! Even fly on a banana peel...\n");

    fp = fopen("dreamworld.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        printf("%s\n", line);
    }

    fclose(fp);

    printf("But be careful! The dreamworld can also turn into a nightmare...\n");

    fp = fopen("dreamworld.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *nightmare = "I am being chased by giant pencils!";

    fputs(nightmare, fp);

    fclose(fp);

    printf("You have to escape the nightmare before it's too late!\n");

    fp = fopen("dreamworld.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        printf("%s\n", line);
    }

    fclose(fp);

    printf("Phew, you made it back to reality. Or did you?\n");

    return 0;
}