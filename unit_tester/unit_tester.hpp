#include <iostream> 
#include <string> 
#include <vector> 
#include <functional> 

using namespace std; 

/* 
Singleton unit test, test the singleton class 
- must only have one instance for the whole application 
- for another test maybe check name of singleton object, i.e. name = "main_singleton" 
*/ 

class UnitTest {
    public: 
        bool check_equal(); 
}; 

/* 
Unit Tests
Rule 0: Write unit tests
- even if it is not good or incomplete, always do your best and write some tests ! 

Rule 1: Good tests, good code, good process 
Good tests 
- falsifiable, i.e. we can prove if something fails but not if it works 
    - detect bugs 
- repeatable, run test many times 
- replicable, others can run tests 
- accurate, how often the test passes 
    - true positive, test failed there is bug
    - true negative, test passed there is no bug 
    - false positive, test failed there is no bug 
    - false negative, test passed there is bug 
- precise 
    - completeness, identify all possible execution paths, find boundary conditions, 
- validity, test correctly, how do we know the correct value? 
    - "the code you wrote is the code you wrote", avoid this! 

Good code 
- readable 
- maintainable 
- document 
- try to avoid conditionals and loops in test functions 

Good process, testability ! 
- simplicity, small functions, single responsbility rule 
- enapsulation and loose coupling 
- DRY, don't repeat yourself 
- SOLID 
- Test driven development 
    - start with minimal code, write failing test, write code to make it pass, refactor, are we done? if not go back to writing fail test, repeat 


Testing classes 
- maybe test each member function individually? (white box) 
    - use "friend" member to access private members if needed 

White Box vs Black Box
White
- Unit test and reach / access internal states i.e. private 
- Commonly used, straight forward, easy to hit edge and errors 
- Couples tester tightly to the code which can be bad for maintainance 

Black 
- Unit test strictly through public members 
- Can have circular logic problem 

Behavior-Driven Design 
- Test class behavior as a whole 

*/