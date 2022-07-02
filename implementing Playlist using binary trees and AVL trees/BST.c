#include <stdio.h>
#include"BST.h"
#include"AVL.h"
struct node *insert_bst(struct node*node, char word[100])
{
    if(node==NULL){
        node= malloc(sizeof(struct node));
        strcpy(node->key, word);//strcpy function used to copy one string to another
        node->left=NULL;
        node->right=NULL;
    }
    else{
        if(strcmp(word, node->key)<0)//strcpy function used to for comparing two strings
         { node->left=insert_bst(node->left, word);}
        else if(strcmp(word, node->key)>0)
         { node->right=insert_bst(node->right, word);}
    } return node;//returning root after inserting
      }
 struct node*min_Node(struct node*node)
 {    struct node*current=node;
      while(current&&current->left!=NULL)
      { current=current->left;}                
      return current;}
      
struct node* deletion_bst(struct node*root,char*key)
{  if(root==NULL)//insert/create the first node
    {return NULL;}
   if(strcmp(key,root->key)<0)
    { root->left=deletion_bst(root->left,key);}  
   else if(strcmp(key,root->key)>0)
    { root->right=deletion_bst(root->right,key); }
    else{               
        if(root->right==NULL&&root->left==NULL)
        { return NULL;}
        else if(root->left==NULL)
        { struct node*temp=root->right;
           free(root); 
           return temp;}
        else if(root->right==NULL) 
        {  struct node*temp=root->left;
           free(root);// freeing root here
           return temp;}
       struct node*temp=min_Node(root->right);
       strcpy(root->key,temp->key);
       root->right=deletion_bst(root->right,temp->key);
      }
      return root;}//returning root after deletion 