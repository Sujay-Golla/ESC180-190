# [1, 4, 5, 10, 12]
def reverse_rec(L):
    swap(L, 0, len(L)-1)
    return L


def swap(L, a, b):
    if a >= b:
        return
    else:
        swap(L, a+1, b-1)
    L[a], L[b] = L[b], L[a]

L = [1,4,5,10,12]
print(reverse_rec(L))