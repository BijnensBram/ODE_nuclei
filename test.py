import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("xdata_test3", delimiter=";")
y = np.loadtxt("ydata_test3", delimiter=";")

for i in range(0,len(x)):
    plt.scatter(x[i,:],y[i,:])
    plt.xlim([0,250])
    plt.ylim([0,50])
    plt.show()
