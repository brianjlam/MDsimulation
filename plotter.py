import numpy as np
import matplotlib.pyplot as plt
import csv

def plotThermo(filename):
    K = []
    P = []
    U = []
    time = []
    with open(filename, 'rt') as f:
        reader = csv.reader(f)
        next(reader)
        next(reader)
        for row in reader:
            K.append(row[2])
            P.append(row[3])
            U.append(row[4])
            time.append(row[0])
    plt.plot(time, K, time, P, time, U)
    plt.axis([0,0.24,-40,400])
    plt.xlabel('Time')
    plt.ylabel('Energy')
    plt.title('Energy Plot for MD Simulation')
    plt.legend(['Kinetic Energy','Potential Energy','Total Energy'], loc='upper left')
    plt.show()
    plt.savefig("thermoplot.png")

plotThermo('thermolog.csv')
