#include <stdio.h>
#include"linkedlist.h"
#include"queue.h"

 void insert( char *b)
 {  
   struct node*temp;//creating a temporary pointer of struct node
   temp=(struct node*)malloc(sizeof(struct node));
       temp->name_of_song=b;
      temp->link=NULL;
      if(root==NULL)
      {  root=temp; 
      }
      else{ 
        struct node*temp_1;
        temp_1=root;
         while(temp_1->link!=NULL)
           {  temp_1 =temp_1->link;}
            temp_1->link=temp;
      }

 }

 void store()
 {   char *a[100],i=0; //*a[some value] is used for                                    temporarily storing a song name
    printf("Enter all songs\n"); 
    while(1)
    {  a[i]=(char*)malloc(sizeof(char));
       scanf("%s",a[i]);
      if(strncmp(a[i],"-1",100)==0)
        {break;}
      else{ insert(a[i]); }
         i=i+1;}
    { printf("All songs entered\n"); }                         }
 
  int search(char*k)
  { struct node *temp_1;//creating a temporary pointer of struct node
     temp_1= (struct node*)malloc(sizeof(struct node));        temp_1=root;
   while(temp_1!=NULL)
    { if(strncmp(temp_1->name_of_song,k,100)==0)
      { return 1;}  
        temp_1 =temp_1->link;
           } 
        return 0;  
  }
   
   void create_playlist()
   {  char *c[100],j=0; //*c[some value] is used for                                    temporarily storing a song name
      printf("create playlist,End with -1\n");
    while(1)
      { c[j]=(char*)malloc(sizeof(char)); 
        scanf("%s",c[j]);
         if( strncmp(c[j],"-1",100)==0)
           {break;} 
         else { if(search(c[j])==1)
           {enqueue(c[j],playlist);  
          printf("found,enqueued\n");}    
          else{ printf("sorry,song not found in the song library\n");}      
         j=j+1;}}
      printf("playlist ready\n");  
    }
        
      