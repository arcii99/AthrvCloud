//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include<stdio.h>
#include<time.h>

void print_time(struct tm *t) {
    char s[100];
    strftime(s, sizeof(s), "Today is %A, %B %d.\nCurrent time is %I:%M %p.", t);
    printf("%s\n", s);
}

int main() {
    time_t now;
    struct tm *local_time;

    // Get the current time
    now = time(NULL);
    local_time = localtime(&now);

    print_time(local_time);

    return 0;
}