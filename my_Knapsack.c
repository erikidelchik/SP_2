#include <stdio.h>
#define MAX_WEIGHT 20
#define LEN 5

int selectItems(int*,int*,int*);
int max(int,int);

int main(){

    char items [LEN];
    int value [LEN];
    int weight [LEN];
    int selected_bool[LEN] = {0};
    for(int i=0;i<LEN;i++){
        items[i] = getchar();
        scanf("%d",&value[i]);
        scanf("%d",&weight[i]);
        getchar();
    }
    int max_val = selectItems(weight,value,selected_bool);
    printf("Maximum profit: %d\n",max_val);
    printf("Selected items:");
    for(int i=0;i<LEN;i++){
        if(selected_bool[i])
            printf(" %c",items[i]);
    }

    return 0;
}

int selectItems(int weights[], int values[], int selected_bool[]){
    int t [LEN+1][MAX_WEIGHT+1];
    for(int i=0;i<LEN+1;i++){
        for(int j=0;j<MAX_WEIGHT+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
            else{
                if(j-weights[i-1]>=0)
                    t[i][j] = max(t[i-1][j],values[i-1]+t[i-1][j-weights[i-1]]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
    }

    for(int i=0;i<LEN+1;i++){
        for(int j=0;j<MAX_WEIGHT+1;j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    int max_val = t[LEN][MAX_WEIGHT];
    int i=LEN;
    int j=MAX_WEIGHT;
    while(i>0 && j>0){
        if (j-weights[i-1]>=0){
            if (t[i - 1][j] < values[i - 1] + t[i - 1][j - weights[i - 1]]) {
                selected_bool[i-1] = 1;
                j-=weights[i - 1];
                i--;
            }
            else i--;
        }
        else i--;
    }
    return max_val;


}

int max(int i,int j){
    if(i>j) return i;
    return j;
}

