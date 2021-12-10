import numpy as np
import matplotlib.pyplot as plt

data =np.loadtxt("numbers.txt").T

x = data[0]
t = data[-1]

plt.plot(t, x)
plt.show()