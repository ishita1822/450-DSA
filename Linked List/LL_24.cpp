/*
typedef struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

} Node;
*/

// Rotate doubly Linked List by N(here p) nodes

class Solution
{
public:
    Node *update(Node *head, int p)
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = head;
        head->prev = last;

        while (p != 0)
        {
            head = head->next;
            last = last->next;
            p--;
        }
        head->prev = NULL;
        last->next = NULL;

        return head;
    }
};
// TC = O(n)    SC = O(1)
