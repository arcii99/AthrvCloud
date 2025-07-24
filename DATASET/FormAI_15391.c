//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <string.h>

typedef struct {
   char name[50];
   char type[50];
   char value[50];
} Metadata;

Metadata extractMetadata(char *sourceCode) {
    Metadata data;
    char metadataName[50], metadataType[50], metadataValue[50];
    int i, j = 0;

    for (i = 0; i < strlen(sourceCode) - 1; i++) {
        if (sourceCode[i] == '/' && sourceCode[i + 1] == '/') {
            i += 2;
            while (sourceCode[i] != '=') {
                metadataName[j++] = sourceCode[i++];
            }
            metadataName[j] = '\0';
            j = 0;
            i++;
            while (sourceCode[i] != ';') {
                metadataType[j++] = sourceCode[i++];
            }
            metadataType[j] = '\0';
            j = 0;
            i += 2;
            while (sourceCode[i] != '"') {
                i++;
            }
            i++;
            while (sourceCode[i] != '"') {
                metadataValue[j++] = sourceCode[i++];
            }
            metadataValue[j] = '\0';
            break;
        }
    }

    strcpy(data.name, metadataName);
    strcpy(data.type, metadataType);
    strcpy(data.value, metadataValue);
    return data;
}

void main() {
   char sourceCode[500] = "//name=version;type=string;value=1.0\n\n#include <stdio.h>\n\nint main() {\n\tprintf(\"Hello, World!\\n\");\n\treturn 0;\n}";

   Metadata extractedMetadata = extractMetadata(sourceCode);

   printf("Metadata extracted:\n");
   printf("Name: %s\n", extractedMetadata.name);
   printf("Type: %s\n", extractedMetadata.type);
   printf("Value: %s\n", extractedMetadata.value);
}