/*
    二、給予一個二元搜尋樹(Binary Search Tree)的後序追蹤(5、2、13、9、18、29、25、54、56
    、48、35、16)，請回答下列問題：
    (一)請畫出此二元搜尋樹。（5 分）
    5
    | \
    2 13
      | \
      9 18
        | \
        16 29
           | \
           25 54
              | \
              48 56
              |
              35  
    (二)請使用虛擬碼(Pseudo Code)寫出搜尋此樹的副程式(限以遞迴(Recursive)演算法寫出，
    若有需要，亦須寫出假設或宣告變數及註解)。若要在第(一)小題的二元搜尋樹搜尋 29
    這個節點，則須呼叫此遞迴函數幾次？（15 分）
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<fstream>
#include<cmath>
#include<cstdio>
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v)
        : value(v), left(nullptr), right(nullptr)
    {
    }
};

struct Draw_node {
    Node* node;
    int position;
    int level;
    int is_left;
    Draw_node(Node* n, int p, int l, bool le)
        : node(n), position(p), level(l), is_left(le)
    {
    }
};

class BinarySearchTree {
private:
    Node*   m_tree;
    void    insert_node(Node** node, int value);
    void    draw_nth_level(Node* node, int level);
    bool    search_node(Node* node, int value);
public:
    BinarySearchTree()
        : m_tree(nullptr)
    {
    }
    void    build_tree();
    void    build_from_file(std::string file_name);
    void    insert(int value);
    Node*   remove(int value);
    bool    contained(int value);
    int     get_tree_height();
    int     find_end_node(Node* node);
    void    draw_tree();
};
void BinarySearchTree::build_tree()
{
    std::string input;
    while (true)
    {
        std::cout << "請輸入整數來建立二元搜尋樹 (q=結束)\n";
        try
        {
            if (input == "q") break;
            std::cin >> input;
            int v = std::stoi(input);
            insert(v);
        }
        catch(...)
        {
            std::cout << "非整數 ";
        }
    }
    std::cout << "建立完成\n";
}
void BinarySearchTree::build_from_file(std::string file_name)
{
    std::ifstream num_stream(file_name);
    if (!num_stream.is_open())
    {
        std::cout << "檔案無法開啟\n";
        return;
    }
    int value;
    while (num_stream.good())
    {
        num_stream >> value;
        insert(value);
    }
    if (num_stream.fail())
    {
        std::cout << "有非整數！\n";
        std::exit(1);
    }
}
void BinarySearchTree::insert_node(Node** node, int value)
{
    if (*node == nullptr) 
    {
        *node = new Node(value);
        return;
    }
    if ((*node)->value < value) {
        insert_node(&(*node)->right, value);
    }
    else if ((*node)->value > value) {
        insert_node(&(*node)->left, value);
    }
}
void BinarySearchTree::insert(int value)
{
    insert_node(&m_tree, value);
}
bool BinarySearchTree::search_node(Node* node, int value)
{
    if (!node)
    {
        return false;
    }
    if (node->value == value)
    {
        return true;
    }
    if (node->value > value) 
    {
        return search_node(node->left, value);
    }
    return search_node(node->right, value);
}
bool BinarySearchTree::contained(int value)
{
    return search_node(m_tree, value);
}
int BinarySearchTree::find_end_node(Node* node)
{
    if (node == nullptr) 
    {
        return 0;
    }
    return 1 +
        std::max(find_end_node(node->left), find_end_node(node->right));
}
int BinarySearchTree::get_tree_height() {
    return find_end_node(m_tree);
}
void BinarySearchTree::draw_nth_level(Node* node, int level)
{
    if (node) {
        draw_nth_level(node->left, level - 1);
        if (level == 0) 
        {
            std::cout << node->value << " ";
        }
        draw_nth_level(node->right, level - 1);
    }
}
void BinarySearchTree::draw_tree()
{
    if (m_tree == nullptr) 
    {
        std::cout << "空二元搜尋樹\n";
        return;
    }
    std::queue<Draw_node> q;
    int height = get_tree_height();
    std::vector<std::vector<Draw_node>> buf
        = std::vector<std::vector<Draw_node>>(height);
    int lv = 0;
    q.push(Draw_node(m_tree, std::pow(2, height-1), 1, true));
    while (!q.empty())
    {
        Draw_node curr = q.front();
        q.pop();
        if (curr.node)
        {
            if (lv != curr.level)
            {
                lv = curr.level;
            }
            buf[lv-1].push_back(curr);
            int offset = std::pow(2, height-curr.level-1);
            if (curr.node->left) 
            {
                q.push(Draw_node(curr.node->left, curr.position-offset, lv+1, true));
            }
            if (curr.node->right)
            {
                q.push(Draw_node(curr.node->right, curr.position+offset, lv+1, false));
            }
        }
    }
    for(int i=0; i<height; i++) 
    {
        int pos = 0;
        for (auto& d_node : buf[i])
        {
            std::string s = "";
            while (pos < d_node.position)
            {
                if (pos == d_node.position-1)
                {
                    char num[4];
                    int nc = std::snprintf(num, 4, "%02d", d_node.node->value);
                    if (nc > 0) 
                    {
                        if (d_node.is_left) 
                            s += "L";
                        else
                            s += "R";
                        s += num;
                    }
                }
                else
                {
                    //s += "◡◡◡";
                    s += "   ";
                }
                pos++;
            }
            std::cout << s;
        }
        std::cout << "\n\n";
    }
    std::cout << "\n";
}

void test_contained(BinarySearchTree& t)
{
    while (true)
    {
        std::string input;
        std::cout << "Enter the number to see if it is contained (q to exit)";
        std::cin >> input;
        try
        {
            if (input == "q")
            {
                return;
            }
            int n = std::stoi(input);
            if (t.contained(n))
            {
                std::cout << "Yes";
            }
            else
            {
                std::cout << "No";
            }
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

int main() 
{
    BinarySearchTree tree1;
    tree1.build_from_file("num_list.txt");
    //std::cout << "樹高" << tree1.get_tree_height() << "層\n";
    //tree1.draw_tree();
    test_contained(tree1);
    return 0;
}