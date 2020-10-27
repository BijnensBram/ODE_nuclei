import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("xdata_test5", delimiter=";")
y = np.loadtxt("ydata_test5", delimiter=";")

for i in range(0,len(x)):
    plt.figure(figsize=(25,5))
    plt.scatter(x[i,:],y[i,:])
    plt.xlim([-10,260])
    plt.ylim([-10,60])
    plt.show()

# plt.figure(figsize=(25,5))
# plt.scatter(x[len(x)-1],y[len(x)-1])
# plt.xlim([0,250])
# plt.ylim([0,50])
# plt.show()
