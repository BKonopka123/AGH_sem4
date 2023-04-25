import sys
import math
import cmath

#print(sys.argv)

if len(sys.argv)!=5:
    sys.exit() #do wyjscia  zprogramu zawsze sys.exit, do wyjscia z terminala samo exit wystarczy

a=float(sys.argv[1])
b=float(sys.argv[2])
c=float(sys.argv[3])
eps=float(sys.argv[4])

if (d:=b**2 - 4*a*c) > eps: #stworzenie zmiennej d w ifie
    x1=(-b-math.sqrt(d))/(2*a)
    x2=(-b+math.sqrt(d))/(2*a)
    print(f'x1 = {x1:.3f}, x2 = {x2:.3f}')
elif math.fabs(d) <= eps:
    print(f'x1=x2={-b/(2*a):.3f}')
else:
    x1=(-b-cmath.sqrt(d))/(2*a)
    x2=(-b+cmath.sqrt(d))/(2*a)
    print(f'x1 = {x1:.3f}, x2 = {x2:.3f}')

print(d)