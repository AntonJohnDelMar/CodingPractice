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
    auto algorithm = Array(); 
    std::vector<int> nums {1, 3, 5, 7, 9, 11}; 

    auto result = algorithm.search_insert(nums, 12); 

    return 0; 
} 