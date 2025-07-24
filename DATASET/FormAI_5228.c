//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 25
#define MAX_WORDS 1000

struct wordcount
{
   char word[MAX_WORD_LEN + 1];
   int count;
};

int read_word(FILE *, char *, int);
int compare_wordcount(const void *, const void *);
void sort_wordcount(struct wordcount [], int);
void print_wordcount(struct wordcount [], int);

int main(int argc, char *argv[])
{
   struct wordcount words[MAX_WORDS];
   FILE *fp;
   char word[MAX_WORD_LEN + 1];
   int i;
   int num_words = 0;

   if (argc < 2)
   {
      printf("Syntax: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if ((fp = fopen(argv[1], "r")) == NULL)
   {
      printf("Cannot open %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   while (read_word(fp, word, MAX_WORD_LEN))
   {
      for (i = 0; i < num_words; ++i)
      {
         if (strcmp(words[i].word, word) == 0)
         {
            ++words[i].count;
            break;
         }
      }

      if (i == num_words)
      {
         strncpy(words[num_words].word, word, MAX_WORD_LEN + 1);
         words[num_words].count = 1;

         if (++num_words > MAX_WORDS)
         {
            printf("Maximum number of words exceeded\n");
            exit(EXIT_FAILURE);
         }
      }
   }

   sort_wordcount(words, num_words);
   print_wordcount(words, num_words);

   fclose(fp);

   return 0;
}

int read_word(FILE *fp, char *word, int max_len)
{
   char ch;
   int len = 0;

   while ((ch = getc(fp)) != EOF)
   {
      if (isalnum(ch))
      {
         if (len < max_len)
         {
            word[len++] = tolower(ch);
         }
      }
      else if (len > 0)
      {
         break;
      }
   }

   word[len] = '\0';

   return len;
}

int compare_wordcount(const void *p1, const void *p2)
{
   const struct wordcount *pw1 = (const struct wordcount *)p1;
   const struct wordcount *pw2 = (const struct wordcount *)p2;

   return strcmp(pw1->word, pw2->word);
}

void sort_wordcount(struct wordcount words[], int num_words)
{
   qsort(words, num_words, sizeof(struct wordcount), compare_wordcount);
}

void print_wordcount(struct wordcount words[], int num_words)
{
   int i;

   for (i = 0; i < num_words; ++i)
   {
      printf("%-20s%5d\n", words[i].word, words[i].count);
   }
}