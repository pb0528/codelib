def count_max_status_of_num(target):
    length = len(target)
    lst = [0 for x in range(length)]

    for x in range(length-1,-1,-1):
        count = 0
        if x < length-1:
            count = lst[x+1]
        else:
            count = 1
        if x < length-1:
            digit1 = int(target[x]) - 0
            digit2 = int(target[x+1]) - 0
            convert = digit1*10 + digit2
            if convert >= 10 and convert <= 25:
                if x < length -2:
                    count += lst[x+2]
                else:
                    count += 1

        lst[x] = count
    return lst[0]

if __name__ == '__main__':
    #print(count_max_status_of_num(str(12258)))
    print(ord('A'))      
