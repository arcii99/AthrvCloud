//FormAI DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCES 200
#define MAX_WORDS 1000

void summarize(char *article, char *summary, int num_sentences, int sentence_count, char *temp_sent[MAX_SENTENCES], char *temp_word[MAX_WORDS]);

int main()
{
    char article[] = "The quick brown fox jumped over the lazy dog. The dog barked at the fox in response. The fox gave up and ran away. The dog was pleased with himself.";
    char summary[1000];

    char *temp_sent[MAX_SENTENCES];
    for(int i=0;i<MAX_SENTENCES;i++) temp_sent[i] = (char *)malloc(MAX_WORDS * sizeof(char));
    char *temp_word[MAX_WORDS];
    for(int i=0;i<MAX_WORDS;i++) temp_word[i] = (char *)malloc(MAX_WORDS * sizeof(char));

    int sentence_count = 0;
    int num_sentences = 2; // choose the number of sentences in the summary
    summarize(article, summary, num_sentences, sentence_count, temp_sent, temp_word);

    printf("%s", summary);

    for(int i=0;i<MAX_SENTENCES;i++) free(temp_sent[i]); 
    for(int i=0;i<MAX_WORDS;i++) free(temp_word[i]);
    return 0;
}

void summarize(char *article, char *summary, int num_sentences, int sentence_count, char *temp_sent[MAX_SENTENCES], char *temp_word[MAX_WORDS])
{
    int article_length = strlen(article);
    int sentence_length = 0;
    int word_count = 0;
    int sent_index = 0;
    int word_index = 0;
    int summary_index = 0;

    // read each character in the article
    for(int i=0;i<=article_length;i++)
    {
        if(article[i] == '.' || article[i] == '!' || article[i] == '?')
        {
            // end of a sentence
            sentence_length++;
            word_count = 0;
            temp_sent[sent_index][word_index] = article[i];
            temp_sent[sent_index][word_index+1] = '\0';
            sent_index++;
            word_index = 0;
        }
        else if(article[i] == ' ' || article[i] == '\n' || article[i] == '\t' || article[i] == '\r')
        {
            // end of a word
            if(word_count > 0)
            {
                word_count = 0;
                temp_word[word_index][word_count] = '\0';
                word_index++;
            }
        }
        else
        {
            // add the character to the relevant sentence or word
            if(sentence_length < MAX_WORDS && word_count < MAX_WORDS)
            {
                temp_sent[sent_index][word_index] = article[i];
                temp_word[word_index][word_count] = article[i];
                word_count++;
            }
        }
    }

    // base case: if sentence count has reached the required number of sentences
    if(sentence_count == num_sentences)
    {
        return;
    }

    // find the length of each sentence and store in an array
    int sent_length[sent_index];
    for(int i=0;i<sent_index;i++)
    {
        sent_length[i] = strlen(temp_sent[i]);
    }

    // find the shortest sentence and use it in the summary
    int shortest_sent = 0;
    for(int i=0;i<sent_index;i++)
    {
        if(sent_length[i] < sent_length[shortest_sent])
        {
            shortest_sent = i;
        }
    }
    strcat(summary, temp_sent[shortest_sent]);
    sentence_count++;

    // remove the used sentence from the array and recursively call the function
    for(int i=shortest_sent;i<sent_index-1;i++)
    {
        strcpy(temp_sent[i], temp_sent[i+1]);
    }
    summarize(article, summary, num_sentences, sentence_count, temp_sent, temp_word);
}