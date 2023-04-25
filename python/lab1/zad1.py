#sprawdzanie rozwiazan funkcji kwadratowej
from math import sqrt
from cmath import sqrt as csqrt

a=float(input("a = "))
b=float(input("b = "))
c=float(input("b = "))

d=b*b - 4*a*c

if d>1e-6:
    x1=(-b-sqrt(d))/(2*a)
    x2=(-b+sqrt(d))/(2*a)
    print(f'x1 = {x1:.3f}, x2 = {x2:.3f}')
elif abs(d)<=1e-6:
    x=-b/(2*a)
    print(f'x1=x2={x}')
else:
    x1=(-b-csqrt(d))/(2*a)
    x2=(-b+csqrt(d))/(2*a)
    print(f'x1 = {x1:.3f}, x2 = {x2:.3f}')