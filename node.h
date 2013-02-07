#ifndef NODE_H
#define NODE_H

struct LL{
   char * data;
   struct LL * next; 
};

struct node{
    char* data;
    int count;
    int chain_len;
    struct node * left;
    struct node * right;
    struct LLnode * first;
};
#endif
