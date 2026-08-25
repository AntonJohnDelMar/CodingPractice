// Threading libraries 
#include <iostream> 
#include <thread> 
#include <chrono> 
#include <mutex> 

// Standard libraries 
#include <map> 
#include <string> 

using namespace std::chrono_literals; 



void refresh_forecast(std::map<std::string, int> forecast_map) { 
    while(true) {
        for (auto &item : forecast_map) { 
            std::string city = item.first; 
            int* temperature = &item.second; 
            (*temperature)++; 

            std::cout << city << " - " << *temperature << std::endl; 
        }

        std::this_thread::sleep_for(2000ms); // 2000ms from chrono literals 
    } 
    /*
    std::map<std::string, int> forecast_map = {
        {"Los Angeles", 90}, 
        {"San Diego", 89}, 
        {"San Francisco", 87}, 
    }; 
    
    std::thread worker_1(refresh_forecast, forecast_map); 

    worker_1.join(); 
    */
}; 

std::mutex car_mtx; 

void drive_car(std::string driver_name) { 
    // Unique lock you have to manually lock and unlock 
    // std::unique_lock<std::mutex> car_lock(car_mtx); 
    // Lock gaurd locks where it is created, it unlocks automatically once it is out of scope 
    std::lock_guard<std::mutex> car_lock(car_mtx); 

    std::cout << driver_name << " is driving. \n"; 
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    std::cout << driver_name << " is done driving. \n"; 

    // car_lock.unlock(); 
}; 


void start_threads() { 
    std::thread worker_1(drive_car, "Anton"); 
    std::thread worker_2(drive_car, "Daniel"); 

    worker_1.join(); 
    worker_2.join(); 
}; 

/*
void function_1(char symbol) {
    for (int i = 0; i < 200; i++) {
        std::cout << symbol; 
    }
}

void function_2() {
    for (int i = 0; i < 200; i++) {
        std::cout << "-"; 
    }
}


int main(int argv, char* argc[]) { 
    std::thread worker_1(function_1, 'o'); 
    std::thread worker_2(function_2); 

    worker_1.join(); 
    worker_2.join(); 

    return 0; 
} 
*/