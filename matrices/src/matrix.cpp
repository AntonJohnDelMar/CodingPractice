#include "matrix.hpp" 


SimulateSystem::SimulateSystem() {
    m = 0; n = 0; r = 0; 

    A.resize(1, 1); A.setZero(); 
    B.resize(1, 1); B.setZero(); 
    C.resize(1, 1); C.setZero(); 
    x_0.resize(1, 1); x_0.setZero(); 

    input_sequence.resize(1, 1); input_sequence.setZero();
    simulated_output_sequence.resize(1, 1); simulated_output_sequence.setZero(); 
    simulated_state_sequence.resize(1, 1); simulated_state_sequence.setZero(); 
    time.resize(1, 1); time.setZero(); 
}; 


SimulateSystem::SimulateSystem(Eigen::MatrixXd A_matrix, Eigen::MatrixXd B_matrix, Eigen::MatrixXd C_matrix, Eigen::MatrixXd initial_state, Eigen::MatrixXd input_sequence_matrix) { 
    A = A_matrix; B = B_matrix; C = C_matrix; x_0 = initial_state; input_sequence = input_sequence_matrix; 

    n = A.rows(); 
    m = B.cols(); 
    r = C.rows(); 
    time_samples = input_sequence.cols(); 

    simulated_output_sequence.resize(r, time_samples); 
    simulated_output_sequence.setZero(); 

    simulated_state_sequence.resize(n, time_samples); 
    simulated_state_sequence.setZero(); 

    time.resize(1, time_samples); 

    for (int i = 0; i < time_samples; i++) {
        time(0, i) = i + 1; 
    } 
}; 


void SimulateSystem::run_simulation() { 
    for (int j = 0; j < time_samples; j++) {

        if (j == 0) {
            simulated_state_sequence.col(j) = x_0; 
            simulated_output_sequence.col(j) = C * x_0; 
        }

        else {
            simulated_state_sequence.col(j) = A * simulated_state_sequence.col(j - 1) + B * input_sequence.col(j - 1); 
            simulated_output_sequence.col(j) = C * simulated_state_sequence.col(j); 
        }
    }
}; 