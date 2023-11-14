#include <iostream>

struct Dog {
    int age;
    int weight;

    void bark() {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

struct Cat {
    int age;
    int weight;

    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};


struct Person {
    int age;
    int weight;

    void speak() {
        std::cout << "Hello!\nI am " << age << " years old and I weigh " << weight << " kilos." << std::endl;
    }

    // getters
    int getAge() const {
        return age;
    }

    int getWeight() const {
        return weight;
    }

    // setters
    void setAge(int newAge) {
        age = newAge;
    }

    void setWeight(int newWeight) {
        weight = newWeight;
    }
};

int main() {
    Dog myDog;
    myDog.age = 3;
    myDog.weight = 10;
    myDog.bark();

    Cat myCat = {
        .age = 4,
        .weight = 8
    };
    myCat.meow();

    Person person = {25,70};
    person.speak();

    Person{30,80}.speak();

    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Weight: " << person.getWeight() << std::endl;

    std::cout << "I just had birthday." << std::endl;
    person.setAge(person.getAge() + 1);
    person.speak();


    return 0;
}

