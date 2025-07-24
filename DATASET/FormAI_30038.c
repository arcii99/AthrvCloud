//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *url;
  char *title;
  char *description;
} Webpage;

void displayWebpage(Webpage p) {
  printf("\nTitle: %s\nURL: %s\nDescription: %s", p.title, p.url, p.description);
}

int main() {
  Webpage p;
  p.title = "Eternal Sunshine of the Spotless Mind";
  p.url = "https://www.imdb.com/title/tt0338013/";
  p.description = "When their relationship turns sour, a couple undergoes a medical procedure to have each other erased from their memories.";
  
  displayWebpage(p);
  
  printf("\n\nHave you ever wondered what it would be like to have a plugin that could erase memories directly from your mind?\n\n");
  
  // surreal code begins here
  char *input_str = malloc(sizeof(char) * 50);
  printf("Enter memory to erase: ");
  scanf("%s", input_str);
  
  printf("Erasing memory of %s", input_str);
  for (int i = 0; i < strlen(input_str); i++) {
    input_str[i] = '*';
  }
  
  printf("\n\nMemory erased:");
  displayWebpage(p);
  
  free(input_str);
  return 0;
}