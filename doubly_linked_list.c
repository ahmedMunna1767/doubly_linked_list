void printListForward(listNode *head)
{
    PL("Printing ForWard...");
    LINEBREAK
    int length = 0;
    listNode *ptr = head;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
        length = length + 1;
    }
    LINEBREAK
    PL("Length of the List: %d", length);
    LINEBREAK
}

void printListBackward(listNode *tail)
{
    PL("Printing BackWard...");
    LINEBREAK
    int length = 0;
    listNode *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->prev;
        length = length + 1;
    }
    LINEBREAK
    PL("Length of the List: %d", length);
    LINEBREAK
}

int getLength(listNode *head)
{
    int length = 0;
    listNode *current = head;
    while (current != NULL)
    {
        length = length + 1;
        current = current->next;
    }
    return length;
}

bool isEmpty(listNode *head)
{
    return (head == NULL);
}

void pushFront(listNode **head, listNode **tail, int value)
{
    listNode *link = (listNode *)malloc(sizeof(listNode));
    isValidAddress(link);
    link->value = value;
    link->prev = NULL;
    if (isEmpty(*head))
    {
        *tail = link;
    }
    else
    {
        (*head)->prev = link;
    }

    link->next = *head;
    *head = link;
}

void pushBack(listNode **head, listNode **tail, int value)
{
    listNode *link = (listNode *)malloc(sizeof(listNode));
    isValidAddress(link);

    link->value = value;
    link->next = NULL;
    if (isEmpty(*tail))
    {
        *head = link;
    }
    else
    {
        link->prev = *tail;
        (*tail)->next = link;
    }
    *tail = link;
}

int popFront(listNode **head, listNode **tail)
{
    if (isEmpty((*head)))
    {
        return -1;
    }
    listNode *delItem = *head;
    int retVal = delItem->value;
    if ((*head) == (*tail))
    {
        *tail = NULL;
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(delItem);
    return retVal;
}

int popBack(listNode **head, listNode **tail)
{
    if (isEmpty((*head)))
    {
        return -1;
    }
    listNode *delItem = *tail;
    int retVal = delItem->value;
    if ((*head) == (*tail))
    {
        *tail = NULL;
        *head = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(delItem);
    return retVal;
}

int front(listNode *head)
{
    if (isEmpty(head))
        return -1;

    return head->value;
}

int back(listNode *tail)
{
    if (isEmpty(tail))
        return -1;

    return tail->value;
}

void insert(listNode **head, listNode **tail, int index, int value)
{
    listNode *current = *head;
    listNode *prev = NULL;

    int i; 
    for (i = 0; i < index && current; ++i)
    {
        prev = current;
        current = current->next;
    }

    if (i != index)
    {
        printf("Given index out of bounds.");
        exit(EXIT_FAILURE);
    }

    listNode *node = malloc(sizeof(listNode));
    isValidAddress(node);

    node->value = value;

    if (prev)
    {
        node->prev = prev;
        node->next = current;
        prev->next = node;
        current->prev = node;
    }
    else
    {
        node->next = *head;
        *head = node;
    }
}

void erase(listNode **head, listNode **tail, int index)
{
    listNode *curNode = (*head);
    for (int i = 0; i < index; i++)
    {
        if (curNode == NULL)
        {
            return;
        }
        curNode = curNode->next;
    }
    if (curNode != NULL)
    {
        if (curNode == (*head))
        {
            popFront(head, tail);
        }
        else if (curNode == (*tail))
        {
            popBack(head, tail);
        }
        else
        {
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            free(curNode);
        }
    }
}

int valueAtIndexFromEnd(listNode *tail, int index)
{
    listNode *curNode = tail;
    for (int i = 0; i < index; i++)
    {
        if (curNode == NULL)
        {
            return -1;
        }
        curNode = curNode->prev;
    }

    if (curNode == NULL)
    {
        return -1;
    }
    else
    {
        return curNode->value;
    }
}

int removeValue(listNode **head, listNode **tail, int value)
{
    listNode *curNode = *head;
    while (curNode != NULL && curNode->value != value)
    {
        curNode = curNode->next;
    }

    if (curNode == NULL)
    {
        return -1; 
    }
    

    if (curNode == (*head))
    {
        return popFront(head, tail);
    }
    else if (curNode == (*tail))
    {
        return popBack(head, tail);
    }
    else
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        int retVal = curNode->value; 
        free(curNode);
        return retVal; 
    }
}

int valueAtIndex(listNode *head, int index)
{
    listNode *curNode = head;
    for (int i = 0; i < index; i++)
    {
        if (curNode == NULL)
        {
            return -1;
        }
        curNode = curNode->next;
    }

    if (curNode == NULL)
    {
        return -1;
    }
    else
    {
        return curNode->value;
    }
}

void isValidAddress(void *addr)
{
    if (!addr)
    {
        printf("Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }
}

void deleteList(listNode *head)
{
    listNode *curNode = head;

    while (curNode)
    {
        listNode *nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
}


