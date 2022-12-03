#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtHead(Node *&head, int d)
{
    // new node created//
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node *reverse(Node *&head)
{

    Node *prev = NULL;
    Node *curr = head;
    Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    cout << node1->data << endl;
    // cout << node1->next << endl;

    insertAtTail(tail, 12);
    insertAtTail(tail, 14);
    insertAtTail(tail, 16);

    print(head);
    reverse(head);

    return 0;
}