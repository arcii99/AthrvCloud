//FormAI DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 20
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content[MAX_PAGES];
} Ebook;

void print_menu();
int add_ebook(Ebook ebooks[]);
void display_ebooks(Ebook ebooks[], int num_ebooks);
int read_ebook(Ebook ebooks[], int num_ebooks);
int save_ebook(Ebook ebooks[], int num_ebooks);
void load_ebooks(Ebook ebooks[], int* num_ebooks);
void free_ebooks(Ebook ebooks[], int num_ebooks);
 
int main() {
    Ebook ebooks[MAX_EBOOKS];
    int num_ebooks = 0;
    char choice;
    do {
        print_menu();
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                num_ebooks += add_ebook(&ebooks[num_ebooks]);
                break;
            case '2':
                display_ebooks(ebooks, num_ebooks);
                break;
            case '3':
                read_ebook(ebooks, num_ebooks);
                break;
            case '4':
                num_ebooks = save_ebook(ebooks, num_ebooks);
                break;
            case '5':
                load_ebooks(ebooks, &num_ebooks);
                break;
            case '6':
                free_ebooks(ebooks, num_ebooks);
                break;
            case '7':
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != '7');
    return 0;
}

void print_menu() {
    printf("\n1. Add Ebook\n");
    printf("2. Display Ebooks\n");
    printf("3. Read Ebook\n");
    printf("4. Save Ebooks\n");
    printf("5. Load Ebooks\n");
    printf("6. Free Ebooks Memory\n");
    printf("7. Exit\n");
}

int add_ebook(Ebook ebooks[]) {
    int num_added = 0;
    printf("Enter title of ebook: ");
    fgets(ebooks[num_added].title, MAX_TITLE_LENGTH, stdin);
    ebooks[num_added].title[strcspn(ebooks[num_added].title, "\n")] = 0;
    printf("Enter author of ebook: ");
    fgets(ebooks[num_added].author, MAX_AUTHOR_LENGTH, stdin);
    ebooks[num_added].author[strcspn(ebooks[num_added].author, "\n")] = 0;
    printf("Enter number of pages in ebook: ");
    scanf("%d", &ebooks[num_added].pages);
    getchar();
    printf("Enter content (max %d pages):\n", MAX_PAGES);
    for (int i = 0; i < ebooks[num_added].pages; i++) {
        ebooks[num_added].content[i] = (char*) malloc(sizeof(char) * MAX_PAGES);
        fgets(ebooks[num_added].content[i], MAX_PAGES, stdin);
        ebooks[num_added].content[i][strcspn(ebooks[num_added].content[i], "\n")] = 0;
    }
    num_added++;
    printf("Ebook added successfully\n");
    return num_added;
}

void display_ebooks(Ebook ebooks[], int num_ebooks) {
    printf("\n");
    for (int i = 0; i < num_ebooks; i++) {
        printf("Title: %s\n", ebooks[i].title);
        printf("Author: %s\n", ebooks[i].author);
        printf("Pages: %d\n", ebooks[i].pages);
        printf("Content:\n");
        for (int j = 0; j < ebooks[i].pages; j++) {
            printf("%s\n", ebooks[i].content[j]);
        }
        printf("\n");
    }
}

int read_ebook(Ebook ebooks[], int num_ebooks) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter title of ebook to read: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            printf("Title: %s\n", ebooks[i].title);
            printf("Author: %s\n", ebooks[i].author);
            printf("Content:\n");
            for (int j = 0; j < ebooks[i].pages; j++) {
                printf("%s\n", ebooks[i].content[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("Ebook not found\n");
    return 0;
}

int save_ebook(Ebook ebooks[], int num_ebooks) {
    FILE* fp;
    fp = fopen("ebooks.dat", "wb");
    if (fp == NULL) {
        printf("Error: Could not save ebooks\n");
        return num_ebooks;
    }
    fwrite(&num_ebooks, sizeof(int), 1, fp);
    for (int i = 0; i < num_ebooks; i++) {
        fwrite(&(ebooks[i]), sizeof(Ebook), 1, fp);
    }
    printf("%d ebooks saved successfully\n", num_ebooks);
    fclose(fp);
    return num_ebooks;
}

void load_ebooks(Ebook ebooks[], int* num_ebooks) {
    FILE* fp;
    fp = fopen("ebooks.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not load ebooks\n");
        return;
    }
    fread(num_ebooks, sizeof(int), 1, fp);
    for (int i = 0; i < *num_ebooks; i++) {
        fread(&(ebooks[i]), sizeof(Ebook), 1, fp);
    }
    printf("%d ebooks loaded successfully\n", *num_ebooks);
    fclose(fp);
}

void free_ebooks(Ebook ebooks[], int num_ebooks) {
    for (int i = 0; i < num_ebooks; i++) {
        for (int j = 0; j < ebooks[i].pages; j++) {
            free(ebooks[i].content[j]);
        }
    }
    printf("Ebooks memory freed successfully\n");
}