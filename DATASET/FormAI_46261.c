//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include<stdio.h>
#include<string.h>

struct book {
    char title[50];
    char author[50];
    char publisher[50];
    float price;
};

void display(struct book b);

int main() {
    struct book b1;
  
    strcpy(b1.title,"Learning C");
    strcpy(b1.author,"John Doe");
    strcpy(b1.publisher,"Apress");
    b1.price=39.99;

    display(b1);

    return 0;
}

void display(struct book b) {
    printf("\nBook Title: %s", b.title);
    printf("\nAuthor Name: %s", b.author);
    printf("\nPublisher Name: %s", b.publisher);
    printf("\nPrice: $%.2f\n", b.price);
}