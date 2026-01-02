#Q1 a)
def dict_to_str(d):
    """Return a str containing each key and value in dict d. Keys and
    values are separated by a comma. Key-value pairs are separated
    by a newline character from each other.
    For example, dict_to_str({1:2, 5:6}) should return "1, 2\n5, 6".
    (the order of the key-value pairs doesn’t matter and can be different
    every time).
    """
    for key, value in d.items():
        print(key,",", value)

#Q1 b)
def dict_to_str_sorted(d):
    """Return a str containing each key and value in dict d. Keys and
    values are separated by a comma. Key-value pairs are separated
    by a newline character from each other, and are sorted in
    ascending order by key.
    For example, dict_to_str_sorted({1:2, 0:3, 10:5}) should
    return "0, 3\n1, 2\n10, 5". The keys in the string must be sorted
    in ascending order."""
    keys = list(d.keys())
    keys.sort()
    for k in keys:
        print(k, ",", d[k])

dict_to_str({1:2, 5:6, 3:4})
dict_to_str_sorted({1:2, 5:6, 3:4})