//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define TEST_TIME 60
#define BUF_SIZE 80

int main()
{
    int i, j;
    int count = 0;
    char c;
    char text[BUF_SIZE];
    time_t start, end;
    struct termios org_opts, new_opts;
    int org_flags, new_flags;

    tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    org_flags = fcntl(STDIN_FILENO, F_GETFL);
    new_flags = org_flags | O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, new_flags);

    printf("Type as much text as you can in %d seconds:\n", TEST_TIME);
    scanf("%[^\n]%*c", text);

    printf("Press any key to start (%d seconds remaining)...\n", TEST_TIME);
    while ((c = getchar()) == EOF && count < TEST_TIME)
    {
        printf("Time remaining: %d seconds\n", TEST_TIME - count);
        sleep(1);
        count++;
    }

    time(&start);
    i = 0;
    j = 0;
    count = 0;
    while (difftime(end, start) < TEST_TIME)
    {
        if (i < BUF_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
        {
            text[i++] = c;
        }
        if (i == 0)
        {
            continue;
        }
        if (text[i - 1] == ' ')
        {
            if (strncmp(text + j, " the ", 5) == 0)
            {
                count++;
            }
            j = i;
        }
        time(&end);
    }

    printf("You typed %.2f words per minute!\n", count / ((double)TEST_TIME / 60));

    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    fcntl(STDIN_FILENO, F_SETFL, org_flags);
    return 0;
}