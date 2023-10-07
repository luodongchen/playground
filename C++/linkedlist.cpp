#include<iostream>

using namespace std;
struct Node{
    private: 
        int value;
        Node* next;

    public:
        Node():next(nullptr)
        {}
        Node(int v):value(v), next(nullptr)
        {}

        void setNext(Node* n){
            next=n;
        }

        Node(const  Node& c){
            value=c.value;
            next=c.next;
        }

        Node &operator=(const Node& c){
            if(this!=&c){
                value=c.value;
                next=new Node;
                next=c.next;
            }
            return *this;
        }

        int getValue(){
            return value;
        }

        Node* getNext(){
            return next;
        }

        ~Node(){
            delete next;
        }
};

struct Queue{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        Queue():size(0),head(nullptr),tail(nullptr)
        {}

        void push_back(int v){
            Node n=Node(v);
            if(size==0){
                head = new Node();
                tail = new Node();
                tail=&n;
                head=&n;
            }else{
                tail->setNext(&n);
                tail=&n;
            }
            size++;
        }

        void pop(){
            head=head->getNext();
            size--;
        }

        bool isEmpty(){
            if (size==0){return true;}
            return false;
        }

        int getHead(){
            return head->getValue(); 
        }

        void display(){
            Node* tmp=new Node();
            tmp=head;
            while(tmp!=tail){
                std::cout<<" "<<tmp->getValue()<<""<<std::endl; 
            }
            tmp=tmp->getNext();
        }


        Queue(const Queue& c){
            head=new Node(c.head->getValue());
            tail=new Node(c.tail->getValue());
            Node* tmp=head;
            while(tmp!=c.tail){
                tmp=c.head->getNext();
                Node n= Node(tmp->getValue());
                head->setNext(&n);
            }

        }

        ~Queue(){
            while(!isEmpty()){
                pop();
            }
        }
};

    Queue merge(Queue a,Queue b){
        Queue result;
        while(!a.isEmpty()&&!b.isEmpty()){
            if(a.getHead()<b.getHead()){
                result.push_back(a.getHead());
                a.pop();
            }else{
                result.push_back(b.getHead());
                b.pop();
            }
        }
        if(!a.isEmpty()){
            while(!a.isEmpty()){
                result.push_back(a.getHead());
                a.pop();
            }
        }
        if(!b.isEmpty()){
            while(!b.isEmpty()){
                result.push_back(b.getHead());
                b.pop();
            }
        }
        return result;

    }





    int main(){
        Queue Q1,Q2;
        Q1.push_back(1);
        Q1.push_back(3);
        Q1.push_back(5);
        Q1.push_back(7);
        Q1.push_back(9);
        Q2.push_back(2);
        Q2.push_back(4);
        Q2.push_back(6);
        Q2.push_back(8);
        Q2.push_back(10);
        Q1.push_back(12);
        Q1.display();
    }