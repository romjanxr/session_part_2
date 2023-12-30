#include<bits/stdc++.h>
using namespace std;

class Node{
public:
   int val;
   Node *next;
   Node *prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_head(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_tail(Node *&head, Node *&tail, int val){
    if(tail == NULL){
        insert_head(head, tail, val);
        return;
    }

    Node *newNode = new Node(val);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_into_pos(Node *&head, Node *&tail, int val, int pos){
    if(head == NULL){
        insert_head(head, tail, val);
        return;
    }

    Node *newNode = new Node(val);
    Node *tmp = head;

    for(int i = 1; i < pos; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    if(tmp->next != NULL)
        tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

void delete_head(){

}

void delete_pos(Node *&head, int pos){
    if(head == NULL)
    {
        delete_head();
        return;
    }

     Node *tmp = head;

    for(int i = 1; i < pos; i++){
        tmp = tmp->next;
    }

    Node *del = tmp->next;
    tmp->next = del->next;
    if(del->next != NULL)
        del->next->prev = tmp;
    delete del;
    
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
}