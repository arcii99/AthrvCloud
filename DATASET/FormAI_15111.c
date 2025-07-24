//FormAI DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include<stdio.h>
#include<string.h>

//Function to check whether a character is a sentence terminator or not
int is_sentence_terminator(char ch) {
    if(ch == '.' || ch == '?' || ch == '!')
        return 1;
    else
        return 0;
}

//Function to summarize the given text
void summarize_text(char text[], int summary_length) {
    int text_length = strlen(text);
    int summary_count = 0;
    int sentence_count = 0;
    int sentence_start = 0;
    int sentence_length = 0;
    int i,j;

    printf("Original Text:\n%s\n\n", text);
    printf("Summary:\n");

    for(i=0; i<text_length; i++) {
        //Check if the current character is a sentence terminator
        if(is_sentence_terminator(text[i])) {
            //If a sentence is found, process it
            sentence_count++;
            sentence_length = i - sentence_start + 1;
            //If the summary count is less than the summary length, print the sentence
            if(summary_count + sentence_length <= summary_length) {
                for(j=sentence_start; j<=i; j++)
                    printf("%c", text[j]);
                summary_count += sentence_length;
            } else {
                //If the summary count is greater than the summary length, stop summarizing
                break;
            }
            sentence_start = i + 1;
        }
    }
    //If summary count is less than summary length, print remaining text
    if(summary_count < summary_length) {
        for(i=sentence_start; i<text_length; i++) {
            printf("%c", text[i]);
            summary_count++;
            if(summary_count == summary_length)
                break;
        }
    }
    //Print summary statistics
    printf("\n\nSummary Statistics:\n");
    printf("Original Text Length: %d characters\n", text_length);
    printf("Summary Length: %d characters\n", summary_length);
    printf("Sentence Count: %d\n", sentence_count);
    printf("Summary Count: %d\n", summary_count);
}

int main() {
    char text[] = "In a future world where information is abundant and attention spans are short, there is a need for an automated text summarizer that can help people quickly understand the main points of a lengthy or complex document. The text summarizer presented here is an example of such a tool. It uses simple heuristics based on sentence length and position to extract the most important sentences from a text and present them in a concise summary. The program is designed to be easily customizable and adaptable to a wide range of applications.";
    int summary_length = 100;

    summarize_text(text, summary_length);

    return 0;
}