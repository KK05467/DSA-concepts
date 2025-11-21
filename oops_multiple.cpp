#include<iostream>
using namespace std;

class A{
    public:
    void showA(){
        cout<<"THis is A class!"<<endl;
    }
};

class B{
    public: 
    void showB(){
        cout<<"This is B class!"<<endl;
    }
};

class C : public A, public B{
    public:
    void showC(){
        cout<<"C class is here!"<<endl;
    }
};

int main(){

    C obj;

    obj.showA();
    obj.showB();
    obj.showC();
    return 0;
}


