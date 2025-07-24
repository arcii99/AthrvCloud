//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

// Node structure for words and frequency
typedef struct wordFreq {
    char *word;
    int freq;
    struct wordFreq *next;
} WordFreq;

// Function to create a new node and set initial frequency to 1
WordFreq* createNode(char *word) {
    WordFreq *new_node = (WordFreq*) malloc(sizeof(WordFreq));
    new_node->word = (char*) malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->freq = 1;
    new_node->next = NULL;
    return new_node;
}

// Function to search if word exists in the list and increase its frequency
WordFreq* searchAndUpdate(WordFreq *head, char *word) {
    WordFreq *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->freq++;
            return head;
        }
        current = current->next;
    }
    WordFreq *new_node = createNode(word);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to sort words based on frequency in descending order
WordFreq* sortWords(WordFreq *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    WordFreq *a = head;
    WordFreq *b = head->next;
    int swapped = 0;
    while (b != NULL) {
        if (a->freq < b->freq) {
            WordFreq *temp = a;
            a = b;
            b = temp;
            swapped = 1;
        }
        a->next = sortWords(a->next);
        if (swapped) {
            head = b;
        }
        b = b->next;
    }
    return head;
}

int main() {
    char c, word[MAX_WORD_LEN];
    int i = 0;
    WordFreq *head = NULL;
    FILE *fp;
    fp = fopen("sample_text.txt", "r"); // Replace with your sample text file
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        }
        else if (i > 0) {
            word[i] = '\0';
            head = searchAndUpdate(head, word);
            i = 0;
        }
    }
    fclose(fp);
    head = sortWords(head);
    WordFreq *current = head;
    printf("%-20s | %-10s\n", "Word", "Frequency");
    printf("--------------------|------------\n");
    while (current != NULL) {
        printf("%-20s | %d\n", current->word, current->freq);
        current = current->next;
    }
    return 0;
}