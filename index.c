#include <stdio.h>
#include <stdlib.h>

//exemplo lista encadeada

struct Node {
   int value;
   struct Node *next;
};

void index(struct Node *list);

void index(struct Node *list) {
   while(list != NULL) {
      printf("%i\n", list->value);
      list = list->next;
   }
}

struct Node *insert_right_side(struct Node *list, int item) { 
   struct Node *firstNode = list;
   struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
   newNode->value = item;
   newNode->next = NULL;

   if(list != NULL) {
      while(list->next != NULL) {
         list = list->next;
      }
      list->next = newNode;
      return firstNode;
   }
   else {
      return newNode;
   }
}

int main(void) {
   int item, q;
   struct Node *firstNode = NULL;
   struct Node *hook = firstNode;

   printf("How many number would you like to add? ");
   scanf("%i", &q);

   for(int i = 0; i < q; i++) {
      printf("Type a number to be inserted into the list right side : ");
      scanf("%i", &item);
      hook = insert_right_side(hook, item);
   } 

   index(hook);
   return 0;
}
