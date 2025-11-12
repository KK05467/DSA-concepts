#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Compare function for sorting by value/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // sort in descending order
}

// Function to get maximum value in fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by ratio
    sort(items.begin(), items.end(), cmp);

    double finalValue = 0.0; // total value

    for (auto& item : items) {
        if (W >= item.weight) {
            // Take full item
            W -= item.weight;
            finalValue += item.value;
        } else {
            // Take fractional part
            finalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50; // Capacity of knapsack
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items);
    return 0;
}


// Time Complexity

// O(n log n) → due to sorting

// 💾 Space Complexity

// O(1) (constant extra space)
