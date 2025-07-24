//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>

int main(void) {

    // Declare variables to hold metadata information
    char artist[50], title[50], album[50];
    int year;

    // Prompt the user to enter metadata information
    printf("Enter the artist: ");
    scanf("%49s", artist);

    printf("Enter the title: ");
    scanf("%49s", title);

    printf("Enter the album: ");
    scanf("%49s", album);

    printf("Enter the year: ");
    scanf("%d", &year);

    // Print out the metadata information
    printf("\nMetadata Information\n");
    printf("Artist: %s\n", artist);
    printf("Title: %s\n", title);
    printf("Album: %s\n", album);
    printf("Year: %d\n", year);

    return 0;
}