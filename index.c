#include <stdio.h>
#include <stdlib.h>

//exemplo lista encadeada

struct Node {
   int value;
   struct Node *next;
};

void index(struct Node *list);
int menu();

// **************** LIST ****************
void index(struct Node *list) {
   while(list != NULL) {
      printf("%i\n", list->value);
      list = list->next;
   }
}

// **************** CREATE ****************
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
   int item, q, option;
   struct Node *firstNode = NULL;
   struct Node *hook = firstNode;

   do {
      option = menu();

      switch (option) {
      case 1:
         printf("\n\n **************** ADD ****************\n\n");
         printf("Type a number to be inserted into the list right side : ");
         scanf("%i", &item);
         hook = insert_right_side(hook, item);
         break;
      case 2:
         printf("\n\n **************** INDEX ****************\n\n");
         index(hook);
         break;
      default:
         printf("option unimplemented");
         break;
      }
   } while(option != 0);
   return 0;
}

int menu() {
   int op;
   printf("\n\n ********** menu ********** \n\n");
   printf("1 - add\n");
   printf("2 - list\n");
   printf("3 - remove\n");
   printf("0 - exit\n");
   printf("\n\n");
   printf("Choose a number: ");
   scanf("%i", &op);
   return op;
}