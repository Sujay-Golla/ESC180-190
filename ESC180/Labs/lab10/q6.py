# [1, 4, 5, 10, 12]
def zigzag(L):
    zigzag_i(L, len(L)//2)

def zigzag_i(L, s):
    if s == 0:
        print(L[len(L)//2], end=' ')
        return
    else:
        zigzag_i(L, s-1)
    print(L[len(L)//2 - s], L[len(L)//2 + s], end = " ")


L = [0,1,2,3,4]
zigzag(L)