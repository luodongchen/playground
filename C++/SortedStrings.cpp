#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct STR{
    private:
        vector< vector<string> > v ;
        int counter;

    public:
        STR():counter(0)
        {}

        STR(const STR& co){
            v.clear();
            counter=co.counter;
            for(int i=co.v.size();i>=0;i--){
                    vector<string> str;
                    for(int j=co.v.at(i).size()-1;j>=0;j--){
                        str.push_back(co.v.at(i).at(j));
                    }
                    v.push_back(str);
                }

        }

        void put(string s){
            if(counter==0){
                vector<string> str=vector<string>();
                str.push_back(s);
                v.push_back(str);
                counter++;
            }else{
                bool done=false;
                for(int i=0;i<v.size();i++){
                    if(s.length()<v[i].front().length()){
                        if(v[i].size()<v[i].capacity() && v[i].capacity()<=v.capacity()){
                            if(s.length()<v[i].back().length()){
                                v[i].push_back(s);
                            }else{
                                int j=0;
                                while(s.length()<v[i].at(j).length()){j++;}
                                v[i].insert(v[i].begin()+j,s);
                            }   
                        }else{
                            vector<string> str;
                            str.push_back(s);
                            v.insert(v.begin()+i,str);
                
                        }
                        done=true;
                        break;
                    }
                }
                if(!done){
                    vector<string> str=vector<string>();
                    str.push_back(s);
                    v.push_back(str);
                }
                counter++;
            }
        }

        string longest(){
            string str;
            if(!v.empty()){
                str=v.back().at(0);
            }
            return str;
        }

        string shortest(){
            string str;
            int end=v.front().size()-1;
            if(!v.empty()){
                str=v.front().at(end);
            }
            return str;
        }

        void erase_longest(){
            v.back().erase(v.back().begin());
            if(v.back().empty()){
                v.pop_back();
            }
        }

        void erase_shortesr(){
            v.front().pop_back();
            if(v.front().empty()){
                v.erase(v.begin());
            }
        }

        STR &operator=(const STR &co){
            if(this!=&co){
                v.clear();
                for(int i=co.v.size();i>=0;i--){
                    vector<string> str;
                    for(int j=co.v.at(i).size()-1;j>=0;j--){
                        str.push_back(co.v.at(i).at(j));
                    }
                    v.push_back(str);
                }
                counter=co.counter;
            }
            return *this;
        }

        bool isEmpty(){
            return counter==0;
        }

        ~STR(){
            v.clear();
        }

};


struct SortedStrings{
    private:
        STR strs;
        bool order;

    public:
        SortedStrings(bool o){
            order=o;
        }

        SortedStrings(const SortedStrings& co){
            order=co.order;
            strs=STR(co.strs);
        }

        SortedStrings &operator=(const SortedStrings& co){
            if(this!=&co){
                order=co.order;
                strs=co.strs;
            }
            return *this;
        }

        void insert(string s){
            strs.put(s);
        }

        string first(){
            string s;
            if(order){
                s=strs.shortest();
                strs.erase_shortesr();
            }else{
                s=strs.longest();
                strs.erase_longest();
            }
            return s;
        }

        


};


int main(){
    
    SortedStrings x(true);
    x.insert("asdf");
    x.insert("a");
    x.insert("bbb");
    x.insert("asdfasdfasdf");
    std::cout << "x: " << std::endl;
    std::cout << x.first() << std::endl;
    std::cout << x.first() << std::endl;
    std::cout << x.first() << std::endl;
    std::cout << std::endl;

    SortedStrings y(false);
    y.insert("asdf");
    y.insert("a");
    y.insert("bbb");
    y.insert("asdfasdfasdf");
    std::cout << "y: " << std::endl;
    std::cout << y.first() << std::endl;
    std::cout << y.first() << std::endl;
    std::cout << y.first() << std::endl;

}