#include<bits/stdc++.h>
using namespace std;

class Node
{
  int data;
  Node* next = NULL;
  Node* prev = NULL;
  Node (int data)
  {
    this->data = data;
  }
}

Node* sort_list(Node* head)
{
  if (head == NULL || head->next == NULL) 
  { 
        return head; 
  }
  
  Node* front = head;
  Node* last = head;

  Node* newlist = new Node();
  Node* temp;
  
  Node* next;
  
  while(last->next != NULL)
  {
    last = last->next;
  }
  
  while(front!=last)
  {
    if(last->data <= front->data)
    {
      temp->next = last;
      next = last->prev;
      last->prev->next = NULL;
      last->prev = temp;
      last = next;
      temp = temp->next;
    }
    else
    {
      temp->next = front;
      next = front->next;
      front->next = NULL;
      front->prev = temp;
      front = next;
      temp = temp->next;
    }
  }
  
  temp->next = front;
  front->prev = temp;
  
  return newlist;
}

int main()
{
    //H.W
}
