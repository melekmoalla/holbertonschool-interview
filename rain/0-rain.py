#!/usr/bin/python3
"""
rain
"""

def rain(walls):
    if not walls or len(walls) < 3:
        return 0
    block = 0
    num = 0
    sum = 0
    stock = 0
    #print(walls)
    for i in walls:
        first_index = i
        #print(first_index , sum)
        if first_index == 0:
            if  block != 0:
                num += 1 
        else:
            if  block == 0:
                block = 1
            else:
                #print(first_index, stock)
                sum += min(first_index, stock) * num
                num = 0
            stock = first_index
    return sum