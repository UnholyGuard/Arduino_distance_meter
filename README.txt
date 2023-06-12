Ovaj program također koristi Arduino platformu i biblioteku LiquidCrystal za upravljanje LCD zaslonom. Evo detaljnog opisa koda:

1. Uključujemo potrebnu biblioteku "LiquidCrystal.h".

2. Definiramo konstante "trig" i "echo" koje predstavljaju pinove za trig i echo senzore.

3. Definiramo varijable "trajanje" (tip "long"), "udaljenost" (tip "int"), "bt", "bt_old" koje se koriste za upravljanje izbornikom.

4. Inicijaliziramo objekt "LiquidCrystal" koristeći odgovarajuće pinove za upravljanje LCD zaslonom (rs, en, d4, d5, d6, d7).

5. U "setup()" funkciji inicijaliziramo LCD zaslon pozivom "lcd.begin(16, 2)", postavljamo način rada pinova ("pinMode()") za trig i echo pinove.

6. Glavna logika programa nalazi se u "loop()" funkciji koja se neprestano izvršava.

7. Provjeravamo stanje gumba povezanih na digitalne pinove 8, 9, 10 i 11. Ako je neki od tih gumba pritisnut (stanje je "HIGH"), postavljamo vrijednost varijable "bt" na odgovarajuću vrijednost (1, 2, 3 ili 4).

8. Ako se vrijednost varijable "bt" promijeni u odnosu na prethodnu iteraciju ("bt != bt_old"), brišemo sadržaj LCD zaslona pozivom "lcd.clear()".

9. Na temelju vrijednosti varijable "bt", odabiremo koji dio koda treba izvršiti.

10. Ako je "bt" jednako 1, pozivamo funkciju "ispis_izbornik()" koja prikazuje izbornik na LCD zaslonu.

11. Ako je "bt" jednako 2, 3 ili 4, pozivamo funkciju "mjerenje()" koja koristi ultrazvučni senzor za mjerenje udaljenosti. Zatim pozivamo odgovarajuću funkciju "ispis_mm()", "ispis_cm()" ili "ispis_in()" za prikaz rezultata na LCD zaslonu.

12. Na kraju petlje, spremanje trenutne vrijednosti "bt" u "bt_old" za sljedeću iteraciju.

13. Funkcija "mjerenje()" koristi ultrazvučni senzor za mjerenje udaljenosti. Postavlja "trig" pin na nisku razinu, čeka kratko, zatim ga postavlja na visoku razinu i čeka još kraće vrijeme. Nakon toga ponovno postavlja "trig" pin na nisku razinu. 

14. Koristimo "pulseIn()" funkciju za mjerenje trajanja signala na "echo" pinu kada se odrazi od objekta. Vrijeme trajanja se pohranjuje u varijablu "trajanje".

15. Računamo udaljenost na temelju trajanja signala i brzine zvuka. Udaljenost se pohranjuje u varijablu "udaljenost".

16. Funkcije "ispis_izbornik()", "ispis_mm()", "ispis_cm()" i "ispis_in()" služe za prikazivanje odgovarajućih poruka na LCD zaslonu.

To je ukratko opis funkcionalnosti programa. Izgleda da program omogućuje odabir izbornika putem gumba i prikazuje udaljenost izmjerenu ultrazvučnim senzorom u različitim mjerama na LCD zaslonu.