
def find_num_in_two_dimen(target,row,col,args):
    row_index,col_index = 0,col-1
    while (row_index<row) and (col_index >= 0):
        index = row_index*col+col_index
        if target == args[index]:
            return True
        elif target < args[index]:
            col_index -=1
        else:
            row_index +=1
    return False




if __name__ == '__main__':
    lis = [1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15]
    print(find_num_in_two_dimen(10,4,4,lis))
