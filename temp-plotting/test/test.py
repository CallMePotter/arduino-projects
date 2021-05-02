import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2 * np.pi, 100)
y = np.sin(x)
z = np.cos(x)

plt.plot(x, y, 'b-', label = "y = sin(x)")
plt.plot(x, z, 'r-', label = "y = cos(x)")
plt.legend()
plt.grid(True)
plt.title("sin and cos waves")
plt.xlabel("x")
plt.ylabel("y")
plt.show()
