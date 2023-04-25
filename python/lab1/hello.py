#!/usr/bin/env python3     #w takim wypadku chmod i otwieranie pliku./ a nie python - wersja bardziej znaczaca z wiersza polecen, moze sie psuc

#print("hello")

import keyword #slowa kluczowe
#print(keyword.kwlist)

import builtins #funkcje wbudowane
#print(dir(builtins))

import math
#print(dir(math))
#print(help(math.log10))

#print(dir(''))
#print(type(''))
#print(type(""))

#TYPY
a=7
#print(type(a))
a=1.5
#print(type(a))
a=1,1
#print(type(a))
a,b=1,'2'
#print(type(a), type(b))
a,*b=1,'2',3.,4,5
#print(type(a), type(b))

#MATH
#print(1/2, 1//2)
#print(1./2, 1.//2)
#print(2**3, pow(2,3), math.pow(2,3))
#print(pow(2,3,4), pow(2,3,5)) #3 liczba to modulo czyli 2^3 % 4
#print(math.modf(1/3), math.modf(2.5)) #czesc ulamkowa i czesc calkowita
a=-1.5
#print(abs(a), math.fabs(a))
a=-1
#print(abs(a), math.fabs(a)) #abs do inta(zwraca ten sam typ), fabs do floata(zawsze zwraca floata)

#KROTKI - wydajniejsze nz listy, nie modyfikuje sie ich
k=()
#print(type(k))
k=(2) #to nie jest krotka 
#print(type(k))
k=(2,) #krotka jednoelementowa ma przecinek i tka za soba, dodawac przecinek po ostatnim elemencie
#print(type(k))
k=(1, 2.3, '3', (4,7), [2,3,4])
#print(len(k))
#print(k[0], k[len(k)-1], k[-1][0])

#k[-1] = 3 #to jest blad bo krorki nie mozna modyfikowac
k[-1][1] = 8 #tto nie jest blad bo modyfikujemy liste w krotce, a lista jest typem modyfikowalnym

#LISTY
l=[]
#print(type(l))
l=[2]
#print(type(l))
l=[2,]
#print(type(l))
l=[1, 2.3, '3', (4,7), [2,3,4]]
#print(l[0], l[len(l)-1], l[-1])
#k[-2][1] = 8 #to jest blad bo probujemy zmodyfikowac srodek krotki
l[-2] = 8 #to nie jest blad bo modyfikujemy element listy a nie krotki

#pusta lista ma wartosc logiczna falszu, jezeli cokolwiek zawiera to ma wartosc logiczna prawdy, tak samo ze stringiem

#WYCINKI LIST
k=[8, 0, 17, 1, 10, 13, 19, 13, 10, 3]
#print(k[:]) #wypisywanie calosci
#print(k[2:-3]) # od kad wlacznie : do kad wylaczie !!!! 
#print(k[2:-3:2]) #od kad : do kad : z krokiem
#print(k[2:])
#print(k[:-3])
#print(k[::-1]) #wypisanie listy od tylu, dziala  te z dla stringow

#KOPIOWANIE LIST
k=[1, 2.3, '3', (4,7), [2,3,4]]
c=k
c[1]=[7,8,9]
#print(c, k)
#print(id(c), id(k)) #id sie nie zmienilo, oryginal zobaczyl zmiane

c=k[:]
c[1]='7,8,9'
#print(c, k)
#print(id(c), id(k)) #id sie zmienia, oryginal nie zobaczyl zmiany

#c[-1][1]='7,8,9' #przy takiej zmianie oryginal zobaczyl
#print(c,k)

c=k.copy() #to rowniez nie dziala
c[1]='7,8,9'
#print(c, k)
#print(id(c), id(k))
#c[-1][1]='7,8,9'
#print(c,k)

import copy
#copy.copy tez nie zadziala

#copy.deepcopy zadziala !!!!!!
c=copy.deepcopy(k)
c[1]='7,8,9'
#print(c,k)
#print(id(c), id(k))
c[-1][1]='7,8,9'
#print(c,k)

#ZLICZANIE / ZNAJDOWANIA ELEMENTU W LISCIE
k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3, ]
#print(k.count( 13 )) #ile jest 13
#print(k.count( -13 ))

#print(k.index(13)) #index 13

#print(13 in k) #czy 13 jest w liscie
#print(13 not in k) #czy 13 nie ma w liscie

#WSTAWIANIE ELEMENTU DO LISTY
k.insert(4,-13) #4 to index a -13 to wartosc
print(k) #jezeli wstawimy element>wielkosc listy to i tak wstawi na koniec, wstawi 1 element 