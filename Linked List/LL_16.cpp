/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    if (head == NULL)
        return true;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next == head)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
// TC = O(n)   SC = O(1)