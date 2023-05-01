import glob
import numpy
import string

#ZAD 1
print('ZAD1'.center(20,'*'))

def fun1(name, n):
    with open(name) as pl:
        lista = list(pl.readlines()[::])
        print(list(i.strip() for i in lista[:n:]), '\n')
        print(list(i.strip() for i in lista[-n::]), '\n')
        print(list(i.strip() for i in lista[::n]), '\n')
        print(list(i.strip().split()[n-1] for i in lista[::] if n<len(i.strip().split())), '\n')
        print(list(i.strip()[n-1] for i in lista[::] if n<len(i.strip()) ))

fun1('2000.txt', 3)

print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

lista_plikow = glob.glob('data*.in')
lista = {}
for i in lista_plikow:
    with open(i) as pl1:
        for j,k in enumerate(pl1):
            lista.setdefault(j,[]).append(float(k))

print(lista)

with open('zad2.txt', 'w') as pl2:
    for i,j in lista.items():
        write_data = f'{i} \t {numpy.average(j)} \t {numpy.std(j)} \n'
        pl2.write(write_data)

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

with open('extra.py', 'w') as pl1:
    pl1.write('''import numpy
import glob
import matplotlib.pyplot as plt 
lista_plikow = glob.glob('data*.in')
for i in lista_plikow:
    y=numpy.loadtxt(i, unpack=True)
    x=range(len(y)) 
    plt.plot(x, y, 'o') 
x,y,z = numpy.loadtxt('zad2.txt', unpack=True)
plt.errorbar(x, y, marker='*', yerr=z) 
plt.xlabel('x') 
plt.savefig('res.pdf')''')


print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))

lista_plikow = glob.glob('2*.txt')
lista = {}
for i in lista_plikow:
    with open(i) as pl1:
        for k in pl1:
            lista.setdefault(k.split()[0] , []).append((int(f'{i[0:-4]}'),float(k.split()[1])))
for i,j in lista.items():
    j.sort()
print(lista)


with open('zad4.txt', 'w') as pl2:
    data1 = f'Nazwisko'.center(21,' ')
    temp1=2000
    while(temp1 <=2020):
        data1+=f'{temp1}'.center(5,' ')
        temp1+=1
    data1+=f'\n\n'
    pl2.write(data1)
    for i,j in lista.items():
        write_data = f'{i}'.center(21,' ')
        temp=2000
        k1=[z[0] for z in j]
        k2=[z[1] for z in j]
        while(temp <=2020):
            if temp in k1:
                inde = k1.index(temp) 
                write_data += f'{k2[inde]}'.center(5,' ')
            else:
                write_data += f'--'.center(5,' ')
            temp+=1
        write_data += '\n'    
        pl2.write(write_data)

print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

lista_plikow = glob.glob('zad5*.in')
lista = {}
temp=[]
for i in lista_plikow:
    with open(i) as pl1:
        for k in pl1:
            temp.extend(k.split())
for i in temp:
    if i[0] in lista:
        lista[i[0]] += 1
    else:
        lista[i[0]] = 1 
for i in string.ascii_letters:
    if not i in lista:
        lista[i] = 0

print(dict(sorted(lista.items()))) 
print(dict(sorted(lista.items(), key=lambda item: item[1]))) 

print('\n')