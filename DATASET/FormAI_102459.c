//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>

int main() {
  char *metadata = "I'm just a string, no metadata here!";
  char *filename = "funny_picture.jpg";
  int numTags = 5;
  char *tags[] = {"funny", "lol", "hilarious", "comedy", "joke"};
  int filesize = 12000;
  
  printf("Extracting metadata from %s...\n", filename);
  printf("File size: %d bytes\n", filesize);
  printf("Number of metadata tags found: %d\n", numTags);
  printf("Tags found: ");
  for (int i = 0; i < numTags; i++) {
    printf("%s, ", tags[i]);
  }
  printf("\n");

  printf("Wait, what's this? There's more metadata hidden in the file!\n");
  printf("Extracting additional metadata...\n");
  printf("Title: \"The Funny Picture\"\n");
  printf("Author: Chuckles McLaughlin\n");
  printf("Year: 2022\n");
  printf("Description: This is a hilarious image that will leave you in stitches!\n");

  printf("Sorry, I couldn't resist. Of course there's no C metadata in a picture file! But hey, at least I made you smile, right?\n");

  return 0;
}