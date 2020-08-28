#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> Item;

/**
 * Driver function to sort the vector elements
 * by price / volume ratio.
 */
bool sortby_price_volume(const std::pair<int, int> a,
                         const std::pair<int, int> b) {
    return ((a.first / (double)a.second) > (b.first / (double)b.second));
}

/**
 * Continuous knapsack problem solution.
 *
 * Given items' prices and volumes.
 * Find max value of items which are
 * able to fit in knapsack.
 *
 * @param capacity Knapsack capacity.
 * @param items Vector contains pairs
 *     of prices and volumes of items.
 * @return Max value of items parts.
 */
double get_max_value(double capacity, std::vector<Item> items) {
    double max_value = 0;

    // Sorting items by their
    // price / volume ratio.
    std::sort(items.begin(), items.end(), sortby_price_volume);

    // Iterating throw sorted items and
    // filling knapsack. If we are unable
    // to fit whole item, we fill it
    // partly.
    for (std::size_t i = 0; i < items.size(); i++) {
        if (capacity > items[i].second) {
            max_value += items[i].first;
            capacity -= items[i].second;
        } else {
            max_value += (capacity / items[i].second) * items[i].first;
            break;
        }
    }

    return max_value;
}

int main(void) {
    int items_count;
    int capacity;

    std::cin >> items_count >> capacity;

    std::vector<Item> items(items_count);
    for (int i = 0; i < items_count; i++) {
        std::cin >> items[i].first >> items[i].second;
    }

    double max_value = get_max_value(capacity, items);
    std::cout << std::fixed << std::setprecision(3) << max_value << std::endl;

    return 0;
}
