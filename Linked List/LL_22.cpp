// Method 1 - 2 pointers

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node *head, int x)
{
    // if list is empty
    if (head == NULL)
        return 0;

    struct Node *current, *first, *last;
    int count = 0;

    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != NULL)
        last = last->next;

    // traversing the doubly linked list
    for (current = head; current != NULL; current = current->next)
    {
        int sum = x - (current - data);
        if (first->data + last->data == sum)
        {
            count++;
            first = first->next;
            last = last->next;
        }
        else if (first->data + last->data < sum)
        {
            first = first->next;
        }
        else
        {
            last = last->next;
        }
    }

    // required count of triplets
    return count;
}
// Tc = O(n)   SC = O(1)

// Method 2 - Hashmap
int countTriplets(struct Node *head, int x)
{
    struct Node *ptr, *ptr1, *ptr2;
    int count = 0;

    // unordered_map 'um' implemented as hash table
    unordered_map<int, Node *> um;

    // insert the <node data, node pointer> tuple in 'um'
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;

    // generate all possible pairs
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {

            // p_sum - sum of elements in the current pair
            int p_sum = ptr1->data + ptr2->data;

            // if 'x-p_sum' is present in 'um' and either of the two nodes
            // are not equal to the 'um[x-p_sum]' node
            if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1 && um[x - p_sum] != ptr2)
            {
                count++;
            }
        }
    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return (count / 3);
}
// Tc = O(n^2)   SC = O(n)

// Method 3 - naive approach
int countTriplets(struct Node *head, int x)
{
    struct Node *ptr1, *ptr2, *ptr3;
    int count = 0;

    // generate all possible triplets
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)

                // if elements in the current triplet sum up to 'x'
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
                {
                    count++;
                }
    // required count of triplets
    return count;
}
// Tc = O(n^3)   SC = O(1)
