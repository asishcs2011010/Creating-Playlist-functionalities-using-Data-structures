
#include <stdio.h>
#include"linkedlist.h"
#include"queue.h"
#include"stack.h"
int main(void) {
  store();
  create_playlist();
  play_next();
  play_next();
  play_next();
  play_previous(3);
  play_previous(3);
  return 0;
}