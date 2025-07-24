//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <string.h>

void print_char(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}

void print_A()
{
    print_char(' ', 3);
    print_char('*', 3);
    printf("\n");
    print_char(' ', 2);
    print_char('*', 1);
    print_char(' ', 1);
    print_char('*', 1);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 1);
    print_char('*', 1);
    print_char(' ', 1);
    print_char('*', 1);
    printf("\n");
    print_char('*', 3);
    print_char(' ', 1);
    print_char('*', 3);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 5);
    print_char('*', 1);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 5);
    print_char('*', 1);
    printf("\n");
}

void print_B()
{
    print_char('*', 4);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 2);
    print_char('*', 2);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 2);
    print_char('*', 2);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 2);
    print_char('*', 2);
    printf("\n");
    print_char('*', 4);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 2);
    print_char('*', 2);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 2);
    print_char('*', 2);
    printf("\n");
    print_char('*', 4);
    printf("\n");
}

void print_C()
{
    print_char(' ', 3);
    print_char('*', 4);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 3);
    printf("\n");
    print_char('*', 1);
    printf("\n");
    print_char('*', 1);
    printf("\n");
    print_char('*', 1);
    printf("\n");
    print_char('*', 1);
    print_char(' ', 3);
    printf("\n");
    print_char(' ', 3);
    print_char('*', 4);
    printf("\n");
}

void print_ascii_art(char name[])
{
    int len = strlen(name);
    
    for (int i = 0; i < len; i++)
    {
        switch (name[i])
        {
            case 'A':
                print_A();
                break;
            case 'B':
                print_B();
                break;
            case 'C':
                print_C();
                break;
            default:
                printf("Invalid character: %c\n", name[i]);
        }
    }
}

int main()
{
    char name[] = "ABC";
    print_ascii_art(name);

    return 0;
}