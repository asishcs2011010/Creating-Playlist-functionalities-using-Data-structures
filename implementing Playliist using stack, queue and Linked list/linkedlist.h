#ifndef LINKEDLIST
#define LINKEDLIST
#include "string.h"
#include"stdlib.h"

  struct node  
 { char *name_of_song;
   struct node *link;
 };
  struct node * root;
  void insert(char*);//used for adding a new element to the linkedlist
  void deletion();//used for removing existing element from the linkedlist
  void store();//this function stores  all the songs given by user in a linkedlist
  int search(char*);//this function searches for a particular name of song in the linkedlist
  void create_playlist();//used to create a playlist in a queue
#endif 