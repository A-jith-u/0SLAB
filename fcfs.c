#include<stdio.h>
struct process{
    int at,bt,id,wt,tat,ct;
}arr[10];

void read(int n){
    printf("\nEnter the ID AT BT\n");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].id,&arr[i].at,&arr[i].bt);
    }

}

void sort(int n){
    struct  process p;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].at>arr[j+1].at){
                p=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=p;
            }
        }
    }
}
        

void fcfs(int n){
    sort(n);
    float twt=0,t_tat=0;
    arr[0].ct=arr[0].at+arr[0].bt;
    arr[0].tat=arr[0].ct-arr[0].at;
    arr[0].wt=arr[0].tat-arr[0].bt;
    for(int i=1;i<n;i++){
        arr[i].ct=arr[i-1].ct+arr[i].bt;
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        twt+=arr[i].wt;
        t_tat+=arr[i].tat;
    }
    printf("The average waiting time is:%f",(twt/n));
    printf("\nThe average TAT is:%f",(t_tat/n));
}
int main(){
    int n,i;
    printf("Enter the number of process:");
    scanf("%d",&n);
    read(n);
    
    fcfs(n);
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt);
    }
}
