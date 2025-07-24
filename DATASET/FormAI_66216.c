//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_JSON_LENGTH 1000

typedef struct {
    char name[MAX_JSON_LENGTH];
    char value[MAX_JSON_LENGTH];
} JsonProperty;

typedef struct {
    JsonProperty props[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(Stack *s, JsonProperty prop) {
    if (s->top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    strcpy(s->props[s->top].name, prop.name);
    strcpy(s->props[s->top].value, prop.value);
}

JsonProperty pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        JsonProperty dummyProp = {"", ""};
        return dummyProp;
    }
    JsonProperty prop = s->props[s->top];
    s->top--;
    return prop;
}

int main() {
    char json[MAX_JSON_LENGTH] = "{\"name\": \"John\", \"age\": 30, \"car\": {\"make\": \"Toyota\", \"model\": \"Corolla\"}}";
    int len = strlen(json);
    Stack propertyStack;
    initStack(&propertyStack);

    char currentName[MAX_JSON_LENGTH] = "";
    char currentValue[MAX_JSON_LENGTH] = "";
    int parsingName = 0;
    int parsingValue = 0;
    int inNestedObject = 0;
    int i;

    printf("Parsing JSON:\n%s\n", json);

    for (i = 0; i < len; i++) {
        char currentChar = json[i];

        if (currentChar == '{') {
            if (!isStackEmpty(&propertyStack) && !inNestedObject) {
                printf("Error: nested object must have a name\n");
                return 1;
            }
            inNestedObject = 1;
        } else if (currentChar == '}') {
            if (!isStackEmpty(&propertyStack) && strcmp(propertyStack.props[propertyStack.top].name, currentName) == 0) {
                JsonProperty objProp = pop(&propertyStack);
                strcpy(currentValue, objProp.value);
            }
            if (isStackEmpty(&propertyStack) && !inNestedObject) {
                break;
            }
            inNestedObject = 0;
        } else if (currentChar == ':') {
            parsingName = 0;
            parsingValue = 1;
        } else if (currentChar == ',') {
            JsonProperty prop = {currentName, currentValue};
            push(&propertyStack, prop);
            strcpy(currentName, "");
            strcpy(currentValue, "");
            parsingName = 1;
            parsingValue = 0;
        } else if (parsingName) {
            strncat(currentName, &currentChar, 1);
        } else if (parsingValue) {
            strncat(currentValue, &currentChar, 1);
        }
    }

    if (!isStackEmpty(&propertyStack)) {
        printf("Error: object not properly closed\n");
        return 1;
    }

    printf("\nParsed properties:\n");

    for (i = 0; i <= propertyStack.top; i++) {
        printf("%s: %s\n", propertyStack.props[i].name, propertyStack.props[i].value);
    }

    return 0;
}