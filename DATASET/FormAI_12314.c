//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char alienLanguage[30], translatedMessage[100];
  printf("Enter the Alien Language message (Use only alphabets): ");
  scanf("%s", alienLanguage);

  int len = strlen(alienLanguage), flag = 0, vowelFlag = 0, consonantFlag = 0, i, j = 0;

  for(i=0; i<len; i++) {
    flag = 0;
    if(alienLanguage[i] == 'a' || alienLanguage[i] == 'e' || alienLanguage[i] == 'i' || alienLanguage[i] == 'o' || alienLanguage[i] == 'u') {
      vowelFlag = 1;
      printf("%c", alienLanguage[i]-32); // Convert vowel to uppercase
    } else {
      consonantFlag = 1;
      for(j=i+1; j<len; j++) {
        if(alienLanguage[i] == alienLanguage[j]) {
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        printf("%cav", alienLanguage[i]); // Append "av" to consonant
        j = j+2;
      } else {
        continue;
      }
    }
  }

  if(vowelFlag == 0) {
    printf("No vowels in the Alien Language message! Translation not possible!\n");
  } else if(consonantFlag == 0) {
    printf("No consonants in the Alien Language message! Translation not possible!\n");
  }

  return 0;
}