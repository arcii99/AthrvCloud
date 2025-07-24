//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <string.h>

//function to find the length of a string
int find_length(char str[])
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}

//function to remove all punctuation from a string
void remove_punctuation(char str[])
{
    int i, j;
    int length = find_length(str);
    char new_str[length];

    //only add non-punctuation characters to the new string
    for(i = 0, j = 0; i < length; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))
        {
            new_str[j] = str[i];
            j++;
        }
    }

    //copy new string back to original string
    for(i = 0; i < j; i++)
    {
        str[i] = new_str[i];
    }
    str[j] = '\0';
}

//function to convert all characters to lowercase
void convert_to_lowercase(char str[])
{
    int i;
    int length = find_length(str);
    for(i = 0; i < length; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

//function to split a string into an array of substrings based on a delimiter
int split_string(char str[], char delimiter, char array[][100])
{
    int i, j, k;
    int length = find_length(str);
    for(i = 0, j = 0, k = 0; i <= length; i++)
    {
        if(str[i] == delimiter || str[i] == '\0')
        {
            array[j][k] = '\0';
            j++;
            k = 0;
        }
        else
        {
            array[j][k] = str[i];
            k++;
        }
    }
    return j;
}

//function to find the most frequent word in an array of strings
int find_most_frequent_word(char array[][100], int length, char most_frequent_word[])
{
    int count[length];
    int max_count = 0;
    int max_index = 0;
    int i, j;

    //initialize count array to 0
    for(i = 0; i < length; i++)
    {
        count[i] = 0;
    }

    //calculate frequency of each word in array
    for(i = 0; i < length; i++)
    {
        for(j = i+1; j < length; j++)
        {
            if(strcmp(array[i], array[j]) == 0)
            {
                count[i]++;
            }
        }
        if(count[i] > max_count)
        {
            max_count = count[i];
            max_index = i;
        }
    }

    //copy most frequent word to output parameter
    if(max_count == 0)
    {
        return 0;
    }
    else
    {
        strcpy(most_frequent_word, array[max_index]);
        return max_count;
    }
}

//function to summarize a text string
void summarize_text(char text[], int num_sentences)
{
    //remove punctuation and convert to lowercase
    remove_punctuation(text);
    convert_to_lowercase(text);

    //split text into an array of sentences
    char sentences[100][100];
    int num_sentences_in_text = split_string(text, '.', sentences);

    //if there are fewer sentences in the text than the desired number of sentences in the summary, use all sentences
    if(num_sentences_in_text <= num_sentences)
    {
        printf("%s", text);
    }
    else
    {
        //find the most frequent word in each sentence and concatenate those sentences into the summary
        char words[100][100];
        char most_frequent_word[100];
        int num_words;
        int frequency;
        int i, j, k;

        //initialize words array to empty strings
        for(i = 0; i < 100; i++)
        {
            words[i][0] = '\0';
        }

        //split each sentence into an array of words, find the most frequent word in each sentence, and add those words to the words array
        for(i = 0; i < num_sentences_in_text; i++)
        {
            num_words = split_string(sentences[i], ' ', words);
            find_most_frequent_word(words, num_words, most_frequent_word);
            strcat(text, sentences[i]);
            if(i != num_sentences_in_text-1)
            {
                strcat(text, ". ");
            }
        }

        //split the concatenated sentences into an array of sentences and only include the desired number of sentences in the summary
        char summary_sentences[100][100];
        split_string(text, '.', summary_sentences);
        for(i = 0; i < num_sentences; i++)
        {
            printf("%s. ", summary_sentences[i]);
        }
    }
}

int main()
{
    char text[] = "The quick brown fox jumped over the lazy dog. The lazy dog was not impressed. The quick brown fox was very proud of himself. The lazy dog just wanted to take a nap.";
    int num_sentences = 2;
    summarize_text(text, num_sentences);
    return 0;
}