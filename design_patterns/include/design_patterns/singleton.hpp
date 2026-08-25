#include <iostream>
#include <string> 


/*
Singleton - enforce only one single instance of an object for the duration of the program 
*/
class Singleton { 
    protected: 
        Singleton(const std::string name); 

        std::string instance_name; 
        static Singleton* instance; 

    public: 
        Singleton(Singleton &other) = delete; // Prevent clones 
        void operator=(const Singleton &other) = delete; // Prevent assignment 

        static Singleton* get_instance(std::string instance_name); 
        std::string get_name() const; 
 
}; 