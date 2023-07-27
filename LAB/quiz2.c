#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * next;
  
} Node ;

typedef struct header {
  struct node * head;
  struct node * last;
  int n;

} Header;

int main(void) {
    struct node * first = (struct node *)malloc(sizeof(struct node)) ;
    first->data =1;
    first->next = NULL;

    struct node * kla = (struct node *)malloc(sizeof(struct node)) ;
    kla->data =2;
    kla->next = NULL;
    
    first->next = kla;
    
    struct header * vi = (struct header *)malloc(sizeof(struct header));
    vi->head = kla;
    vi->last = first;

    int num = 2;
    vi->n = num;



//   Node* head;
//   int n = 2;
//   Header * header = (Header *)malloc(sizeof(Header));
//   header->n = n;

  
  
//   Node * temp = (Node*)malloc(sizeof(Node));
//   temp->data = 1;
//   temp->next = NULL;
//   header->last = temp;
//   head = temp;

//   Node * temp_two = (Node*)malloc(sizeof(Node));
//   temp_two->data = 2;
//   head->next= temp_two;
//   header->head = temp_two;
//   head = temp_two;

 
  

  
}