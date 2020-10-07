// A simple C program for traversal of a linked list 
#include <stdio.h> 
#include <stdlib.h> 
  
struct node { 
    int data; 
    struct node* next; 
}; 
  
 
void printList(struct node* n) 
{ 
  int c = 0;
    while (n != NULL) { 
        if(c!=0){
        printf(" %d ", n->data); 
        }
        n = n->next; 
        c++;
    }
    printf("\n") ;
} 
  
void insert_node(struct node** root_ref, int new_data) 
{ 
       struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
      struct node *last = *root_ref;     
    
    new_node->data  = new_data;
    new_node->next = NULL; 
  
   
    if (*root_ref == NULL) 
    { 
       *root_ref = new_node; 
       return; 
    }   
       
    
    while (last->next != NULL) {
        last = last->next; 
      }
   
   last->next = new_node; 
    return;     
}

void delete_node(struct node** root_ref, int value){
 struct node *del = *root_ref;     
struct node *prev = *root_ref;
      
       
    
    while (del->next->data != value) {
        prev = del;
        del = del->next; 
      }
   prev = del;
        del = del->next; 


    if(del->next!=NULL){
        prev->next = del->next;
    }else{
      prev->next = NULL;
    }

   
    return;     

}


int main() 
{ 
    struct node* root = NULL; 
    
  
    // allocate 3 nodes in the heap 
    root = (struct node*)malloc(sizeof(struct node)); 
    insert_node(&root, 2);
    insert_node(&root, 3);
    insert_node(&root,8);
  
    printList(root);
    delete_node(&root,2) ;
  printList(root);
    return 0; 
}