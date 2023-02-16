#!/usr/bin/python3
import sys

from scipy.optimize import brentq
import numpy as np

# Constants for Si
B = 1.08e-16  # K^-3cm^-6
Eg = 1.12  # eV
k = 8.617e-5  # eV/K

# Constants for Ge
B_Ge = 7.6e18  # K^-3cm^-6
Eg_Ge = 0.66  # eV
k_Ge = 8.617e-5  # eV/K

# Constants for GeAs
B_GeAs = 8.4e18  # K^-3cm^-6
Eg_GeAs = 1.52  # eV
k_GeAs = 8.617e-5  # eV/K

CONST_DICT = {
    "Si": [B, Eg, k],
    "Ge": [B_Ge, Eg_Ge, k_Ge],
    "GeAs": [B_GeAs, Eg_GeAs, k_GeAs]
}


def f(T, ni, B_, Eg_):
    k_ = 8.62e-5
    return ni ** 2 - B_ * (T ** 3) * np.exp(-(Eg_ / (k_ * T)))


def FindT(ni, min_val=-1.0, max_val=1000.0, element="Si"):
    """ returns the corresponding value for T """
    constants = CONST_DICT[element]
    B_ = constants[0]
    Eg_ = constants[1]
    k_ = constants[2]



    # N^2 = B_T^3 * e^(- Eg_/kt)
    # N = sqrt(B_T^3 * e^(- Eg_/kt))
    # root_sc
    # T_solution = fsolve(f,[min_val,max_val],args=(ni,B_,Eg_,k_))  # solve for T with an initial guess of 300 K
    # print(T_solution[0])
    try:
        T = brentq(f, min_val, max_val, args=(ni, B_, Eg_))
        return T
    except ValueError:
        raise ValueError("No solution found")
    # return brentq(f, min_val, max_val)


# b.

def main():
    """takes ni min max element as command line arguments and prints the value for T as "T={:.2e}" """

    ni = float(sys.argv[1])
    min_val = float(sys.argv[2])
    max_val = float(sys.argv[3])
    element = sys.argv[4]

    try:
        T = FindT(ni, min_val, max_val, element)
    except ValueError:
        print("No solution found")
        return -1
    print("T={:.2e}".format(T))


if __name__ == "__main__":
    main()

# y = sin(x) * x-1
# x = np.linspace(0, np.pi*2, 1000)
# class 'numpy.ndarray'
#     plt.plot(x,y)
#
# plt.show()
#
# # class example
#
# def f(x):
#     return np.sin(x)*x-1-2
#
# def main():
#
#     x = scipy.optimize.brentq(f, np.pi, np.pi*2) # gives me what function to optimize, where to start and where to stop
#     print(x)
