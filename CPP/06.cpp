#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    int speed;
    string color;
//same name as class name
//does not have a return type
//it is called automatically when object is created
    // Car(){
    //     cout << "Default constructor method called"<<endl;
    // }

    Car(string name){
        this->name = name;

    }

    void increaseSpeed(){

    }

    void fly(){

    }
};
 
int main()
{
    // Car c1("Suzuki");
    // Car c2("Tata");

    Car *c1 = new Car("Tata");

    cout << c1->name << endl;
}