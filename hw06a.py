#!/usr/bin/python3

from scipy.optimize import brentq
import numpy as np
import matplotlib.pyplot as plt


def constants(Si, Ge, GeAs):
    """ constants """

    # Constants for Si
    B = 1.08e-16  # K^-3cm^-6
    Eg = 1.12  # eV
    k = 8.617e-5  # eV/K
    Si = B, Eg, k

    # Constants for Ge
    B_Ge = 7.6e18  # K^-3cm^-6
    Eg_Ge = 0.66  # eV
    k_Ge = 8.617e-5  # eV/K
    Ge = B_Ge, Eg_Ge, k_Ge


    # Constants for GeAs
    B_GeAs = 8.4e18  # K^-3cm^-6
    Eg_GeAs = 1.52  # eV
    k_GeAs = 8.617e-5  # eV/K
    GeAS = B_GeAs, Eg_GeAs, k_GeAs

    return Si, Ge, GeAS


# def function(T):
#
#     function_T = ni ** 2 - B_ * (T ** 3) * np.exp(-Eg_ / (2 * k_ * T))
#     return function_T


def FindT(ni, min, max, element):
    """ returns the corresponding value for T """

    # a.
    # includes optional arguments min and max to limit the search space for the solution T.
    # Min should default to 1 and max to 1000

    # Optional Argument element is either "Si" "Ge" or "GeAs". It should default to "Si" and choose
    # the correct constants based on its value

    # If no solution is found it should raise a ValueError exception
    constants(Si, Ge, GeAs)

    if element == "Si":
        return Si

    elif element == "Ge":
        return Ge

    elif element == "Si":
        return GeAs

    else:
        raise ValueError("invalid element")

    ni = ni ** 2 - B_ * (T ** 3) * np.exp(-Eg_ / (2 * k_ * T))

    try:
        T = brentq(ni, min, max)
    except ValueError:
        raise ValueError("No solution found")

    return T

    # if element == "Si":
    #     B_ = B
    #     Eg_ = Eg
    #     k_ = k
    # elif element == "Ge":
    #     B_ = B_Ge
    #     Eg_ = Eg_Ge
    #     k_ = k_Ge
    # elif element == "GeAs":
    #     B_ = B_GeAs
    #     Eg_ = Eg_GeAs
    #     k_ = k_GeAs
    # else:
    #     raise ValueError("Invalid element")


# b.

def main():
    """takes ni min max element as command line arguments and prints the value for T as "T={:.2e}" """

    x = scipy.optimize.brentq(f, np.pi,
                              np.pi * 2)  # gives me what function to optimize, where to start and where to stop
    print(x)

    # Call it from the command line for example:
    # 1. ./hw06a.py 10e10 100 400 Si

    # min, max and element are optional and should only be used if provided.

    # if it fails it should print "No Solution", an explanation of what went wrong and return -1


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
