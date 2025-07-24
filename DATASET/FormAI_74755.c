//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node {
    char word[100];
    int count;
    struct list_node *next;
} ListNode;

ListNode *addToFront(ListNode *head, char word[]) {
    ListNode *node = malloc(sizeof(ListNode));
    strcpy(node->word, word);
    node->count = 1;
    node->next = head;
    return node;
}

void printList(ListNode *head) {
    ListNode *node = head;
    while (node) {
        printf("%s (count: %d)\n", node->word, node->count);
        node = node->next;
    }
}

int isSpam(char message[]) {
    char spamWords[5][20] = {
        "buy now",
        "limited time offer",
        "amazing deal",
        "act fast",
        "money back guarantee"
    };
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(message, spamWords[i])) {
            return 1;
        }
    }
    return 0;
}

ListNode *updateList(ListNode *head, char message[]) {
    char *word;
    ListNode *current = head;
    ListNode *prev = NULL;

    word = strtok(message, " ");
    while (word != NULL) {
        if (isSpam(word)) {
            return head;
        }

        current = head;
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->count++;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            head = addToFront(head, word);
        }

        word = strtok(NULL, " ");
        prev = NULL;
    }

    return head;
}

void detectSpam(char message[], ListNode *head) {
    head = updateList(head, message);
    printList(head);
}

int main() {
    char message1[] = "Hello, this is a test message.";
    char message2[] = "Money back guarantee on all purchases!";
    char message3[] = "Limited time offer: buy now and save!";
    char message4[] = "Act fast and get an amazing deal on our products!";
    char message5[] = "This is not spam.";

    ListNode *head = NULL;

    printf("Message 1:\n");
    detectSpam(message1, head);

    printf("\nMessage 2:\n");
    detectSpam(message2, head);

    printf("\nMessage 3:\n");
    detectSpam(message3, head);

    printf("\nMessage 4:\n");
    detectSpam(message4, head);

    printf("\nMessage 5:\n");
    detectSpam(message5, head);

    return 0;
}