//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  int vowel_count = 0, consonant_count = 0, digit_count = 0, space_count = 0;
  printf("Please enter a sentence: ");
  fgets(sentence, 100, stdin);

  for(int i = 0; i < strlen(sentence); i++) {
    if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {
      vowel_count++;
    }
    else if(sentence[i] >= 'a' && sentence[i] <= 'z' || sentence[i] >= 'A' && sentence[i] <= 'Z') {
      consonant_count++;
    }
    else if(sentence[i] >= '0' && sentence[i] <= '9') {
      digit_count++;
    }
    else if(sentence[i] == ' ') {
      space_count++;
    }
  }

  printf("\nTotal Vowels: %d", vowel_count);
  printf("\nTotal Consonants: %d", consonant_count);
  printf("\nTotal Digits: %d", digit_count);
  printf("\nTotal Spaces: %d", space_count);

  return 0;
}