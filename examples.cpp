#include <iostream>

void promenne() {
    int cele_cislo = -1;

    unsigned int cele_nezaporne_cislo = 1;

    std::size_t index_v_poli = 0;

    double desetinne_cislo = 3.14;

    char znak = 'a';

    bool pravda_nebo_nepravda = true;

    std::string retezec = "Ahoj";
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

void stars(unsigned int numStars) {
    for (int i = 0; i < numStars; i++) {
        std::cout << "*" ;
    }
}

int a = 0;

void scope() {
    int a = 5; 

    a = 3;

    std::cout << a << std::endl; // 3
    
    {
        int a = 4;
        std::cout << a << std::endl; // 4
        a = 6;
        std::cout << a << std::endl; // 6
    }

    std::cout << a << std::endl; // 3

}

void cykly() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    int i = 0;
    while (i < 10) {
        std::cout << i << std::endl;
        i++;
    }

    i = 0;
    do {
        std::cout << i << std::endl;
        i++;
    } while (i < 10);
}

void rectangle(int height) {
    for(int i = 0; i < height; i++) {
        stars(3);
        std::cout << std::endl;
    }
}

void sidePyramid(int height) {
    for(int i = 0; i < height; i++) {
        stars(i);
        std::cout << std::endl;
    }

    for(int i = 0; i < height; i++) {
        stars(height - i);
        std::cout << std::endl;
    }
}

void pyramid(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            std::cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

int main() {
    std::cout << a << std::endl;
    scope();
    std::cout << a << std::endl;

    std::cout << sum(64, 5) << std::endl;
    std::cout << std::endl;

    rectangle(4);
    std::cout << std::endl;
    sidePyramid(5);
    std::cout << std::endl;
    pyramid(6);
    

    return 0;
}
