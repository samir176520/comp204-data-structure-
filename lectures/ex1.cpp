#include <iostream>

using namespace std;

class list 
{
    int *elements = NULL; // i didn't define array yet
    int capacity; // how much list can hold
    int last; // index of last element in list
public:
    // initilize list elements
    list()
    {
        elements = new int[100]; // define array in the runtime enviroment pointer = new DataType[size]
        capacity = 100; // how much array can hold
        last = -1; // array is not have elements 0 mean there is one element
    }

    list(int size)
    {
        elements = new int[size];
        capacity = size;
        last = -1; 
    }

    // empety list
    void empty()
    {
        last = -1;
    }
    // get end of array
    int END()
    {
        return last + 1;
    }
    // insert element by popsition
    void insert(int data, int position)
    {
        if (position > last + 1 || position < 0) // last + 1 is i will insert in last of array
            cout << "position out of range!\n";
        else if (last + 1 == capacity)
            cout << "List is full, can't be insert!\n";
        else
        {
            int temp;
            for (int i = last; i >= position; i--)
                elements[i + 1] = elements[i]; // shift for next element
            
            elements[position] = data;
            last++;
        }
    }

    // delete element
    void remove(int position)
    {
        if (position > last || position < 0)
            cout << "position out of range!\n";
        else if (last == -1)
            cout << "List is empty, there is no need for deletion!\n";
        else
        {
            for (int i = position; i <= last; i++)
            {
                elements[i] = elements[i + 1]; // shift to overwrite deleted element
            }
            last--;
        }        
    }
    // locate position for speciefic data
    int Locate(int x)
    {
        for (int i = 0; i <= last; i++)
        {
            if( (x == elements[i]) )
            return i;
        }
        return END();
    }
    // retreve element based on position
    int retreve(int position)
    {
        if (position > last || position < 0)
        {
            cout << "position out of range!\n";
            return -1;
        }
        else 
        return elements[position];
    }
    // print list
    void print()
    {
        if (last == -1)
            cout << endl;
        else
        {
            for (int i = 0; i <= last;i++)
                cout << elements[i] << "  "; 
            cout << endl;
        }
    }

    // return position of first element
    int first()
    {
        return 0;
    }
    // return next position for send position
    int next(int position)
    {
        if (position == last)
            cout << "End of array doesn't have next element";
        else if (position > last || position < 0)
        {
            cout << "Position out of range!\n";
            return -1;
        }
        else 
            return position + 1;
    }

    // return previows position for send position
    int previos(int position)
    {
        if (position == 0)
            cout << "Start of array doesn't have previos element";
        else if (position > last || position < 0)
        {
            cout << "Position out of range!\n";
            return -1;
        }
        else 
            return position - 1;
    }

    // return size of list
    int size()
    {
        return last + 1;
    }
}; 

int main()
{
    list l(10);
//------------------Test Insert---------------------
    l.insert(1,l.END());

    l.insert(2,l.first());

    l.insert(3,l.END());

    l.insert(4,l.END());

    l.insert(5,l.first());
//------------------Test print--------------------

    cout << "List before changes\n";

    l.print();

//------------------Test delete--------------------

    l.remove(2);

    cout << "List after remove\n";
    l.print();

//------------------Test retrieve-------------------

    cout <<"enter the position of your element that you want to retrieve: ";
    int pos;
    cin >> pos;
    cout<<"the element of position "<< pos << " is " << l.retreve(pos) << endl;

//------------------Test function Size------------------
    cout<<"The size of your List is "<< l.size() << endl;
    return 0;
}