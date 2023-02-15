#!/usr/bin/python3

import sys
import sympy as sym

import numpy as np


# class example Part B
def solve(Kn, VDD, Vg, Vtn, LAM):
    """ logic """

    Id, Vo, Vs = sym.symbols("Id Vo Vd")

    s = sym.solve((
        Kn * (VDD - Vo - Vtn) ** 2 * (1 + LAM * (VDD - Vo)) - Id,
        Kn * (Vg - Vs - Vtn) ** 2 * (1 + LAM * (Vo - Vs)) - Id,
        Kn * (Vs - Vtn) ** 2 * (1 + LAM * Vs) - Id),
        (Id, Vo, Vs)
    )

    return s


def main():
    """ main """

    # len(sys.argv) = 4
    # file_name = sys.argv[0]
    # f = open(file_name)

    VDD = 5
    Vtn = 1
    LAM = 0.1
    Kn = 1e-3
    Vg = 0

    # Kn = None
    # VDD = str
    # Vtn = None
    # LAM = None
    # Vg = None
    Id, Vo, Vs = solve(Kn, VDD, Vg, Vtn, LAM)

    if len(sys.argv) > 5:
        Kn = sys.argv[1]
        VDD = sys.argv[2]
        Vg = sys.argv[3]
        Vtn = sys.argv[4]
        LAM = sys.argv[5]
    else:
        print("needs 6 arguments")

    good = False

    for v in s:
        Id = sym.re(v[0])
        Vo = sym.re(v[1])
        Vs = sym.re(v[2])

        if Id > 0 and 0 < Vo < VDD and 0 < Vs < VDD:
            good = True
            break

    if not good:
        raise ValueError("No solution found")

    print("Id={:.2e} Vo={:.2e} Vs={:.2e}".format(Id, Vo, Vs))


if __name__ == "__main__":
    main()
