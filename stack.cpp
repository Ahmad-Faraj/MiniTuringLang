#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T x)
    {
        data = x;
        next = NULL;
    }
};

template <typename T>
class Stack
{
public:
    Node<T> *head;
    int sz;

    Stack()
    {
        head = NULL;
        sz = 0;
    }

    void push(T y)
    {
        sz++;
        Node<T> *newNode = new Node<T>(y);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        if (head != NULL)
        {
            sz--;
            Node<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    T top()
    {
        if (head == NULL)
            throw runtime_error("Stack is empty");
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }

    int length() // takes O(n)
    {
        Node<T> *tmp = head;
        int counter = 0;
        while (tmp != NULL)
        {
            counter++;
            tmp = tmp->next;
        }
        return counter;
    }

    int size() // takes O(1)
    {
        return sz;
    }

    int search(T x)
    {
        Node<T> *tmp = head;
        int counter = 0;
        while (tmp != NULL)
        {
            if (tmp->data == x)
            {
                return counter;
            }
            counter++;
            tmp = tmp->next;
        }
        return -1;
    }

    void print()
    {
        cout << "\nStack:" << endl;
        Node<T> *tmp = head;

        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }

    ~Stack()
    {
        while (head != NULL)
        {
            pop();
        }
    }
};
