//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

/* Function to translate a C Alien language phrase */
void translateToEnglish(char alienPhrase[]) {
  
  char translatedPhrase[100] = "";
  
  /* Iterate through each character in the alien phrase */
  for(int i = 0; i < strlen(alienPhrase); i++) {
    
    /* Determine the translated version of the current character */
    switch(alienPhrase[i]) {
      
      case 'x':
        strcat(translatedPhrase, "a");
        break;
        
      case 'z':
        strcat(translatedPhrase, "b");
        break;
        
      case 't':
        strcat(translatedPhrase, "c");
        break;
        
      case 'd':
        strcat(translatedPhrase, "d");
        break;
        
      case 'm':
        strcat(translatedPhrase, "e");
        break;
        
      case 'l':
        strcat(translatedPhrase, "f");
        break;
        
      case 's':
        strcat(translatedPhrase, "g");
        break;
        
      case 'q':
        strcat(translatedPhrase, "h");
        break;
        
      case 'p':
        strcat(translatedPhrase, "i");
        break;
        
      case 'v':
        strcat(translatedPhrase, "j");
        break;
        
      case 'n':
        strcat(translatedPhrase, "k");
        break;
        
      case 'r':
        strcat(translatedPhrase, "l");
        break;
        
      case 'g':
        strcat(translatedPhrase, "m");
        break;
        
      case 'e':
        strcat(translatedPhrase, "n");
        break;
        
      case 'f':
        strcat(translatedPhrase, "o");
        break;
        
      case 'y':
        strcat(translatedPhrase, "p");
        break;
        
      case 'u':
        strcat(translatedPhrase, "q");
        break;
        
      case 'i':
        strcat(translatedPhrase, "r");
        break;
        
      case 'h':
        strcat(translatedPhrase, "s");
        break;
        
      case 'j':
        strcat(translatedPhrase, "t");
        break;
        
      case 'k':
        strcat(translatedPhrase, "u");
        break;
        
      case 'o':
        strcat(translatedPhrase, "v");
        break;
        
      case 'b':
        strcat(translatedPhrase, "w");
        break;
        
      case 'c':
        strcat(translatedPhrase, "x");
        break;
        
      case 'a':
        strcat(translatedPhrase, "y");
        break;
        
      case 'w':
        strcat(translatedPhrase, "z");
        break;
        
      default:
        /* For any unknown characters, simply add them as is to the translated phrase */
        strncat(translatedPhrase, &alienPhrase[i], 1);
    }
  }
  
  /* Print the translated phrase */
  printf("\nTranslated Phrase: %s\n", translatedPhrase);
}

int main() {
  
  /* Prompt user for input */
  printf("Enter a phrase in the C Alien language to be translated: ");
  
  /* Read in user input */
  char alienPhrase[100];
  fgets(alienPhrase, 100, stdin);
  
  /* Remove the newline character from the user input */
  alienPhrase[strcspn(alienPhrase, "\n")] = 0;
  
  /* Translate the alien phrase and print the result */
  translateToEnglish(alienPhrase);
  
  return 0;
}