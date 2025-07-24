//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Ebook structure
typedef struct {
    char title[100];
    char author[100];
    char filepath[100];
} Ebook;

// Define the Ebook reader function
void ebookReader(Ebook ebook) {
    FILE *file = fopen(ebook.filepath, "r");
    if (file) {
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error: Could not open file.\n");
    }
}

int main() {
    // Define an array of Ebook structures
    Ebook ebooks[3];
    strcpy(ebooks[0].title, "The Hitchhiker's Guide to the Galaxy");
    strcpy(ebooks[0].author, "Douglas Adams");
    strcpy(ebooks[0].filepath, "hitchhikers-guide.txt");

    strcpy(ebooks[1].title, "1984");
    strcpy(ebooks[1].author, "George Orwell");
    strcpy(ebooks[1].filepath, "1984.txt");

    strcpy(ebooks[2].title, "Brave New World");
    strcpy(ebooks[2].author, "Aldous Huxley");
    strcpy(ebooks[2].filepath, "brave-new-world.txt");

    // Prompt the user to select an Ebook
    printf("Select an Ebook:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s by %s\n", i + 1, ebooks[i].title, ebooks[i].author);
    }

    // Read the user's choice
    int choice;
    scanf("%d", &choice);

    // Display the chosen Ebook
    ebookReader(ebooks[choice-1]);

    return 0;
}