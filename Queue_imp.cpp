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

class MyQueue
{
public:
    int sz;
    Node *head;
    Node *tail;

    MyQueue()
    {
        this->head = NULL;
        this->tail = NULL;
        sz = 0;
    }

    void enqueue(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deque()
    {
        if (this->empty())
        {
            cout << "Queue empty from" << endl;
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

    int front()
    {
        if (this->empty())
        {
            cout << "Queue empty from top" << endl;
            return -1;
        }
        return head->val;
    }
};

int main()
{
    queue<int> q;
    q.push(5);
    q.push(6);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
}