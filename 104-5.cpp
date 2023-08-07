/*
五、如欲以結構化程式設計方式利用堆疊設計一簡易撲克牌遊戲發牌系統，包含洗牌、切牌及
發牌，以數字 1～52代表撲克牌 52張牌，堆疊陣列 R[0..51]儲存代表 52張撲克牌之數字，
R[51]為底部第 52 張牌，R[0]為頂部第 1 張牌：
(一)洗牌部分，先用亂數方式隨機取出上述 52 個數字其中 1 個數字(代表隨機取一張牌)以
堆疊方式填入陣列 R 之底部，再繼續取下 1 個數字(下一張牌，須判斷亂數取出之數是
否已被取出過，若已取過須重取)以堆疊方式依序填入陣列 R，直至 52 個數字(52 張牌)
皆被取出填入陣列 R 為止，試畫出其流程圖。（5 分）
(二)已用隨機方式選擇從陣列 R 第 20 張牌(R[19])切牌，並開始取出發牌，請問取出發牌的
順序為何？請以 R 陣列內含引數 R[i]方式表示。（5 分）
(三)開始發牌後，如何判斷已發牌至堆疊陣列 R 之底部，以及如何繼續取出下一張牌至整
副牌發完？試以流程圖表示之。（10 分）
(四)洗牌及切牌均須隨機從 1～52 取出一數字，今有一無參數之亂數函數 rand( )可隨機傳
回值 K，其中 0 ≤ K < 1，請問如何利用 rand( )隨機取出 1～52，試寫出其程式表示式。
（5 分）
*/

#include<iostream>
#include<random>
class Poker {
public:
    Poker()
    {
        capacity = 52;
        remainder = capacity;
        top_idx = capacity;
        R = new int[capacity];
        record = new bool[capacity];
        for (int i=0; i<capacity; i++)
            record[i] = false;
    }
    void    shuffle_deck();
    bool    empty();
    bool    full();
    void    print();
    void    deal_from(int cut);
private:
    int     top_idx;
    int     capacity;
    int     remainder;
    int*    R;
    bool*   record;
    int     generate_number();
};
int Poker::generate_number()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> uidist(1, capacity);
    return uidist(generator);
}
void Poker::shuffle_deck()
{
    remainder = 0;
    while (remainder < 52)
    {
        int n = generate_number();
        if (record[n-1] == false)
        {
            R[--top_idx] = n;
            remainder++;
            record[n-1] = true;
        }
    }
}
bool Poker::empty()
{
    return remainder == 0;
}
bool Poker::full()
{
    return remainder == 52;
}
void Poker::print()
{
    for (int i=0; i<capacity; i++)
    {
        std::cout << R[i];
        if ((i+1) % 13 == 0) std::cout << '\n';
        else std::cout << ' ';    
    }
}
void Poker::deal_from(int cut)
{
    int remainder = 52;
    while (remainder > 0)
    {
        std::cout << R[cut] << ' ';
        cut++;
        if (cut % 13 == 0) std::cout << '\n';
        cut %= 52;
        remainder--;
    }
    std::cout << '\n';
}

void test_build_deck()
{
    Poker p;
    p.shuffle_deck();
    p.print();
}
void test_deal_from_cut()
{
    Poker p;
    p.shuffle_deck();
    std::cout << "origin\n";
    p.print();
    std::cout << "\nafter deal all from cut\n";
    p.deal_from(19);
}
int main()
{
    test_deal_from_cut();
    return 0;
}