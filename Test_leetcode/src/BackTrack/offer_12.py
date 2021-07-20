def has_core_path(char_map,row,col,r_index,c_index,s_tr,visited,length):
    if(length == len(s_tr)):
        return True
    is_in_path = False
    if r_index >= 0 and r_index < row and c_index >= 0 and c_index < col \
        and char_map[r_index*col+c_index] == s_tr[length] and (not visited[r_index*col+c_index]):
        length += 1
        visited[r_index*col+c_index] = True
        is_in_path = has_core_path(char_map,row,col,r_index-1,c_index,s_tr,visited,length)\
            or has_core_path(char_map,row,col,r_index+1,c_index,s_tr,visited,length)\
                or has_core_path(char_map,row,col,r_index,c_index-1,s_tr,visited,length)\
                    or has_core_path(char_map,row,col,r_index,c_index+1,s_tr,visited,length)
        
        if not is_in_path:
            length-=1
            visited[r_index*col+c_index] = False
        
    return is_in_path

def has_path(char_map,row,col,s_str):
    visited = [False for x in range(0,row*col)]
    length = 0
    for x in range(0,row):
        for y in range(0,col):
            if has_core_path(char_map,row,col,x,y,s_str,visited,length):
                return True
    
    return False

if __name__ == '__main__':
    lis = ['a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h']
    visited = [False for x in range(0,3*4)]

    #print(lis[0])
    print(has_path(lis,3,4,'bfce'))

