#include <cassert>
#include <iostream>

template <class Int>

/**
 * Finding greatest common divisor
 * of 2 numbers.
 *
 * Using euclidean algorithm.
 *
 */
Int gcd(Int a, Int b) {
    assert(a > 0);

    if (b > 0) {
        return gcd(b, a % b);
    }

    return a;
}

int main(void) {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
