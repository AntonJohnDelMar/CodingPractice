# Object Oriented Programming - General Notes

## Four Pilars of OOP 

### Abstraction 
- Only show necessary details of an object to user, hide underlying implementation 
    - Ex: Car class has complex functions inside that the user does't need to see like starting the engine or interfacing electronics 

### Inheritance 
- Reusability, extend classes and utilize their og features, 
    - Ex: Animal class, Dog and Cat can inherit / extend the animal class and add their own features, here Animal is the parent class and Dog / Cat are the children classes 

### Polymorphism 
- Many forms, determine what kind of function will run for a program, 
    - Runtime polymorphism, achieved with overriding virtual functions 
        - Ex: Animal class has speak function, but Dog and Cat override speak, when program runs if speak is called it determines which speak to call 
    - Compiletime polymorphism, achieved with operator / function overloading 
        - Ex: Addition class has add function, you can overload the add function by defining different parameters, like add(int a, int b) and add(float a, float b), the function call is determined at compile time 

### Encapsulation 
- Data hiding, restrict access of properties or methods of an object, 
    - Ex: Bank Account hides balance with private, can only be accessed with getter or setter functions, 