struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

* /

    Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = NULL, *curr, *temp;
    int n1, n2;

    while (head1 != NULL && head2 != NULL)
    {
        n1 = head1->data;
        n2 = head2->data;

        if (n1 == n2)
        {
            temp = new Node(n1);
            if (head == NULL)
            {
                head = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (n1 < n2)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }

    return head;
}
// TC = O(n+m)     SC = O(n+m)
