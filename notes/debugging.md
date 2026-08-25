# Debugging Notes 


## Debug / Check Usage 
- "top", tells you the CPU usage of processes 
    - While in top press "k" to kill process 
    - MiB Mem: tells you total memory and how much is free / used, cache 
    - MiB Swap: memory on hardrive, can indicate RAM usage 
    - Important info to look at: 
        - "up _ min", up time 
        - "# id", idle, higher number means less work system is doing 
        - "MiB Swap", if used to much something may be saturating memory, you probably don't want it to be spiking 
    - "# us, # sy", tells us user and system time usage of CPU 
        - Time CPU spends excuting user level code and system level code like syscalls 
        - Ex. (user) program spends 10s running loop in code vs (system) program spends 2s waiting for data to be loaded from disk by OS 
- "vmstat 1", tells you info every 1 second, can change 1 
    - r: processes being run, r > cpu's is bad it says cpu is saturated 
    - tells us overview of memory, using swap means we may have used all memory 
- "mpystat -P ALL 1", time breakdowns for CPU 
    - single hot CPU means one process may be doing too much 
- "iostat -x 1"
    - Disk usage > %60 may be bad, accessing (read/write) to disk is expensive 
- "sar -n DEV 1" 
    - Network I/O
- "strace", powerful tool to check system calls, be careful when using it 
    - "ls" tells us which system call we can trace 
    - "-c ls", command whose system call is traced 
    - "-e trace=write ls", trace specific calls like write or read, check ls to see which specifcs you can check 
    - "-r ls" prints timestamp of each call 
    - "-T ls", time spent on sys call 
- "pidstat 1", check if lots of system time is being used 
- "perf" 
    - "list", list all currently known events 
    - "record -F 99 _", 99Hz sample of CPU functions for specific _ commands 

