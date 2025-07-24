//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
//The Case of the Mysterious JSON Parser
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to store a key-value pair
typedef struct {
    char *key;
    char *value;
} KeyValuePair;

//Function to parse a JSON string and store key-value pairs in an array
void parseJSON(char *jsonString, KeyValuePair *kvPairs, int *numPairs) {
    //Variable to keep track of the current position in the string
    int pos = 0;
    //Variable to keep track of the number of pairs parsed so far
    int count = 0;
    //Skip any whitespace at the beginning of the string
    while (jsonString[pos] == ' ' || jsonString[pos] == '\t' || jsonString[pos] == '\n') {
        pos++;
    }
    //The beginning of a new key-value pair is marked by a double quote
    while (jsonString[pos] == '\"') {
        //Move past the double quote
        pos++;
        //Find the end of the key by searching for the next double quote
        int endKey = pos;
        while (jsonString[endKey] != '\"') {
            endKey++;
        }
        //Allocate memory for the key and copy it from the string
        char *key = (char*)malloc((endKey-pos+1)*sizeof(char));
        strncpy(key, &jsonString[pos], endKey-pos);
        key[endKey-pos] = '\0';
        //Move past the closing double quote and any whitespace
        pos = endKey + 1;
        while (jsonString[pos] == ' ' || jsonString[pos] == '\t' || jsonString[pos] == '\n' || jsonString[pos] == ':') {
            pos++;
        }
        //Find the start of the value
        int startValue = pos;
        //The value can be a string (marked by double quotes) or a number (which can include a decimal point)
        if (jsonString[pos] == '\"') {
            //Find the end of the string
            int endValue = pos + 1;
            while (jsonString[endValue] != '\"') {
                endValue++;
            }
            //Allocate memory for the value and copy it from the string
            char *value = (char*)malloc((endValue-pos+1)*sizeof(char));
            strncpy(value, &jsonString[pos+1], endValue-pos-1);
            value[endValue-pos-1] = '\0';
            //Move past the closing double quote and any whitespace
            pos = endValue + 1;
            while (jsonString[pos] == ' ' || jsonString[pos] == '\t' || jsonString[pos] == '\n' || jsonString[pos] == ',' || jsonString[pos] == '}' || jsonString[pos] == ']') {
                pos++;
            }
            //Store the key-value pair
            kvPairs[count].key = key;
            kvPairs[count].value = value;
            count++;
        }
        else {
            //Search for the end of the number
            int endValue = pos;
            while ((jsonString[endValue] >= '0' && jsonString[endValue] <= '9') || jsonString[endValue] == '.') {
                endValue++;
            }
            //Allocate memory for the value and copy it from the string
            char *value = (char*)malloc((endValue-pos+1)*sizeof(char));
            strncpy(value, &jsonString[pos], endValue-pos);
            value[endValue-pos] = '\0';
            //Move past any whitespace
            pos = endValue;
            while (jsonString[pos] == ' ' || jsonString[pos] == '\t' || jsonString[pos] == '\n' || jsonString[pos] == ',' || jsonString[pos] == '}' || jsonString[pos] == ']') {
                pos++;
            }
            //Store the key-value pair
            kvPairs[count].key = key;
            kvPairs[count].value = value;
            count++;
        }
    }
    //Update the number of pairs parsed
    *numPairs = count;
}

int main() {
    //A sample JSON string to parse
    char jsonString[] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    //Allocate memory for an array of key-value pairs
    KeyValuePair *kvPairs = (KeyValuePair*)malloc(3*sizeof(KeyValuePair));
    //Parse the JSON string and store the key-value pairs in the array
    int numPairs = 0;
    parseJSON(jsonString, kvPairs, &numPairs);
    //Print out the key-value pairs
    int i;
    for (i = 0; i < numPairs; i++) {
        printf("%s: %s\n", kvPairs[i].key, kvPairs[i].value);
        //Free memory allocated for the key and value
        free(kvPairs[i].key);
        free(kvPairs[i].value);
    }
    //Free memory allocated for the array
    free(kvPairs);
    return 0;
}