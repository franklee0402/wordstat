#ifndef NODE_H
#define NODE_H

struct node{
    char* data;
    int count;
    struct node * left;
    struct node * right;
    struct node * parent;

};
#endif
