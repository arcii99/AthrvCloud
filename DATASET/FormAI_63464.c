//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    int *ptr = NULL;

    printf("Enter the size of the memory block you want to allocate: ");
    scanf("%d", &input);

    ptr = (int*)malloc(input * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Memory block of size %d bytes has been allocated to ptr at address %p.\n", input*sizeof(int), ptr);

    int loop = 1;
    while(loop == 1)
    {
        printf("Enter 1 to fill the allocated memory or 2 to check current usage: ");
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Filling the memory block...\n");

                for (int i = 0; i < input; i++)
                {
                    *(ptr + i) = i;
                }

                printf("Memory block has been filled.\n");
                break;
            case 2:
                int used = 0;

                for (int i = 0; i < input; i++)
                {
                    if (*(ptr + i) != 0)
                    {
                        used += sizeof(int);
                    }
                }

                int total = input*sizeof(int);
                float utilization = ((float)used/(float)total)*100.0;

                printf("Current memory usage:\n");
                printf("Bytes used: %d\n", used);
                printf("Total bytes allocated: %d\n", total);
                printf("Utilization: %.2f%%\n", utilization);
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &loop);

        if (loop != 1)
        {
            free(ptr);
            printf("Memory block has been freed.\n");
        }
    }

    return 0;
}