def make_dict(file_name):
    text = open(file_name).read().split()
    dict = {}

    for word in text:
        added = False
        for key, value in dict.items():
            if key == word:
                dict[key] += 1
                added = True
        if not added:
            dict[word] = 1

    return dict

def top10(L):
    L.sort()
    return L[90:]

def top10words(dict):
    L = dict.items()
    new_L = []
    for i in L:
        j = list(i)
        j[0], j[1] = j[1], j[0]
        k = tuple(j)
        new_L.append(k)

    return sorted(new_L)[-10:]

# Part A
print(make_dict("text.txt"))

# Part B
L = []
for i in range(100,0,-1):
    L.append(i)
print(top10(L))

# Part C
freq = make_dict("1342-0.txt")
print(top10words(freq))

