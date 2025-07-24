//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

 // Function to remove non-alphanumeric characters from a string
 void removeNonAlphaNum(char *str)
 {
   int i, j = 0;
   for (i = 0; str[i] != '\0'; i++)
   {
     if (isalnum(str[i]))
     {
       str[j] = tolower(str[i]);
       j++;
     }
   }
   str[j] = '\0';
 }

 // Function to create a frequency table of words in a given text
 void createFrequencyTable(char *text, int *freqtable)
 {
   char *word = strtok(text, " ");
   while (word != NULL)
   {
     if (strlen(word) > 1) // Ignore single character words
     {
       freqtable[hashcode(word)]++;
     }
     word = strtok(NULL, " ");
   }
 }

 // Function to calculate the hashcode of a given word
 int hashcode(char *word)
 {
   int i, hash = 0;
   for (i = 0; word[i] != '\0'; i++)
   {
     hash = hash * 31 + tolower(word[i]);
   }
   return hash % 101; // Return the hashcode
 }

 // Function to calculate the score of a sentence
 int sentenceScore(char *sentence, int *freqtable)
 {
   char *word = strtok(sentence, " ");
   int score = 0;
   while (word != NULL)
   {
     if (strlen(word) > 1) // Ignore single character words
     {
       score += freqtable[hashcode(word)];
     }
     word = strtok(NULL, " ");
   }
   return score;
 }

 // Function to summarize text
 void summarize(char *text, int numSentences)
 {
   int numWords = 0, numSentencesInText = 0, i;
   char *sentence, *tmpText = strdup(text);
   int freqtable[101] = {0}; // Initialize the frequency table to 0

   // Remove non-alphanumeric characters from the text and create the frequency table
   removeNonAlphaNum(tmpText);
   createFrequencyTable(tmpText, freqtable);

   // Calculate the total number of sentences in the text
   for (i = 0; tmpText[i] != '\0'; i++)
   {
     if (tmpText[i] == '.')
     {
       numSentencesInText++;
     }
   }

   // Calculate the average number of words per sentence
   numWords = strlen(tmpText) - numSentencesInText;
   numWords /= numSentencesInText;

   // Select the top numSentences sentences with the highest score
   sentence = strtok(text, ".");
   int scores[numSentencesInText], index[numSentencesInText];
   for (i = 0; i < numSentencesInText; i++)
   {
     scores[i] = sentenceScore(sentence, freqtable);
     index[i] = i;
     sentence = strtok(NULL, ".");
   }
   for (i = 0; i < numSentencesInText - 1; i++)
   {
     int j;
     for (j = i + 1; j < numSentencesInText; j++)
     {
       if (scores[i] < scores[j])
       {
         int tmpScore = scores[i];
         scores[i] = scores[j];
         scores[j] = tmpScore;

         int tmpIndex = index[i];
         index[i] = index[j];
         index[j] = tmpIndex;
       }
     }
   }
   printf("\nSummarized Text:\n");
   for (i = 0; i < numSentences; i++)
   {
     printf("%d. ", i + 1);
     sentence = strtok(text, ".");
     int j;
     for (j = 0; j < index[i]; j++)
     {
       sentence = strtok(NULL, ".");
     }
     printf("%s.\n", sentence);
   }
 }

 int main()
 {
   char text[] = "In computing, a text summarizer is a program or system that automatically generates a summary from one or more documents. The text summarizer is used to create a summary of a text for various purposes, such as to make it more manageable or to present it in a shortened form. The text summarizer works by analyzing the text and selecting the most important sentences, phrases or words. The text summarizer can be used to summarize articles, news stories, documents, and other types of text. There are different types of text summarizers, such as extractive summarizers and abstractive summarizers.";

   int numSentences = 3;
   printf("Original Text:\n%s\n", text);
   summarize(text, numSentences);
   return 0;
 }