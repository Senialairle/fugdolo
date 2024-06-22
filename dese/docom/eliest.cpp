#include <iostream>
#include <climits>

int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
            return 0; // Overflow will occur if we add the next digit
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
            return 0; // Underflow will occur if we add the next digit
        }
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return reversed;
}

int main() {
    int num = 123;
    std::cout << "Reversed number: " << reverse(num) << std::endl;
    return 0;
}
