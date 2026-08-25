# Design Patterns in C++

## Creational 

### Abstract Factory 
- Factory to create family of related objects 
- Consider a furniture factory, but we may have different styles like modern, victorian, classic 
- Furniture factory can create furniture, then we can have a ModernFurnitureFactory that creates the modern variants 
- All while implementing the original functionalities each furniture object should make 

### Builder 
- Say we have a house object, we want to create different types of houses, we use a builder 
- This object can have functions like build_wall(), build_door(), and we can extend this 
- We do not have to worry about initializing house object with everything all at once, we can do that later with the builder 
- We can use a director class to specify order in which the builder builds 

### Factory Method 
- Factory method creates objects for us 
- Say we have a Car class, then we extend that into a SportsCar and Truck class, they all implement their own version of drive() or passanger_size() for example 
- The factory can create these types of cars, without the user having to call new 

### Prototype
- We want to copy an object, we could create a new one and copy the values but what if there are private members
- So we let our object have a clone function that creates a copy of itself, we have access to our own members 

### Singleton 
- Ensure a class has only one instance in the whole program 
- We need to handle this carefully for threads 
- Make constructor private and static, if we try to construct the object just pass the reference of the object 

## Structural Patterns 

### Adapter 
- Adapt object so another can understand it 
- Say we have a RoundHole and RoundPeg, we can insert() the peg into the hole if the radius match, but now we have a SquarePeg
- We create an adapter for the square peg, SqaurePegAdapter extends the SquarePeg but the insert() is special, it calculates if the SquarePeg can fit into a RoundHole 

### Bridge 
- Split a large class or set of related classes into two hiearchies, abstraction and implementation, which are developed independently 
- Bridge is like composition, say we have Shape objects Sphere and Cube, we want to add color so we could do BlueCube, BlueSphere...
- This clearly is not extensible and grows exponentially 
- Instead we can let shapes have a color, this is HAS-A relation, inheritance is more of a IS-A
- So the Shape gets a reference to a Color object, any color related work goes to that object, this is the bridge between the two 

### Composite 
- Compose object into tree structure, then work on these structures individually 
- Must have a tree like structure 
- Say we have a Box that contains Products, sometimes we have nesting, but there is always a hiearchy
- If we want the price of the box we ask it, then it asks the Box and Product within it, it goes down the chain and then back up 
- Another analogy is the military, the highest order officer gives an order and it is passed down to lower officers until it reaches the soldiers 

### Decorator 
- Attach new behaviors by placing an object in a special wrapper that has them 
- Avoids deep nested inheritance and keeps original functionality working 
- Say we have a Data object, we then have FileData object that implements its write() and read() data functions 
- Our decorator extends the FileData, keeping the original write and read methods 
- Our new object EncryptData implements the write() method but encrypts the data then passes it to the wrappee which calls the og write() from the FileData method, allowing us to write encrypted data into a file !

### Facade 
- Provide simple interface for compelx code 
- For example a StartCar object has start(), but this can envoke more complex objects functionality like Engine, Battery, Transmission, Radio, Lights, etc. 

### Flyweight 
- Fit more objects into RAM by sharing common parts between multiple objects 
- Intrinsic state is constant data that lives in object, other objects can read it but no change 
    - the intrinsic state: the fields that contain unchanging data duplicated across many objects
- Extrinsic state is data that can be altered by other objects 
    - the extrinsic state: the fields that contain contextual data unique to each object
- We should let the extrinsic state be passed to specific methods, not store it 
- A flyweight only contains intrinsic state ! 
- An example is say we have a Bullet, we can contain it's speed and location but also it's color and vector 
- If we made a lot of these objects it takes up a lot of space, so we separate the members 
- We have a single BulletParticle which contrains intrinsics like color and sprite
- Now MovingBulletParticles can just reference the BulletParticle, so each moving bullet does not contain it's own sprite, saving tons of space !

### Proxy 
- Placeholder for another object, controls access to it, allows us to perform something before or after a request gets to original object 
- Say we have a Database and a whole bunch of Clients, we don't want them to access the Database all at once, 
- Create a proxy like DBProxy which has the same services as the Database, but this proxy can handle the user requests before actually making a real request to the Database 

## Behavioral Patterns 

