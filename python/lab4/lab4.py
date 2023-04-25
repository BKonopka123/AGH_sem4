#1.Proszę utworzyć k-elementową listę całkowitych wartości losowych z przedziału [0,5k).
#Proszę sprawdzić ile elementów pozostaje na swoim miejscu po losowym przemieszaniu listy, mieszanie proszę wykonać 100 razy a wyniki zapisywać w słowniku (2p)
#2.Proszę utworzyć losowy string o długości k zawierający tylko małe litery, pomiędzy poszczególne litery proszę wstawić kropkę (1p)
#3.Proszę utworzyć listę stu całkowitych wartości losowych z przedziału [0,20). Następnie na jej podstawie proszę utworzyć słownik, w którym klucze są liczbami z listy, a wartościami lista ich indeksów.
#w rozwiązaniu proszę wykorzystać metodę setdefault i funkcjię enumerate (1p)
#w rozwiązaniu proszę wykorzystać metody setdefault i index (1.5p)
#4.Proszę sprawdzić ile spośród 1000 losowych wartości całkowitych składających się z n cyfr, gdzie n jest z przedziału [3,6], jest liczbami palindromowymi. Wynik proszę zapisać w słowniku - jedna linijka (2.5p)
#5.Proszę utworzyć dwa słowniki o rozmiarze 10, w których kluczami są kolejne liczby naturalne, a wartościami liczby losowe z przedziału [1,100). Następnie w obu słownikach proszę zamienić miejscami klucze z wartościami.
#Na podstawie tak otrzymanych słowników proszę utworzyć nowy słownik, w którym klucze są kluczami występującymi jednocześnie w obu wcześniej utworzonych słownikach, wartościami natomiast są dwuelementowe krotki wartości związanych z danym kluczem w słownikach oryginalnych  (2p)

#ZAD 1
print('ZAD1'.center(20,'*'))

import random
import copy

k=10
s={}
rand_list_1=[random.randrange(5000) for i in range(k)]
rand_list_1_cpy = copy.deepcopy(rand_list_1)
print(rand_list_1)
for i in range(100):
    number=0
    random.shuffle(rand_list_1_cpy)
    for j in range(k):
        if rand_list_1_cpy[j] == rand_list_1[j]:
            number+=1
    if number in s:
        s[number]+=1
    else:
        s[number]=1
print(s)
    
print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

import string

napis='.'.join(random.sample(string.ascii_lowercase, k))
print(napis)

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

rand_list_2 = [random.randrange(20) for i in range(100)]
s={}

print('A:')
for i,j in enumerate(rand_list_2):
    s.setdefault(j,[]).append(i)
print(s)

s={}

print('B:')
for i in rand_list_2:
    s.setdefault(i,[]).append(rand_list_2.index(i, s[i][-1]+1 if s[i] else 0))
print(s)

print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))


print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

s1={i: random.randrange(1,100) for i in range(10)}
s2={i: random.randrange(1,100) for i in range(10)}
print(s1, s2)
s1={j: i for i,j in s1.items()}
s2={j: i for i,j in s2.items()}
print(s1, s2)
s3={}
for a,b in s1.items():
    for c,d in s2.items():
        if a == c:
            s3={a: (b,d)}
print(s3)

print('\n')