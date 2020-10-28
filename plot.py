import numpy as np
import matplotlib.pyplot as plt

cNrange=[10, 20, 50, 100, 250]
cSrange=[10, 20, 50, 100]
cPrange=[10, 20, 50, 100, 250]
MSrange=[10, 20, 30, 50, 100]
MPrange=[10, 20, 30, 50, 100]

for cN in cNrange:
    for cS in cSrange:
        for cP in cPrange:
            for MS in MSrange:
                for MP in MPrange:
                    filenamex="./data/xdata_cN="+str(cN)+"_cS="+str(cS)+"_cP="+str(cP)+"_MS="+str(MS)+"_MP="+str(MP)+".txt"
                    filenamey="./data/ydata_cN="+str(cN)+"_cS="+str(cS)+"_cP="+str(cP)+"_MS="+str(MS)+"_MP="+str(MP)+".txt"
                    plotname="./fig/cN="+str(cN)+"_cS="+str(cS)+"_cP="+str(cP)+"_MS="+str(MS)+"_MP="+str(MP)+".pdf"
                    x = np.loadtxt(filenamex,delimiter=";")
                    y = np.loadtxt(filenamey,delimiter=";")
                    
                    N=15
                    fig = plt.figure(figsize=(25,10))
                    ax = fig.add_subplot()
                    for i in range(0,N):
                        ax.add_artist(plt.Circle((x[i],y[i]),7))
                    plt.xlim([0,250])
                    plt.ylim([0,100])
                    plt.savefig(plotname)
                    plt.close()
