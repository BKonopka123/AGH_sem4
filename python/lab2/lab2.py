
#1.Korzystając z pętli for proszę usunąć wszystkie wystąpienia określonej wartości z listy (1p)
#2.j.w. ale korzystając z pętli while (1p)
#3.Korzystając z pętli for oraz funkcji range proszę wypisać co drugi element listy począwszy od elementu o indeksie 1 (bez instrukcji warunkowej) (0.5p)
#4.j.w. ale bez range (0.5p)
#5.Korzystając z pętli for oraz funkcji range proszę wypisać co drugi element listy od końca (bez instrukcji warunkowej) (1p)
#6.j.w. ale bez range (1p)
#7.Proszę utworzyć nową listę, której elementami są krotki (indeks, element) na podstawie istniejącej listy <- lista składana (1p)
#8.Proszę posortować listę z poprzedniego punktu wg drugiego elementu krotek (1p)
#9.Proszę utworzyć nową listę, której elementami są krotki (indeks, element) na podstawie istniejącej listy, przy czym dodajemy krotkę tylko, jeśli wartość pobrana z listy jest wartością parzystą <- lista składana (1p)
#10.Proszę utworzyć nową listę, której elementami są krotki (indeks, element) lub (element, indeks) na podstawie istniejącej listy, tak, aby pierwszy element krotki był mniejszy od drugiego <- lista składana (1p)
#11.Proszę utworzyć listę 2D (lista składana) wypełnioną zerami oraz jedynkami, przy czym jedynki występują:
#-w kwadracie o boku mniejszym od rozmiaru listy na jej "środku" (0.2p)
#-na przekątnej od lewego górnego rogu do prawego dolnego (0.2p)
#-na przekątnej od prawego górnego rogu do lewego dolnego (0.2p)
#-na obu przekątnych (0.2p)
#-w szachownicę (0.2p)

import copy

k = [8, 0, 17, 1, 10, 13, 13, 19, 13, 10, 3,]
#zad1
c=copy.deepcopy(k)
for i in k:
    if i == 13:
        c.remove(13)
print('zad1\n', c)
print('\n')

k = [8, 0, 17, 1, 10, 13, 13, 19, 13, 10, 3,]
#zad2
i=0
while i < len(k):
    if k[i] == 13:
        k.remove(13)
        i-=1
    i+=1
print('zad2\n', k)
print('\n')

k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
#zad3
print('zad3 ')
for i in range(len(k)//2):
    print(k[2*i+1], end=', ')
print('\n')

k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
#zad4
print('zad4 ')
for i in k[1::2]:
    print(i, end=', ')
print('\n')

k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
#zad5
print('zad5 ')
for i in range(len(k)//2):
    print(k[-2*i-1], end=', ')
print('\n')

k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
#zad6
print('zad6 ')
print(k[-1::-2], end=', ')
print('\n')

c = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
#zad7
print('zad7 ')
k=[(i,c[i]) for i in range(len(c))]
print(k, '\n')

#zad8
print('zad 8')
k.sort(key=lambda x: x[1])
print(k, '\n')

#zad9
print('zad9 ')
k=[(ind,val) for ind,val in enumerate(c) if not val%2]
print(k, '\n')

#zad10
print('zad10 ')
k=[(ind,val) if ind>=val else (val,ind) for ind,val in enumerate(c)]
print(k, '\n')

#zad11
print('zad11 ')

roz=10 #rozmiar duzego kwadratu

print('a)\n')

rozk=4 #rozmiar malego kwadratu
if rozk>roz:
    print('za duzy rozmiar malego kwadratu\n')
else:
    a=(roz//2) - (rozk//2) 

    if a%2:
        k=[[0 if i<a or j<a or i>roz-a or j>roz-a else 1 for j in range(roz)] for i in range(roz)]
    else:
        k=[[0 if i<a or j<a or i>roz-a-1 or j>roz-a-1 else 1 for j in range(roz)] for i in range(roz)]
    for i in range(len(k[0])):
        print(k[i])
    print('\n')

print('b)\n')
k=[[1 if i==j else 0 for j in range(roz)] for i in range(roz)]
for i in range(len(k[0])):
    print(k[i])
print('\n')

print('c)\n')
k=[[1 if i+1==len(k)-j else 0 for j in range(roz)] for i in range(roz)]
for i in range(len(k[0])):
    print(k[i])
print('\n')

print('d)\n')
k=[[1 if i+1==len(k)-j or i==j else 0 for j in range(roz)] for i in range(roz)]
for i in range(len(k[0])):
    print(k[i])
print('\n')

print('e)\n')
k=[[1 if (not i%2 and j%2) or (not j%2 and i%2) else 0 for j in range(roz)] for i in range(roz)]
for i in range(len(k[0])):
    print(k[i])
print('\n')