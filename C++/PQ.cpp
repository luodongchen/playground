#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Customer{
    public: 
        int priority;
        string name;

        Customer()
        {}

        Customer(int p,string n):priority(p),name(n)
        {}

        Customer(const Customer& co){
            if(this!=&co){
                priority=co.priority;
                name=co.name;
            }
        }

        Customer&operator=(const Customer& co){
            priority=co.priority;
            name=co.name;
            return *this;
        }

        ~Customer(){}
};

struct PriorityQueue{
    private:
        vector< vector<Customer> > data;
        int size;

    public:
        PriorityQueue():size(0)
        {}

        PriorityQueue(const PriorityQueue& co){
            size=co.size;
            data.clear();
            for(int i=co.data.size();i>0;i--){
                vector<Customer> col;
                for(int j=co.data.at(i).size();j>0;j--){
                    col.push_back(co.data.at(i).at(j));
                }
                data.push_back(col);
            }
        }

        PriorityQueue &operator=(const PriorityQueue& co){
            if(this!=&co){
                size=co.size;
                data.clear();
                for(int i=co.data.size();i>0;i--){
                    vector<Customer> col;
                    for(int j=co.data.at(i).size();j>0;j--){
                        col.push_back(co.data.at(i).at(j));
                    }
                    data.push_back(col);
                }
            }
            return *this;
        }

        void push_back(int p,string n){
            if(data.empty()){
                vector<Customer> v;
                v.push_back(Customer(p,n));
                data.push_back(v);              
            }else{
                if(p>data.back().back().priority){(data.back()).push_back(Customer(p,n));}
                else{
                    int i=0;
                    while(p>data.at(i).back().priority){i++;}
                    if(data.at(i).size()==data.capacity()){
                        vector<Customer> v;
                        v.push_back(Customer(p,n));
                        data.insert(data.begin()+i,v);
                    }else{
                        int j=0;
                        while(p>data.at(i).at(j).priority){j++;}
                        (data.begin()+i)->insert((data.begin()+i)->begin()+j,Customer(p,n));
                    }
                }
            }
            size++;
        }

        
        

        Customer front(){
            return data.back().back();
        }

        void pop_front(){
            data.back().pop_back();
        }

        ~PriorityQueue(){
            data.clear();
        }
        
};


int main(){

    PriorityQueue q2;
    Customer c;

    q2.push_back(1, "Joe Nobody");
    q2.push_back(1, "Cecil D. Whocares");
    q2.push_back(1, "Ann Idontknowher");
    q2.push_back(1, "U. N. Known");

    c = q2.front();
    std::cout << c.priority << ", " << c.name << std::endl;
    // the line above should print 1, Joe Nobody, just as before
    // but now let us add a customoer with a higher priority:

    q2.push_back(2, "Elizabeth Somebody");

    c = q2.front();
    std::cout << c.priority << ", " << c.name << std::endl;
    // Since Elizabeth has a higher priority than Joe, she should be put in front of Joe in the queue
    // the line above should therefore print 2, Elizabeth Somebody

    q2.pop_front(); // this deletes Elizabeth from our queue
    // Joe should be now the next to be served
    c = q2.front();
    std::cout << c.priority << ", " << c.name << std::endl;
    // the line above should again print 1, Joe Nobody
    // but now let us again add a customoer with a higher priority
    // Joe gets pushed back in the queue, again
    q2.push_back(2, "Tom Known");
    // and once more let add a customoer with a higher priority
    q2.push_back(2, "Evelyn Recognizable");

    c = q2.front();
    std::cout << c.priority << ", " << c.name << std::endl;
    // the line above should print 2, Tom Known
    q2.pop_front(); // this deletes Tom from our queue
    // Evelyn should be now the next to be served,
    // because Evelyn was put in the queue after Tom, and has a higher priority than Joe.
    
    c = q2.front();
    std::cout << c.priority << ", " << c.name << std::endl;
    // the line above should print 2, Evelyn Recognizable
    q2.pop_front(); // this deletes Evelyn from our queue
    // Joe should be now the next to be served
    c = q2.front();
    // the line above should again print 1, Joe Nobody

    return 0;
}