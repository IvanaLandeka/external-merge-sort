# external-merge-sort
quick sort + merge

Napisite program za sortiranje velikih datoteka. Rijec je o datotekama koje su prevelike da bi se odjednom
drzale u glavnoj memoriji racunala. Program radi na sljedeci nacin.

    • Polazna datoteka cijepa se na nekoliko manjih, tako da svaka mala datoteka stane u glavnu memoriju.
    • Svaka mala datoteka ucitava se u glavnu memoriju, sortira se nekim od poznatih algoritama (npr.
      quick sort) te se tako sortirana ponovo ispisuje na disk.
    • Male sortirane datoteke spajaju se u vece sortirane datoteke postupkom spajanja (merge). Prilikom
      svakog spajanja, ulazne datoteke se sekvencijalno citaju izravno s diska, a izlazna datoteka se
      izravno ispisuje na disk.
    • Sortiranje je zavrseno onda kad, nakon dovoljnog broja spajanja, na disku ostane samo jedna velika
      sortirana datoteka.
      
U vasem programu mozete pretpostaviti da se datoteke sastoje od cijelih brojeva. Osmislite odgovarajuci
test primjer gdje se polazna datoteka sastoji od npr. 5000 cijelih brojeva te se na poˇcetku cijepa na 10
manjih datoteka od po 500 cijelih brojeva.
