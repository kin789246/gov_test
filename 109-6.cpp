/*
六、給定一陣列名稱為 NUM，包含 n 個不重複整數(n > 2)，請撰寫虛擬程式碼找出該陣
列中元素兩兩乘積最大者(即 Maximum pairwise product，變數名稱為 maxprod，
maxprod = maximum (NUM[i] * NUM[j], i <> j) )，完成下列 2 項子題。（共 2 題，共
25 分）
(一)請說明欲撰寫之虛擬程式碼的主要程式邏輯。（10 分）
(二)請在演算法時間複雜度須為 O(n)的限制下，撰寫虛擬程式碼。(請注意，如作答內容之
演算法時間複雜度經分析為 O(n^2)，本子題僅給 5 分)（15 分）
*/

#include<iostream>

int main()
{
    const int N = 9;
    int nums[N] = {3, 8, 9, 5, 10, 1, 7, 4, 11};
    int idx1 = 0;
    int idx2 = 0;
    for (int i=1; i<9; i++) /* find the maximum */
    {
        if (nums[idx1] < nums[i])
        {
            idx1 = i;
        }
    }
    if (idx1 == 0)
        idx2 = 1;
    else
        idx2 = 0;
    for (int i=0; i<N; i++) /* find the second maximum */
    {
        if (i != idx1 && nums[i]<nums[idx1] & nums[idx2]<nums[i])
        {
            idx2 = i;
        }
    }
    std::cout << "Array = [ ";
    for (int i=0; i<N; i++)
    {
        std::cout << nums[i];
        if (i < N-1)
            std::cout << ' ';
    }
    std::cout << " ]\n";
    std::cout << "Maximum pairwise product = " << nums[idx1]*nums[idx2] << '\n';
    return 0;
}