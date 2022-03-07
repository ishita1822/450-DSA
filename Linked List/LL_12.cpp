/* struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
      data = x;
      next = NULL;
  }
};  */

// Method 1
// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    Node *a = head1, *b = head2;

    while (a != b)
    {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    if (a == b)
    {
        return a->data;
    }
    return -1;
}
// TC = O(n+m)  SC = O(1);

// Method 2 - Using difference of 2 linked list
//  Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    Node *l1 = head1, *l2 = head2;
    int n1 = 0, n2 = 0, diff = 0;

    while (l1 != NULL)
    {
        n1++;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        n2++;
        l2 = l2->next;
    }

    l1 = head1;
    l2 = head2;

    diff = abs(n1 - n2);

    if (n1 > n2)
    {
        while (diff != 0)
        {
            l1 = l1->next;
        }
    }
    else
    {
        while (diff != 0)
        {
            l2 = l2->next;
        }
    }

    while (l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1)
    {
        return l1->data;
    }
    return -1;
}
// TC = O(n+m)  SC = O(1);