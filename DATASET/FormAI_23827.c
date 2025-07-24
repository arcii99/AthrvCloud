//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LENGTH 1000

typedef struct sentence
{
   int index;
   char text[MAX_SENTENCE_LENGTH];
   int score;
} Sentence;

void calculate_sentence_scores(Sentence *sentences, int sentence_count, char *keywords[]);
int compare_scores_descending(const void *a, const void *b);
void print_summary(Sentence *sentences, int num_sentences);

int main()
{
   char input_text[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
   char *keywords[] = {"algorithm", "data", "programming"};
   Sentence sentences[MAX_SENTENCES];

   // read in input text until maximum number of sentences or string length is reached
   int sentence_count = 0;
   while (sentence_count < MAX_SENTENCES && 
          fgets(sentences[sentence_count].text, MAX_SENTENCE_LENGTH, stdin) != NULL) 
   {
      sentences[sentence_count].index = sentence_count;
      sentence_count++;
   }

   calculate_sentence_scores(sentences, sentence_count, keywords);

   // sort sentences by score in descending order
   qsort(sentences, sentence_count, sizeof(Sentence), compare_scores_descending);

   print_summary(sentences, sentence_count);

   return 0;
}

// calculate scores for each sentence based on number of occurrences of keywords
void calculate_sentence_scores(Sentence *sentences, int sentence_count, char *keywords[])
{
   for (int i = 0; i < sentence_count; i++)
   {
      int score = 0;
      char *word = strtok(sentences[i].text, " ");
      while (word != NULL)
      {
         for (int j = 0; j < sizeof(keywords) / sizeof(char*); j++)
         {
            if (strcmp(word, keywords[j]) == 0)
            {
               score++;
            }
         }
         word = strtok(NULL, " ");
      }
      sentences[i].score = score;
   }
}

// compare function for qsort to sort sentences by score in descending order
int compare_scores_descending(const void *a, const void *b)
{
   Sentence *sentence_a = (Sentence*)a;
   Sentence *sentence_b = (Sentence*)b;
   return sentence_b->score - sentence_a->score;
}

// print summary of the top scoring sentences
void print_summary(Sentence *sentences, int num_sentences)
{
   int summary_length = num_sentences > 3 ? 3 : num_sentences;
   printf("Summary:\n");
   for (int i = 0; i < summary_length; i++)
   {
      printf("%d. %s", i+1, sentences[i].text);
   }
}