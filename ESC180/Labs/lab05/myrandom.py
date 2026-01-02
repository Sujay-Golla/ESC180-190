def initialize():
    global a, b, c, cur, my_max
    a = 1238912378978923498394
    b = 12384982837423894789
    cur = 1
    my_max = 100000
def next_cur():
    global cur
    cur = (cur * a % b)
    return cur % my_max
def myrandom():
    return next_cur()/my_max

initialize()
if __name__ == "__main__":
    print(myrandom())
