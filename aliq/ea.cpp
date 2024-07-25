#include <iostream>

void printFee(int fee) {
    std::cout << "The current fee is: " << fee << std::endl;
}

int applyDiscount(int fee, int discount) {
    return fee - discount;
}

int main() {
    int TFee = 4000;
    std::cout << "Initial fee: ";
    printFee(TFee);

    int discount = 500;
    TFee = applyDiscount(TFee, discount);

    std::cout << "Fee after applying discount: ";
    printFee(TFee);

    return 0;
}
