#include<iostream>
int gcd(int a, int b) {
    if (b != 0) {
        return gcd(b, a%b);
    }
    return a;
}

int main() {
    int a = 36, b = 6;
    std::cout << "gcd (" << a << ", " << b << ")= " << gcd(a,b) << '\n';
    return 0;
}