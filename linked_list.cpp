#include <bits/stdc++.h>
using namespace std;
// first we create a node class
class Node
{
public:
    int data;   // it is for sttore the vlues;
    Node *next; // it is pointr used for store the address for next node
    // lets create a constructer
    Node(int d)
    {
        this->data = d;
        this->next = NULL; // initially store the value null value
    }
    // lets create a destructer

};
void print(Node *&head)
{
    Node *temp = head; // create a temp var for sotre head value
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // move the pointer to next node
    }
    cout << endl;
}
// creating a fuction to insert the value at head
void insert_at_head(Node *&head, int d)
{
    Node *temp = new Node(d); // ctreate a new node with value
    temp->next = head;        // point that node to the head node
    head = temp;              // shift the head to the newly created node
}
// creating a function to the end of the linked list
void insert_at_tail(Node *&tail, int d)
{
    // create a new node
    Node *temp = new Node(d);
    tail->next = temp; // it is for point tail to new node
    tail = temp;       // it is for move tail to right
}
void insert_at_position(Node *tail, Node *&head, int position, int val)
{
    if (position == 1)
    {
        // this condition for if the position for insetion is head
        insert_at_head(head, val);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        ++cnt;
        // this is for rech to postion because we canot access the direct index at the position where we have to //insert the node
    }
    if (temp->next == NULL)
    {
        // if the insertion position in the tail of the linkded list
        insert_at_tail(tail, val);
        return;
    }
    // create new node
    Node *nod = new Node(val);
    nod->next = temp->next;
    temp->next = nod;
}
// functionn for remove the value of a given position
void delet_Node(int position , Node *head){
    Node *temp = head;
    int cnt =1;
    if(position==1){
     head = temp->next;
     free(temp);
     return;
    }
    while (cnt<position-1){
        temp =  temp->next;
        cnt++;
    }
   temp->next= temp->next->next;
    
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insert_at_head(head, 34);
    print(head);
    insert_at_head(head, 33);
    print(head);
    insert_at_tail(tail, 2);
    print(head);
    insert_at_tail(tail, 21);
    print(head);
    insert_at_tail(tail, 82);
    print(head);
    insert_at_position(tail, head, 7, 143);
    print(head);
    delet_Node(1,head);

    print(head);

    return 0;
}