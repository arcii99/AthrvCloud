//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_SUBSCRIPTIONS 100

struct EmailList {
    char email[MAX_EMAIL_LENGTH];
};

struct SubscriptionList {
    char topic[20];
    struct EmailList emails[MAX_SUBSCRIPTIONS];
    int num_emails;
};

struct TopicList {
    struct SubscriptionList subscriptions[MAX_SUBSCRIPTIONS];
    int num_subscriptions;
};

struct TopicList topic_list;

int search_subscription_index(char *topic, char *email) {
    int i, j;
    for (i = 0; i < topic_list.num_subscriptions; i++) {
        if (strcmp(topic_list.subscriptions[i].topic, topic) == 0) {
            for (j = 0; j < topic_list.subscriptions[i].num_emails; j++) {
                if (strcmp(topic_list.subscriptions[i].emails[j].email, email) == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}

void add_subscription(char *topic, char *email) {
    int index = search_subscription_index(topic, email);
    if (index == -1) {
        // Subscription not found, create new subscription
        index = topic_list.num_subscriptions;
        strcpy(topic_list.subscriptions[index].topic, topic);
        topic_list.subscriptions[index].num_emails = 0;
        topic_list.num_subscriptions++;
    }
    // Add email to subscription
    strcpy(topic_list.subscriptions[index].emails[topic_list.subscriptions[index].num_emails].email, email);
    topic_list.subscriptions[index].num_emails++;
}

void remove_subscription(char *topic, char *email) {
    int i, j, index;
    index = search_subscription_index(topic, email);
    if (index != -1) {
        // Remove email from subscription
        for (i = 0; i < topic_list.subscriptions[index].num_emails; i++) {
            if (strcmp(topic_list.subscriptions[index].emails[i].email, email) == 0) {
                for (j = i + 1; j < topic_list.subscriptions[index].num_emails; j++) {
                    strcpy(topic_list.subscriptions[index].emails[j-1].email, topic_list.subscriptions[index].emails[j].email);
                }
                topic_list.subscriptions[index].num_emails--;
                break;
            }
        }
        // Remove subscription if no more emails
        if (topic_list.subscriptions[index].num_emails == 0) {
            for (i = index + 1; i < topic_list.num_subscriptions; i++) {
                topic_list.subscriptions[i-1] = topic_list.subscriptions[i];
            }
            topic_list.num_subscriptions--;
        }
    }
}

void show_subscriptions(char *email) {
    int i, j, num_subscriptions = 0;
    for (i = 0; i < topic_list.num_subscriptions; i++) {
        for (j = 0; j < topic_list.subscriptions[i].num_emails; j++) {
            if (strcmp(topic_list.subscriptions[i].emails[j].email, email) == 0) {
                if (num_subscriptions == 0) {
                    printf("%s subscriptions:\n", email);
                }
                printf("\t%s\n", topic_list.subscriptions[i].topic);
                num_subscriptions++;
                break;
            }
        }
    }
    if (num_subscriptions == 0) {
        printf("%s has no subscriptions.\n", email);
    }
}

int main() {
    int choice;
    char email[MAX_EMAIL_LENGTH];
    char topic[20];
    while (1) {
        printf("\n1. Add subscription\n");
        printf("2. Remove subscription\n");
        printf("3. Show subscriptions for email\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter topic: ");
                scanf("%s", topic);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscription(topic, email);
                printf("Subscription added successfully.\n");
                break;
            case 2:
                printf("\nEnter topic: ");
                scanf("%s", topic);
                printf("Enter email: ");
                scanf("%s", email);
                remove_subscription(topic, email);
                printf("Subscription removed successfully.\n");
                break;
            case 3:
                printf("\nEnter email: ");
                scanf("%s", email);
                show_subscriptions(email);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}