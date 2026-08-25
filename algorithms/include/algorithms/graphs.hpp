#include <iostream>
#include <vector>
#include <map> 
#include <queue> 
#include <set> 
#include <unordered_set> 
#include <unordered_map> 



class Node {
    public: 
        int val; 
        std::vector<Node*> neighbors; 

        Node() {
            val = 0; 
            neighbors = std::vector<Node*>(); 
        }; 

        Node(int _val) {
            val = _val;
            neighbors = std::vector<Node*>();
        }; 

        Node(int _val, std::vector<Node*> _neighbors) {
            val = _val; 
            neighbors = _neighbors;
        }; 

}; 


class Graph {
    public: 
        Node* root; 

        // Use BFS, track nodes that have been created, connect neighbors as we check since undirected 
        Node* clone_graph(Node* node); 
        Node* check_node_created(std::map<int, Node*> &created_nodes, Node* og_node); 

        // 
        bool contains_cycle_DFS(int &current_class, std::unordered_map<int, std::vector<int>> &class_requirements, std::unordered_set<int> &visited, std::unordered_set<int> &class_path); 
        bool can_finish(int numCourses, std::vector<std::vector<int>>& prerequisites); 
}; 

/*
Completed: 
- (Medium) Clone Graph 
- (Medium) Course Schedule 

TODO: 
- Pacific Atlantic Water Flow
- Number of Islands
- Longest Consecutive Sequence
- Alien Dictionary (Leetcode Premium)
- Graph Valid Tree (Leetcode Premium)
- Number of Connected Components in an Undirected Graph (Leetcode Premium)
*/

/*
auto algorithm = Graph(); 

std::vector<std::vector<int>> prerequisites {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 0}}; 
std::cout << algorithm.can_finish(6, prerequisites) << std::endl; 
*/