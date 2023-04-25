#1.Proszę napisać funkcję przyjmującą jako parametr string (przy wywołaniu będziemy przekazać argument wiersza poleceń). Zakładamy, że string ten zawiera poprawną definicję wyrażenia/funkcji matematycznej z jedną zmienną x, czyli np. 'a*x+b', 'a*x**2+b*x+c'. W miejscu wszystkich stałych proszę wstawić losowe liczby całkowite z przedziału [0,10), proszę wykorzystać metodę translate. Z funkcji proszę zwrócić listę dwuelementowych krotek (x, f(x)), dla 10 losowych liczb rzeczywistych z przedziału [0,1] (2p).

#2.Proszę napisać funkcję, do której można przekazać zmienną liczbę parametrów, zwracającą listę. Do wynikowej listy trafiają elementy, które powtarzają się we wszystkich parametrach przekazanych do funkcji, np. ([1,2,3], (1,3,5), [3,2]) -> [3], ([1,2,3], (1,3,5), [3,2,1]) -> [1,3].
#Proszę użyć konstrukcji for-else (2p)

#3.Proszę napisać funkcję przyjmującą dwie sekwencje i parametr z wartością domyślną True. Funkcja zwraca listę dwuelementowych krotek zawierających elementy o tych samych indeksach z obu sekwencji. Jeżeli wartość trzeciego parametru wynosi True, długość zwracanej listy równa jest długości krótszej z przekazanych sekwencji, w przeciwnym wypadku brakujące elementy w krotkach uzupełniamy wartością None. Budowanie każdej z wynikowych list jedna linijka, proszę nie używać funkcji wbudowanych! (2p) 

#4.Proszę napisać funkcję umożliwiającą rozmienienie kwoty pieniędzy przekazanej jako jej pierwszy parametr nominałami określonymi poprzez drugi parametr - wartość domyślna krotka (10,5,2) (algorytm zachłanny). Proszę sprawdzić działanie funkcji przekazując inny zestaw monet (2p)

#5.Proszę napisać funkcję przyjmującą cztery parametry: liczba całkowita, której wartość zgadujemy, granice przedziału, w którym szukana liczba się mieści i ostatni określający sposób poszukiwania wartości z wartością domyślną 'r'. Przy wartości domyślnej ostatniego parametru, liczby poszukujemy losując kolejną wartość, w innym przypadku poszukujemy wartości poprzez podział przedziału poszukiwania wartości na pół. W obu przypadkach w każdym kroku odpowiednio zawężamy przedział poszukiwania (proszę wykorzystać operator trójargumentowy). Proszę sprawdzić ile kroków jest potrzebnych do znalezienia szukanej wartości w zależności od metody (2p)

#ZAD 1
print('ZAD1'.center(20,'*'))

import sys
import random
import string

def fun1(napis):
    napis_zmieniony=''.join([i for i in napis if i in string.ascii_lowercase and i != 'x'])
    liczby_zmienione=''.join([ str(random.randrange(10)) for i in range(len(napis_zmieniony))])
    n=napis.translate(str.maketrans(napis_zmieniony, liczby_zmienione))
    print(n)
    return {(x:=random.random()): eval(n) for _ in range(10)}

print(fun1(sys.argv[1]))

print('\n')

#ZAD 2
print('ZAD2'.center(20,'*'))

def fun2(*elementy):
    lista = []
    for i in elementy[0]:
        for j in elementy[1:]:
            if i not in j:
                break
        else:
            lista.append(i)
    return lista

print(fun2([1,2,3], (1,3,5), [3,2,1]))
print(fun2([1,2,3], (1,3,5), [3,2]))

print('\n')

#ZAD 3
print('ZAD3'.center(20,'*'))

def fun3(a, b, c=True):
    if c:
        return [(a[i],b[i]) for i in range(min(len(a), len(b)))]
    else:
        return [(a[i] if i<len(a) else None,b[i] if i<len(b) else None) for i in range(max(len(a), len(b)))]
print(fun3((1,3), [3,2,5]))
    
print('\n')

#ZAD 4
print('ZAD4'.center(20,'*'))

def fun4(a, b=(10,5,2)):
    lista_wynik = []
    while a > 0:
        for i in b:
            if a >= i:
                a-=i
                lista_wynik.append(i)
                break
        else:
            return None
    return lista_wynik
print(fun4(22, (5,2)))

print('\n')

#ZAD 5
print('ZAD5'.center(20,'*'))

def fun5(zgadywana, lewa, prawa, sposob='r'):
    if sposob == 'r':
        z=0
        i=0
        while z != zgadywana:
            z=random.randint(lewa, prawa)
            if z == zgadywana:
                return z
            else:
                continue
    #else:
        
print(fun5(43, 15, 78))

print('\n')
