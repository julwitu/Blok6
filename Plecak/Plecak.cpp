#include "Plecak.hpp"
#include <random>
#include <iostream>


Item Shop::steal(int index){
    Item result;
    result.value = items[index].value;
    result.weight = items[index].weight;
    items[index].value = 0;
    items[index].weight = 0;
    return result;
}

Item Shop::peek(int index){
    Item result;
    result.value = items[index].value;
    result.weight = items[index].weight;
    return result;
}

int Backpack::put(Item item){
    stolen[firstAvailableIndex].value = item.value;
    stolen[firstAvailableIndex].weight = item.weight;
    firstAvailableIndex++;
    currentCapacity += item.weight;
    return 0;
}

Item* Shop::getItems() const{
    return (Item*)items;
}

int Robber::getValue(){
    return 0; //to fix
}

Item* Robber::getBackpackItems() const{
    return backpack.getItems();
}

void Robber::robWhatever(Shop& shop){
    for (int i = 0; i < 10; i++){
        Item item = shop.peek(i);
        if (backpack.fits(item.weight)) {
            Item item = shop.steal(i);
            backpack.put(item);
        }
    }
}

void Robber::robGreedy(Shop& shop) {
    //int values[10];
    //int weights[10];
    //double results[10];
    //for (int i = 0; i < 10; i++) {
    //    values[i] = shop.peek(i).value;
    //    weights[i] = shop.peek(i).weight;
    //   values[i] /= weights[i];
    //   results[i] = static_cast<double>(values[i]) / weights[i];
    //}
    //for (int i = 0; i < 10; i++) {
    //    std::cout << values[i] << " ";
    //}
    //std::cout << std::endl;
    //for (int i = 0; i < 10; i++) {
    //    std::cout << weights[i] << " ";
    //}
    //std::cout << std::endl;
    //for (int i = 0; i < 10; i++) {
    //    std::cout << results[i] << " ";
    //}
    //std::cout << std::endl << std::endl;
    //int max;
    //for (int i = 0; i < 10; i++) {
    //    max = results[0];
    //    if (results[i] > max) {
    //        max = results[i];
    //    }
    //}
    //if (backpack.fits(max)) {
    //}
    for (int m = 0; m < 10; m++) {
        double results[10];
        Item item;
        for (int i = 0; i < 10; i++) {
            item = shop.peek(i);
            results[i] = static_cast<double>(item.value) / item.weight;
        }
        double max = 0;
        int maxIndex = 0;
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (results[k] > max) {
                    max = results[k];
                    maxIndex = k;
                    results[k] = 0;
                }
            }
            if (backpack.fits(/*co tu wpisac */) {
                item = shop.steal(maxIndex);
                    backpack.put(item);
            }
            max = 0;
        }
    }
}
    


Shop::Shop() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 15);

    for (int i = 0; i < 10; i++){
        items[i].weight = distr(gen);
        items[i].value = distr(gen);
    }
}

Robber::Robber(int capacity) : backpack(capacity) { }

Backpack::Backpack(int _capacity) : capacity(_capacity){
    for (int i = 0; i < 10; i++)
    {
        stolen[i].value = 0;
        stolen[i].weight = 0;
    }
}

Item* Backpack::getItems() const{
    return (Item*)stolen;
}

bool Backpack::fits(int weight){
    //czy obiekt zmiesci do naszego plecaka
    return currentCapacity + weight <= capacity;
}

std::ostream& operator<<(std::ostream& s, const Shop& shop){
    Item* items = shop.getItems();
    s << "Shop: " << std::endl;
    for (int i = 0; i < 10; i++){
        s << items[i].value << " " << items[i].weight << std::endl;;
    }
    s << "End of shop: " << std::endl;
    return s;
}

//int&           add      (int           a, const int       b)  // analogiczna struktura
std::ostream& operator<<(std::ostream& s, const Robber& r){
    Item* items = r.getBackpackItems();
    s << "Backpack: " << std::endl;
    for (int i = 0; i < 10; i++){
        s << items[i].value << " " << items[i].weight << std::endl;
    }
    s << "End of backpack: " << std::endl;
    return s;
}

