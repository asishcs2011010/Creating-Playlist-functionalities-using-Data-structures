#ifndef AVL
#define AVL
#include "string.h"
#include"stdlib.h"
 char*list[100];
struct node*leftrotate(struct node*);//used for left rotating
struct node*rightrotate(struct node*);//used for right rotating
struct node*insert_avl(struct node*,char[100]);//used for adding a new element to the avl tree
struct node* deletion_avl(struct node*,char[100]);//used for deleting a existing element from avl tree
int getbalance(struct node*);//used to get balnce of that node
int max(int ,int );// to find max
int search(struct node*,char[100]);//used to search for a particular element
int height(struct node*);//gives height of node
void inorder(struct node *);//prints values in the tree in order
#endif 