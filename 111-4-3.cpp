#include<iostream>

int F(int t, int val=1, int prev=0) {
    if (t == 0)
        return prev;
    return F(t-1, val+prev, val);
}

int main() {
    for (int i=0; i<10; i++) {
        std::cout << F(i) << " ";
    }
    std::cout << "\n";
    return 0;
}