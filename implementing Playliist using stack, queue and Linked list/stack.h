#ifndef STACK
#define STACK
#include "string.h"
#include"stdlib.h"
    int top;
 char temp_3[100];
 char *recent_songs[100];
 char*temp_queue[100];
 void push(char*);
 int pop();//used for removing from stack
 void play_next();//plays the next song in the queue
 void play_previous(int);//plays the previous k songs from recent songs stack
 int isEmpty();//checks if stack is empty or not
 int isFull();//checks if stack is full or not
 

#endif 