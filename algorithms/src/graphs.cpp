#include "algorithms/graphs.hpp"



Node* Graph::check_node_created(std::map<int, Node*> &created_nodes, Node* og_node) { 
    if (created_nodes.find(og_node->val) == created_nodes.end()) {
        Node* new_node = new Node(og_node->val); 
        created_nodes[og_node->val] = new_node; 
        return new_node; 
    }

    else return created_nodes[og_node->val]; 
}; 


Node* Graph::clone_graph(Node* node) { 
    if (node == nullptr) return nullptr; 

    std::map<int, Node*> created_nodes; 
    std::queue<Node*> node_queue; 
    node_queue.push(node); 
 
    while (!node_queue.empty()) { 
        Node* og_curr_node = node_queue.front(); 
        node_queue.pop(); 

        Node* copy_curr_node = this->check_node_created(created_nodes, og_curr_node); 

        for (auto og_neighbor : og_curr_node->neighbors) { 

            if (created_nodes.find(og_neighbor->val) == created_nodes.end()) { 
                node_queue.push(og_neighbor); 
                Node* copy_neighbor = this->check_node_created(created_nodes, og_neighbor); 
            }

            copy_curr_node->neighbors.push_back(created_nodes[og_neighbor->val]); 
        } 

    }     

    return created_nodes[node->val]; 
}; 

/* 
Created: A, B, C, E, D, F
    Queue: 
Current: 

A - B, C
B - A, E 
C - A, D 
E - B, D 
D - C, E, F
F - D 

A -- B -- |
|         E
C -- D -- |
        |
        F 

*/

bool Graph::can_finish(int num_courses, std::vector<std::vector<int>>& prerequisites) { 
    /* 
    Approaches: 
    - O(n + cycle), save pairs into a map, if our prereq is in the map follow it until we find a cycle or not 
    - ^ It is not mentioned in the problem description, but one class can have multiple prereqs, so this doesn't work 
    - O(n + V) Create adjacency list using map and vectors, use DFS to traverse graph and check cycles, recursive 
    
    1 -> 0, 2 -> 0, 3 -> 0, 4 -> 3, 0 -> 4 
    */
    if (prerequisites.empty()) return true; 

    std::unordered_map<int, std::vector<int>> class_requirements; 

    for (auto &class_prereq : prerequisites) {
        class_requirements[class_prereq[0]].push_back(class_prereq[1]); 
    }


    std::unordered_set<int> visited; 
    std::unordered_set<int> class_path; 

    for (auto &_class : class_requirements) { 
        int current_class = _class.first; 

        if (visited.contains(current_class)) continue; 

        if (contains_cycle_DFS(current_class, class_requirements, visited, class_path)) return false; 
    }

    return true; 
}; 

bool Graph::contains_cycle_DFS(int &current_class, std::unordered_map<int, std::vector<int>> &class_requirements, std::unordered_set<int> &visited, std::unordered_set<int> &class_path) { 

    if (visited.contains(current_class)) return false; 

    if (class_path.contains(current_class)) return true; 

    class_path.insert(current_class); 

    if (class_requirements.contains(current_class)) { 
        for (auto &prereq : class_requirements.at(current_class)) {
            if (contains_cycle_DFS(prereq, class_requirements, visited, class_path)) return true; 
        }
    } 

    visited.insert(current_class); 
    class_path.erase(current_class); 
    return false; 
}; 