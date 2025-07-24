//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>

main()
{
    int age = 25;

    if(age < 18)
    {
        printf("Oh Romeo, thou art too young to be coding in C.");
    }
    else if (age >= 18 && age < 35)
    {
        printf("Good morrow Romeo!");
        printf("Thou hast potential to be a great C programmer.");
    }
    else if (age >= 35 && age < 50)
    {
        printf("Good evening Romeo.");
        printf("Take heed and handle thy C errors with care.");
    }
    else
    {
        printf("Good night Romeo.");
        printf("Thou art experienced in C programming and error handling.");
        printf("However, even the most experienced programmers may encounter errors.");
        printf("Fear not, for there are ways to handle them.");
        printf("For example:\n");
        
        //Example error handling code starts here:
        FILE *fp;
        fp = fopen("example.txt", "r");
        if(fp == NULL)
        {
            printf("My dearest Juliet, an error has occurred while opening the file!");
        }
        else
        {
            printf("Hark, the file hath been opened successfully!");
            fclose(fp);
        }
    }

    return 0;
}