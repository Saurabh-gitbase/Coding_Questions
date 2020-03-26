#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* eliminate_duplicate(Node* head)
{
    if (head == NULL || head->next == NULL) 
    { 
        return head; 
    } 
    unordered_map<int,int> frequency;
    Node* temp = head;
    
    int maxnum = 0;
    
    while(temp)
    {
        frequency[temp->data]++;
        if(temp->data > maxnum)
        {
            maxnum = temp->data;
        }
        temp=temp->next;
    }
    
    temp = head;
    
    while(temp)
    {
        if(frequency[temp->data] > 1)
        {
            frequency[temp->data] = -1;
        }
        else if(frequency[temp->data] == -1)
        {
            temp->data = ++maxnum;
        }
        temp=temp->next;
    }
    
    return head;
}
using namespace std;

int main()
{
    Node* head = new Node(1);
    Node* temp = head;
    temp->next = new Node(3); temp = temp->next;
    temp->next = new Node(1); temp = temp->next;
    temp->next = new Node(4); temp = temp->next;
    temp->next = new Node(4); temp = temp->next;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(1);
    
    eliminate_duplicate(head);
    
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
}
