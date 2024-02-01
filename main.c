#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main(){
	int** mat;
	int** my_mat;
	int i;
	int j;
	
	char c;
	while(1){
		
		scanf("%c",&c);
		if(c=='A'){
			mat =initMat(10);
			my_mat = shortestPathMat(10,mat);
		}
		else if(c=='B'){
			scanf("%d",&i);
			scanf("%d",&j);
			if(my_mat[i][j]>0) printf("True\n");
			else printf("False\n");
		}
		else if(c=='C'){
			scanf("%d",&i);
			scanf("%d",&j);
			if(my_mat[i][j]>0) printf("%d\n",my_mat[i][j]);
			else printf("-1\n");

		}
		else if(c=='D') break;
		
	}
	
	
	free(mat);
	return 0;
}
