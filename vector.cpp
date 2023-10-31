#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

int main() {
    // vektor čísel
    std::vector<int> ints;

    // vektor bodů
    std::vector<Point> points;

    // reference na vektor bodů
    std::vector<Point>& pointsRef = points;

    // přidání prvků na konec vektoru
    ints.push_back(1);
    ints.push_back(2);

    // rozšíření vektoru na 10 prvků
    ints.resize(10);

    // zjištění velikosti vektoru
    std::cout << ints.size() << std::endl;

    // přístup k prvkům vektoru
    std::cout << ints[0] << std::endl;
    std::cout << ints.at(1) << std::endl;

    // vytvoření vektoru s 10 prvky
    std::vector<int> ints2(10);

    // vytvoření vektoru s 10 prvky, každý má hodnotu 5
    std::vector<int> ints3(10, 5);

    // vytvoření vektoru s různými prvky
    std::vector<int> ints4 = {1, 2, 3, 4, 5};

    // konstantní reference na vektor
    const std::vector<int>& c_ints4 = ints4;

    // procházení vektoru
    for (std::size_t i = 0; i < c_ints4.size(); i++) {
        std::cout << "ints4[" << i << "]: " << c_ints4[i] << std::endl;
    }

    // procházení vektoru 2.0
    for (const int& element : c_ints4) {
        std::cout << element << std::endl;
    }

    // procházení vektoru s modifikací
    for (std::size_t i = 0; i < ints4.size(); i++) {
        ints4[i] *= 2;
    }

    // procházení vektoru s modifikací 2.0
    for (int& element : ints4) {
        element *= 2;
    }

    // první prvek vektoru
    std::cout << c_ints4.front() << std::endl;
    ints4.front() = 10;
    std::cout << c_ints4.front() << std::endl;

    // poslední prvek vektoru
    std::cout << c_ints4.back() << std::endl;

    // odstranění posledního prvku vektoru
    ints4.pop_back();

    // odstranění všech prvků vektoru
    ints4.clear();

    // je vektor prázdný?
    std::cout << "vektor " << (ints4.empty() ? "je" : "není") << " prázdný" << std::endl;

    return 0;
}
