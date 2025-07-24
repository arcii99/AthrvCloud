//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define helper string variables in medieval style
char *scroll = "King's Scroll";
char *seal = "Royal Seal";
char *ink = "Black Ink";
char *parchment = "Parchment Paper";

// Define our metadata structure
struct metadata {
   char title[100];
   char author[100];
   char date[20];
   char source[100];
   char description[500];
};

// Define a function to extract metadata from the given document
void extract_metadata(char *document, struct metadata *data) {
   // Pretend to take out the King's Scroll from the Royal Library
   printf("Extracting metadata from %s using the %s, %s, %s and %s...\n", document, scroll, seal, ink, parchment);

   // Fill in metadata with fake values
   strcpy(data->title, "The Adventures of Sir Lancelot");
   strcpy(data->author, "Anonymous");
   strcpy(data->date, "1452");
   strcpy(data->source, "Royal Library");
   strcpy(data->description, "A thrilling tale of a brave knight's journey to save the kingdom");

   // Pretend to stamp the Royal Seal on the document
   printf("Stamping the %s on the %s...\n", seal, document);
}

// Main function that uses our metadata extractor
int main() {
   // Declare the document path and metadata structure
   char document[100] = "document.txt";
   struct metadata data;

   // Extract the metadata from our file
   extract_metadata(document, &data);

   // Display the extracted metadata
   printf("\nMetadata for %s:\n", document);
   printf("Title: %s\n", data.title);
   printf("Author: %s\n", data.author);
   printf("Date: %s\n", data.date);
   printf("Source: %s\n", data.source);
   printf("Description: %s\n", data.description);

   return 0;
}