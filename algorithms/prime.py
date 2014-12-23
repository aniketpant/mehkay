""" Find all primes between anything to anything """

import math as math

primes = []

for i in range(2, 10000):
  flag = 1
  for j in range(0, len(primes)):
    if (primes[j] > math.sqrt(i)):
      break
    elif (i % primes[j] == 0):
      flag = 0
      break
  if flag is 1:
    primes.append(i)

for i in range(0, len(primes)):
  print primes[i]
