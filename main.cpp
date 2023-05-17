#include<iostream>
using namespace std;



struct Data 
{
  int value;  
  int hashvalue;
};
struct Node
{
    Data data;
    Node*next;
};

int const size = 9 ;
Node* HashArray[size];

bool LinkedlistExists (Node * head)
{
    return head!=nullptr;
}
void CreateLinkedlist (int i, int val)
{
  HashArray[i] = new Node;
  HashArray[i]->data.value = val;
  HashArray[i]->next = NULL;
}
void AddNode (int i,int val){   
    Node* current = HashArray[i];
    while (current->next != NULL)
    {
        current = current->next;
    }
        current->next = new Node;
        current->next->data.value = val;
        current->next->next=NULL;
}
void insert(int val)
{
    int i = val % size;
    if (HashArray[i]==NULL)
        CreateLinkedlist(i,val);
    else if (HashArray[i]!=NULL)
       AddNode(i, val);
}    

void printResult(){
    for(int i = 0; i< size; i++){
        Node* current = HashArray[i];
        while( current != NULL)
        {
            cout << current->data.value;
            current = current->next;
        }
    }
}

int main ()
{
    for(int i = 0; i < size; i++)
        HashArray[i] = NULL;
    insert(1);
    insert(4);
    insert(7);
    insert(1);
    insert(5);
    insert(4);
    insert(2);
    insert(1);
    insert(3);
    insert(5);
    
    printResult();
}
//[1,4,7,1,5,2,4,1,3,5]