#!/usr/bin/python3

import sympy as sym

import numpy as np


# class example Part B
def solve(Kn, VDD, Vg, Vtn, LAM):
    """ logic """



def main():
    """ main """

    VDD = 5
    Vtn = 1
    LAM = 0.1
    Kn = 1e-3
    Vg = 0

    Id, Vo, Vs = sym.symbols("Id Vo Vd")

    s = sym.solve((
        Kn * (VDD - Vo - Vtn) ** 2 * (1 + LAM * (VDD - Vo)) - Id,
        Kn * (Vg - Vs - Vtn) ** 2 * (1 + LAM * (Vo - Vs)) - Id,
        Kn * (Vs - Vtn) ** 2 * (1 + LAM * Vs) - Id),
        (Id, Vo, Vs)
    )

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
