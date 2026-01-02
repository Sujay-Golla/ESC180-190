def split_list(L, elements):
    newL = []
    first = 0
    for i in range(len(L)):
        for j in elements:
            if L[i] == j:
                newL.append(L[first:i])
                first = i + 1
                break
    if first + 1 <= len(L):
        newL.append(L[first:])

    return newL

L = [1,2,6,4,5,3,7]
print(split_list(L, [3,6]))
