//FormAI DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char* content;
} Ebook;

Ebook* create_ebook(char* title, char* author, int num_pages, char* content) {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    strcpy(ebook->title, title);
    strcpy(ebook->author, author);
    ebook->num_pages = num_pages;
    ebook->content = (char*) malloc(sizeof(char) * (strlen(content) + 1));
    strcpy(ebook->content, content);
    return ebook;
}

void read_ebook(Ebook* ebook) {
    printf("Title: %s\nAuthor: %s\nNumber of pages: %d\n\n", ebook->title, ebook->author, ebook->num_pages);
    printf("Start Reading:\n");
    printf("%s\n\n", ebook->content);
}

int main() {
    Ebook* ebook1 = create_ebook("The Great Gatsby", "F. Scott Fitzgerald", 180, "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.\n\n'Whenever you feel like criticizing any one,' he told me, 'just remember that all the people in this world haven't had the advantages that you've had.'\n\nHe didn't say any more, but we've always been unusually communicative in a reserved way, and I understood that he meant a great deal more than that. In consequence, I'm inclined to reserve all judgments, a habit that has opened up many curious natures to me and also made me the victim of not a few veteran bores.");
    Ebook* ebook2 = create_ebook("Nineteen Eighty-Four", "George Orwell", 328, "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.");
    
    read_ebook(ebook1);
    read_ebook(ebook2);
    
    free(ebook1->content);
    free(ebook1);
    free(ebook2->content);
    free(ebook2);
    
    return 0;
}