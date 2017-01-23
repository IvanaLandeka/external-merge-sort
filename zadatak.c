#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5000
#define segments 10

/* int niz[N];
void swap(int i, int j){
	int pom = niz[i];
	niz[i] = niz[j];
	niz[j] = pom;
}

void kjusort(int lo, int hi){

	int l = lo+1, r = hi, pivot = lo;
	if(lo >= hi) return;

	while(l <= r){
		while(l <= hi && niz[l] <= niz[pivot]) ++l;
		while(r > lo && niz[r] >= niz[pivot]) --r;
		if(l < r) swap(l,r);
	}
	swap(pivot,r);
	kjusort(lo, r-1);
	kjusort(r+1, hi);
} */

void swap (int *x, int *y) {
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

void QuickSort(int a[], int l, int r) {
	int i,j;
	
	if (l>=r) return;
	i = l+1; //razvrstavanje elemenata s obzirom na stozer
	j = r;
	while ((i<=j) && (i<=r) && (j>l)) {
		while ((a[i] <= a[l]) && (i<=r)) i++;
		while((a[j] >= a[l]) && (j>l)) j--;
		if (i<j)
			swap(&a[i], &a[j]);
	}
	if (i>r) { // stozer je najveci u polju
		swap(&a[r], &a[l]);
		QuickSort(a, l, r-1);
	}
	else if (j<=l) { // stozer je najmanji u polju
		QuickSort(a, l+1, r);
	}
	else { //stozer je negdje u sredini
		swap(&a[j], &a[l]);
		QuickSort(a, l, j-1);
		QuickSort(a, j+1, r);
	}
} 

int main (void) {

	char ime[20];
	int i,j, broj, niz[N/segments];
	FILE *pocetni, *pomocni;

	// 1) generiranje pocetnog file-a
	pocetni=fopen("pocetni.txt","w");
	for (i=0; i < N; i++) {
		fprintf(pocetni, "%d", rand());
		fprintf(pocetni, "\n");
	}
	fclose(pocetni);

	// 2) cijepanje pocetnog file-a
	pocetni=fopen("pocetni.txt","r");
	for(j=0; j<segments; j++) {
		sprintf(ime, "%d.txt", j+1);
		pomocni = fopen(ime, "w");
		for(i=j*(N/segments); i<(j+1)*(N/segments); i++) {
			fscanf(pocetni, "%d", &broj);
			fprintf(pomocni, "%d", broj);
			fprintf(pomocni, "\n");
		}
		fclose(pomocni);

		//ucitavanje male datoteke u gl mem
		pomocni = fopen(ime, "r"); //zasto rewind ne radi???
		for (i=0; i<(N/segments); i++) {
			fscanf(pomocni, "%d", &broj);
			niz[i]=broj;
		}
		fclose(pomocni);

		// 3) quicksort malih datoteka
		QuickSort(niz, 0, (N/segments)-1);

		//ponovno ispisivanje male datoteke na disk
		pomocni = fopen(ime, "w");
		for (i=0; i<(N/segments); i++) {
			fprintf(pomocni, "%d\n", niz[i]);
		}
		fclose(pomocni);
	}
	fclose(pocetni);
	
	// 4) merge
	

	return 0;
}
