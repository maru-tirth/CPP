#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal *animal;
    animal = new Dog();
    animal->speak();

    animal = new Cat();
    animal->speak(); 

    return 0;
}