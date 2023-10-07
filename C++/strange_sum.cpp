#include<iostream>
#include<vector>

using namespace std;

struct Queue{
    private:
        vector<int> pos;
        vector<int> neg;
        vector<int> zeros;


    public:
        Queue(){}

        Queue(const Queue& co){
            pos.clear();
            neg.clear();
            for(int i=0;i<co.pos.size();i++){
                pos.push_back(co.pos.at(i));
            }
            for(int i=0;i<co.neg.size();i++){
                neg.push_back(co.neg.at(i));
            }
            for(int i=0;i<co.zeros.size();i++){
                zeros.push_back(co.zeros.at(i));
            }
        }

        Queue &operator=(const Queue& co){
            if(this!=&co){
                pos.clear();
                neg.clear();
                for(int i=0;i<co.pos.size();i++){
                    pos.push_back(co.pos.at(i));
                }
                for(int i=0;i<co.neg.size();i++){
                    neg.push_back(co.neg.at(i));
                }
                for(int i=0;i<co.zeros.size();i++){
                    zeros.push_back(co.zeros.at(i));
                }
            }
            return *this;
        }

        void read(vector<int> v,int start,int end){
/*            if(start<end-1){
                read(v,start,end/2);
                read(v,(end/2)+1,end);
            }else{
                insert(v.at(start));
                insert(v.at(end));
            }*/
            for(int i = 0 ; i < v.size(); i++) {
                insert(v[i]);
                /*if(i>0){
                    pos.push_back(i);
                }else if(i<0){
                    neg.push_back(i);
                }*/
            }
        }

        void insert(int num){
            if(num>0){
                pos.push_back(num);
            }else if(num<0){
                neg.push_back(num);
            }else{
                zeros.push_back(num);
            }
        }

        int countPos(){
            return pos.size();
        }

        int countNeg(){
            return neg.size();
        }

        int countRM(){
            return countPos()-countNeg();
        }


        int sum_RM(bool s){
            int sum=0;

            int n=countRM();
            /*
            while (!pos.empty() && !neg.empty()) {
                pos.pop_back();
                neg.pop_back();
            }

            for (int i = 0 ; i < pos.size() ; i++) {
                sum += pos[i];
            }

            for (int i = 0 ; i < pos.size() ; i++) {
                sum += neg[i];
            }*/
            if(s){
                pos.reserve(pos.size());
                
                while(n>0){
                    sum=pos.at(pos.size()-n);
                    n--;
                }
            }else{
                neg.reserve(neg.size());
                int n=-n;
                while(n>0){
                    sum=neg.at(n-1);
                    n--;
                }
            }
            return sum;
        }


        ~Queue(){
            pos.clear();
            neg.clear();
        }
};

int strange_sum(vector<int> arr){
    int sum=0;
    Queue Q;
    Q.read(arr, 0, arr.size());
    if(Q.countRM()==0){
        return 0;
    }else if(Q.countRM()>0){
        sum=Q.sum_RM(true);
    }else{
        sum=Q.sum_RM(false);
    }
    return sum;
}


int main(){
std::vector<int> xs ;//{-1,  2, 1});
xs.push_back(1);
xs.push_back(2);
xs.push_back(-1);
std::cout<<strange_sum(xs)<<std::endl;
return 0;
}