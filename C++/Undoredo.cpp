#include<iostream>
#include<string>

struct STR
{
    private: std::string *str;
    private: int cur;
    private: int size;
    
    public: STR(){
        size=8;
        str=new std::string[size];
        cur=-1;
    }

    public: int getCur(){return cur;}
    public: void setCur(int index){cur=index;}

    public: void push_back(std::string s){
        if(cur==(size-1)){resize();}
        str[++cur]=s;
    }

    private: void resize(){
        int old_size=size;
        size=2*size;
        std::string *new_str=new std::string[size];
        memcpy(new_str,str,old_size*sizeof(std::string));
        delete[] str;
        str=new_str;
    }

    public: int getSize(){
        return size;
    }

    public: std::string at(int i){
        return str[i];
    }

    public: void setSize(int asize){
        size=asize;
    }

    public: std::string *getSTR(std::string* astr){
        return str;
    }

    /*STR &operator=(const STR& astr) {
        if (this != &astr) {
            // deallocate old data
            delete []str;
            //copy
            size = astr.size;
            cur = astr.cur;
            str = new std::string[size];
            for (int i = 0 ; i < size ; i++) {
                str[i] = astr.str[i];
            }
        }
        return *this;
    }

    STR &operator=(STR astr) {
        std::swap(astr.size, size);
        std::swap(astr.cur, cur);
        std::swap(astr.str, str);
        return *this;
    }*/

    STR &operator=(const STR& astr){
        cur=astr.cur;
        size=astr.size;
        str=new std:: string[size];
        for(int i=0;i<size;i++){
            str[i]=(*(astr.str+i));
        }
        str=astr.str;
        return *this;
    }

    public: STR(STR &co){
        size=co.getSize();
        str=new std::string[size];
        for(int i=0;i<size;i++){
            str[i]=co.str[i];
        }
        cur=co.getCur();
    }


    public: ~STR(){
        delete[] str;
    }
};




struct UndoRedo
{
   private: STR str;
   private:int max_index;
   private:int index;

   public:UndoRedo(){
    index=-1;
    max_index=-1;
   }

   public:std::string current(){
        if(index<0){return std::string();}
        return str.at(index);
   }

   public:void write(std::string s){
        if(max_index!=index){
            max_index=index;
            str.setCur(index);    
        }
        str.push_back(s);
        index++;
        max_index++;
    }

   public:void undo(){
        if(index>0){
            index--;
        }
   }

   public:void redo(){
        if(index<max_index){
            index++;
        }
   }

   UndoRedo &operator=(const UndoRedo& U){
        index=U.index;
        max_index=U.max_index;
        str=U.str;
        return *this;
   }

   public: UndoRedo(UndoRedo &U){
        str=U.str;
        max_index=U.max_index;
        index=U.index;
   }

   
};






int main(){
  
  UndoRedo buf;
  buf.write("a");
  buf.write("b");
  buf.write("c");
  buf.write("d");
  UndoRedo buf2(buf);
  /*UndoRedo buf3= buf2;*/ //copy construction (it runs the copy constructor)
  /*buf2 = buf; */// asignment (it runs the operator= method)
  //buf2.operator=(buf);
  // data structure should contain four things: "a", "b", "c" and "d"
  buf2.undo();
  std::cout << buf2.current() << std::endl; // should print "c"
  buf2.undo();
  std::cout << buf2.current() << std::endl; // should print "b"
  buf2.redo();
  std::cout << buf2.current() << std::endl; // should print "c"
  buf2.undo();
  std::cout << buf2.current() << std::endl; // should print "b"
  // before this write the data structure should contain: "a", "b", "c", "d"
  buf2.write("e");
  // after this write data structure should contain three elements: "a", "b", "e"
  // "c", and "d" become inaccessible and should be removed
  std::cout << buf2.current() << std::endl; // should print "e"
  buf2.undo();
  std::cout << buf2.current() << std::endl; // should print "b"
  buf2.redo();
  std::cout << buf2.current() << std::endl; // should print "e"

  return 0;

} 