import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("data/xdata_21.txt", delimiter=";")
y = np.loadtxt("data/ydata_21.txt", delimiter=";")

# for i in np.linspace(0,len(x)-1,100):
#     plt.figure(figsize=(25,5))
#     plt.scatter(x[int(i),:],y[int(i),:])
#     # plt.xlim([0,250])
#     plt.ylim([0,42])
#     plt.show()

plt.figure(figsize=(25,5))
plt.scatter(x,y,s=15)
plt.hlines(100,0,250,colors="black")
plt.hlines(0,0,250,colors="black")
plt.vlines(250,0,100,colors="black")
plt.vlines(0,0,100,colors="black")
# plt.xlim([0,250])
# plt.ylim([0,100])
plt.show()
