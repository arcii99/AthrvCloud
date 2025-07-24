//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000

int main()
{
    char filename[100], option;

    printf("Enter the filename to edit (with extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        printf("File not found\n");
        return 1;
    }

    int size = 0, current_position = 0;
    char *file_contents = malloc(MAX_FILE_SIZE);

    size = fread(file_contents, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    while (1)
    {
        printf("\nEnter the option to edit:\n");
        printf("1. Convert to Upper Case\n");
        printf("2. Convert to Lower Case\n");
        printf("3. Reverse\n");
        printf("4. Find and Replace\n");
        printf("5. Save and Quit\n");
        scanf(" %c", &option);

        switch (option)
        {
            case '1':
                for (int i = 0; i < size; ++i)
                {
                    if (islower(file_contents[i]))
                        file_contents[i] = toupper(file_contents[i]);
                }

                printf("\nText converted to upper case.\n");
                break;

            case '2':
                for (int i = 0; i < size; ++i)
                {
                    if (isupper(file_contents[i]))
                        file_contents[i] = tolower(file_contents[i]);
                }

                printf("\nText converted to lower case.\n");
                break;

            case '3':
                for (int i = 0; i < size / 2; ++i)
                {
                    char tmp = file_contents[i];

                    file_contents[i] = file_contents[size - i - 1];
                    file_contents[size - i - 1] = tmp;
                }

                printf("\nText reversed.\n");
                break;

            case '4':
                char find[100], replace[100];
                printf("Enter the text to find: ");
                scanf("%s", find);
                printf("Enter the text to replace: ");
                scanf("%s", replace);

                int find_size = strlen(find);
                int replace_size = strlen(replace);

                for (int i = 0; i < size - find_size; ++i)
                {
                    int match = 1;

                    for (int j = 0; j < find_size; ++j)
                    {
                        if (file_contents[i + j] != find[j])
                        {
                            match = 0;
                            break;
                        }
                    }

                    if (match)
                    {
                        current_position = i;

                        for (int k = 0; k < replace_size; ++k)
                            file_contents[current_position++] = replace[k];

                        for (int k = i + find_size; k < size - find_size; ++k)
                            file_contents[current_position++] = file_contents[k];

                        size = size - find_size + replace_size;
                        file_contents[size] = '\0';
                    }
                }

                printf("\nText replaced.\n");

                break;

            case '5':
                file = fopen(filename, "wb");
                fwrite(file_contents, sizeof(char), size, file);
                fclose(file);
                free(file_contents);

                return 0;

            default:
                printf("\nInvalid option.\n");
                break;
        }
    }

    return 0;
}