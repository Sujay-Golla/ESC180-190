def word_segmentation(s, word_dict):
    n = len(s)
    OPT = [False] * (n + 1)
    OPT[0] = True

    for i in range(1, n + 1):
        for j in range(i):
            if OPT[j] and s[j:i] in word_dict:
                OPT[i] = True
                break

    return OPT[n]

s = "applepenapple"
word_dict = {"apple", "pen"}
print(word_segmentation(s, word_dict))

s = "catsandog"
word_dict = {"cats", "dog", "sand", "and", "cat"}
print(word_segmentation(s, word_dict))