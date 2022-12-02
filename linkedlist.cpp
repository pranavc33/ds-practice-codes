#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node created//
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // creating a node for insertion//

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // insert at last
    if (temp->next = NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}

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

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // free up memory
        temp->next = NULL;
        delete temp;
    }

    else
    {
        // deleting middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    // head pointed to node1
    Node *head = node1;
    // tail pointed to node1
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);

    insertAtPos(head, tail, 3, 20);
    print(head);

    insertAtPos(head, tail, 1, 22);
    print(head);

    insertAtPos(head, tail, 1, 23);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(3, head);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}
