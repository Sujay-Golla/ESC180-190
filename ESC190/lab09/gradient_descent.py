import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**5 - 7 * x**4 + 13 * x**3 + 5 * x**2 + - 48 * x + 20

def df(x):
    return 5 * x**4 - 28 * x**3 + 39 * x**2 + 10 * x - 48


alpha = [0.001, 0.005, 0.01, 0.015, 0.02, 0.03, 0.05]

for rate in alpha:
    x0 = 4
    x = x0
    i = 0
    isDiverging = False
    
    while i < 100000 and abs(df(x)) > 1e-4:
        x = x - rate * df(x)
        if abs(x) > 1e10:
            print("Divergence detected, stopping iteration.")
            isDiverging = True
            break
        i += 1
    
    if not isDiverging:
        print(f"Alpha: {rate:.3f} -> Minimum at x = {x:.6f}, f(x) = {f(x):.6f}, after {i} iterations")