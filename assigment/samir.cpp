// Samir Ahmed معمل الارضي دكتور الاء وهاجر
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// define queue
class queue 
{
    int front, rear;
    int counter;
    char* queueptr;
    int capacity;

public:
    queue(int size)
    {
        queueptr = new char[size];
        clear();
        capacity = size;
    }
    void clear()
    {
        front = rear = -1;
        counter = 0;
    }
    bool full() {return counter == capacity;}
    bool empty() {return counter == 0;}
    void enqueue(char q)
    {
        if (full())
            cout << "Stack is full, error in size\n";
        else
        {
            rear = (rear + 1) % capacity;
            queueptr[rear] = q;
            counter++;
            if (counter == 1) front = rear; // first insertion initialize
        }
    }
    char dequeue()
    {
        if (empty())
        {
            cout << "Error in lenth queue is full";
            return 0;
        }
        else 
        {
            char temp = queueptr[front];
            front = (front + 1) % capacity;
            counter--;
            if (counter == 0) front = rear = -1; // for the last element
            return temp;
        }
    }
};

// define stack
class stack
{
    int top, capacity, counter;
    char* stackptr;
public:
    stack(int size)
    {
        stackptr = new char[size];
        capacity = size;
        clear();
    }
    void clear()
    {
        top = -1;
        counter = 0;
    }
    bool full() {return counter == capacity;}
    bool empty() {return counter == 0;}
    void push(char element)
    {
        if (full())
            cout << "Error in lenth, stack is full\n";
        else
        {
            stackptr[++top] = element;
            counter++; 
        }
    }
    char pop()
    {
        if (empty())
        {
            cout << "Error in lenth, can't pop empty list\n";
            return 0;
        }
        else 
        {
            char element = stackptr[top--];
            counter--;
            return element;
        }
    }
};

// clean string convert to alphapet
string clean(string element)
{
    // get only alphabets from string
    string clean;
    for (int i = 0, lenth = element.length(); i < lenth; i++)
        if(isalpha(element[i])) clean += tolower(element[i]);
    
    return clean;
}

// function to fill stack and queue with string and use it to check if string palindrome
void checker(string input) 
{
    input = clean(input);
    stack string(input.length());
    queue reverse(input.length());
    for (int i = 0, length = input.length(); i < length; i++)
    {
        string.push(input[i]);
        reverse.enqueue(input[i]);
    }

    while (!(string.empty() && reverse.empty()))
    {
        if (string.pop() != reverse.dequeue())
        {
            cout << "Word is not palindrome.\n";
            return;
        }
    }
    cout << "Word is palindrome.\n";

}

// main function get string and apply operations
int main()
{
    string word;
    cout << "Enter string to test: ";
    cin >> word;
    checker(word);
    return 0;
}