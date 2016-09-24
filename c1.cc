#include <iostream>
using namespace std;

class Animal {
public:
	void bark();
	int age;
};

void Animal::bark(){
	cout<<"grr"<<endl;
}

class Dog{
public:
	void bark();
};

void Dog::bark(){
	cout<<"ruf ruf"<<endl;
}

int main(){
	Animal a;
	a.age=4;
	a.bark();
	cout<<"a is "<<a.age<<endl;
	Dog d;
	d.bark();
	return 0;
}
