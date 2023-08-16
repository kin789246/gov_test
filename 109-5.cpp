/* 
swap children of the binary tree
      A                     A
    /   \                 /   \
   B     C      ===>     C     B
  / \     \             /     / \ 
 D   E     F           F     E   D  


五、請於下方標示之【待填入程式區塊】中，以 6 行內為限填入虛擬程式碼(pseudo-code)，實
現將二元樹(以鏈結串列方式儲存)中每一節點的左子樹、右子樹皆調換之功能(示意如下，
交換前二元樹如【圖 1】，交換後二元樹如【圖 2】，以 t 表示父節點之指標，t->leftchild
表示 t 的左子節點指標，t->rightchild 表示 t 的右子節點指標)。（15 分）
Swaptree(t pointer)
{
  if ( t <> NULL) then
  {
   【待填入程式區塊】
  }
} // Swaptree 函式結尾
*/

#include<iostream>
#include<vector>

struct Node
{
    char  c;
    Node* left;
    Node* right;
    Node(char c) : c{c}, left{nullptr}, right{nullptr}{}
};

class BinaryTree 
{
    public:
        BinaryTree() : m_tree{nullptr} {}
        void build_from(std::vector<char>& vec);
        void in_order(Node* node);
        void print();
        void swap_tree(Node *node);
        void swap_tree();
    private:
        Node* m_tree;
};
void BinaryTree::build_from(std::vector<char>& vec)
{
    std::vector<Node*> tree;
    for (char c : vec)
    {
        if (c == '0')
        {
            tree.push_back(nullptr);
        }
        else
        {
            tree.push_back(new Node{c});
        }
    }
    m_tree = tree[0];
    int i = 1;
    for (auto node : tree)
    {
        if (node)
        {
            if (!node->left)
                node->left = tree[i++];
            if (!node->right)
                node->right = tree[i++];
        }
    }
}
void BinaryTree::in_order(Node* node)
{
    if (node)
    {
        std::cout << node->c << ' ';
        in_order(node->left);
        in_order(node->right);
    }
}
void BinaryTree::print()
{
    in_order(m_tree);
    std::cout << '\n';
}
void BinaryTree::swap_tree(Node* node)
{   
    if (node)
    {
        swap_tree(node->left);
        swap_tree(node->right);
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void BinaryTree::swap_tree()
{
    swap_tree(m_tree);
}
int main()
{
    std::vector<char> v{ 'A', 'B', 'C', 'D', 'E', '0', 'F' };
    //std::vector<char> v{ 'A', 'C', 'B', 'F', '0', 'E', 'D' };
    BinaryTree t;
    t.build_from(v);
    t.print();
    t.swap_tree();
    t.print();
    return 0;
}