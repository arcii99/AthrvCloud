//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_TABLE_SIZE 1000 //maximum size of hash table

//defining a node for Linked List chaining
typedef struct listNode {
    char value[100];
    struct listNode* next;
} ListNode;

//defining hash table, which is an array of pointers to ListNode structs
typedef struct hashTable {
    ListNode* listArray[HASH_TABLE_SIZE];
} HashTable;

//hash function to determine index of an input value, using djb2 algorithm
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_TABLE_SIZE;
}

//function to initialize hash table with NULL values
void initHashTable(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->listArray[i] = NULL;
    }
}

//function to insert a value into the hash table
void insertValue(HashTable* ht, char* value) {
    unsigned long index = hash(value);
    ListNode* newNode = malloc(sizeof(ListNode)); //creating a new node for the linked list in hash table
    strcpy(newNode->value, value);
    newNode->next = NULL;

    //check if head of linked list at the index is NULL or not
    if (ht->listArray[index] == NULL) {
        ht->listArray[index] = newNode;
    }
    else {
        ListNode* current = ht->listArray[index];

        //traverse to the end of linked list and then add new node
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//function to determine if value already exists in the hash table
int findValue(HashTable* ht, char* value) {
    unsigned long index = hash(value);

    //check if head of linked list at the index is NULL or not
    if (ht->listArray[index] == NULL) {
        return 0;
    }
    else {
        ListNode* current = ht->listArray[index];

        //traverse through the linked list until the last node or value is found
        while (current != NULL) {
            if (strcmp(current->value, value) == 0) {
                return 1;
            }
            current = current->next;
        }
        return 0;
    }
}

//main function to call other functions and check for spam messages
int main() {
    HashTable ht; //initialize hash table
    initHashTable(&ht);

    //input array of sample spam messages
    char spamMessages[][100] = {
       "Hello my friend, please click on the link to win a million dollar prize",
       "Congratulations! You have been selected for a free vacation to Hawaii",
       "URGENT! Your account has been hacked. Please click on this link to reset your password immediately",
       "Are you tired of working hard for money? Join our pyramid scheme and start earning passive income",
       "Free trial offer! Sign up now to receive a month's supply of our new product",
       "Congratulations! You have won a new car",
       "You have been selected for a special promotion. Click the link to claim your reward",
       "Get rich quick! Join our program now and start earning money immediately",
       "Incredible opportunity! Invest in our business and triple your money",
       "Limited time offer! 50% off on all products. Click the link to redeem the offer"
    };

    //check if each spam message exists in the hash table
    for (int i = 0; i < 10; i++) {
        if (findValue(&ht, spamMessages[i])) {
            printf("Spam message detected: %s \n\n", spamMessages[i]);
        }
        else {
            insertValue(&ht, spamMessages[i]);
        }
    }
    return 0;
}