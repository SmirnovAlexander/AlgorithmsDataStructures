#include <iostream>
#include <cassert>
#include <vector>

/**
 * Composition of an integer.
 *
 * Composition should contain
 * as many as possible members.
 *
 * @return Vector of integers.
 */
std::vector<int> number_as_sum(int n) {
    assert(n > 0);

    std::vector<int> result;

    result.push_back(n);
    result.push_back(n);

    return result;
}

int main(void) {
    int n;
    std::cin >> n;

    std::vector<int> result = number_as_sum(n);

    std::cout << result.size() << std::endl;
    for (std::size_t i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    return 0;
}
