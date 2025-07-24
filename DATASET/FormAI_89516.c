//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} KeyValue;

typedef struct {
    char* name;
    KeyValue* keyValuePairs;
    int numKeyValuePairs;
} JSONNode;

JSONNode* parseJSON(char* jsonString);
int countKeyValuePairs(char* jsonString);
KeyValue* parseKeyValuePairs(char* jsonString, int numPairs);

int main()
{
    char jsonString[1000] = "{ \
    \"name\":\"John\", \
    \"age\":30, \
    \"city\":\"New York\" \
    }";

    JSONNode* parsedJSON = parseJSON(jsonString);

    printf("Parsed JSON:\nName: %s\nAge: %s\nCity: %s\n", parsedJSON->name,
           parsedJSON->keyValuePairs[0].value, parsedJSON->keyValuePairs[1].value);
}

JSONNode* parseJSON(char* jsonString)
{
    JSONNode* node = (JSONNode*)malloc(sizeof(JSONNode));

    int numKeyValuePairs = countKeyValuePairs(jsonString);
    node->keyValuePairs = parseKeyValuePairs(jsonString, numKeyValuePairs);
    node->numKeyValuePairs = numKeyValuePairs;

    int nameStartIndex = strstr(jsonString, "\"name\":\"") - jsonString + strlen("\"name\":\"");
    int nameEndIndex = strstr(jsonString, "\",") - jsonString;
    int nameLength = nameEndIndex - nameStartIndex;
    node->name = (char*)malloc(nameLength + 1);
    strncpy(node->name, jsonString + nameStartIndex, nameLength);
    node->name[nameLength] = '\0';

    return node;
}

int countKeyValuePairs(char* jsonString)
{
    int numPairs = 0;

    char* start = jsonString;
    while (*start)
    {
        if (*start == ',')
            numPairs++;
        start++;
    }

    return numPairs;
}

KeyValue* parseKeyValuePairs(char* jsonString, int numPairs)
{
    KeyValue* pairs = (KeyValue*)malloc(sizeof(KeyValue) * numPairs);

    char* start = jsonString;
    char* end = jsonString;

    for (int i = 0; i < numPairs; i++)
    {
        start = strstr(start, "\":\"") + strlen("\":\"");
        end = strstr(start, "\",");
        int length = end - start;
        pairs[i].value = (char*)malloc(length + 1);
        strncpy(pairs[i].value, start, length);
        pairs[i].value[length] = '\0';

        end += strlen("\",\"");
        
        start = strstr(end, "\":\"") + strlen("\":\"");
        end = strstr(start, "\",");
        length = end - start;
        pairs[i].key = (char*)malloc(length + 1);
        strncpy(pairs[i].key, start, length);
        pairs[i].key[length] = '\0';
    }

    return pairs;
}