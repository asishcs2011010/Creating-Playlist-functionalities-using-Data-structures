#include <stdio.h>
#include"queue.h"
  void enqueue(char*m,char*queue[100])
    { int i;
       if(queue==playlist)
       { i=0; } 
       else {i=1;}     
      queue[rear[i]]=(char*)malloc(sizeof(char));
      strcpy(queue[rear[i]],m);//strcpy function used to copy one string to another
      rear[i]=rear[i]+1; }
      
    int dequeue(char*queue[100])
    {  int i;
       if(queue==playlist)
       { i=0; } 
       else {i=1;}  
       queue[rear[i]]=(char*)malloc(sizeof(char));
      if(front[i]==rear[i])
        { return 0; } 
      else
        { strcpy(temp_2,queue[front[i]]);
        front[i]=front[i]+1;}  
      return 1;                         
        }  

        
      int isempty(char*queue[100])
      { int i;
      if(queue==playlist)
       { i=0; } 
       else {i=1;}  
        if(rear[i]==front[i])
          {  return 1;       }  
          else {return 0;}
          } 
      