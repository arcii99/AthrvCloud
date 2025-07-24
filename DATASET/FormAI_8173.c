//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include<stdio.h>
#include<string.h>

int main() {
  char phrase[100]; // String to enter the phrase by user
  int i, j, k = 0;
  char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  char translated[200] = "";
  char append[] = "at";

  printf("Enter phrase to translate in Cat Language:\n");
  scanf("%[^\n]s", phrase); // Accepting the string with spaces

  for (i = 0; i < strlen(phrase); i++) {
    int flag = 0;
    for (j = 0; j < 10; j++) { // Checking if the letter is a vowel
        if (phrase[i] == vowel[j]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0 && phrase[i] != ' ') {
        translated[k++] = phrase[i]; // If letter is not a vowel add it to translated string
    }
    else if (phrase[i] != ' ') {
        strcat(translated, append); // If letter is a vowel, append "at" to it in translated string
        translated[k++] = phrase[i];
    }
  }

  printf("\nTranslated Phrase in Cat Language:\n%s", translated);
  return 0;
}