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
    assert(a >= 0 && b >= 0);

    if (a == 0)
        return b;

    else if (b == 0)
        return a;

    else if (a > b) {
        return gcd(a % b, b);
    }

    else {
        return gcd(a, b % a);
    }
}

int main(void) {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
