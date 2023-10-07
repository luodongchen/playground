#include<iostream>
#include<string>

struct Customer{
    
    private:
        Customer* pre;
        Customer* post;
        
    
    public:
        std::string name;
        int priority;
        bool no_pre;
        bool no_post;

        Customer():pre(nullptr),post(nullptr),no_pre(true),no_post(true)
        {}

        Customer(int p, std::string n):priority(p),name(n),pre(nullptr),post(nullptr),no_post(true),no_pre(true)
        {}

        Customer &operator=(const Customer& C){
            if(this!=&C){
                name=C.name;
                priority=C.priority;
                no_pre=C.no_pre;
                no_post=C.no_post;
                post=C.post;
                pre=C.pre;
            }
            return *this;
        }

        void setPre(Customer* C){
            pre=C;
            no_pre=false;
        }

        void setPost(Customer* C){
            post=C;
            no_post=false;
        }

        Customer* getPre(){
            return pre;
        }

        Customer* getPost(){
            return post;
        }

        void wipe_pre(){
            no_pre=true;
            pre=nullptr;
        }

        void wipe_post(){
            no_post=true;
            pre=nullptr;
        }

    
};


struct PriorityQueue{
    private:
        Customer* top;
        Customer* cur;
        int size;

    public:
        PriorityQueue():top(nullptr),cur(nullptr),size(0){}

        PriorityQueue(PriorityQueue &P){
            top=new Customer();
            top=P.top;
            cur=new Customer();
            cur=P.cur;
            size=P.size;
        }
        
        PriorityQueue &operator=(const PriorityQueue& P){
            top=P.top;
            cur=P.cur;
            size=P.size;
            return *this;
        }

        Customer front(){
            while (!top->no_pre){
                top=top->getPre();
            }
            return *top;
        }

        void push_back(int p,std::string n){
            Customer* C = new Customer(p,n);
            if(size==0){ 
                top=C;
                cur=C;
            }else{
                if(p>(cur->priority)){
                    if(cur->no_pre){
                        cur->setPre(C);
                        C->setPost(cur);
                        top=C;
                    }else{
                        while (p>(cur->priority)){
                            if(!cur->no_pre){
                                cur=cur->getPre();
                            }else{
                                break;
                            }
                        }
                        if(cur->no_pre && p>cur->priority){
                            top=C;
                            cur->setPre(C);
                            C->setPost(cur);
                        }else{
                            C->setPre(cur);
                            C->setPost(cur->getPost());
                            cur->getPost()->setPre(C);
                            cur->setPost(C);
                        }
                        
                    }
                }else{
                    while(p<=(cur->priority)){
                        if(!cur->no_post){
                            cur=cur->getPost();
                        }else{
                            break;
                        }
                    }
                    if(cur->no_post){
                        C->setPre(cur);
                        cur->setPost(C);
                    }else{
                        C->setPost(cur);
                        C->setPre(cur->getPre());
                        cur->getPre()->setPost(C);
                        cur->setPre(C);
                    }   
                }
            }        
            size++;   
        }


        void pop_front(){
            if(size>0){
                size--;
                if(!top->no_post){
                    top=top->getPost();
                    top->wipe_pre();
                    cur=top;
                }else{
                    top=nullptr;
                    cur=nullptr;
                }
            }
        }

        void print(){
            cur=top;
            std::cout<<top->priority<<","<<top->name<<std::endl;
            while(!cur->no_post){
                std::cout<<cur->getPost()->priority<<","<<cur->getPost()->name<<std::endl;
                cur=cur->getPost();
            }
            std::cout<<"current: "<<cur->priority<<","<<cur->name<<std::endl;
            std::cout<<"Top: "<<top->priority<<","<<top->name<<std::endl;
            std::cout<<"*****************"<<std::endl;
        }


        ~PriorityQueue(){
            while(!top->no_post){
                pop_front();
            }
            delete top;
        }
        
};









int main(){

    PriorityQueue q3;
    Customer c;
    
    q3.push_back(1, "Norman Nobody");
    q3.print();
    q3.push_back(60, "Marilyn Monroe");
    q3.print();
    q3.push_back(100, "Marie Curie");
    q3.print();    
    q3.push_back(80, "Freddie Mercury");
    q3.print();
    q3.push_back(90, "Martin Luther King");
    q3.print(); 
    q3.push_back(1, "Samuel Someguy");
    q3.print();
    q3.push_back(90, "Mohandas Gandhi");
    q3.print();    
    q3.push_back(100, "Albert Einstein");
    q3.print();
    q3.push_back(80, "John Lennon");
    q3.print();
    
    return 0;
}