### Chain of Responsibility
- Pass request along chain of handlers, they can decide whether to process or pass it on, 
- Consider a CustomerService, you need help so you call, first you have to talk to an AutomatedService, then a BasicServiceRep, before finally a AdvancedServiceRep 
- Requests that are passed in a chain like a sequence or even a tree branch is CoR 
- As long as request is handled by each step individually, if there is an issue the request will not reach those farther levels 

### Iterator 
- Traverse collection without exposing its underlying representation 
- For example a Tree object, how can we traverse the nodes, we can make iterators to do that 
- LevelOrderIterator, InOrderItr, PreOrderItr, PostOrderItr, these iterator patterns give us the nodes without needing to know the tree structure 

### Memento 
- Save and restore previous state of object without revealing details of implementation 
- Say we have a Text object, we saved its state but after a while we realized our edits were wrong and needed to revert, we need an undo
- The Originiator object can have a method to save a Memento, the Memento should be immutable and data passed when created in it's constructor 
- We finally have a Caretaker object, it knows "when" and "why" we capture the og state, it is responsible for when the state should be restored 
- We can save Mementos i.e. previous states in a stack, allowing for easy reversal 

### State 
- Let object alter behavior when its internal state changes, appearing as if object changed class
- For example a state machine with switch statements to change which stage a document is in like draft, moderation, and publish
- This is hard to extend and can get complicated quickly 
- Consider an AudioPlayer, its State contains methods like click_play() or click_next(), we can extend this into a LockedState, ReadyState, and PlayingState for our player 
- If we click play in locked state nothing happens, versus if we click play in the ready state it starts the music, versus if we are in playing state click play stops the music currently playing 
- Any time we are in a state that may envoke another we create a new state i.e. clicking play in ready state not only starts music but it creates a new ReadyState for us to use 
- The AudioPlayer contains a reference to its states 

### Template Method 
- Design skeleton of algorithm in superclass and subclass can override specific steps without changing structure 
- We can split up a function into multiple methods if many classes use the same steps and just need a slight difference 
- Take a DataProcessor, it can open_file(), extract_data(), parse_data(), analyze_data(), send_report(), and close_file()
- A CSVProcessor and PDFProcessor both use open, send report, and close, but they can implement extract, parse, and anaylze themselves 

### Command 
- Turn a request into a stand alone object that contains info about the request, 
- Lets us pass request as method arguments, delay or queue execution, and support undoable operations 
- We have a Command that has execute(), then our Application can use that command and simply call execute, 
- We create CopyCommand, PasteCommand, UndoCommand, all extend Command and implement their own execute
- Now whenever a user does a action that command is put in a queue for example and the App can execute it easily 

### Mediator 
- Restrict communication between objects, forcing them to collaborate via a mediator object 
- Airport control tower is a mediator for all the aircraft in the air, the aircraft don't talk to eachother as that would be crazy, the control tower helps coordinate everyone 

### Observer 
- Subscribe mechanism to notify many objects about events that occur to the object they're observing 
- Say we have a YouTube Channel, we can notify() all Users on the platform when we upload a new video but some people don't like your content 
- Instead Users can subscribe to your Channel and these specific users will be notified when you upload rather than everyone 

### Strategy 
- Define family of algorithms, put them into separate classes, and make objects interchangeable 
- Say we have a Strategy to perform some mathematical operation between two numbers, the Strategy has an execute()
- We create AddStrat, SubtractStrat, MultiplyStrat, which perform the respective operation on the two numbers 
- At runtime we can decide which strategy we want to use! 
- Difference between command pattern? 
    - You can use Command to convert any operation into an object. The operation’s parameters become fields of that object. The conversion lets you defer execution of the operation, queue it, store the history of commands, send commands to remote services, etc.
    - On the other hand, Strategy usually describes different ways of doing the same thing, letting you swap these algorithms within a single context class.

### Visitor 
- Separate algorithms from the objects on which they operate 
- Say we have a City network of Industry, Restaurants, and Retail businesses, we want to get data from each place and save it to a file
- We could modify each object to have a save data function, but what if later we need the data saved in a different format? 
- Here we use a vistior, each class has a method to accept_visitor(Visitor v) and we can just v.do_for_industry(this)
- Maybe we have a CSV_Visitor which when called it saves data from the business into a CSV, later we get a PDF_Visitor, which saves data into PDF, 
- We only have to add one function to each business object in the City, and it is extensible by just making more visitors 
