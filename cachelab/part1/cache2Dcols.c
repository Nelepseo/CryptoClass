#include <stdio.h>

int arr2d[3000][500];
int main(){
	int i, j;
	for(i = 0; i < 500; i++){
		for(j = 0; j < 3000; j++){
			arr2d[j][i] = i + j;
		}
	}
}