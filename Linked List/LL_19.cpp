/* structure for a node
struct Node
{
    int data;
    struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }

    // if head node valse is the key
    /*  Node *p=*head;
      if(p->data == key){
          Node *t = *head;
          Node *curr = *head;

          while(curr->next!=*head){
              curr = curr->next;
          }
          curr->next = t->next;
          t = t->next;
          free(p);

      } */

    Node *cur = *head;
    Node *temp;

    while (cur->next != *head && cur->next->data != key)
    {
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = temp->next;
    free(temp);
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *curr = *head_ref, *temp;
    Node *nex = curr->next;

    while (nex != *head_ref)
    {
        temp = nex->next;
        nex->next = curr;
        curr = nex;
        nex = temp;
    }
    nex->next = curr;
    *head_ref = curr;
}
// TC = O(n)    SC=O(1)
