// C++ implementation to sort a k sorted doubly
// linked list
// a node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Method 1 - using priority queue
//  function to sort a k sorted doubly linked list
// 'compare' function used to build up the
// priority queue
struct compare
{
    bool operator()(struct Node *p1, struct Node *p2)
    {
        return p1->data > p2->data;
    }
};

struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL)
        return head;

    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node *, vector<Node *>, compare> pq;

    struct Node *newHead = NULL, *cur;

    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            cur = newHead;
        }

        else
        {
            cur->next = pq.top();
            pq.top()->prev = cur;
            cur = pq.top();
        }

        pq.pop();

        // if there are more nodes left in the input list
        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }
    // making 'next' of cur node point to NULL
    cur->next = NULL;

    return newHead;
}
// TC = O(nlogk)    SC = O(k)

// Method 2 - by insertion sort
// function to sort a k sorted doubly linked list
struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    // perform on all the nodes in list
    for (Node *i = head->next; i != NULL; i = i->next)
    {
        Node *j = i;
        // There will be atmost k swaps for each element in the list
        // since each node is k steps away from its correct position
        while (j->prev != NULL && j->data < j->prev->data)
        {
            // swap j and j.prev node
            Node *temp = j->prev->prev;
            Node *temp2 = j->prev;
            Node *temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if (temp != NULL)
                temp->next = j;
            if (temp3 != NULL)
                temp3->prev = temp2;
        }
        // if j is now the new head
        // then reset head
        if (j->prev == NULL)
            head = j;
    }
    return head;
}

// TC = O(nk)    SC = O(1)