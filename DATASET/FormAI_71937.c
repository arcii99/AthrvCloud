//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  printf("Enter an English sentence to translate to Cat Language (Max 100 characters):\n");
  fgets(sentence, 100, stdin);
  
  // Convert every vowel to "meow"
  for(int i = 0; i < strlen(sentence); i++) {
    if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u') {
      sentence[i] = 'm'; // Replace the vowel with "m"
      strcat(sentence, "eow"); // Add "eow" to the end
    }
  }
  
  printf("In Cat Language, your sentence is:\n%s", sentence);
  return 0;
}