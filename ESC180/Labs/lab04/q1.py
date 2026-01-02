import numpy as np
import matplotlib.pyplot as plt
def plot_sin(a):
    x = np.linspace(0, 2 * np.pi, 100)
    y = np.sin(a * x)
    plt.plot(x, y)
    plt.show()
if __name__ == "__main__":
    plot_sin(2)