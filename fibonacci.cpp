#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci {
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

        return v.back();
    }

   public:
    static int get(int n) {
        assert(n >= 0);

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        std::vector<int> v = {};
        v.push_back(0);
        v.push_back(1);

        for (int i = 2; i <= n; i++) {
            int next_fib = v.at(i - 2) + v.at(i - 1);
            v.push_back(next_fib);
        }

        return v.back();
    }
};

int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get_last_digit(n) << std::endl;
    return 0;
}
