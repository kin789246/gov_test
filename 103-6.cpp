/*
六、請使用.NET 或 Java 程式語言，利用物件導向程式設計的方法作答(註明所使用的程式語言)。
(一)設計具有分數四則運算功能的 Rational 類別，並符合下列規則。（15 分）
(1)使用整數變數來表示類別的 private 實體變數 numerator(分子)及 denominator(分母)。
(2)提供一個有引數的建構子方法，並以最簡分數的形式儲存。
(3)提供一個無引數的建構子方法，並設定初始值為 1/1。
(4)提供加、減、乘、除四種運算的方法及過程，結果以最簡分數的形式儲存。
(5)提供將結果以 a/b 格式輸出的方法，其中 a 為分子，b 為分母，若結果為 1/1 時則輸
出 1。
(二)利用設計的類別計算 1/6 + 1/3 並將結果輸出(需列出程式步驟)。（5 分）
*/

#include<iostream>

class Rational {
    public:
    Rational() : numerator(1), denominator(1) {}
    Rational(int n, int d);
    Rational add(const Rational& a);
    Rational subtract(const Rational& a);
    Rational multiply(const Rational& a);
    Rational divide(const Rational& a);
    friend std::ostream& operator<<(std::ostream& o, const Rational& a)
    {
        if (a.numerator == a.denominator)
        {
            o << "1";
        }
        else
        {
            o << a.numerator << '/' << a.denominator;
        }
        return o;
    }
    private:
    int numerator;
    int denominator;
    int gcd(int a, int b);
    int lcm(int a, int b);
};
Rational::Rational(int n, int d)
{
    if (d == 0)
    {
        std::cout << "denominator can not be 0\n";
        std::exit(1);
    }
    int g = gcd(n, d);
    numerator = n/g;
    denominator = d/g;
}
int Rational::gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}
int Rational::lcm(int a, int b)
{
    return a*b / gcd(a,b);
}
Rational Rational::add(const Rational& a)
{
    int d = lcm(denominator, a.denominator);
    int n = d/denominator*numerator + d/a.denominator*a.numerator;

    return Rational(n, d);
}
Rational Rational::subtract(const Rational& a)
{
    int d = lcm(denominator, a.denominator);
    int n = d/denominator*numerator - d/a.denominator*a.numerator;

    return Rational(n, d);
}
Rational Rational::multiply(const Rational& a)
{
    return Rational(numerator*a.numerator, denominator*a.denominator);
}
Rational Rational::divide(const Rational& a)
{
    return Rational(numerator*a.denominator, denominator*a.numerator);
}
void test_add()
{
    Rational a = Rational(3, 8);
    Rational b = Rational(1, 8);
    std::cout << a << " + " << b << " = " << a.add(b) << '\n';
}
void test_subtract()
{
    Rational a = Rational(3, 10);
    Rational b = Rational(3, 5);
    std::cout << a << " - " << b << " = " << a.subtract(b) << '\n';
}
void test_multiply_divide()
{
    Rational a = Rational(3, 10);
    Rational b = Rational(3, 5);
    std::cout << a << " * " << b << " = " << a.multiply(b) << '\n';
    std::cout << a << " / " << b << " = " << a.divide(b) << '\n';
}
int main()
{
    test_add();
    test_subtract();
    test_multiply_divide();
    return 0;
}