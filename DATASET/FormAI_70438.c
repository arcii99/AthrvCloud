//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100000
#define MAX_NAME_LENGTH 50
#define MAX_AGE 100

struct record {
   char name[MAX_NAME_LENGTH];
   int age;
   // other details of the record
};

struct index_node {
   int record_index;
   struct index_node *left_child;
   struct index_node *right_child;
};

struct index_node *create_index_node(int record_index) {
   struct index_node *new_node = (struct index_node *) malloc(sizeof(struct index_node));
   new_node->record_index = record_index;
   new_node->left_child = NULL;
   new_node->right_child = NULL;
   return new_node;
}

void insert_index_node(struct index_node **root, int record_index) {
   if (*root == NULL) {
      *root = create_index_node(record_index);
   }
   else if (record_index < (*root)->record_index) {
      insert_index_node(&((*root)->left_child), record_index);
   }
   else if (record_index > (*root)->record_index) {
      insert_index_node(&((*root)->right_child), record_index);
   }
}

void inorder_traversal(struct index_node *root, struct record records[]) {
   if (root != NULL) {
      inorder_traversal(root->left_child, records);
      printf("%s,%d\n", records[root->record_index].name, records[root->record_index].age);
      inorder_traversal(root->right_child, records);
   }
}

int main() {
   struct record records[MAX_RECORDS];
   struct index_node *root = NULL;
   int num_records = 0;

   // populate the records array with sample data
   strcpy(records[num_records].name, "Arthur");
   records[num_records].age = 32;
   insert_index_node(&root, num_records);
   num_records++;

   strcpy(records[num_records].name, "Merlin");
   records[num_records].age = 78;
   insert_index_node(&root, num_records);
   num_records++;

   strcpy(records[num_records].name, "Lancelot");
   records[num_records].age = 26;
   insert_index_node(&root, num_records);
   num_records++;

   // print the records in alphabetical order
   printf("Records in alphabetical order:\n");
   inorder_traversal(root, records);

   return 0;
}