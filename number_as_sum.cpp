#include <cassert>
#include <iostream>
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

    int i = 1;
    int sum = 0;
    std::vector<int> result;

    // We accumulate values in sum
    // variable. We start from 1 and
    // keep adding numbers until
    // sum + next_number will be over
    // target value n. When we face this
    // we should remove last value in vector
    // and add n - sum of elements in vector
    // to complement sum to n.
    while (sum != n) {
        if (sum + i > n) {
            result.pop_back();
            result.push_back(n - (sum - (i - 1)));
            sum = n;
        } else {
            sum += i;
            result.push_back(i);
        }

        i++;
    }

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
