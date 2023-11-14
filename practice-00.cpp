#include <iostream>
#include <cstdint>
#include <cassert>

/*
 * Mějme množinu celých čísel reprezentovanou pomocí 64 bitového čísla (naše množina tedy může obsahovat prvky z intervalu [0, 63]). Napište funkce pro práci s množinami:
 * - addToSet(Set&, int) - přidá číslo do množiny
 * - removeFromSet(Set&, int) - odebere číslo z množiny
 * - contains(const Set&, int) - zjistí, zda je číslo v množině
 * - printSet(const Set&) - vytiskne množinu na obrazovku (např. {1, 2, 3})
 * - setUnion(const Set&, const Set&) - sjednocení množin
 * - setIntersection(const Set&, const Set&) - průnik množin
 * - setSymmetricDifference(const Set&, const Set&) - symetrický rozdíl množin
 * - isEmpty(const Set&) - zjistí, zda je množina prázdná
 * - isSubset(const Set&, const Set&) - zjistí, zda je první množina podmnožinou druhé
 * - areEqual(const Set&, const Set&) - zjistí, zda jsou množiny stejné
 */

using Set = std::uint64_t;

void addToSet(Set& set, unsigned x) {
    set |= 1ULL << x;
}

void removeFromSet(Set& set, unsigned x) {
    set &= ~(1ULL << x);
}

bool contains(const Set& set, unsigned x) {
    return set & (1ULL << x);
}

void printSet(const Set& set) {
    std::cout << "{";
    bool first = true;
    for (std::size_t i = 0; i < 64; ++i) {
        if (contains(set, i)) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << "}" << std::endl;
}

Set setUnion(const Set& a, const Set& b) {
    return a | b;
}

Set setIntersection(const Set& a, const Set& b) {
    return a & b;
}

Set setSymmetricDifference(const Set& a, const Set& b) {
    return a ^ b;
}

bool isEmpty(const Set& set) {
    return set == 0;
}

bool isSubset(const Set& a, const Set& b) {
    return (a & b) == a;
}

bool areEqual(const Set& a, const Set& b) {
    return a == b;
}

int main() {
    Set a = 0;
    Set b = 0;
    const Set c = 0b1011;
    const Set d = 0b1100 | 1ULL << 63;

    // Test addToSet 
    addToSet(a, 0);
    addToSet(a, 1);
    addToSet(a, 2);
    addToSet(a, 3);
    addToSet(a, 63);

    assert(a == (1ULL << 63 | 1ULL << 3 | 1ULL << 2 | 1ULL << 1 | 1ULL << 0));

    // Test removeFromSet
    
    removeFromSet(a, 0);
    removeFromSet(a, 1);
    removeFromSet(a, 2);
    removeFromSet(a, 3);

    assert(a == (1ULL << 63));

    // Test contains

    b = 1ULL << 62 | 1ULL << 61 | 1ULL << 60 | 1ULL << 59 | 1ULL << 58;
    for (std::size_t i = 0; i < 58; ++i) {
        assert(!contains(b, i));
    }

    for (std::size_t i = 58; i <= 62; ++i) {
        assert(contains(b, i));
    }

    // Test printSet
    printSet(b);

    // Test setUnion
    assert(setUnion(c, d) == (1ULL << 63 | 1ULL << 3 | 1ULL << 2 | 1ULL << 1 | 1ULL << 0));

    // Test setIntersection
    assert(setIntersection(c, d) == 1ULL << 3);

    // Test setSymmetricDifference
    assert(setSymmetricDifference(c, d) == (1ULL << 63 | 1ULL << 2 | 1ULL << 1 | 1ULL << 0));

    // Test isEmpty
    assert(isEmpty(0));
    assert(!isEmpty(1ULL << 63));

    // Test isSubset
    assert(!isSubset(c, d));
    assert(isSubset(c, c));
    assert(isSubset(0, c));
    assert(isSubset(0, 0));
    assert(isSubset(1ULL << 63, d));

    // Test areEqual
    assert(!areEqual(c, d));
    assert(areEqual(c, c));
    assert(areEqual(0, 0));
    assert(areEqual(1ULL << 63, 1ULL << 63));

    return 0;
}
