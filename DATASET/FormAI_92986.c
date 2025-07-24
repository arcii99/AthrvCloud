//FormAI DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 5000
#define MAX_RECIPIENTS 100

struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipients[MAX_RECIPIENTS][100];
    int num_recipients;
};

struct node {
    struct email data;
    struct node* next;
};

struct mailing_list {
    char name[50];
    struct node* head;
    pthread_mutex_t lock;
};

struct mailing_list* create_mailing_list(char* name) {
    struct mailing_list* list = (struct mailing_list*) malloc(sizeof(struct mailing_list));
    strcpy(list->name, name);
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
    return list;
}

bool is_empty(struct node* head) {
    return head == NULL;
}

struct node* create_node(struct email data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct mailing_list* list, struct email data) {
    pthread_mutex_lock(&list->lock);
    struct node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    pthread_mutex_unlock(&list->lock);
}

void print_list(struct mailing_list* list) {
    pthread_mutex_lock(&list->lock);
    struct node* current = list->head;
    while(current != NULL) {
        printf("Subject: %s\n", current->data.subject);
        printf("Body: %s\n", current->data.body);
        printf("Recipients:\n");
        for(int i = 0; i < current->data.num_recipients; i++) {
            printf("\t%s\n", current->data.recipients[i]);
        }
        printf("------------------------------\n");
        current = current->next;
    }
    pthread_mutex_unlock(&list->lock);
}

void* send_emails(void* arg) {
    struct mailing_list* list = (struct mailing_list*) arg;
    struct node* current = list->head;
    while(current != NULL) {
        printf("Sending email with subject: %s to recipients:\n", current->data.subject);
        for(int i = 0; i < current->data.num_recipients; i++) {
            printf("\t%s\n", current->data.recipients[i]);
            // simulate sending email by sleeping for 1 second
            sleep(1);
        }
        printf("Email sent successfully.\n");
        current = current->next;
    }
    pthread_exit(NULL);
}

int main() {
    struct mailing_list* list = create_mailing_list("Announcements");
    
    struct email email1 = {
        .subject = "Important Announcement",
        .body = "Dear recipients,\nPlease be advised that there will be a scheduled maintenance.\nBest regards,\nThe team",
        .recipients = { "person1@example.com", "person2@example.com", "person3@example.com" },
        .num_recipients = 3
    };
    push(list, email1);
    
    struct email email2 = {
        .subject = "Reminder",
        .body = "Dear recipients,\nThis is just a reminder to submit your application before the deadline.\nBest regards,\nThe team",
        .recipients = { "person4@example.com", "person5@example.com" },
        .num_recipients = 2
    };
    push(list, email2);
    
    print_list(list);
    
    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_emails, (void*)list);
    pthread_join(send_thread, NULL);
    
    return 0;
}