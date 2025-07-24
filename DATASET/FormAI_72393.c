//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to parse JSON objects
void parseJsonObject(char *jsonStr)
{
    int len = strlen(jsonStr);
    int i = 0;
    while (i < len)
    {
        // Look for the key
        char key[50];
        sscanf(jsonStr + i, "\"%[^\"]\"", key);
        i += strlen(key) + 3;

        // Look for the value
        char value[50];
        if (jsonStr[i] == '\"')
        {
            sscanf(jsonStr + i, "\"%[^\"]\"", value);
            printf("%s: %s\n", key, value);
            i += strlen(value) + 2;
        }
        else if (jsonStr[i] == '{')
        {
            int count = 1;
            char subObject[1000];
            int j = 0;
            while (count > 0)
            {
                subObject[j] = jsonStr[i];
                if (jsonStr[i] == '{')
                {
                    count++;
                }
                else if (jsonStr[i] == '}')
                {
                    count--;
                }
                i++;
                j++;
            }
            subObject[j] = '\0';
            printf("%s: {\n", key);
            parseJsonObject(subObject);
        }
        else if (jsonStr[i] == '[')
        {
            int count = 1;
            char subArray[1000];
            int j = 0;
            while (count > 0)
            {
                subArray[j] = jsonStr[i];
                if (jsonStr[i] == '[')
                {
                    count++;
                }
                else if (jsonStr[i] == ']')
                {
                    count--;
                }
                i++;
                j++;
            }
            subArray[j] = '\0';
            printf("%s: [\n", key);
            parseJsonArray(subArray);
        }
        else
        {
            sscanf(jsonStr + i, "%s", value);
            printf("%s: %s\n", key, value);
            i += strlen(value) + 1;
        }

        if (jsonStr[i] == ',')
        {
            i++;
        }
        else if (jsonStr[i] == '}')
        {
            printf("}\n");
            return;
        }
    }
}

// A function to parse JSON arrays
void parseJsonArray(char *jsonStr)
{
    int len = strlen(jsonStr);
    int i = 0;
    while (i < len)
    {
        // Look for the value
        char value[50];
        if (jsonStr[i] == '\"')
        {
            sscanf(jsonStr + i, "\"%[^\"]\"", value);
            printf("\t%s\n", value);
            i += strlen(value) + 2;
        }
        else if (jsonStr[i] == '{')
        {
            int count = 1;
            char subObject[1000];
            int j = 0;
            while (count > 0)
            {
                subObject[j] = jsonStr[i];
                if (jsonStr[i] == '{')
                {
                    count++;
                }
                else if (jsonStr[i] == '}')
                {
                    count--;
                }
                i++;
                j++;
            }
            subObject[j] = '\0';
            printf("\t{\n");
            parseJsonObject(subObject);
        }
        else if (jsonStr[i] == '[')
        {
            int count = 1;
            char subArray[1000];
            int j = 0;
            while (count > 0)
            {
                subArray[j] = jsonStr[i];
                if (jsonStr[i] == '[')
                {
                    count++;
                }
                else if (jsonStr[i] == ']')
                {
                    count--;
                }
                i++;
                j++;
            }
            subArray[j] = '\0';
            printf("\t[\n");
            parseJsonArray(subArray);
        }
        else
        {
            sscanf(jsonStr + i, "%s", value);
            printf("\t%s\n", value);
            i += strlen(value) + 1;
        }

        if (jsonStr[i] == ',')
        {
            i++;
        }
        else if (jsonStr[i] == ']')
        {
            printf("]\n");
            return;
        }
    }
}

int main()
{
    // Example JSON object
    char *jsonStr = "{\"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\", \"hobbies\": [\"reading\", \"jogging\"], \"address\": {\"street\": \"123 Main St\", \"zip\": 12345}}";

    printf("Parsed JSON:\n");
    parseJsonObject(jsonStr);

    return 0;
}