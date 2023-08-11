/*
    五、試以設計線上英文字典查詢的搜尋法為例，假設其資料分布均勻，請回答下列問題：（15
    分）
    (一)常見之搜尋法中，哪一種最適合應用此搜尋，且搜尋時間最有效率（3 分）？並請說
    明此搜尋法的時間複雜度（3 分）。
    (二)有一數列：15、1、3、100、50、44、58、46、27、38，如以 50 作為欲搜尋之鍵值，
    請以上述回答的搜尋法，依序列出於搜尋成功前，各次與鍵值比較的值為何。(未列出
    算式不計分)（9 分）
*/

// interpolation search from a sorted and uniformly distubed data
#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::vector;

int interpolation(vector<int> vec, int x, int lo, int hi)
{
    int pos;
    if (lo <= hi && vec[lo] <= x && x <= vec[hi])
    {
        pos = lo + (x - vec[lo]) * (hi - lo) / (vec[hi] - vec[lo]);
        if (vec[pos] == x)
        {
            return pos;
        }
        if (vec[pos] < x)
        {
            return interpolation(vec, x, pos+1, hi);
        }
        if (vec[pos] > x)
        {
            return interpolation(vec, x, lo, pos-1);
        }
    }
    return -1;
}

int main()
{
    vector<int> dic{15, 1, 3, 100, 50, 44, 58, 46, 27, 38};
    std::sort(dic.begin(), dic.end());
    int x = 0;
    int find = interpolation(dic, x, 0, dic.size()-1);
    if (find != -1)
    {
        cout << "find " << x << '\n';
    }
    else
    {
        cout << "can't find " << x << '\n';
    }
    return 0;
}