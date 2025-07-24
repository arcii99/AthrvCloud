//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to print an ASCII art message */
void print_art(char* message) {
    int length = strlen(message);
    char filename[100], command[100];

    /* Create a unique filename for temporary file */
    srand(time(NULL));
    sprintf(filename, "ascii_art_%d.txt", rand());

    /* Write message to the file */
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%s", message);
    fclose(fp);

    /* Run the figlet command to create the ASCII art */
    sprintf(command, "figlet -f slant -w 80 -t -c $(cat %s) > output.txt", filename);
    system(command);

    /* Read the ASCII art from the output file */
    fp = fopen("output.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    /* Delete temporary files */
    remove(filename);
    remove("output.txt");
}

int main() {
    /* Asynchronous input */
    char message[100];
    printf("Enter a message to convert to ASCII art: ");
    scanf("%s", message);

    /* Print ASCII art */
    print_art(message);

    return 0;
}