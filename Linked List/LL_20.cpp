/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head, *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
        if (curr != NULL && curr->next == NULL)
        {
            head = curr;
        }
    }

    return head;
}
// Tc = O(n)   SC = O(1)
