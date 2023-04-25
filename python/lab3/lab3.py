#1.Proszę utworzyć string składający się z elementów listy argv z wyłączeniem nazwy programu. Jeżeli program został uruchomiony bez podania parametrów proszę wypisać na ekran komunikat informujący o właściwym sposobie uruchomienia programu (1p)
#2.Na podstawie wcześniej utworzonego stringa proszę utworzyć cztery listy: zawierającą małe litery, zawierającą duże litery, zawierającą cyfry oraz zawierającą wszystko co nie jest literą (2p)
#3.Na podstawie utworzonej listy zawierającej małe litery proszę utworzyć listę małych liter bez powtórzeń (bez użycia typu set). Następnie proszę utworzyć nową listę, w której każdy element jest dwuelementową krotką (litera, krotność jej wystąpienia w liście oryginalnej), proszę wykorzystać konstrukcję listy składanej (2p)
#4.Otrzymaną w powyższym punkcie listę proszę wyświetlić w kolejności od najwyższej krotności (bez sortowania listy oryginalnej) (1p)
#5.Proszę utworzyć listę dwuelementowych krotek, w których pierwszy element jest liczbą pobraną z listy cyfr, drugi natomiast wartością funkcji liniowej ax+b dla danej liczby; wartości współczynników proszę ustalić w następujący sposób: a równa się liczbie samogłosek w stringu z punktu pierwszego, a b - liczbie spółgłosek tamże (2p)
#6.Proszę obliczyć wartości parametrów prostej korzystając z metody najmniejszych kwadratów (2p):



#ZAD 1
print('ZAD1'.center(20,'*'))

import sys
if len(sys.argv)==1:
    print("Nic nie wpisano")
    exit()
s=''.join(sys.argv[1:])
print(s)

print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

low=[i for i in s if i.islower()]
up=[i for i in s if i.isupper()]
num=[i for i in s if i.isdigit()]
nolet=[i for i in s if not i.isalpha()]

print(low, '\n', up, '\n', num, '\n', nolet) 

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

lowno=[]
for i in low:
    if i not in lowno:
        lowno.append(i)

print(lowno)

lownotup=[(i,low.count(i)) for i in lowno]
print(lownotup)

print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))

print(sorted(lownotup, key=lambda x:x[1], reverse=True))

print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

a=0
samo='AaEeIiOoUuYy'
for i in samo:
    if i in s:
        a+=s.count(i)
b=len(low)+len(up)-a
print(a, '    ',b,'\n')

fun=[(int(i),a*int(i)+b) for i in num]
print(fun)

print('\n')

#ZAD 6
print('ZAD6'.center(20,'*'))

if num:
    xsr=sum(x for x,_ in fun)/len(fun)
    ysr=sum(y for _,y in fun)/len(fun)
    D=sum((x-xsr)**2 for x,_ in fun)
    A=(sum(((x-xsr)**2)*y for x,y in fun))/D
    B=ysr-A*xsr
    print('A =', A, 'D =', D, 'B =', B)

print('\n')