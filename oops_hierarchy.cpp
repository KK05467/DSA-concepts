// #include<iostream>
// using namespace std;

// class A{
//     public:
//    void showA() {
//     cout<<"Class A is called"<<endl;
//    }
// };

// class B : public A{
//     public:
//     void showB(){cout<<"Class B is here!"<<endl;}
// };

// class C: public A{
//     public:
//     void showC(){
//         cout<<"Class C is called!"<<endl;
//     }
// };


// int main(){
//     B obj1;
//     C obj2;

//     obj1.showA();
//     obj1.showB();

//     obj2.showA();
//     obj2.showC();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Number {
//     public:
//     int num;
//     void get_number(){
//         cin>>num;
//     }
// };

// class Cube : public Number{
//     void showCube(){
//         cout<<num * num * num<<endl;
//     }
// };

// class Square : public Number {
//     void showSquare(){
//         cout<<num * num<< endl;
//     }
// };

// int main() {
//     Cube obj1;
//     Square obj2;

//     obj1.get_number();
//     obj1.showCube();

//     obj2.get_number();
//     obj2.showSquare();
//     return 0;
// }

#include<iostream>
using namespace std;

class Number {
public:
    int num;
    void get_number() {
        cin >> num;
    }
};

class Cube : public Number {
public:
    void showCube() {
        cout << num * num * num << endl;
    }
};

class Square : public Number {
public:
    void showSquare() {
        cout << num * num << endl;
    }
};

int main() {
    Cube obj1;
    Square obj2;

    obj1.get_number();
    obj1.showCube();

    obj2.get_number();
    obj2.showSquare();

    return 0;
}
