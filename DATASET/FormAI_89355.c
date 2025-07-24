//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing the ebook information
struct Ebook {
    char title[100];
    char author[100];
    int publishYear;
    char publisher[100];
    int pageCount;
    char* content;
};

// Function to read ebooks from a file
void readEbooksFromFile(FILE* file, struct Ebook* ebooks, int ebookCount) {
    char buffer[1000];
    int lineCount = 0;
    int ebookIndex = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        // If line count is 0, then it is the title of the ebook
        if (lineCount == 0) {
            strcpy(ebooks[ebookIndex].title, buffer);
        }
        // If line count is 1, then it is the author of the ebook
        else if (lineCount == 1) {
            strcpy(ebooks[ebookIndex].author, buffer);
        }
        // If line count is 2, then it is the publish year of the ebook
        else if (lineCount == 2) {
            ebooks[ebookIndex].publishYear = atoi(buffer);
        }
        // If line count is 3, then it is the publisher of the ebook
        else if (lineCount == 3) {
            strcpy(ebooks[ebookIndex].publisher, buffer);
        }
        // If line count is 4, then it is the page count of the ebook
        else if (lineCount == 4) {
            ebooks[ebookIndex].pageCount = atoi(buffer);
        }
        // If line count is 5 or greater, then it is the content of the ebook
        else {
            if (lineCount == 5) {
                ebooks[ebookIndex].content = (char*)malloc((ebooks[ebookIndex].pageCount * 1000 + 1) * sizeof(char));
            }
            strcat(ebooks[ebookIndex].content, buffer);
        }
        // Increment the line count
        lineCount++;
        // If line count is greater than 5 and a multiple of 1000, then reallocate memory for content
        if (lineCount > 5 && (lineCount - 5) % 1000 == 0) {
            ebooks[ebookIndex].content = (char*)realloc(ebooks[ebookIndex].content, (ebooks[ebookIndex].pageCount * 1000 + lineCount - 5 + 1) * sizeof(char));
        }
        // If line count is greater than 5 and divisible by 1000, then set line count to 5 and increment ebook index
        if (lineCount > 5 && (lineCount - 5) % 1000 == 1) {
            lineCount = 5;
            ebookIndex++;
        }
        // If ebook index is equal to ebook count, then break the loop
        if (ebookIndex == ebookCount) {
            break;
        }
    }
}

// Function to display ebook information
void displayEbook(struct Ebook ebook) {
    printf("Title: %s", ebook.title);
    printf("Author: %s", ebook.author);
    printf("Publish Year: %d\n", ebook.publishYear);
    printf("Publisher: %s", ebook.publisher);
    printf("Page Count: %d\n", ebook.pageCount);
}

// Main function
int main() {
    // Open the ebook file in read mode
    FILE* file = fopen("ebooks.txt", "r");
    // If file cannot be opened, then return 1
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }
    // Count the number of lines in the file to determine the number of ebooks
    int lineCount = 0;
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file)) {
        lineCount++;
    }
    // Divide the line count by 1005 to get the number of ebooks (title, author, publish year, publisher, page count, and content)
    int ebookCount = lineCount / 1005;
    // Allocate memory for ebooks
    struct Ebook* ebooks = (struct Ebook*)malloc(ebookCount * sizeof(struct Ebook));
    // Reset the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);
    // Read ebooks from the file
    readEbooksFromFile(file, ebooks, ebookCount);
    // Close the file
    fclose(file);
    // Display the first ebook
    displayEbook(ebooks[0]);
    // Free memory for ebooks
    for (int i = 0; i < ebookCount; i++) {
        free(ebooks[i].content);
    }
    free(ebooks);
    return 0;
}