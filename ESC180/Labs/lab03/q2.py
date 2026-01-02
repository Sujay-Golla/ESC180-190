def pi():
    res = 0
    i = 0
    while i <= 1000:
        res += ((-1)**i) / (2*i + 1)
        i += 1
    print(res*4)

if __name__ == "__main__":
    pi()