import random
import math

#ZAD 1
print('ZAD1'.center(20,'*'))

import time
import sys

powt=1000
N=10000

def forStatement():
    #A
    #list_N =[]
    #for i in range(N):
    #    list_N.append(i)

    #B
    #list_N =[]
    #for i in range(N):
    #    list_N.append(i**2)

    #C
    #list_N =[]
    #for i in range(N):
    #    list_N.append(i**2)
    #my_sum = 0
    #for i in list_N:
    #    my_sum+=i

    #D
    #list_N =[]
    #for i in range(N):
    #    list_N.append(i**2)
    #sum(list_N)

    return 0

def listComprehension():
    #A
    #list_N = [i for i in range(N)]

    #B
    #list_N = [i**2 for i in range(N)]

    #C
    #list_N = [i**2 for i in range(N)]
    #my_sum = 0
    #for i in list_N:
    #    my_sum+=i

    #D
    #list_N = [i**2 for i in range(N)]
    #sum(list_N)

    return 0


def mapFunction():
    #A
    #list_N = []
    #map(lambda x: list_N.append(x) ,range(N))

    #B
    #list_N = []
    #map(lambda x: list_N.append(x**2) ,range(N))

    #C
    #list_N = []
    #map(lambda x: list_N.append(x**2) ,range(N))
    #my_sum = 0
    #for i in list_N:
    #    my_sum+=i

    #D
    #list_N = []
    #map(lambda x: list_N.append(x**2) ,range(N))
    #sum(list_N)

    #E
    #list_N = []
    #list(map(lambda x: list_N.append(x**2) ,range(N)))

    return 0


def generatorExpression():
    #A
    #list_N = (i for i in range(N))
    
    #B
    #list_N = (i**2 for i in range(N))

    #C
    #list_N = (i**2 for i in range(N))
    #my_sum = 0
    #for i in list_N:
    #    my_sum+=i
    
    #D
    #list_N = (i**2 for i in range(N))
    #sum(list_N)
    
    #E
    #list_N = list((i**2 for i in range(N)))

    return 0

def tester(test_f):
    t1 = time.time_ns()
    for _ in range(powt):
        test_f()
    t2 = time.time_ns()
    return t2-t1

print(sys.version)
test=(forStatement, listComprehension, mapFunction, generatorExpression)
for testFunction in test:
    print(testFunction.__name__.ljust(20), '=>', tester(testFunction))

print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

dlg = 100000
print(4 * len(list(filter(lambda x: math.hypot(x[0],x[1]) < 1, ((random.uniform(-1,1), random.uniform(-1,1)) for _ in range(dlg))))) / dlg)

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

def fun3(list_x, list_y):
    x_sr = sum(list_x)/len(list_x)
    y_sr = sum(list_y)/len(list_y)
    D=sum((i - x_sr)**2 for i in list_x)
    a=sum(map(lambda x, y: y*(x-x_sr), list_x, list_y))/D
    b=y_sr - a*x_sr
    y_delta = math.sqrt(sum(map(lambda x, y: (y-(a*x+b))**2, list_x, list_y)) / (len(list_x) -2))
    a_delta = y_delta / math.sqrt(D)
    b_delta = y_delta * math.sqrt(1/len(list_x) + x_sr**2/D)
    return a, b, a_delta, b_delta

a, b, a_delta, b_delta= fun3([1,2,3], [1,2,3])
print(a, b, a_delta, b_delta)

print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))

def myreduce(function, sequence):
    a=function(sequence[0],sequence[1])
    for i in range(2, len(sequence)):
        a=function(a, sequence[i])
    return a

print(myreduce(lambda x,y: x*y, [1,2,3,4,5]))
print(myreduce(lambda x,y: x+y, [1,2,3,4,5,6,7]))

print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

matrix = [[random.randint(0,10) for _ in range(4)] for _ in range(4)]
print(matrix)
#A
print(list(map(lambda x: max(x), matrix)))
#B
print(list(map(lambda x: max(x), zip(*matrix))))
#C
print([list(map(lambda x: sum(x), zip(matrix[i], matrix[i]))) for i in range(len(matrix))])

print('\n')