 #include <stdio.h>
#include"AVL.h"
#include"BST.h"
int max(int a,int b)
{  if(a>b)
   { return a;}
   else if(a<b)
   { return b;}
   else {return a;}}

int height(struct node*node)
{ if(node==NULL) 
    { return 0;}  
   return node->height;   
   }

  int search(struct node*node,char word[100])
  {  if(node==NULL)
      { return 0;}    
     if(strcmp(node->key,word)<0)
       { return search(node->right,word); }  
     if(strcmp(node->key,word)>0)
       { return search(node->left,word);}
     return 1; 
       }  

struct node*rightrotate(struct node*y)//right rotating subtree rooted at y
 { struct node*x=y->left;
   struct node*temp=x->right;
   x->right=y;
   y->left=temp;
   y->height=max(height(y->left),height(y->right));
   x->height=max(height(x->left),height(x->right));
   return x;}

 struct node*leftrotate(struct node*y)//left rotating subtree rooted at y
 { struct node*x=y->right;
   struct node*temp=x->left;
   x->left=y;
   y->right=temp;
   y->height=max(height(y->left),height(y->right));
   x->height=max(height(x->left),height(x->right));
   return x;}

  int getbalance(struct node*node)
  {  if(node==NULL)
      {return 0;}                    
      return height(node->left)-height(node->right);}

  
  struct node*insert_avl(struct node*node,char word[100])
  { if(node==NULL)//insert/create the first node
     { node= malloc(sizeof(struct node));
        strcpy(node->key,word);
        node->left=NULL;
        node->right=NULL; 
        node->height=1;
        return node;}
    else if(strcmp(word, node->key)<0)
      {node->left=insert_avl(node->left,word);}
    else if(strcmp(word, node->key)>0)
         {node->right=insert_avl(node->right, word);}
    else {return node;}//returning root after insertion
       node->height=1+max(height(node->left),height(node->right));//updating heights
       int balance = getbalance(node);

    if(balance>1 && strcmp(word,node->left->key)<0)
      {return rightrotate(node);}//left left case
    if(balance<-1 && strcmp(word,node->right->key)>0)
      {return leftrotate(node);}//right right case
    if(balance>1 && strcmp(word,node->left->key)>0)
      {node->left = leftrotate(node->left);
      return rightrotate(node);}//left right case
    if(balance<-1 && strcmp(word,node->right->key)<0)
      {node->right = rightrotate(node->right);
      return leftrotate(node);}//right left case
      return node;}

void inorder(struct node *node)
   { if(node!=NULL) 
   { inorder(node->left);
     printf("%s\n",node->key);
     inorder(node->right);}}
     
struct node* deletion_avl(struct node*node,char word[100])
{ if(node==NULL)  //performing normal bst deletion
    {return NULL;}
   if(strcmp(word,node->key)<0)
    { node->left=deletion_avl(node->left,word);}  
   else if(strcmp(word,node->key)>0)
    { node->right=deletion_avl(node->right,word); }
    else{               
        if(node->right==NULL&&node->left==NULL)
        { return NULL;}
        else if(node->left==NULL)
        { struct node*temp=node->right;
           free(node); 
           return temp;}
        else if(node->right==NULL) 
        {  struct node*temp=node->left;
           free(node); 
           return temp;}
       struct node*temp=min_Node(node->right);
       strcpy(node->key,temp->key);
       node->right=deletion_avl(node->right,temp->key);
      }
      return node; 
    node->height=1+max(height(node->left),height(node->right));
    int balance = getbalance(node);//balancing the tree by using rotation
    if(balance>1 && getbalance(node->left)>=0)
      {return rightrotate(node);}
    if(balance<-1 && getbalance(node->right)<=0)
      {return leftrotate(node);}
    if(balance>1 && getbalance(node->left)<0)
      {node->left = leftrotate(node->left);
      return rightrotate(node);}
    if(balance<-1 && getbalance(node->right)>0)
      {node->right = rightrotate(node->right);
      return leftrotate(node);}
      return node;
      }


     

      