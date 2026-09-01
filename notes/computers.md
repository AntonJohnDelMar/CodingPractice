# Computer Notes 


## Computer Architecture 

### Operating Systems 
- Main role handles applications and resources 
- Users interact with GUI or command lines 
- Run applications and processes simultaneously 
- Multi-tasking OS, support many programs to be run at same time, think Window or MacOS, 
    - Run in parallel or concurrently, 
- Embedded OS, computer can perform limited range of functions that are surrounded by a larger system, usually read only, 
    - Ex: washing machine has embedded computer that performs the functions of the machine 
- Real Time OS, handle inputs in guaranteed response time, try to minimize response time, 
    - Used in safety critical tasks, like health care machines or plane autopilot, 
- Multi-user OS, used by many users at the same time, 
    - Needs to balance CPU between users, prevent conflicts between users, prevent accesssing other user data 
    - Think servers with many terminals that people use at same time, 
- Distributed OS, run same program across many computers, 
    - Split up program and combine results, 
    - Think cloud computing and big analytics, AWS or Azure, 



### Kernels 
- Main role is to handle processes, memory, and hardware directly, 
    - It is the only one who touches hardware like CPU, disk, memory, devices
    - Monolithic, microkernel, hybrids 
- Take care of task schedules, prioritization, multitasking 

## Applications 

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
- Race condition, two threads are accessing the same resource but keep changing it for the other one 
    - Ex: thread A writes a value for a variable then reads it but thread B writes to the variable before A causing a misread, 
- Deadlock, two threads are waiting on a resource the other is holding, 
    - Ex: thread A needs resource X and is holding resource Y but thread B needs resource Y and is holding resource X, they are stuck ! 

### Concurrency 
- OS execute many tasks at same time, allow process and threads to make progress independently if sharing same CPU 
    - Ex: web browsers loading many tabs at once, you can run many programs on your computer at same time like music downloads etc., in gaming we can handle graphics sound and user inputs together, 
- Better CPU utilization, no CPU idle as a process waits, faster response time so apps feel smoother, 
    - Resource sharing, many users and programs can share system resources efficiently 
    - Scalablility, multi core processors need concurrency for max performance 
- Principles of concurrency 
    - Mutual exclusion, only one process should access shared resource at a time, prevent race conditions, 
        - Ex: two people edit google doc, we need system to prevent conflicts 
    - Synchronization, processes coordinate ordering or interaction of concurrent tasks, helps to avoid race conditions, 
        - Ex: you can't withdraw money from ATM before logging in 
    - Deadlock handling, avoid situation where processes get stuck 
        - Ex: two threads need a resource that the other is holding, 
    - Fairness and progress, every process should have fair chance to execute, some tasks may be delegated more CPU time than others, 

### Scheduling 
- Assign jobs to resources, OS determines when different processes get access to the processor, 
- First come first serve, jobs are dispatched in the order they arrive, think like a queue, each jobs is carried out to completion, 
    - Simple fast implementation, long jobs can hold up shorter jobs,     
- Short jobs first, more jobs can be completed 
    - Can causes overhead determining an accurate estimate for run times 
    - Starvation, job is waiting indefintely as other jobs are prioritized over it, long jobs may suffer 
- Shortest remaining time, job with shortest execution time left is dispatched first, 
    - Job can be suspended if shorter job arrives, but suspended jobs need resgisters to be saved and reloaded 
    - More overhead in switching often, could have more risk of starvation, 
- Round robin, each job is allocated fixed time slice to carry out
    - If job didn't finish it is suspended and next job in queue goes 
    - Equal resource shared, all jobs are dispatched, some overhead switching between many jobs 
- Multi-level feedback queues, many different priority queues are created 
    - Jobs ordered by priority, each queue has different priority 
    - Can move jobs between queues as priorities change 
    - If job takes too long it can be demoted, if a job is waiting too long it can be promoted 
    - Overhead through determining priorities and moving jobs 
- Earliest deadline first, prioritiy queue where priority is determined by task deadline, 
    - Helps keep real time response by ensuring deadlines met 



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
