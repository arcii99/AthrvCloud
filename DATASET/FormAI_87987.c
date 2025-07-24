//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[30];
    char email[50];
    char phone[15];
    char address[100];
    char designation[50];
} Employee;

void embed_watermark(FILE *fp, char *watermark) {
    char text[MAX_FILE_SIZE];
    int watermark_len = strlen(watermark);
    int index = 0;
    while (fgets(text, MAX_FILE_SIZE, fp) != NULL) {
        int text_len = strlen(text);
        int i;
        for (i = 0; i < text_len; i++) {
            if (text[i] == '\n')
                continue;
            if (index < watermark_len) {
                printf("%c", watermark[index]);
                text[i] = watermark[index++];
            } else {
                break;
            }
        }
        printf("%s", text);
    }
    if (index < watermark_len) {
        printf("%s", watermark+index);
    }
}

void extract_watermark(FILE *fp, char *watermark) {
    char text[MAX_FILE_SIZE];
    int index = 0;
    while (fgets(text, MAX_FILE_SIZE, fp) != NULL) {
        int text_len = strlen(text);
        int i;
        for (i = 0; i < text_len; i++) {
            if (text[i] == '\n')
                continue;
            if (index < strlen(watermark)) {
                watermark[index++] = text[i];
            } else {
                break;
            }
        }
    }
}

int main() {
    Employee e1 = {"John", "john@gmail.com", "1234567890", "123 Street, City, State", "Manager"};
    char watermark[50] = "MyDigitalWatermark123";

    // Write employee structure to file
    FILE *fp1 = fopen("employee.txt", "w");
    fwrite(&e1, sizeof(Employee), 1, fp1);
    fclose(fp1);

    // Open file for reading and writing
    FILE *fp2 = fopen("employee.txt", "r+");
    if (fp2 == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    // Embed watermark in file
    embed_watermark(fp2, watermark);

    // Flush stream
    fflush(fp2);

    // Extract watermark from file
    rewind(fp2);
    char extracted_watermark[50] = "";
    extract_watermark(fp2, extracted_watermark);
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Read employee structure from file
    Employee e2;
    fread(&e2, sizeof(Employee), 1, fp2);
    printf("Name: %s\n", e2.name);
    printf("Email: %s\n", e2.email);
    printf("Phone: %s\n", e2.phone);
    printf("Address: %s\n", e2.address);
    printf("Designation: %s\n", e2.designation);

    fclose(fp2);
    return 0;
}