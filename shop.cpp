#include <cassert>

enum ProductType {
    ELECTRONICS,
    CLOTHING,
    FOOD,
    BOOKS,
    FURNITURE
};

struct InventoryItem {
    int itemID;
    int quantity;
    int yearManufactured;
    int price;
    ProductType type;
};

struct Shop {
    std::vector<InventoryItem> inventory;
};

std::vector<InventoryItem> getItemsByType(Shop& shop, ProductType type);
std::vector<InventoryItem> getItemsByYear(Shop& shop, int year);
std::vector<InventoryItem> getItemsByPrice(Shop& shop, int price);

std::vector<InventoryItem> getItemsCheaperThan(Shop& shop, int price);
std::vector<InventoryItem> getItemsMoreExpensiveThan(Shop& shop, int price);



