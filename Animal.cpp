#include <iostream>
using namespace std;

class Animal
{
    public:
    string name;
    string breed;
    string size;
    string color;
    int age;

    void printInfo()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
        cout<<"Breed is "<<breed<<endl;
        cout<<"Size is "<<breed<<endl;
        cout<<"Color is "<<breed<<endl;
    }
    Animal();
    ~Animal();
    void putAnimal(string name, string breed, string color, string size, int age);
    string getAnimal();
};

Animal::Animal()
{
    name=" ";
    breed=" ";
    size=" ";
    color=" ";  
    age=0;
    cout<<"animal initialized.\n";
}
Animal::~Animal()
{
    cout<<"animal destroyed(destructered)./n";
}

void Animal::putAnimal(string name, string breed, string color, string size, int age)
{
    name=name;
    breed=breed;
    color=color;
    size=size;
    age=age;
}

string Animal::getAnimal()
{
    return name + " " + breed + " " + color + " " + size + ".\n" ;
}

int main()
{
    Animal animal, animal1;
    animal.putAnimal("Caine","bichon","negru","big",2);
    animal1.name = "Caine";
    animal1.breed = "bichon";
    animal1.size = "big";
    animal1.age = 2;
    animal1.color = "negru";
    animal1.printInfo();
    animal.getAnimal();


    return 0;

}

