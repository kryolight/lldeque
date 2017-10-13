/*
 * A definition for a linked list-based deque implementation.
 */

#ifndef __LLDEQUE_H
#define __LLDEQUE_H

/*
 * Structure used to represent a linked list-based deque.
 */
struct lldeque;

/*
 * Creates a new, empty deque.
 */
struct lldeque* lldeque_create();

/*
 * Free the memory associated with a deque.
 */
void lldeque_free(struct lldeque* deque);

/*
 * Returns 1 if the given deque is empty or 0 otherwise.
 */
int lldeque_isempty(struct lldeque* deque);

/*
 * Endeque a new value at the front of a deque.
 *
 * @param value the new value to be added to the front deque.
 */
void lldeque_add_front(struct lldeque* deque, int value);

/*
 * Endeque a new value at the back of a deque.
 *
 * @param value the new value to be added to the back deque.
 */
void lldeque_add_back(struct lldeque* deque, int value);

/*
 * Returns a deque's front value.
 */
int lldeque_front(struct lldeque* deque);

/*
 * Returns a deque's back value.
 */
int lldeque_back(struct lldeque* deque);

/*
 * Removes the front element from a deque and returns its value.
 */
int lldeque_remove_front(struct lldeque* deque);

/*
 * Removes the back element from a deque and returns its value.
 */
int lldeque_remove_back(struct lldeque* deque);

#endif
