//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void SIGINT_handler(int signal)
{
    printf("Received interrupt signal. Exiting the program.\n");
    exit(0);
}

void SIGSEGV_handler(int signal)
{
    printf("Received segmentation fault. Possible intrusion detected.\n");
    printf("Segfault occurred at address: 0x%lx\n", (unsigned long)signal);
    printf("Dumping the memory at 0x%lx:\n", (unsigned long)signal);
    void* buf[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        buf[i] = (void*)*((char**)signal + i);
        printf("%p : %02x %02x %02x %02x %02x %02x %02x %02x\n", 
            buf[i],
            *((unsigned char*)buf[i]),
            *((unsigned char*)buf[i] + 1),
            *((unsigned char*)buf[i] + 2),
            *((unsigned char*)buf[i] + 3),
            *((unsigned char*)buf[i] + 4),
            *((unsigned char*)buf[i] + 5),
            *((unsigned char*)buf[i] + 6),
            *((unsigned char*)buf[i] + 7)
            );
    }
    exit(1);
}

int main()
{
    printf("Starting the intrusion detection system...\n");

    signal(SIGINT, SIGINT_handler);
    signal(SIGSEGV, SIGSEGV_handler);

    char password[16] = "mysecretpass123";
    char buffer[256];

    while(1)
    {
        printf("Enter the password: ");
        fgets(buffer, 256, stdin);
        if(strcmp(buffer, password) == 0)
        {
            printf("Correct password entered. Access granted.\n");
            break;
        }
        else
        {
            printf("Incorrect password entered. Access denied.\n");
        }
    }

    printf("Stopping the intrusion detection system...\n");
    return 0;
}