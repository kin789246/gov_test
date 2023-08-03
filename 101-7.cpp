/*
請撰寫程式，求出N!的結果值中，從右邊算來第一個不是0的數字位置，例如
N輸入了:因為3!=6，其右邊算來第一個不是0的數字位置為1，所以輪出1
N輸入5:因為5!=120，其右邊算來第一個不是0的數字位置為2，所以輸出2
N輪入10:因為10!=3628800，其右邊算來第一個不是0的數字位置為3，所以輪出3
撰寫過程，請註明您所使用的程式語言，並在適當位置加上註記。
N的IO部分，可以以虛擬碼代替，其餘部分不得使用虛擬碼。(15分)
*/

#include<iostream>
#include<string>
using std::cout, std::cin, std::string;

int factorial(int n) {
    if (n == 1) return 1;
    return n*factorial(n-1);
}

int main() {
    string cmd;
    while (true) {
        try {
            cout << "ENTER A NUMBER TO GET THE FACTORIAL RESULT\n"
                << "q / Q TO EXIT => ";
            cin >> cmd;
            if (cmd == "q" || cmd == "Q") {
                cout << "打完收工！\n";
                break;
            }
            int n = std::stoi(cmd);
            int f = factorial(n);
            cout << n << "! = " << f << "\n";
            int c = 0;
            while (f > 0) {
                if (f % 10 != 0) {
                    cout << "右邊算來第一個不為0的位置為" << c+1 << "\n";
                    break;
                }
                c++;
                f /= 10;
            }
        }
        catch (...) {
            cout << "PLEASE ENTER A NATURE NUMBER\n";
        }
    }
    return 0;
}