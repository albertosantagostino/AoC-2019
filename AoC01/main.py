# !/usr/bin/env python
# -*- coding: utf-8 -*-

# Alberto Santagostino
# https://adventofcode.com/2019/day/1

import math

def compute_needed_fuel(mass):
    return math.floor(float(mass)/3)-2

def main():
    # Read file
    with open("input.txt", 'r') as f:
        lineList = f.readlines()

    # Part 1
    out = 0
    for el in lineList:
        out = out + compute_needed_fuel(el)
    print(f"The solution of the first part is {out}")

    # Part 2
    out = 0
    for el1 in lineList:
        fuel = []
        fuel.append(curr := compute_needed_fuel(el1))
        while curr > 0:
            curr = compute_needed_fuel(curr)
            if curr > 0:
                fuel.append(curr)
        for el2 in fuel:
            out = out + el2

    print(f"The solution of the second part is {out}")
    return

if __name__ == "__main__":
    main()
