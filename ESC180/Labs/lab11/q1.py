def all_combinations(n, alphabet, start_str = None):
    if n == 0:
        return [start_str]
    else:
        res = []
        if start_str == None:
            start_str = []
        for letter in alphabet:
            temp_start_str = start_str.copy()
            temp_start_str.append(letter)
            res += (all_combinations(n-1, alphabet, temp_start_str))
    return res

if __name__ == "__main__":
    print(all_combinations(2, [1,2,3]))