#include "node.h"
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void insert(struct node ** root, char * data){
    struct node *ptr = *root;
    struct node *prev = NULL;
    int comp;
    struct node * newnode = malloc(sizeof(struct node));
    char * temp;

    while (ptr != NULL){
        comp = strcmp(ptr->data, data);
        if(comp == 0){   /*match found*/
            ptr->count++;
            return;
        }
        prev = ptr;
        ptr = (comp<0) ? ptr->left : ptr->right;
    }
    temp = (char*)malloc(sizeof(char) *( strlen(data)+1));
    strcpy(temp, data);
    newnode->data = temp;
    newnode->count = 1;

    if( *root == NULL){
        *root = newnode;
        return;
    }
      if(comp < 0){
      prev->left = newnode;
    }
    else{
        prev->right = newnode;
    }
}


void traversal(struct node * root){
    if(root == NULL){return;}
    traversal(root->right);
    printf("%s \t\t  %d\n", root->data, root->count);
    traversal(root->left);
}
