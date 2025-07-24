//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct Metadata {
   char title[100];
   char artist[100];
   int track_number;
   float duration;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char *filename) {
   Metadata metadata;
   FILE *fptr;

   // Open the file in read-only binary mode
   fptr = fopen(filename, "rb");
   if (fptr == NULL) {
      printf("Error opening file %s.\n", filename);
      exit(1);
   }

   // Read in the metadata fields from the file
   fread(metadata.title, sizeof(metadata.title), 1, fptr);
   fread(metadata.artist, sizeof(metadata.artist), 1, fptr);
   fread(&metadata.track_number, sizeof(metadata.track_number), 1, fptr);
   fread(&metadata.duration, sizeof(metadata.duration), 1, fptr);

   // Close the file
   fclose(fptr);

   // Return the extracted metadata
   return metadata;
}

int main() {
   Metadata file_metadata;
   char *filename = "example_song.mp3";

   // Extract the metadata from the file
   file_metadata = extract_metadata(filename);

   // Print out the extracted metadata fields
   printf("Title: %s\n", file_metadata.title);
   printf("Artist: %s\n", file_metadata.artist);
   printf("Track Number: %d\n", file_metadata.track_number);
   printf("Duration: %f seconds\n", file_metadata.duration);

   return 0;
}