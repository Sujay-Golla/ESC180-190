def my_sqrt(x):
    global sqr
    sqr = x**.5
    return sqr
def my_print_sqr(x):
    print(x**2)
if __name__ == "__main__":
    res = my_sqrt(25)
    print(res)
    print(sqr)
    my_print_sqr(25)




# Part A: nothing prints as we assign res the value of the function but don't print it
# Part B: sqr is a local variable inside the function, so making it global can make it work
# Part C: None is the value when you print my_print_sqr(25)

