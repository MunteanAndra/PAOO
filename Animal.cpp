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

    public:
        void printInfo()
        {
            cout<<"Animal's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl;
    
        }
        int calculateAge()
        {
            return age * 1;
        }
    Animal();
    ~Animal();
    void putAnimal(string name, string breed, string color, string size, int age);
    string getAnimal();
};

class Dog : public Animal
{
    public:
        void printInfo()
        {
            cout<<"Dog's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl;
        }
        int calculateAge()
        {
            return age * 7;
        }

};

class Cat : public Animal
{
    public:
        void printInfo()
        {
            cout<<"Cat's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl;
        }
        int calculateAge()
        {
            if(age > 6)
                return (age - 6) * 4 + 40;
            else
                return (age * 19) / 3 + 1; 
        }

};

//constructor
Animal::Animal()
{
    name=" ";
    breed=" ";
    size=" ";
    color=" ";  
    age=0;
    cout<<"animal initialized.\n";
}
//destructor
Animal::~Animal()
{
    cout<<"animal destroyed(destructered).\n";
}

void Animal::putAnimal(string n, string b, string c, string s, int a)
{
    name=n;
    breed=b;
    color=c;
    size=s;
    age=a;
}

string Animal::getAnimal()
{
    return name + " " + breed + " " + color + " " + size + ".\n" ;
}

int main()
{
    Animal animal;
    Dog dog;
    Cat cat;
    //animal.putAnimal("Caine","bichon","negru","big",2);
    animal.name = "domestic animal";
    animal.breed = "mixt";
    animal.size = "big";
    animal.age = 4;
    animal.color = "black";

    dog.name = "Rex";
    dog.breed = "labrador";
    dog.size = "big";
    dog.age = 2;
    dog.color = "white";

    cat.name= "Kitty";
    cat.breed= "american shorthair";
    cat.size= "medium";
    cat.age= 3;
    cat.color= "grey";

    animal.printInfo();
    cout<<"Animal's age "<<animal.calculateAge();
    cout<<endl<<endl;
    dog.printInfo();
    cout<<"Dog's age "<<dog.calculateAge();
    cout<<endl<<endl;
    cat.printInfo();
    cout<<"Cat's age "<<cat.calculateAge();
    cout<<endl;
    //animal.getAnimal();

    return 0;

}

