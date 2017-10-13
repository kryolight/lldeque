#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "lldeque.h"

// Structure representing a single link in a doubly linked list.
struct link {
  int value;
  struct link* next;
  struct link* prev;
};


struct lldeque {
  struct link* front_sentinel;
  struct link* back_sentinel;
};


struct lldeque* lldeque_create() {
  struct lldeque* deque = malloc(sizeof(struct lldeque));
  assert(deque);

  deque->front_sentinel = malloc(sizeof(struct link));
  assert(deque->front_sentinel);

  deque->back_sentinel = malloc(sizeof(struct link));
  assert(deque->back_sentinel);

  deque->front_sentinel->next = deque->back_sentinel;
  deque->front_sentinel->prev = NULL;

  deque->back_sentinel->next = NULL;
  deque->back_sentinel->prev = deque->front_sentinel;

  return deque;
}


void lldeque_free(struct lldeque* deque) {
  assert(deque);

  /*
   * Here, we're assuming that lldeque_remove_back() handles freeing the memory
   * associated with each removed element.
   */
  while (!lldeque_isempty(deque)) {
    lldeque_remove_back(deque);
  }
  free(deque->front_sentinel);
  free(deque->back_sentinel);
  free(deque);
}


int lldeque_isempty(struct lldeque* deque) {
  assert(deque);
  return deque->front_sentinel->next == deque->back_sentinel;
}


void _lldeque_add_before(struct link* link, int value) {
  struct link* new_link = malloc(sizeof(struct link));
  assert(new_link);

}


void lldeque_add_front(struct lldeque* deque, int value) {
  assert(deque);
  _lldeque_add_before(deque->front_sentinel->next, value);
}


void lldeque_add_back(struct lldeque* deque, int value) {
  assert(deque);
  _lldeque_add_before(deque->back_sentinel, value);
}


int lldeque_front(struct lldeque* deque) {
  assert(deque && !lldeque_isempty(deque));
  return deque->front_sentinel->next->value;
}


int lldeque_back(struct lldeque* deque) {
  assert(deque && !lldeque_isempty(deque));
  return deque->back_sentinel->prev->value;
}


int _lldeque_remove_link(struct link* link) {
  assert(link);

  int value = link->value;
  
  return value;
}


int lldeque_remove_front(struct lldeque* deque) {
  assert(deque && !lldeque_isempty(deque));
  return _lldeque_remove_link(deque->front_sentinel->next);
}


int lldeque_remove_back(struct lldeque* deque) {
  assert(deque && !lldeque_isempty(deque));
  return _lldeque_remove_link(deque->back_sentinel->prev);
}
