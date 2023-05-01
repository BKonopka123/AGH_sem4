import random
import math

#ZAD 1
print('ZAD1'.center(20,'*'))

def gen1():
    pascal=[1]
    while 1:
        yield pascal, sum(pascal)
        temp=[1]
        temp.extend(i+j for i, j in zip(pascal[:-1], pascal[1:]))
        temp.append(1)
        pascal=temp

a=gen1()
for _ in range(10):
    print(next(a))

print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

def gen2(seq):
    number=0
    for i in seq:
        if i==1:
            yield number
            number=0
            continue
        number+=1

N=20
zo = [random.randint(0,1) for _ in range(N)]
coile = [i for i in gen2(zo)]
del coile[0]
print(zo)
print(coile)
srednia=sum(coile)/len(coile)
print(srednia)

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

#A
def gen3a():
    number1 = 0
    number2 = 1
    fibbonaci = 0
    yield number2
    while 1:
        fibbonaci=number1+number2
        yield fibbonaci
        number1=number2
        number2=fibbonaci

#B
def gen3b(seq, podzielnosc='parzyste'):
    for i in seq:
        if podzielnosc == 'parzyste':
            if not i%2:
                yield i
        elif podzielnosc == 'nieparzyste':
            if i%2:
                yield i

#C
def gen3c(seq, maxwart):
    for i in seq:
        if i > maxwart:
            return 'za duza'
        yield i

tmp=gen3a()
list1 = []
for _ in range(20):
    list1.append(next(tmp))
list2 = [i for i in gen3b(list1)]
elempar = [i for i in gen3c(list2,100)]
list3 = [i for i in gen3b(list1, 'nieparzyste')]
elemnie = [i for i in gen3c(list3,100)]

print(elempar)
print(elemnie)
print(sum(elempar), sum(elemnie))

print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))

def gen4(*a):
    if len(a) == 1:
        start = 0
        stop = a[0]
        step = 1
    elif len(a) == 2:
        start = a[0]
        stop = a[1]
        step =1
    elif len(a) ==3:
        start = a[0]
        stop = a[1]
        step =a[2]
    if stop<0 or start>stop:
        step = -step
    if step>=0:
        while start<stop:
            yield start
            start+=step
    elif step<0:
        while start>stop:
            yield start
            start+=step

for i in gen4(7):
    print(i, end=' ')
print()
for i in gen4(-7):
    print(i, end=' ')
print()
for i in gen4(2,7):
    print(i, end=' ')
print()
for i in gen4(7,2):
    print(i, end=' ')
print()
for i in gen4(2,7,2):
    print(i, end=' ')
print()
for i in gen4(2,7,-2):
    print(i, end=' ')
print()
for i in gen4(7,2,2):
    print(i, end=' ')
print()
for i in gen4(7,2,-2):
    print(i, end=' ')
print()

print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

def gen5(N):
    while True:
        r=0
        l=0
        for i in range(N):
            p=random.randint(0,1)
            if p == 0:
                r+=1
            else:
                l+=1
        yield r-l

N=20
powt=1000000

result = {}
a=gen5(N)
for _ in range(powt):
    tmp=next(a)
    if tmp in result:
        result[tmp] += 1
    else:
        result[tmp] = 1
print(result)

def dwumian(a,b):
    return math.factorial(a) / (math.factorial(int(b)) * math.factorial(int(a-b)))

oczekiwany = {}
for i in range(-20,21,2):
    oczekiwany[i] = 1/pow(2,N) * dwumian(N, (i+N)/2) *1000000
print(oczekiwany)

import matplotlib.pyplot as plt
plt.plot(result.keys(), result.values(),'o')
plt.plot(oczekiwany.keys(), oczekiwany.values(),'x')
plt.savefig('res.pdf')

print('\n')