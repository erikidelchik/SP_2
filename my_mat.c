#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"


int min(int a,int b){
    if (a>b) return b;
    else return a;
}

int** shortestPathMat(int n,int** a){
    for(int x = 0;x<n;x++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0 && i!=j) {
                    if (a[i][x] == 0 || a[x][j] == 0)
                        a[i][j] = 0;
                    else a[i][j] = a[i][x]+a[x][j];
                }
                //if all ribs exist
                else if(a[i][x]!=0 && a[x][j]!=0)
                    a[i][j] = min(a[i][x]+a[x][j],a[i][j]);

                //else a[i][j] stays as it is, cuz a[i][j]!=0 and a[i][x]==0 || a[x][j]==0
            }
        }
    }
    return (int **) a;

}

int** initMat(int n){
    int** mat;
    mat = malloc(n*sizeof (int*));
    for(int i=0;i<n;i++){
        mat[i] = malloc(n* sizeof (int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    return mat;
}
