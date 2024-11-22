#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node * head)
{
    struct Node *p = head;
    do
    {
        cout << "Element : " << p->data << endl;
        p = p->next;
    }while (p != head);
}

// Circular Link List Insertion
struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = new struct Node[1];
    struct Node *p = head->next;
    ptr -> data = data;
    while (p->next != head)
    {
       p = p->next;
    }

    // At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = new Node[1];
    second = new Node[1];
    third = new Node[1];
    fourth = new Node[1];

    head->data = 7;
    head->next = second;

    second->data = 37;
    second->next = third;

    third->data = 38;
    third->next = fourth;

    fourth->data = 70;
    fourth->next = head;

    // cout << "Linked list Before" << endl;
    // LinkedListTraversal(head);
    cout << "Linked list After" << endl;
    head = insertAtFirst(head,89);
    LinkedListTraversal(head);
    return 0;
}