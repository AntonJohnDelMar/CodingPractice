#include <Eigen/Dense> 
#include <iostream> 
#include <random> 



std::vector<int> gen_rand_vector(const int min_value, const int max_value, const int num_elements) {
    std::mt19937 prng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(min_value, max_value); 

    std::vector<int> nums; 

    for (int i = 0; i <= num_elements; i++) {
        int num = dist(prng); 
        nums.push_back(num); 
        std::cout << num << " "; 
    } 
    std::cout << std::endl; 

    return nums; 
}

/* 
int max_value = 100; 
int min_value = 0; 
int num_elements = 40; 
auto nums = gen_rand_vector(min_value, max_value, num_elements); 
*/ 


void run_matrix_code() {
    Eigen::Matrix<float, 4, 4> matrix_A; 
    matrix_A.setZero(); 
   
    std::cout << matrix_A << std::endl; 
}; 