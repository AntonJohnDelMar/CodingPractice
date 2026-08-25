# Import libraries 
from collections import deque, defaultdict 


messages = [ 
    "LiDAR", 
    "Camera",
    "LiDAR",
    "LiDAR", 
    "GPS",
    "Camera",
    "Camera", 
    "IMU", 
]; 

def first_unique(messages): 
    seen_list = {}; 
    unique_list = {}; 

    for message in messages: 
        if message not in seen_list: 
            seen_list[message] = True; 
            unique_list[message] = True; 

        else: 
            if message in unique_list: 
                unique_list.pop(message); 
            else: 
                continue; 

    for sensor in unique_list: 
        return sensor; 

    return None; 

dictionary = {
    "dog": 3, 
    "cat": 2, 
    "hat": 1, 
}

dict_sorted = sorted(dictionary, key = lambda x : x[1]); 

print(f"Sorted dictionary: {dict_sorted}"); 

