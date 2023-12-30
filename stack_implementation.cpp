#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyStack
{
public:
    int sz;
    Node *head;
    Node *tail;

    MyStack()
    {
        this->head = NULL;
        this->tail = NULL;
        sz = 0;
    }

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void pop()
    {
        if (this->empty())
        {
            cout << "Stack empty!!";
            return;
        }
        sz--;
        Node *del = head;
        head = head->next;
        delete del;
    }

    bool empty()
    {
        return sz == 0;
    }

    int top()
    {
        if (this->empty())
        {
            cout << "Stack empty from top";
            return -1;
        }
        return head->val;
    }
};

int main()
{
    MyStack st1, st2;

    st1.push(10);
    st1.push(20);

    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();
}