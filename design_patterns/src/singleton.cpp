#include "singleton.hpp" 



Singleton::Singleton(std::string name) {
    this->instance_name = name; 
    std::cout << "Instance Name: " << name << std::endl; 
}; 

Singleton* Singleton::get_instance(std::string instance_name) { 
    if (instance == nullptr) { 
        instance = new Singleton(instance_name); 
        return instance; 
    }

    else {
        std::cout << "Single instance already exists!\n"; 
        return instance; 
    }

}; 

std::string Singleton::get_name() const {
    return instance_name; 
}


// Singleton* Singleton::instance = nullptr; 

/* 
Singleton* singleton = Singleton::get_instance("main"); 
Singleton* singleton_2 = Singleton::get_instance("secondary"); 

std::cout << "Singleton: " << singleton->get_name() << std::endl; 
std::cout << "Singleton: " << singleton_2->get_name() << std::endl; 
*/ 