# a) General formula: OPT(n) = min(OPT(n - c_i) + 1) for all c_i in coins

# b)
def min_coins_with_recovery(denominations, amount):
    OPT = [float('inf')] * (amount + 1)
    OPT[0] = 0

    for v in range(1, amount + 1):
        for d in denominations:
            if d <= v and OPT[v - d] + 1 < OPT[v]:
                OPT[v] = OPT[v - d] + 1

    # Recover the coins similar to Houses painting problem
    coins = []
    v = amount
    while v > 0:
        for d in denominations:
            if d <= v and OPT[v - d] + 1 == OPT[v]:
                coins.append(d)
                v -= d
                break

    return coins


print(min_coins_with_recovery([1, 4, 5, 10], 8))   # [4, 4]