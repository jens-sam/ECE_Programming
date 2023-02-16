#!/usr/bin/python3
# final/working
import sys
import sympy as sym
import numpy as np


# class example Part B
def solve(Kn, VDD, Vg, Vtn=1.0, LAM=0.0):
    """ logic """

    Id, Vo, Vs = sym.symbols("Id Vo Vd")

    s = sym.solve((
        Kn * (VDD - Vo - Vtn) ** 2 * (1 + LAM * (VDD - Vo)) - Id,
        Kn * (Vg - Vs - Vtn) ** 2 * (1 + LAM * (Vo - Vs)) - Id,
        Kn * (Vs - Vtn) ** 2 * (1 + LAM * Vs) - Id),
        (Id, Vo, Vs)
    )

    # TODO: test against possible imaginary numbers
    for tup in s:
        Id = float(sym.re(tup[0]))
        Vo = float(sym.re(tup[1]))
        Vs = float(sym.re(tup[2]))

        if Id > 0 and 0 < Vo < VDD and 0 < Vs < VDD:
            return Id, Vo, Vs  # returning tuple of Id, Vo, Vs

    raise ValueError("No solution found")


def main():
    """ main """

    if len(sys.argv) != 6:
        print("needs 6 arguments")

    Kn = float(sys.argv[1])
    VDD = float(sys.argv[2])
    Vg = float(sys.argv[3])
    Vtn = float(sys.argv[4])
    LAM = float(sys.argv[5])

    try:
        sol_tup = solve(Kn, VDD, Vg, Vtn, LAM)
        Id = sol_tup[0]
        Vo = sol_tup[1]
        Vs = sol_tup[2]

    except ValueError:
        print("No solution found")
        return -1

    print("Id={:.2e} Vo={:.2e} Vs={:.2e}".format(Id, Vo, Vs))


if __name__ == "__main__":
    main()
