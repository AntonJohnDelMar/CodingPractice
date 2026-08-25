// Add files 
#include "design_patterns/singleton.hpp" 
#include "design_patterns/factory_method.hpp" 
#include "algorithms/arrays.hpp" 
#include "algorithms/strings.hpp" 
#include "algorithms/dynamic_programming.hpp" 
#include "algorithms/linked_lists.hpp" 
#include "algorithms/trees.hpp" 
#include "algorithms/graphs.hpp" 
#include "threads/threading.hpp" 
#include "matrices/matrix.hpp" 



int main(int argv, char* argc[]) { 
    auto alg = LinkedList(); 

    ListNode* list_1 = alg.generate_list({1, 2, 4}); 
    ListNode* list_2 = alg.generate_list({1, 3, 4, 5}); 

    ListNode* result = alg.merge_two_lists(list_1, list_2); 

    return 0; 
} 