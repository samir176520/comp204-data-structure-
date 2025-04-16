// create a double linked list that have methods:
// 1. insertion
// 2. deletion
// 3. locator
// 4. display

#include <iostream>

using namespace std;

struct node 
{
    int data;
    node* next;
    node* previos;
};

class list
{
    node* head, *tail;
    int counter;
public:
 void MakeNull()
    {
        head = tail = NULL;
        counter = 0;
    }

    list()
    {
        MakeNull();
    }
   
    void insert(node* p,int data)
    {
        if (p == NULL && head == NULL)
        {
            node* ptr = new node;
            ptr-> next = ptr -> previos = NULL;
            head = tail = ptr;
            counter++;
            ptr -> data = data;
        }
        else if (p == NULL)
            cout << "Error can't insert in NULL";
        else if (p == head)
        {
            node* ptr = new node;
            ptr -> next = head;
            ptr -> previos = NULL;
            head -> previos = ptr;
            head = ptr;
            ptr -> data = data;
        }
        else if (p == tail) 
        {
             node* ptr = new node;
             tail -> next = ptr;
             ptr -> previos = tail;
             ptr -> next = NULL;
             tail = ptr;
             counter++;
             ptr -> data = data;
        }
        else
        {
            node* ptr = new node;
            ptr -> next = p;
            ptr -> previos = p -> previos;
            p -> previos -> next =  ptr;
            p -> previos = ptr;
            counter++;
            ptr -> data = data;

        }
    }

    void Delete(node* p)
    {
        if (p == NULL)
            cout << "Error can't delete\n";
        else if (p == head)
        {
            p -> next -> previos = NULL;
            head = p -> next;
            p -> next = NULL;
            delete p;
        }
        else if (p == tail)
        {
            p -> previos -> next = NULL;
            tail = p -> previos;
            p -> previos = NULL;
            delete p;
        }
        else
        {
            p -> previos -> next = p -> next;
            p -> next -> previos - p -> previos;
            p -> next = p -> previos = NULL;
            delete p;
        }

    }

    void display()
    {
        node* p = head;
        while (p != NULL)
        {
            cout << p -> data << "  " ;
            p = p -> next; 
        }
        cout << endl;
    }

    node* locator(int target)
    {
        node* p = head;
        while (p != NULL)
        {
            if(p -> data == target)
                return p;
            else
                p = p -> next;
        }
        return NULL;
    }

    node* header()
    {
        return head;
    }

    node* tailBack()
    {
        return tail;
    }



};

int main()
{
    list  la;

// ----------------------- test insertion -----------------//
    la.insert(NULL, 5);
    la.insert(la.header(), 6);
    la.insert(la.header(), 8);
    la.insert(la.header(), 6);    
    la.insert(la.header(), 9);    
    la.insert(la.header(), 10);    
    la.insert(la.header(), 3);    
    la.insert(la.header(), 7);
    cout << "After Insertion: ";
    la.display();

//------------------------ test deletion -------------------//
    la.Delete(la.header());
    cout << "After Deletion: ";
    la.display();
    la.insert(la.tailBack(), 75);
    cout << "After insert in tail: ";
    la.display();

// ----------------------- test Locator --------------------//
    int target;
    cout << "Enter number to search for: ";
    cin >> target;
    if (la.locator(target) == NULL)
        cout << "Target not in List" << endl;
    else
        cout << "Target found at adress " << la.locator(target) << endl;
        
    return 0;
}