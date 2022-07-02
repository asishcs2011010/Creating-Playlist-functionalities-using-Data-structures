#include <stdio.h>
#include"stack.h"
#include"linkedlist.h"
#include"queue.h"
int top=-1;
  int isEmpty()
    {   if(top<0)                           
      {  return 1; }
      else { return 0;}
    }
  void push(char *r_song)
     { 
       top=top+1;
       recent_songs[top]=(char*)malloc(sizeof(char));
       strcpy(recent_songs[top],r_song);
     }
   int pop()
    {   if(top==-1)
        {return 0;}  
        else
       {strcpy(temp_3,recent_songs[top]);
        top=top-1;
        return 1;}        
    }

   void play_next()
     {  if(isempty(playlist)==1)
        {printf("no song to play,please create your             playlist\n");}  
        if(dequeue(playlist)==1)
        { printf("playing %s\n",temp_2);
         push(temp_2);}             
     }               

  void play_previous(int k) 
     { int i=0,j=0;
      while(i<k) 
        { if(isEmpty()==1) 
           {printf("sorry,there weren’t %d recent songs\n",k);break;}
          else
           {pop();
            printf("playing %s\n",temp_3);
            enqueue(temp_3,temp_queue); }
            i=i+1;
        }
       while(j<i)
        { { dequeue(temp_queue);
            push(temp_2);} 
          j=j+1;
        }
       }
       