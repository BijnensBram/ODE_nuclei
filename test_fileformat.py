import numpy as np
import matplotlib.pyplot as plt

N=3 # Number of particles
D=2 # Number of dimensions of simulation

xmin=-1
xmax=3
ymin=-1
ymax=3

filename="test.txt"
data = np.loadtxt(filename, delimiter=";")
data_reshaped = data.reshape((-1,N,D)) # The -1 indicates take whatever fits

for i in range(0,len(data_reshaped)):
    for j in range(0,N):
        plt.scatter(data_reshaped[i,j,0],data_reshaped[i,j,1])

    plt.xlim([xmin, xmax])
    plt.ylim([ymin, ymax])
    plt.show()

