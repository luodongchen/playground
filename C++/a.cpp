#include<iostream>
#include<string>
#include<fstream>

template<class T>
struct Queue{
    private:
        T* n;
        int size;
        int counter;

    public:
        Queue(){
            size=8;
            counter=0;
            n=new T[size];
        }

        Queue(Queue& Q){
            size=Q.size;
            n=new T[size];
            counter=Q.counter;
            for(int i=0;i<counter;i++){
                n[i]=Q.n[i];
            }
        }

        T front(){
            if(counter!=0){
                return *(n+counter-1);
            }
        }

        void resize(){
            T* new_n=new T[size*2];
            for(int i=0;i<size;i++){
                new_n[i]=n[i];
            }
            size=size*2;
            delete[]n;
            n=new_n;
        }
        
        void push_back(T num){
            if(counter==size){
                resize();
            }
            n[counter]=num;
            counter++;
        }

        void pop(){
            T* new_n=new T[counter-1];
            for(int i=0;i<counter-1;i++){
                new_n[i]=n[i];
            }
            delete[]n;
            n=new_n;
            counter--;
        }

        Queue &operator=(const Queue& Q){
            if(this!=&Q){
                delete[]n;
                size=Q.size;
                counter=Q.counter;
                n=new T[size];
                for(int i=0;i<counter;i++){
                    n[i]=Q.n[i];
                }
            }
            return *this;
        }

        Queue &operator+(const Queue& Q){
            for(int i=0;i<Q.counter;i++){
                push_back(Q.n[i]);
            }
            return *this;
        }

        int getCounter(){
            return counter;
        }

        void print(){
            for(int i=0;i<counter;i++){
                std::cout<<n[i]<<std::endl;
            }
            
        }

        ~Queue(){
            delete[]n;
        }

};
template<class T>
Queue<T> f1(Queue<T> a,Queue<T> b){
    Queue<T> c;
    if(a.getCounter()==0){
        c=b;
    }else if(b.getCounter()==0){
        c=a;
    }else{
        if(a.front()<=b.front()){
            c.push_back(a.front());
            a.pop();
            c=c+f1(a,b);
        }else{
            c.push_back(b.front());
            b.pop();
            c=c+f1(a,b);
        }
    }
    return c;
}



Queue<int> f2(){
    Queue< Queue<int> > xs;
    Queue<int> c;
    std::ifstream file_in;
    file_in.open("~/Desktop/C++/data.txt");
    std::string n;
    while(file_in){
        Queue<int> Q;
        getline(file_in,n);
        std::cout<<n<<std::endl;
        /*int num= std::stoi(n);
        Q.push_back(n);*/
        xs.push_back(Q);
    }
    if(xs.getCounter()==1){
        c = xs.front();
        return c;
    }else{
        Queue<int> a,b;
        a=xs.front();
        xs.pop();
        b=xs.front();
        c=f1(a,b);
        xs.push_back(a);
        xs.push_back(c);
        return c;
    }
    file_in.close();

}

int main(){
    Queue<int> Q1,Q2;
    Queue< Queue<int> > Q3;
    Q1.push_back(1024);
    Q2.push_back(2);
    Q3.push_back(Q1);
    Q3.push_back(Q2);
    Queue<int> Q;
    Q=f1(Q1,Q2);
    std::cout<<Q.front()<<std::endl;
    
}

