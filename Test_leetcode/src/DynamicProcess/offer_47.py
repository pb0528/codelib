def max_price_for_gift(lst,row,col):
    # length = row*col
    result = [[0 for y in range(col)]for x in range(row)]
    for r_index in range(0,row):
        for c_index in range(0,col):
            left,up = 0,0
            if r_index >= 1:
                left = result[r_index-1][c_index]
            if c_index >= 1:
                up = result[r_index][c_index-1]
            result[r_index][c_index] = max(left,up) + lst[r_index][c_index]

    return result[row-1][col-1]


if __name__ == '__main__':
    matrix = [[1,10,3,8],[12,2,9,6],[5,7,4,11],[3,7,16,5]]
    print(max_price_for_gift(matrix,4,4))

