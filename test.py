import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("data/xdata_26.txt", delimiter=";")
y = np.loadtxt("data/ydata_26.txt", delimiter=";")

N=15
fig = plt.figure(figsize=(25,10))
ax = fig.add_subplot()
for i in range(0,N):
    ax.add_artist(plt.Circle((x[i],y[i]),7))
plt.xlim([0,250])
plt.ylim([0,100])
plt.savefig("250vs100_4.pdf")
plt.show()
