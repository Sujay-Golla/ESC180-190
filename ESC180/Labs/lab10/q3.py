# L = [1, 4, 12, 345]

def linear_search(L, e):
    if L[(len(L)-1)//2] == e:
        return (len(L)-1)//2
    elif L[(len(L)-1)//2] < e:
        return len(L)//2 + linear_search(L[len(L)//2:], e)
    else:
        return linear_search(L[:len(L)//2], e)

print(linear_search([1, 4, 12, 345, 1432], 12))
print(linear_search([1, 4, 12, 345, 1432], 4))
print(linear_search([1, 4, 12, 345, 1432], 1))
print(linear_search([1, 4, 12, 345, 1432], 345))
print(linear_search([1, 4, 12, 345, 1432], 1432))
