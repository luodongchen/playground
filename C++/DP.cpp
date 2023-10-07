#include<iostream>
#include<vector>

struct Node{
    private: 
        Node* pre;
        Node* post;
        bool noPre,noPost;
        int x,y;

    public:
        Node():x(NULL),y(NULL),pre(nullptr),post(nullptr),noPre(true),noPost(true)
        {}

        Node(int a,int b):x(a),y(b),pre(nullptr),post(nullptr),noPre(true),noPost(true)
        {}

        Node(Node& N){
                delete pre;
                delete post;
                pre=new Node();
                post=new Node();
                pre=N.pre;
                post=N.post;
                noPost=N.noPost;
                noPre=N.noPre;
                x=N.x;
                y=N.y;
        }

        void setPre(Node* N){
            noPre=false;
            pre=N;
        }

        void setPost(Node* N){
            noPost=true;
            post=N;
        }

        Node &operator=(const Node& N){
            if(this!=&N){
                delete pre;
                delete post;
                pre=new Node();
                post=new Node();
                pre=N.pre;
                post=N.post;
                noPost=N.noPost;
                noPre=N.noPre;
                x=N.x;
                y=N.y;
            }
            return *this;
        }
        
        ~Node(){
            delete pre;
            delete post;
        }


};


struct Queue{
    private: 
        Node* cur;
        Node* top;
        int size;

    public:
        Queue():cur(nullptr),top(nullptr),size(0)
        {}

        Queue(const Queue& Q){
            cur=new Node();
            top=new Node();
            cur=*(Q.cur);
            top=*(Q.top);
            size=Q.size;
        }
};


bool DP( ){

}
