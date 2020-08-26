#include <math.h>

#include <cassert>
#include <iostream>
#include <vector>

/**
 * Functions to operate
 * on fibonacci sequence.
 */
class Fibonacci {
    /**
     * Calculating n-th fibonacci number.  *
     * @param n.
     * @return n-th fibonacci number.
     */
   public:
    static int get(int n) {
        assert(n >= 0);

        if ((n == 0) | (n == 1)) {
            return n;
        }

        int previous = 0;
        int current = 1;

        for (int i = 2; i <= n; i++) {
            int new_current = previous + current;
            previous = current;
            current = new_current;
        }

        return current;
    }

    /**
     * Last digit of fibonacci number.
     *
     * Counting fibonacci numbers with modulus 10.
     *
     * @param n N-th fibonacci number to get digit.
     * @return Last digit.
     */
   public:
    static int get_last_digit(int n) {
        assert(n >= 1);

        if (n == 1) {
            return 1;
        }

        std::vector<int> v = {};
        v.push_back(0);
        v.push_back(1);

        for (int i = 2; i <= n; i++) {
            int next_last_digit = (v.at(i - 2) + v.at(i - 1)) % 10;
            v.push_back(next_last_digit);
        }

        int last_digit = v.back();

        return last_digit;
    }

    /**
     * Pisano period on m.
     *
     * Period with which the sequence of Fibonacci
     * numbers taken modulo m repeats.
     *
     * @param m.
     * @return Period if exists and 0 if otherwise.
     */
   private:
    static int get_pisano_period(int m) {
        assert(m >= 2);

        // First values of fibonacci sequence.
        int previous = 0;
        int current = 1;
        int current_temp;

        // Calculating fibonacci elements on
        // modulo m till we find sequence of
        // two elements: 0 and 1 or we will
        // reach (m * m)-th element.
        for (int i = 0; i < m * m; i++) {
            current_temp = (previous + current) % m;
            previous = current;
            current = current_temp;

            if (previous == 0 and current == 1) {
                return i + 1;
            }
        }

        return 0;
    }

    /**
     * Counting fibonacci number with modulus m.
     *
     * @param n N-th fibonacci number.
     * @return Remainder.
     */
   public:
    static int get_remainder(long long n, int m) {
        assert(n >= 1);
        assert(m >= 2);

        int pisano_period = get_pisano_period(m);

        // in case we don't find pisano period,
        // we are not able to reduce calculations
        // by finding number of element with
        // same remainder.
        int num_of_element_with_same_remainder = n;

        // if pisano period exists, we find smallest
        // number of element with same remainderl
        if (pisano_period != 0) {
            num_of_element_with_same_remainder = n % pisano_period;
        }

        // assigning remainder value of element number
        // because it will always be recalculated except
        // we get 0 or 1. in this cases remainders are
        // same: 0th fibonacci element (0) always have
        // remainder of 0 and 1st element (1) always have
        // remainder of 1.
        int remainder = num_of_element_with_same_remainder;

        // First values of fibonacci sequence.
        int previous = 0;
        int current = 1;

        // Calculation the remainder of the division of
        // num_of_element_with_same_remainder-th
        // fibonacci element keeping on m.
        for (int i = 2; i <= num_of_element_with_same_remainder; i++) {
            remainder = (previous + current) % m;
            previous = current;
            current = remainder;
        }

        return remainder;
    }
};
int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}
