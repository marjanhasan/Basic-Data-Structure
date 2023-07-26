#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    /*
    without tracking tail
    1) newNode banao
    2) head NULL hle head = newNode && return kro
    3) tmp er vetore head rekhe traverse kre last node e jabo
    4) tmp er next e newNode bosay dibo
    */
}
void insert_at_position(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    /*
    1) newNode banao
    2) tmp er vetore head rakho
    3) indexing 1 thk start kre desired pos er ag porjonto traverse kro
    4) proti traversing e tmp te tmp->next assign kro,
       tmp equal NULL hle return kro,
       means pos er ag porjonto traverse kro
    6) newNode er next e tmp er next rakho(po)
    7) tmp er next newNode rakho
    */
}
void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}
void delete_from_position(Node *head, int pos)
{
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            return;
        }
    }
    if (tmp->next == NULL)
    {
        return;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}
void delete_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int pos, val;
    val = 10;
    insert_at_head(head, val);
    val = 30;
    insert_at_tail(head, val);
    print_linked_list(head);
    pos = 2;
    val = 20;
    insert_at_position(head, pos, val);
    print_linked_list(head);
    delete_head(head);
    print_linked_list(head);
    pos = 1;
    delete_from_position(head, pos);
    print_linked_list(head);
    return 0;
}
