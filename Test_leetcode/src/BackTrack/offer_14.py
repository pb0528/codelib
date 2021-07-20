#dynamic plan

def max_product_after_counting_solution1(length):
    if length<2 :
        return 0
    if length==2 :
        return 1
    if length==3 :
        return 2
    lst = [0,1,2,3]
    max_num = 0
    for x in range(4,length+1):
        max_num = 0
        for j in range(1,x//2+1):
            product = lst[j] * lst[x-j]
            max_num = max(max_num,product)
        
        lst.append(max_num)
    
    return lst[length]


if __name__ == '__main__':
    #print(max_product_after_counting_solution1(5))
    print(1<<1)