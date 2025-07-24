//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct dictionary {
    char word[50];
    struct dictionary *next;
};

typedef struct dictionary Dictionary;

Dictionary * create_node(char word[]) {
    Dictionary *temp = (Dictionary*)malloc(sizeof(Dictionary));
    strcpy(temp->word, word);
    temp->next = NULL;
    return temp;
}

void add_to_dictionary(Dictionary *dictionary[], char word[]) {
    int index = tolower(word[0]) - 'a';
    if(dictionary[index] == NULL) {
        dictionary[index] = create_node(word);
        return;
    }
    Dictionary *temp = dictionary[index];
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = create_node(word);
}

void print_dictionary(Dictionary *dictionary[]) {
    for(int i=0;i<26;i++) {
        printf("\nWords starting with %c: ", 'A'+i);
        Dictionary *temp = dictionary[i];
        while(temp != NULL) {
            printf("%s ", temp->word);
            temp = temp->next;
        }
    }
}

int search_dictionary(Dictionary *dictionary[], char word[]) {
    int index = tolower(word[0]) - 'a';
    if(dictionary[index] == NULL) {
        return 0;
    }
    Dictionary *temp = dictionary[index];
    while(temp != NULL) {
        if(strcmp(temp->word, word) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void check_spelling(Dictionary *dictionary[], char sentence[]) {
    char delim[] = " !?.";
    char *word = strtok(sentence, delim);
    while(word != NULL) {
        if(!search_dictionary(dictionary, word)) {
            printf("\n%s is not spelled correctly.", word);
        }
        word = strtok(NULL, delim);
    }
}

int main() {
    Dictionary *dictionary[26];
    memset(dictionary, NULL, sizeof(dictionary));
    add_to_dictionary(dictionary, "apple");
    add_to_dictionary(dictionary, "bananna");
    add_to_dictionary(dictionary, "cherry");
    add_to_dictionary(dictionary, "dates");
    add_to_dictionary(dictionary, "elephant");
    char sentence[100];
    printf("Enter the sentence:");
    fgets(sentence, 100, stdin);
    check_spelling(dictionary, sentence);
    return 0;
}