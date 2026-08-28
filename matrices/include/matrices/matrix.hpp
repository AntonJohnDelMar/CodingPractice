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


void run_matrix_code() {
    Eigen::Matrix<float, 4, 4> matrix_A; 
    matrix_A.setZero(); 
   
    std::cout << matrix_A << std::endl; 
}; 


class SimulateSystem {
    public: 
        SimulateSystem(); 

        SimulateSystem(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd x_0, Eigen::MatrixXd input_sequence); 

        void run_simulation(); 

    private: 
        Eigen::MatrixXd A, B, C; 
        Eigen::MatrixXd x_0; 
        Eigen::MatrixXd input_sequence; 
        Eigen::MatrixXd simulated_state_sequence; 
        Eigen::MatrixXd simulated_output_sequence; 
        Eigen::MatrixXd time; // Row vector 

        int m, n, r, time_samples; // Matrix dimensions 
}; 