#include <iostream>
#include <memory>
using namespace std;

class Animal
{
    public:
        string name;
        string breed;
        string size;
        string color;
        int age;
        string newField;

    public:
        void printInfo()
        {
            cout<<endl<<"Animal's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl;
            cout<<"New field is "<<newField<<endl;
    
        }
        int calculateAge()
        {
            return age * 1;
        }
        void resources()
        {
            unique_ptr<Animal> plnv(new Animal());
            cout<<plnv<<endl;
            cout<<"resource management called"<<endl;
        }
        void resourcesWithCopy()
        {
            shared_ptr<Animal> ptr1(new Animal());
            cout<<ptr1<<endl;
            shared_ptr<Animal> ptr2(ptr1);
            ptr1 = ptr2;
            cout<<ptr2<<endl;
            cout<<ptr1<<endl;
            cout<<"resource management called"<<endl;
        }
    Animal();
    ~Animal();
    void putAnimal(string name, string breed, string color, string size, int age);
    string getAnimal();

    Animal& operator = (const Animal& rhs)
    {
        name = rhs.name;
        breed = rhs.breed;
        size = rhs.size;
        color = rhs.color;
        age = rhs.age;
        newField = rhs.newField;
        cout<<"copy all assignment called"<<endl<<endl;
        return *this;
    }
    //Animal* FactoryMethod();

};

class Dog : public Animal
{
    string *copyDog;
    public:
        Dog()
        {
            name="";
            breed="";
            size="";
            color="";  
            age=0;
            cout<<"Dog initialized.\n";
        }
        ~Dog()
        {
            cout<<"Dog destroyed(destructered).\n";
        }
        // copy constructor
        Dog(const Dog &obj)
        {
            //copyDog = new string;
            //*copyDog = *obj.copyDog; //copy value
            cout<<"Copy operator for new Dog. \n\n";
        }
        void printInfo()
        {
            cout<<"Dog's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl<<endl;
        }
        int calculateAge()
        {
            return age * 7;
        }
        Dog& operator=(const Dog& rhs){
            cout<< "Assignment operator called"<<endl<<endl;
            return *this;
        }
};

class Cat : public Animal
{
    private:
    string *moveCat;
    Animal *a;

    public:
        Cat()
        {
            name="";
            breed="";
            size="";
            color="";  
            age=0;
            cout<<"Cat initialized.\n";
        }
        ~Cat()
        {
            cout<<"Cat destroyed(destructered).\n";
        }
        void printInfo()
        {
            cout<<"Cat's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl<<endl;
        }
        int calculateAge()
        {
            if(age > 6)
                return (age - 6) * 4 + 40;
            else
                return (age * 19) / 3 + 1; 
        }
        // Move constructor
        Cat ( Cat & obj)
        {
            cout <<"Move constructor for Cat. \n";
            this->moveCat = obj.moveCat;
            obj.moveCat = NULL;
        }
        Cat& operator=(const Cat &rhsCat){
            cout<< "\nAssignment operator called for cat"<<endl;
            if(this == &rhsCat){
                cout<<"same object \n\n";
                return *this;
            } else{
                //delete a;
                //a = new Animal(*rhsCat.a);
                cout<<"different object \n";
                return *this;
            } 
        }
};

class Mouse : public Animal
{
    public:
        Mouse()
        {
            name="";
            breed="";
            size="";
            color="";  
            age=0;
            cout<<"Mouse initialized.\n\n";
        }
        ~Mouse()
        {
            cout<<"Mouse destroyed(destructered).\n";
        }
        Mouse(const Mouse& rhMouse) : Animal(rhMouse){
            cout<<"copy all assignment called"<<endl;
        }
        void printInfo()
        {
            cout<<"Mouse's"<<endl;
            cout<<"Name is "<<name<<endl;
            cout<<"Age in human years is "<<age<<endl;
            cout<<"Breed is "<<breed<<endl;
            cout<<"Size is "<<size<<endl;
            cout<<"Color is "<<color<<endl;
            cout<<"New field is"<<newField<<endl<<endl;
        }

};

class Uncopyable {
    protected: // allow construction
        Uncopyable() {} // and destruction of
        ~Uncopyable() {} // derived objects...
    private:
        Uncopyable(const Uncopyable&); // ...but prevent copying
        Uncopyable& operator=(const Uncopyable&);
};

//constructor
Animal::Animal()
{
    name="";
    breed="";
    size="";
    color="";  
    age=0;
    cout<<"animal initialized.\n";
}
//destructor
Animal::~Animal()
{
    cout<<"animal destroyed(destructered).\n";
}

int main()
{
    Animal animal;
    Dog dog, dog1, dog2, dog3, dog4, dog5;
    Cat cat, cat1;
    
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
    cout<<"Animal's "<<animal.name<<" age is "<<animal.calculateAge();
    cout<<endl<<endl;
    dog.printInfo();
    cout<<"Dog's "<<dog.name<<" age is "<<dog.calculateAge();
    cout<<endl<<endl;
    cat.printInfo();
    cout<<"Cat's "<<cat.name<<" age is "<<cat.calculateAge();
    cout<<endl<<endl;

    dog1 = dog;

    cat1 = std::move(cat);
    cat1.printInfo();

    //dog2.name = dog.name;
    //dog2.age = dog.age;
    //dog2.size = dog.size;
    //dog2.breed = dog.breed;
    //dog2.color = dog.color;
    dog2 = dog;
    dog2.printInfo();

    dog.name = "Tano";
    cout<<"Dog's name changed"<<endl;
    dog.printInfo();
    cout<<"Dog2's name after Dog's name changed"<<endl;
    dog2.printInfo();

    cout<<"ITEM 10 \n\n";

    dog3.name = "Rex";
    dog3.breed = "labrador";
    dog3.size = "big";
    dog3.age = 2;
    dog3.color = "white";

    dog5 = dog4 = dog3; // dog4.operator=(dog3) dog5.operator=(dog4)
    Dog dog6 = dog4;
    
    dog5.printInfo();
    dog3.printInfo();

    cout<<"ITEM 11 \n\n";

    Cat cat3;
    cat3 = cat;
    cat = cat; 
    cat3 = cat3 = cat3;

    cout<<"ITEM 12 \n\n";

    Mouse mouse1, mouse2;

    mouse1.name = "Jerry";
    mouse1.age = 10;
    mouse1.color = "grey";
    mouse1.size = "small";

    mouse1.printInfo();
    mouse2.printInfo();

    mouse2 = mouse1;

    mouse1.printInfo();
    mouse2.printInfo();

    cout<<"ITEM 13 \n\n";

    Animal a, a1;
    cout<<endl;
    a.resources();
    cout<<endl;
    a1.resourcesWithCopy();
    cout<<endl;

    return 0;

}

