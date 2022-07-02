#ifndef BST
#define BST
#include "string.h"
#include"stdlib.h"
char*temp_1[100];
struct node{
  char key[100];
  struct node*left;
  struct node*right;
  int height;
};
struct node*insert_bst(struct node *, char[100]);//used for adding a new element to the binary search tree
struct node*min_Node(struct node*);//used to find the node which carries min value
struct node* deletion_bst(struct node*,char*);////used for deleting an existing element froom the BST
#endif 