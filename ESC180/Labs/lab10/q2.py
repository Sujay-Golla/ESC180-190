# sum = n%10 + sum(n//10)

def sum_digits(n):
    if n == 0:
        return 0
    return n%10 + sum_digits(n//10)

# Part 2?

def times(a,b):
    if b == 0:
        return 0
    return a + times(a, b-1)



# Testing
print(sum_digits(12345))
print(times(3, 5))