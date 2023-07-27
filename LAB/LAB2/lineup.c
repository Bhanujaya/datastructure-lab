#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} Node ;


void printLinkList(Node * head) {
    Node * temp;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;

    }
    printf("\n");
   

}

Node * start;
Node * tail;

void addNode(int data) {
    Node * temp = (Node * )malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;

    }
    if (tail == NULL) {
        tail = temp;

    }
    if (temp == start) {
        ;
    }
    else if (temp->data > tail->data) {
        // printf("%d > %d\n" ,temp->data , tail->data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

    } else if (temp ->data < start->data){
        // printf("%d < %d\n" ,temp->data , start->data);
        start->prev = temp;
        temp->next = start; 
        start = temp;


    } else {
        
        printLinkList(start);
        start = temp;
        tail = temp;
    }
   
    


}



int main(void) {
    int num , i ;
    // Node  *head = NULL;
    scanf("%d", &num);
    int num_list[num];
    for (i = 0 ; i < num ; i++) {
        scanf("%d", &num_list[i]);
        
    }

    for (i = 0 ; i < num ; i++) {
        // printf("addNode %d\n", num_list[i]);
        addNode(num_list[i]);


        
    }
    printLinkList(start);

}