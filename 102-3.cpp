/*
    GRAPH
    6 -- 4 - 5 - 2     11 - 10
    |\   /      / \   /    /
    | \ /      /   \ /    /       
    7  3 ---- 8 --- 1 -- 9
        \    /
         \  /
          12

    1 -> 2, 8, 9, 11
    2 -> 1, 5, 8
    3 -> 4, 6, 8, 12
    4 -> 3, 5, 6
    5 -> 2, 4
    6 -> 3, 4, 7
    7 -> 6
    8 -> 1, 2, 3, 12
    9 -> 1, 10
    10-> 9, 11
    11-> 1, 10
    12-> 3, 8
*/
#include<iostream>
#include<map>
#include<set>
#include<list>
#include<string>
#include<fstream>
#include<sstream>
class Graph {
    public:
    int vertices;
    std::map<int, std::list<int>> adjacent; 
    std::set<int> visited;
    void add_edge(int v, int t);
    void dfs(int v);
    void bfs(int v);
    void creat_from(std::string& file_name, int n);
    void print_adjacent();
};
void Graph::print_adjacent()
{
    for (auto k=adjacent.begin(); k != adjacent.end(); k++)
    {
        std::cout << k->first << ": ";
        for (auto i : k->second)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}
void Graph::add_edge(int v, int t)
{
    adjacent[v].push_back(t);
}
void Graph::dfs(int v)
{
    if (visited.find(v) != visited.end())
    {
        return;
    }
    visited.insert(v);
    std::cout << v << " ";
    for (auto node : adjacent[v])
    {
        if (visited.find(node) != visited.end())
            continue;
        dfs(node);
    }
}
void Graph::bfs(int v)
{
    std::list<int> queue;
    queue.push_back(v);
    while (!queue.empty())
    {
        int curr = queue.front();
        queue.pop_front();
        visited.insert(curr);
        std::cout << curr << " ";
        for (auto i : adjacent[curr])
        {
            if (visited.find(i) == visited.end())
            {
                visited.insert(i);
                queue.push_back(i);
            }
        }
    }
}
void Graph::creat_from(std::string& file_name, int n)
{
    vertices = n;
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cout << "file can't open\n";
        return;
    }
    std::string s;
    std::string w = "";
    char c;
    while (file.good())
    {
        int v;
        int t;
        c = file.get();
        if (c == ':')
        {
            v = std::stoi(w);
            w = "";
            file.get(); // skip the next space
            while (file.good())
            {
                c = file.get();
                if (c == ' ' || c == '\n')
                {
                    t = std::stoi(w);
                    w = "";
                    add_edge(v, t);
                    if (c == '\n')
                        break;
                }
                else
                {
                    w.push_back(c);
                }
            }
        }
        else 
        {
            w.push_back(c);
        }
    }
}
void test_create_from()
{
    Graph g;
    std::string file_name = "graph.txt";
    g.creat_from(file_name, 12);
    g.print_adjacent();
}
void test_dfs()
{
    Graph g;
    std::string file_name = "graph.txt";
    g.creat_from(file_name, 12);
    std::cout << "DFS traversal order -> ";
    g.dfs(2);
    std::cout << "\n";
}
void test_bfs()
{
    Graph g;
    std::string file_name = "graph.txt";
    g.creat_from(file_name, 12);
    std::cout << "BFS traversal order -> ";
    g.bfs(1);
    std::cout << "\n";
}
int main()
{
    test_bfs();
    return 0;
}