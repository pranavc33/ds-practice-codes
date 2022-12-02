#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

/// destructor
//~Node()
//{
// int val = this->data;
//  if (next != NULL)
//{
//  delete next;
// next = NULL;
//}
// cout << "memory is free with data" << endl;
//{
//  /* code */
//}
//}
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
// gives length of linked list
// void getLength(Node *head)
//{
//     int len = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }
void insertAtHead(Node *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // insert at start
    // if (position == 1)
    //{
    //  insertAtHead(head, d);
    // return;
    //}
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // insert at last position//
    // if (temp->next == NULL)
    // {
    //    insertAtTail(tail, d);
    //  return;
    //}

    // create a node to insert//
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// deletion in dll

void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    // deleting middle nodes
    Node *curr = head;
    Node *prev = NULL;
    int count = 1;
    while (count < position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    //  cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 8);
    print(head);

    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 3, 27);
    print(head);

    insertAtPosition(head, tail, 4, 30);
    print(head);

    insertAtPosition(head, tail, 5, 35);
    print(head);

    deleteNode(head, 2);
    print(head);
    return 0;
};