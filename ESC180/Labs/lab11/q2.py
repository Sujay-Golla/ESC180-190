# sum5(5, 6, 7, 8, 9) # ERROR: sum5 is not defined
def make_sum_fn(n):
    code_str = 'def sum' + str(n) + '('
    for i in range(n-1):
        code_str += chr(ord('a') + i) + ","
    code_str += chr(ord('a') + n-1) + "):\n"
    code_str += "\treturn "
    for i in range(n):
        code_str += chr(ord('a') + i) + "+"
    code_str += "0"
    return code_str

if __name__== '__main__':
    exec(make_sum_fn(5))
    print(sum5(5, 6, 7, 8, 9)) # prints 35 since sum5 is now defined!