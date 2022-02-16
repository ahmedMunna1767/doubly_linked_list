#include <stdio.h>
#include <assert.h>

#include "doubly_linked_list.h"
#include "doubly_linked_list.c"

int main()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    
    assert(isEmpty(head) == 1);

    // pushing five elems 14 - 10
    for (int i = 0; i < 5; i++)
    {
        pushFront(&head, &tail, i + 10);
    }
    assert(getLength(head) == 5); 

    insert(&head, &tail, 1, 235);
    assert(getLength(head) == 6); 
    

    // pushing five elems 20 - 24
    for (int i = 0; i < 5; i++)
    {
        pushBack(&head, &tail, i + 20);
    }
    assert(getLength(head) == 11); 
    printListForward(head);
    printListBackward(tail); 

    assert(isEmpty(head) == 0);
    popFront(&head, &tail); 
    popBack(&head, &tail); 

    assert(getLength(head) == 9);
    assert(valueAtIndex(head, 0)== 235);
    assert(front(head) == 235); 
    assert(back(tail) == 23);
    assert(valueAtIndexFromEnd(tail, 0) == 23); 

    insert(&head, &tail, 0, 1000); 
    assert(front(head) == 1000); 

    erase(&head, &tail, 0); 
    assert(front(head) == 235); 

    assert(removeValue(&head, &tail, 10000) == -1); 
    assert(removeValue(&head, &tail, 235) == 235); 

    deleteList(head); 
    printf("Program Ran Successfully.....");
    return 0;
}