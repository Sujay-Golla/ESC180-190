# x^n = x * x^(n-1)

def power(x, n):
    if n == 1:
        return x

    return x * power(x, n-1)

print(power(3, 2))

# power(3, 1)
#               \
#               / 3
# power(3, 2)
#               \
#                \ 3 * 3