//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50
#define WORD_LIST {"apple", "banana", "carrot", "dog", "elephant", "fire", "guitar", "happiness", "island", \
                   "jazz", "kangaroo", "language", "mango", "noodle", "orange", "peace", "quick", "rain", \
                   "sunset", "tiger", "umbrella", "violin", "watermelon", "xylophone", "yellow", "zebra"}

typedef struct Node {
    char word[MAX_LENGTH];
    struct Node* next;
} Node;

void insert(Node** head, char* word) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    snprintf(new_node->word, MAX_LENGTH, "%s", word);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

void shuffle_words(char** word_list, int list_size) {
    srand(time(NULL));
    for (int i = list_size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char* temp = word_list[i];
        word_list[i] = word_list[j];
        word_list[j] = temp;
    }
}

int main() {
    char* word_list[MAX_WORDS] = WORD_LIST;
    int list_size = sizeof(word_list) / sizeof(char*);
    shuffle_words(word_list, list_size);

    Node* head = NULL;
    for (int i = 0; i < list_size; i++) {
        insert(&head, word_list[i]);
    }

    printf("Type the following words as quickly as possible:\n");
    print_list(head);

    time_t start_time = time(NULL);
    char input[MAX_LENGTH];
    int words_correct = 0;
    while (head != NULL) {
        scanf("%s", input);
        if (strcmp(head->word, input) == 0) {
            printf("Correct!\n");
            words_correct++;
        } else {
            printf("Incorrect!\n");
        }
        head = head->next;
    }
    time_t end_time = time(NULL);
    int total_time = (int) difftime(end_time, start_time);
    int typing_speed = (int) ((words_correct / (float) total_time) * 60);
    printf("You typed %d words correctly in %d seconds.\n", words_correct, total_time);
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    return 0;
}