//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  int vowels = 0, consonants = 0, spaces = 0, digits = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  for(int i=0; i<strlen(sentence); i++) {
    if(sentence[i] == ' ')
      spaces++;

    else if(isdigit(sentence[i]))
      digits++;

    else if(sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U' || sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
      vowels++;

    else if((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z'))
      consonants++;       
  }

  printf("\nYour sentence contains:\n");
  printf("%d vowels\n", vowels);
  printf("%d consonants\n", consonants);
  printf("%d spaces\n", spaces);
  printf("%d digits\n", digits);

  return 0;
}