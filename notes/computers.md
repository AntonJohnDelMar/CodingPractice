# Computer Notes 


## Computer Architecture 

### Operating Systems 
- Main role handles applications and resources 
- Users interact with GUI or command lines 
- Run applications and processes simultaneously 

### Kernels 
- Main role is to handle processes, memory, and hardware directly, 
    - It is the only one who touches hardware like CPU, disk, memory, devices
    - Monolithic, microkernel, hybrids 
- Take care of task schedules, prioritization, multitasking 

### Program 
- We can execute program via GUI or cli, OS generates process to execute program
- Program can have several processes 
- Creates process instructions 

### Process 
- Program code loaded into memory to be executed by CPU 
- They get allotted memory space to use, one process cannot access anothers 
    - If one fails the others keep running, ex. chrome tabs 
- Code segment, data segment, heap, stack, registers, 

### Thread 
- Thread is unit of execution within a process, one misbehaved thread can kill a process 
- Have shared resources in a process, like heap or code, 
- Physical core is hardware i.e. four core processor, logical is related to how cores are working, so four core with 2 threads each is 8 logical cores 
- Think of a core as a worker, the thread is sequences of commands given to the core, 
    - If one thread is taking long then the worker works on another thread 


## Cloud Services 

### On Premise 
- Physical computers in your building, 
- Buy server but you have to install, service, etc., this is expensive and not very scalable, 

### Cloud Computing 
- Some company offers their computers for you to use, data centers, 
- Pay as you go, low maintenance, very scalable, cloud provider takes care of things related to the computers, good security 
- Data centers have racks of servers
    - Virtualization: server run virtual machines with their own resources, OS, and network, 
- Cloud Providers: Amazon Web Services (AWS), Microsft Azure, Google Cloud 
- Private Clouds: Organization owns all tools 
- Public Clouds: Company that offers tools to public 
    - Infrastructure as a Service (IaaS)
        - User control applications, OS, hardware 
    - Software as a Service (SaaS) 
        - User control application 
        - Provider controls OS and hardware 
        - You have access to application over the internet, you do not have access to behind the scenes 
        - You don't worry about install, maintenance, or backened infrastructure behind the app 
    - Platform as a Service (PaaS) 
        - User controls application 
        - Procider controls OS and hardware 
        - Provides platform for devs to build deploy and maintain apps, 
        - Difference between IaaS and PaaS is focus on dev tools and configs 
