//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct IndexNode{           //structure for creating the index node
    int frequency;
    char word[MAX];
    struct IndexNode *next;
};

int hash(char *s){         //hash function to calculate the hash value index 
    int hash = 0;
    int length = strlen(s);
    for(int i=0;i<length;i++){
        hash += s[i];
    }
    return hash % 10;
}

void add_word(struct IndexNode *hashtable[], char *word){    //function to add a new word in the index node
    int index = hash(word);
    if(hashtable[index] == NULL){
        struct IndexNode *new_node = (struct IndexNode*) malloc(sizeof(struct IndexNode));
        new_node->frequency = 1;
        strcpy(new_node->word,word);
        new_node->next = NULL;
        hashtable[index] = new_node;
    }
    else{
        struct IndexNode *head = hashtable[index];
        while(head->next!=NULL){
            if(strcmp(head->word,word) == 0){
                head->frequency+=1;  // if word is already present, just increment its frequency
                return;
            }
            head = head->next;      
        }
        if(strcmp(head->word,word) == 0){   //checking for last word left
            head->frequency+=1;
        }
        else{
            struct IndexNode *new_node = (struct IndexNode*) malloc(sizeof(struct IndexNode));
            new_node->frequency = 1;
            strcpy(new_node->word,word);
            new_node->next = NULL;
            head->next=new_node;
        }
    }
}

void printIndex(struct IndexNode *hashtable[]){    //function to print the Index table created

    printf("WORD\t\tFREQUENCY\n");
    for(int i=0;i<10;i++){
        struct IndexNode *head = hashtable[i];
        if(head != NULL){
            while(head!=NULL){
                printf("%s\t\t%d\n", head->word, head->frequency);
                head = head->next;
            }
        }
    }
}

int main(){
    struct IndexNode *hashtable[10];  //declaring hash table
    char temp[MAX];

    //initializing all the elements of the hash table to NULL
    for(int i=0;i<10;i++){
        hashtable[i] = NULL;
    }

    //adding words in the hashtable
    add_word(hashtable,"apple");
    add_word(hashtable,"ball");
    add_word(hashtable,"cat");
    add_word(hashtable,"dog");
    add_word(hashtable,"elephant");
    add_word(hashtable,"fish");
    add_word(hashtable,"goat");
    add_word(hashtable,"horse");
    add_word(hashtable,"ice-cream");
    add_word(hashtable,"jelly");

    printIndex(hashtable);   //printing INDEX table
    return 0;
}