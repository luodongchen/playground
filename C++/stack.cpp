#include<iostream>
#include<string>


struct Node{
    private:char content; 
    private:Node* pre;

    public:Node(){}

    public:Node(char s): content(s), pre(nullptr)
           {}

    public:Node(Node &co){
        content=co.content;
        pre=co.pre;
    }

    Node &operator=(const Node& co){
        content=co.content;
        pre=co.pre;
        return *this;
    }

    public:char getContent(){
        return content;
    }

    public:void setPre(Node* node){
        pre=node;
    }


    public: Node* getPre(){
        return pre;
    }

};

struct Stack{
    private:Node *top;
    private:int size;

    public:Stack(){
        size=0;
    }

    public:int getSize(){
        return size;
    }

    public:char getTop() const{
        return top->getContent();
    }


    public:Stack(Node &aNode){
        top=&aNode;
        size=1;
    }

    public:Stack(Stack &aStack){
        char c = aStack.getTop();
        Node *aNode=new Node(c);
        top=aNode;
        size=aStack.size;
    }

    

    public:void push(char c){
        Node *node=new Node(c);
        if(size==0){
            top=node;
            size++;
        }else{
            node->setPre(top);
            top=node;
            size++;
        }
    }

    public:void pop(){
        if(size>0){
            top=top->getPre();
            size--;
        }
    }

    Stack &operator=(const Stack& co){
        if(this!=&co){
            delete top;
            size=co.size;
            char c = co.getTop();
            Node *aNode=new Node(c);
            top=aNode;
        }
        return *this;
    }

    Stack &operator+(const char& c){
        push(c);
        return *this;
    }

    public:void print(){
        int len = size;
        Node *toprint=top;
        for (int i = 0 ; i < size ; i++) {
            std::cout<<toprint->getContent()<<std::endl;
            toprint=toprint->getPre();
        }
    }

    public:void read(std::string str){
        for(int i=0;i<str.length();i++){
            push(str[i]);
        }
    }

    public:~Stack(){
        while(top!=nullptr){
            pop();
        }
    }

};

bool match(char a, char b){
        if((a=='('&& b==')')||(a=='[' && b==']')||(a=='{'&&b=='}')){
            return true;
        }
        return false;
    }

bool balance(std::string str){
    Stack stc;
    for(int i=0;i<str.length();i++){
        if(stc.getSize()==0){
            if(str[i]==')'|| str[i]==']'|| str[i]=='}'){
                return false;
            }
            stc.push(str[i]);
        }else{
            if(match(stc.getTop(),str[i])){
                stc.pop();
            }else{
                if(str[i]==')'||str[i]==']'||str[i]=='}'){
                    return false;
                }else{
                    stc.push(str[i]);
                }
            }
        }
        stc.print();
    }
    return stc.getSize()==0;
}

int main(){
    char s[4];
    scanf("%s",s);
    if(balance(s)){
        puts("Balance");
    }else{
        puts("Imbalance");
    }

    return 0;
}
