import math

def pi(x, best_approx):
    res = 0
    counter = 0
    while round(res*4*(10**(x-1))) != best_approx:
        res += ((-1)**counter) / (2*counter + 1)
        counter += 1
    print(res*4, counter, best_approx, round(res*4*(10**(x-1))))


if __name__ == "__main__":
    x = 3
    best_approx = round(math.pi*(10**(x-1)))
    pi(x, best_approx)