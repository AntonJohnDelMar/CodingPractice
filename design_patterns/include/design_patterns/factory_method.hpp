#include <iostream>
#include <string>
#include <memory>



// Turn into .csv or other file format 
enum class colleges { MICHIGAN, HAWAII, UCSD, UCI, UCLA, MIT, NYU }; 

enum class sports { BASKETBALL, VOLLEYBALL }; 



class Sport {
    public: 
        virtual ~Sport() {}; 
        virtual const colleges best_mens_college() = 0; 
}; 


class Volleyball : public Sport {
    public: 
        Volleyball(); 
        const colleges best_mens_college() override; 
}; 


class Basketball : public Sport {
    public: 
        Basketball(); 
        const colleges best_mens_college() override; 
}; 


/*
Factory method - how we create objects, in this case we can create different sport objects, each one has their own implementation of the sport class through intheritance 
*/
class SportFactory {
    public: 
        static std::shared_ptr<Sport> create_sport(sports sport); 

    private: // Make factory a singleton 
        SportFactory() {}; 
        ~SportFactory() {}; 
        SportFactory(const SportFactory &factory) {}; 
}; 