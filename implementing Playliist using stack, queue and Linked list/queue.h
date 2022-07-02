#ifndef QUEUE
#define QUEUE
#include "string.h"
#include"stdlib.h"
char*playlist[100];
  char temp_2[100];//used to temporarily store after removing from queue
   int rear[2];
   int front[2];
  void enqueue(char*,char*[100]);//used for adding item in to the queue
  int dequeue(char*[100]);//used for removing item from queue
  int isempty(char*[100]);//checks if queue is empty or not

#endif 
