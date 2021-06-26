import xlrd as ex_reader

print("start reading excel!")
data = ex_reader.open_workbook('E:/C++/workspace/codelib/Python/参会注册表.xlsx') 
table = data.sheets()[0]                   
rows1 = table.nrows   #表一行数


data2 = ex_reader.open_workbook('E:/C++/workspace/codelib/Python/磁悬浮相关领域专家学者.xlsx')
table2 = data2.sheets()[0]
row2 = table2.nrows   #表二行数


name = table.col_values(1, 1, rows1)
name2 = table2.col_values(1, 1, row2)

result = [x for x in name2 if x not in name]


print(result)
print(len(result))
with open("result.txt","w") as f:
    f.write("the lenth of result is" + str(len(result)))
    for line in result:
        f.write(line+'\n')
f.close()