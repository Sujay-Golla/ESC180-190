def interleave(L1, L2):
    if len(L1) == 1:
        return [L1[0], L2[0]]
    L = [L1[0], L2[0]]
    L.extend(interleave(L1[1:], L2[1:]))
    return L

print(interleave([1, 2, 3, 4], [5, 6, 7, 8]))