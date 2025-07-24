//FormAI DATASET v1.0 Category: Spell checking ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 150

char dictionary[MAX][MAX];
char check_text[MAX][MAX];

void read_dictionary_file();
void read_text_for_checking();

int main() {
   int i, j;
   int test_case;

   char word[MAX];
   int word_length;
   int found = 0;

   printf("Spell Checking Program\n\n");

   read_dictionary_file();
   read_text_for_checking();

   for (i = 0; i < MAX; i++) {
      for (j = 0; j < MAX; j++) {
         if (check_text[i][j] == '\0') {
            break;
         }
         if (check_text[i][j] == ' ' || check_text[i][j] == '\n' || check_text[i][j] == '\t' || check_text[i][j] == '.' || check_text[i][j] == ',') {
            continue;
         }
         word_length = 0;
         memcpy(word, &check_text[i][j], sizeof(word));
         while (check_text[i][j+word_length] != ' ' && check_text[i][j+word_length] != '\n' && check_text[i][j+word_length] != '\t' && check_text[i][j+word_length] != '.' && check_text[i][j+word_length] != ',' && check_text[i][j+word_length] != '\0') {
            word_length++;
         }
         word[word_length] = '\0';
         for (test_case = 0; test_case < MAX; test_case++) {
            if (strcmp(word, dictionary[test_case]) == 0) {
               found = 1;
            }
         }
         if (found == 0) {
            printf("Misspelled word found: %s\n", word);
         }
         found = 0;
      }
   }
   return 0;
}

void read_dictionary_file() {
   FILE *file;
   int i = 0;
   char buffer[MAX];

   file = fopen("dictionary.txt", "r");
   if(file == NULL) {
      printf("Failed to open dictionary file\n");
      exit(1);
   }

   while(fgets(buffer, MAX, file)) {
      strcpy(dictionary[i], buffer);
      i++;
   }

   fclose(file);
}

void read_text_for_checking() {
   FILE *file;
   int i = 0;
   char buffer[MAX];

   file = fopen("text_for_checking.txt", "r");
   if(file == NULL) {
      printf("Failed to open text file\n");
      exit(1);
   }

   while(fgets(buffer, MAX, file)) {
      strcpy(check_text[i], buffer);
      i++;
   }

   fclose(file);
}