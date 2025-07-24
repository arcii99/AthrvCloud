//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main(){

  char alien_language[] = "Xyzqtwrstvmnklopbuhgjcdfea";

  int sentence_length, word_length, i, j;
  char sentence[1000], word[1000];

  printf("Enter a sentence in Alien language: ");
  fgets(sentence, sizeof(sentence), stdin);
  sentence_length = strlen(sentence);

  printf("Translation: ");
  i = 0;
  while (i < sentence_length){

        /* Check if the current character is a space or a punctuation mark */
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '!'){

            /* Print the same character if it's a punctuation mark */
            if (sentence[i] != ' '){
                printf("%c", sentence[i]);
            }
            else{
                printf(" ");
            }
            i++;
            continue;
        }
    
        /* Copy the current word to a separate string */
        j = i;
        word_length = 0;
        while(sentence[j] != ' ' && sentence[j] != '.' && sentence[j] != ',' && sentence[j] != '?' && sentence[j] != '!'){
            word[word_length] = sentence[j];
            word_length++;
            j++;
        }
        word[word_length] = '\0';
        
        /* Translate the current word */
        for(j = 0; j < word_length; j++){
            if(word[j] >= 'a' && word[j] <= 'z'){
                printf("%c", alien_language[word[j] - 'a']);
            }
            else{
                printf("%c", word[j]);
            }
        }
        
        /* Move to the next word */
        i = j;
    }
    printf("\n");
    return 0;
}