/*
有一數列：30、5、37、2、61、8、55、19、46、23 ，欲以快速排序法進行排序，以 30作
為第一次比較之鍵值：
(一)請將數列由小至大排列完成為止，寫出排序的步驟。（10 分）
(二)請將每次做比較之鍵值列出。（5 分）
第一次比較之鍵值：30
第二次比較之鍵值：
第三次比較之鍵值：
依此類推。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

void print(vector<int>& vec)
{
    for (auto i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
int partition(vector<int>& vec, int low, int high)
{
    if (vec.size() <= 1)
    {
        return 0;
    }
    int i = high+1;
    int pivot = vec[low];
    for (int j=high; j>low; j--)
    {
        if (vec[j] > pivot)
        {
            i--;
            std::swap(vec[j], vec[i]);
        }
    }
    std::swap(vec[low], vec[i-1]);
    std::cout << pivot << ": ";
    print(vec);
    return i-1;
}
void quick_sort(vector<int>& vec, int low, int high)
{
    if (low < high)
    {
        int p = partition(vec, low, high);
        quick_sort(vec, low, p-1);
        quick_sort(vec, p+1, high);
    }
}
int main()
{
    //vector<int> qs{30, 5, 37, 2, 61, 8, 55, 19, 46, 23};
    vector<int> qs{ 30, 5, 37, 2 };
    print(qs);
    quick_sort(qs, 0, qs.size()-1);
    print(qs);
    return 0;
}