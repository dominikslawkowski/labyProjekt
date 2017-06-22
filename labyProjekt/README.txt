Dominik Sławkowski

Projek ma być symulacja zwiedzania lochów i walka z przeciwnikami.
Po rozpoczęciu gry, od góry będzie się wyświetlać karta postaci, niżej panel z przeciwnikiem i na samym dole aktualne opcje wyboru.

Gra polega na pokonaniu 3 przeciwników, od najsłabszego do najsilniejszego. 
Pojedynki są turowe.

Nasza postać ma do dyspozycji 4 ruchy:
1. Atak
  Postać może wykorzystać turę na zadanie obrażeń przeciwnikowi.
  Wartość ataku jest równa = Fe * 10% + St * 10% + We - Fr
  Fe - randomowy procent wartości fechtnuku postaci
  St - wartość siły postaci
  We - wartość ataku broni
  Fe - wartość aktualnego poziomu strachu postaci
  
2. Obrone
  Postać może wykorzystać turę na obrone. 
  Spowoduje to obniżenie o jeden niżej poziomu aktualnego stachu postaci, a atak przeciwnika bedzie słabszy.
  
3. Wypicie mikstury zdrowia
  Ta akcja nie zabiera tury i dodaje +10 HP do aktualnej wartości zdrowia.
  
4. Użycie zaklęcia
  Ta akcja zabiera turę, ale dodaje +10 do wartości siły postaci i zeruje jej poziom strachu.

Po naszej turze nastepuje kolej przeciwnika, wtedy dla niego jest losowana akcja którą wykona.
Przeciwnika może nas zaatakować - siła ataku zależy od atrybutów i broni przeciwnika,
lub wystraszyć - zwiększa nam to poziom strachu o +1.

Strach:
Na poczatku gry postać ma poziom strachu równy 0. int fear[5] = { 0, 1, 2, 5, 10 };
W trakcie kolejnych tur, może się on zwiększyć aż do poziomu 5.
Kolejnym poziomom strachu przypisane są coraz wieksze wartości, które zmniejszają naszą siłę ataku.
lvl --- nerf
 0  ->   0
 1  ->   1
 2  ->   2
 3  ->   5
 4  ->   10
 
Po wygranym pojedynku następuje wybranie nagrody ale postaci, jest to zwiększenie któregoś z atrybutów.

Rozkład pracy:
2 czerwca - dopracowanie klasy Option
9 czerwca - dopracowanie klasy Enemy
16 czerwca - dopracowanie klasy Event
