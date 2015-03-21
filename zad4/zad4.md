### First - fast processing (and low storage) optimize

Sabrati sve brojeve niza i oduzeti to od zbira svih brojeva od 1 do n (za ovo ima formula). Razlika je rezultat.

input (n=100, a[1..n-1])
    s1 := 0
    for i=1..n-1
        s1 += a[i]
    
    s2 = n*(n+1)/2

    return s2 - s1

Space: O(1) // ne racunajuci input
Time: O(n)


### Second - fast processing optimize

Vrsta hesiranja, uzeti niz ciji su indexi vrijednosti elemenata niza i za svaki element koji je u nizu staviti mu vrijednost true. Ostat ce 1 koji je false, naci ga.

input (n=100, a[1..n-1])
	b[i] := false (i=1..n)
	for i=1..n-1
		b[a[i]] := true
	for i=1..n
		if b[i] == false
			return i

Space: O(n) // ne racunajuci input
Time: O(n)

### Third - low storage optimize

Brute force, za svaki broj provjeriti je li u nizu.

input (n=100, a[1..n-1])
	for i=1..n
		found := false
		for (j=1..n-1)
			if i == b[j]
				found := true
				break
		if found == false
			return i 

Space: O(1) // ne racunajuci input
Time: O(n^2)

### Fourth - low storage optimize

Sortirati elemente i onda ici od prvog broja i cim naidjemo na element ciji se index i vrijednost u nizu ne poklapaju, to znaci da tu fali broj.

input (n=100, a[1..n-1])
	sort (a,n-1)
	for i=1..n-1
		if i != a[i]
			return i
	return n

Space: O(1) // ne racunajuci input
Time: O(nlogn) // ako uzmemo neki O(nlogn) sorting algoritam, npr. merge sort