#include "node.h"
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void insert(struct node * root, char * data){
    struct node *ptr = root;
    struct node *prev = NULL;
    int comp;
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    char * temp;

    while (ptr != NULL){
        comp = strcmp(ptr->data, data);
        if(comp == 0){   /*match found*/
            ptr->count++;
        }
        printf("fine here");
        prev = ptr;
        ptr = (comp<0) ? ptr->left : ptr->right;
    }
    temp = (char*)malloc(sizeof(char) *( strlen(data)+1));
    strcpy(temp, data);
    newnode->data = temp;

    if( root == NULL){
        root = newnode;
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
    printf("root data: %s\n", root);
    if(root == NULL){ return;}
    traversal(root->left);
    printf("word: %s count: %d", root->data, root->count);
    traversal(root->right);
}
