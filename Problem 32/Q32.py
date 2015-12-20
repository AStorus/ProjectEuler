#By Andrew Storus

'''

only two situations for a 9 digit pandigital

multiplicand * multiplier = product

1 digit number * 4 digit number = 4 digit number
2 digit number * 3 digit number = 4 digit number

list all 4 digit number combinations
loop through them, divide them by all 1 digit numbers (1-9)
or divide them by all 2 digit numbers which produce a 3 digit number
check if the divisor, dividend, and quotient contain the digits 1-9

'''

import math
from itertools import permutations

def listToInt(l):
    total = 0
    multiplier = 1
    for i in l[::-1]:
        total += i * multiplier
        multiplier *= 10
    return total

def IntToList(i):
    i = int(i)
    l = []
    for j in range(len(str(i))):
        l = [i % 10] + l
        i = i / 10
    return l

def threeDigitMultipliers(candidates):
    for index, candidate in enumerate(candidates):
        ub = listToInt(candidates[index]) / 100
        lb = listToInt(candidates[index]) / 999

        if lb < 10:
            lb = 12

        for i in range(lb + 1, ub + 1):
            if i % 10 != 0:
                l = candidates[index]
                z = listToInt(candidates[index]) / float(i)

                if (z).is_integer() == True:
                    l = l + IntToList(z) + IntToList(i)
                    l.sort()
                    if l == [1, 2, 3, 4, 5, 6, 7, 8, 9]:
                        final.add(listToInt(candidate))

def fourDigitMultipliers(candidates):
    for index, candidate in enumerate(candidates):
        ub = 9
        lb = 1

        for i in range(lb, ub + 1):
            l = candidates[index]
            z = listToInt(candidates[index]) / float(i)
            if (z).is_integer() == True:

                l  = l + IntToList(z) + IntToList(i)
                l.sort()
                if l == [1, 2, 3, 4, 5, 6, 7, 8, 9]:
                    final.add(listToInt(candidate))




nums = [i for i in range(1,10)]
candidates = []

for i in permutations(nums, 4):
    candidates.append(list(i))

final = set()

threeDigitMultipliers(candidates)
fourDigitMultipliers(candidates)

total = 0
for f in final:
    print f
    total += f
print total