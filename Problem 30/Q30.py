'''
By: Andrew Storus
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
https://projecteuler.net/problem=30

where n is the number of digits

6*9^5 is chosen because the maximum value that can be checked is of 6 digits length, and the max value
that the value of the sums of those 6 digits raised to the 5th power can be is if they are all 9 (ie 9^5 is the maximal value for a single digit)

'''

table = []

for i in range(10):
    table.append(i**5)


i = 2
sum = 0
val = 0

while i < 6*9**5:
    digits = str(i)

    for j in digits:
        val += table[int(j)]

    if val == i:
        sum += val

    i += 1
    val = 0

print "Sum: " + str(sum)
