#include <iostream>

#define n 11

using namespace std;

struct node 
{
    int data;
    node * next = NULL;
};

class hash_table
{
    node* arr[n];
public: 
     hash_table()
     {
        for (int i = 0; i < n; i++)
            arr[i] =new node;
     }

     void insert(int data)
     {
        node* ptr = new node;
        ptr->data = data;
        data = data % n;
        ptr->next = arr[data]->next;
        arr[data]->next = ptr;
     }

     bool search(int data)
     {
        int k=data%n;
        node*temp=arr[k];
        while(temp->next!=NULL)
        {
           if(temp->next->data==data) 
                return true;
            temp=temp->next;
        }
        return false;
     }

     void display()
     {
        for (int i = 0; i < n; i++)
        {
            int j=0;
            cout << "[" << i << "] -> ";
            node* temp=arr[i];
            while (temp->next != NULL)
            {
                cout << '\t' << temp->next->data;
                temp = temp->next;
            }
            cout << endl;
        }
     }
     // void delete()
};

int main()
{
    hash_table table;
    table.insert(4);
    table.insert(55);
    table.insert(44);
    table.insert(9);
    table.insert(48);
    table.insert(4546);
    table.insert(4254);
    table.insert(846);
    table.insert(86);
    table.insert(24);
    table.insert(756);
    if(table.search(48))
        table.display();
    return 0;
}
