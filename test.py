import numpy as np
import matplotlib.pyplot as plt

x,y = np.loadtxt("test.txt", delimiter=";",unpack=True)

plt.scatter(x,y)
plt.xlim([0,50e-6])
plt.ylim([0,50e-6])
plt.show()
