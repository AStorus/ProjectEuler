#By Andrew Storus

coinVals = [1,2,5,10,20,50,100,200]
#Create 2D list of size 8 by 201
combos = [[0 for i in range(201)] for i in range(len(coinVals))]

#column (y) represents a target value to make
#row (x) represents which coins are available

#for a target value of n with only a 1p available, there will only be one possible way to make that combination
combos[0] = [1 for i in combos[0]]

#otherwise, the number of ways to make that amount is equal to the number of ways using one less coin type
#plus the number of times the new coin value can be subtracted from the target value while still leaving a non negative difference.
for x in range(1, len(combos)):
    for y, numCombos in enumerate(combos[x]):
        combos[x][y] = combos[x - 1][y] + combos[x][y - coinVals[x]]
'''
for c, row in enumerate(combos):
    print "coin value " + str(coinVals[c]).ljust(4) + " " + str(row)
'''
print "\nNumber of combinations for 200p: " + str(combos[len(coinVals) - 1][len(combos[0]) - 1])





