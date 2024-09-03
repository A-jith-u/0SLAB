#include<stdio.h>

int main(){
    int m,n,alloc[20][20],max[20][20],need[20][20],i,j,avail[10],finish[m],safe[m],work[n],y,k,t=0;
    printf("Enter the number of process:");
    scanf("%d",&m);
    printf("\nEnter the number of resources:");
    scanf("%d",&n);
    printf("\nEnter the max matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n Enter the allocation matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter the available matrix:\n");
    for(i=0;i<n;i++){
        scanf("%d",&avail[i]);
    }
     for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nThe need matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
 for(i=0;i<n;i++){
    work[i]=avail[i];
 }
 for(i=0;i<m;i++){
    finish[i]=0;
 }
 for(k=0;k<m;k++){
    for(i=0;i<m;i++){
       if(finish[i]==0){
        int flag=0;
        for(j=0;j<n;j++){
            if(need[i][j]>work[j]){
                flag=1;
                break;
            }
             }
             if(flag==0){
                safe[t++]=i;
                for(y=0;y<n;y++){
                    work[y]+=alloc[i][y];
                    finish[i]=1;
                }
             }
       }                           
    }
 }
 printf("\nThe safe sequence is:\n");
 for(i=0;i<=m-1;i++){
    printf("P%d",safe[i]);
 }
}
