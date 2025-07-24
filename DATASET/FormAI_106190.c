//FormAI DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double inbox_size, outbox_size, total_size;
    int num_emails, num_sent, num_received;
    double avg_sent, avg_received;

    printf("Enter the size of your inbox (in MB): ");
    scanf("%lf", &inbox_size);

    printf("Enter the size of your outbox (in MB): ");
    scanf("%lf", &outbox_size);

    printf("Enter the total number of emails: ");
    scanf("%d", &num_emails);

    printf("Enter the number of emails sent: ");
    scanf("%d", &num_sent);

    printf("Enter the number of emails received: ");
    scanf("%d", &num_received);

    total_size = inbox_size + outbox_size;
    avg_sent = num_sent / total_size;
    avg_received = num_received / total_size;

    printf("Total size of your email account: %.2lf MB\n", total_size);
    printf("Average number of emails sent per MB: %.2lf\n", avg_sent);
    printf("Average number of emails received per MB: %.2lf\n", avg_received);

    return 0;
}