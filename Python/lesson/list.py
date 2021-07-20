def main():
    fruits = ['grape', 'apple', 'strawbery', 'waxberry']
    fruits += ['pitaya', 'pear']
    # 循环遍历列表元素
    for iterm in fruits:
        print(iterm.title(), end='')
    print()

    #列表切片
    fruits1 = fruits[1:4]
    print(fruits1)


def reduces():
    #用range 生成列表
    list1 = list(range(1,11))
    print(list1)

    # 生成表达式
    list2 = [x * x for x in range(1,11)]
    print(list2)

    

if __name__ == '__main__':
    main()