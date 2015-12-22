#By Andrew Storus

from itertools import permutations
from fractions import Fraction

nums = [i for i in range(11,100)]

candidates = []

for c in permutations(nums, 2):
    if c[0] < c[1]:
        if c[0] % 10 != 0 and c[1] % 10 != 0:
            if str(c[0])[0] == str(c[1])[1] or str(c[0])[1] == str(c[1])[0]:
                if c[0]/float(c[1]) == float(str(c[0])[0]) / float(str(c[1])[1]) or c[0]/float(c[1]) == float(str(c[0])[1]) / float(str(c[1])[0]):
                    candidates.append(list(c))

num = 1
den = 1

for c in candidates:
    num *= c[0]
    den *= c[1]

print "the product is " + str(num) + "/" + str(den)

print "reduced form is " + str(Fraction(num/float(den)).limit_denominator())

