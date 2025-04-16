#include <iostream>

using namespace std;

struct node 
{
    int data;
    node* next;
};

class list 
{
    node* head; // is the dummy node
    node* tail; // last element in list
    int counter; // how much nodes i have 
public:
    // initialize list
    list()
    {
        MakeNull();
    }

    void MakeNull()
    {
        head = new node; // will start with dummy node in runtime 
        head -> next = NULL; // make next in dummy node is NULL there is no list
        tail = NULL; // there is no list yet
        counter = 0;
    }
    // return pointer of node point to the last node END
    node* END()
    {
        node* p = head;
        while (p -> next != NULL)
            p = p -> next;
        return p; // return pointer of the last cell
    }
    // insert
    void insert(int data, node* position) // position  is pointer for the previos node
    {
        if (position == NULL)
        position = END(); // it want to insert in it's end

        node* temp = new node; // create node in runtime
        temp->data = data;

        temp -> next = position -> next ;
        position -> next = temp;
        if (temp -> next == NULL)
            tail == temp;
        counter++;
    }

    // delete
    void clear(node* p) // clear the next node of pointer p node
    {
        if (p == NULL || p == END())
        cout << "no element to be deleted\n"; // my limits
        else 
        {
            if (p->next == tail) tail = p; // for delete last element
            node* temp = p -> next;
            p -> next = p -> next -> next; // overwrite in specific element
            delete temp;
            counter--;
        }
    }
    // location of x from the cell previous to x
    node* location(int data)
    {
        node* p = head; 
        while (p ->next != NULL && p -> next ->data != data)
            p = p ->next;
        return p;
        
    }
    // retreve using pointer
    int retreve(node* ptr)
    {
        if(ptr == NULL)
        {
            cout << "Error while retreve"; 
            return -1;
        }
        else
        {
            return ptr -> next -> data;
        }
    }
    // print 
    void print()
    {
        node* p =head;
        while (p ->next != NULL)
        {
            cout << p -> next -> data <<"  ";
            p = p -> next;   
        }
        cout << endl;
    }
    // first
    node* first()
    {
        return head;
    }
    // next
    node* next(node* p)
    {
        if (p == NULL)
        {
            cout << "Error no next for NULL\n";
            return NULL;
        } 
        else
            return p ->next;

    }
    // previos
    node* previos(node* pos)
    {
        node* p = head;
        while (p -> next != NULL && p ->next != pos)
            p = p -> next;
        return p;
    }

    // size
    int size()
    {
        return counter;
    }
};

int main()
{
    list l ; 
//------------------Test Insert---------------------

    l.insert(1,l.END());
    l.insert(2,l.first());
    l.insert(3,l.END());
    l.insert(4,l.END());
    l.insert(5,l.first());
    l.insert(534,NULL);
    l.print();
    int x = 2;
    node* pos=l.location(x);
    cout<<"the Next element of x = 2 is "<< l.retreve(l.next(pos)) << endl;
    cout<<"the previous element of x = 2 is " << l.retreve(l.previos(pos)) << endl;
    cout<<"the list after delete x = 2 is "<< endl;
    l.clear(pos);
    l.print();
    return 0;
}