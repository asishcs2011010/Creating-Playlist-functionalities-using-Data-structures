#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"
#include"AVL.h"  
struct node*root_bst=NULL;
   struct node*root_avl=NULL;
   char*library[100],temp[100],*temp_1[100],*temp_2[100],*temp_3[100];
   int i=0,j=0,p=0,l=0;
   int a=0,b=0,c=0,d=0;
void create_playlist()//used to create playlist
{    printf("\ncreate your playlist,end with -1\n\n");
   
    while(1)
   { temp_2[a]=(char*)malloc(sizeof(char));
     scanf("%s",temp_2[a]); 
     if(strcmp(temp_2[a],"-1")==0)
     {  break; }
     if(search(root_bst,temp_2[a])==1)
     {  root_avl=insert_avl(root_avl,temp_2[a]); 
       printf("inserted\n");  }
     else{printf("not found\n");}
      a=a+1;}
      printf("the playlist is\n");
      inorder(root_avl);}
void delete_from_library()//used to delete songs from library
{     printf("\nsongs which you want to delete from playlist\n\n");
    while(1)
   { temp_1[p]=(char*)malloc(sizeof(char));
     scanf("%s",temp_1[p]); 
      if(strcmp(temp_1[p],"-1")==0)
      { break;}
       if(search(root_bst,temp_1[p])==1)
         { printf("deleted\n"); }   
      else{printf("not found");}
      p=p+1;}
      while(l<p)
      {  
        root_bst=deletion_bst(root_bst,temp_1[l]); 
      l=l+1;}
    printf("the song libarry is\n");
   inorder(root_bst);}
  void delete_from_playlist()//used to delete songs from playlist
  {    printf("\nsongs you want to delete from playlist\n");
       while(1)
   { temp_3[c]=(char*)malloc(sizeof(char));
     scanf("%s",temp_3[c]); 
      if(strcmp(temp_3[c],"-1")==0)
      { break;}
       if(search(root_avl,temp_3[c])==1)
         { printf("deleted\n"); }   
      else{printf("not found\n");}
      c=c+1;}
      while(d<c)
      { root_avl=deletion_avl(root_avl,temp_3[d]); 
         d=d+1;}
       printf("the playlist is");
   inorder(root_avl);                                             }
int main(void) {
   
   FILE*song=NULL;
   song=fopen("songs_friend.txt","r");//opening file in read mode
   if(song==NULL)
    {printf("file not present");}
   while(fgets(temp,1000,song)!=NULL)
     {temp[strcspn(temp,"\n")] = 0;
      library[i]=(char*)malloc(sizeof(char));
      strcpy(library[i],temp);
      i=i+1;}
   while(j<i)
     { root_bst=insert_bst(root_bst,library[j]);
       j=j+1;}
    printf("song libary from the file is\n");
    inorder(root_bst);
   delete_from_library();
   create_playlist();
   delete_from_playlist();
  
  return 0;
}