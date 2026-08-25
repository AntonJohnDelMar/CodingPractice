#include "factory_method.hpp" 



Volleyball::Volleyball() {
    std::cout << "Volleyball created. \n"; 
}; 

const colleges Volleyball::best_mens_college() {
    return colleges::HAWAII; 
}



Basketball::Basketball() {
    std::cout << "Basketball created. \n"; 
}; 

const colleges Basketball::best_mens_college() {
    return colleges::MICHIGAN; 
}; 



std::shared_ptr<Sport> SportFactory::create_sport(sports sport) {
    switch(sport) { 
        case sports::BASKETBALL: 
            return std::make_shared<Basketball>(); 

        case sports::VOLLEYBALL: 
            return std::make_shared<Volleyball>(); 
    }; 
    return nullptr; 
}; 

// std::shared_ptr<Sport> volleyball = SportFactory::create_sport(sports::VOLLEYBALL); 