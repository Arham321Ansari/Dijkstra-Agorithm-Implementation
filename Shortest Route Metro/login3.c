#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "login.h"
#include<distance.h>
#include<signin.h>
//#include "dijkstra.h"
int minDist(int dist[],int visit[]){
	int min=1000;
	int i,min_index;
	for(i=0;i<7;i++){
		if(visit[i]==0 && dist[i]<min){
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}

void printSol(int dist[],int src,int des){
	int i;
	printf("Vertex\t\tdistrance from selected station\n");
	for(i=0;i<7;i++){
	    if(i==des){
			
			printf("%d->%d\t\t\t%d\n",src,i,dist[i]);
		}
	}
}

void dijkstra(int B[7][7],int src,int des){
	int i,count,v,u;
	int dist[7];
	int visit[7];
	
	for(i=0;i<7;i++){
		dist[i]=1000;		//setting maximum value for each node 
		visit[i]=0;			//status is not visited
	}
	dist[src]=0;
	for(count=0;count<7;count++){
		u=minDist(dist,visit);
		visit[u]=1;
		
		for(v=0;v<7;v++){
			if(dist[u]+B[u][v]<=dist[v] && !visit[v] &&B[u][v]){
				dist[v]=dist[u]+B[u][v];
			}
		}
	}
	printSol(dist,src,des);
}

void shortest(){
	int i,n,j,src,des;
	int A[7][7]={{0,8,3,9,0,0,0},{8,0,0,7,5,0,0},{3,0,0,2,0,0,0},{9,7,2,0,7,0,0},{0,5,0,7,0,3,4},{0,0,0,0,3,0,11},{0,0,0,0,4,11,0}};
	printf("the graph is\n");
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("Enter the source station:\t");
	scanf("%d",&src);
	printf("Enter the destination:\t");
	scanf("%d",&des);
	if(src<7){
		dijkstra(A,src,des);
	}
	else{
		printf("\ninvalid Station!!\n");
	}
	
	
}
int main(){
	int p,p2,dis,fare;
	char c;
	int choice,choice2=1,choice3=1;
	do{
		printf("\t\t\tWelcome to metro system\n");
		printf("\t\t========================================\n");
		printf("\t\t\tPress 1 for login\n");
		printf("\t\t\tPress 2 for signup\n");
		printf("\t\t\tPress 3 for exit\n");
		
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				p=Login();
				while(choice2==1 &&p==1)
				{
						dist();
					    shortest();
						printf("\t\t\tPress 1 for Continue\n");
						printf("\t\t\tPress 0 for Logout\n");
						scanf("%d",&choice2);
					}
				if(p==1){
				printf("\t\t\tLogout Successfully\n\n");
				printf("Press 1 to continue...");
				scanf(" %c",&c);
				}	
				system("cls");
				break;
			case 2:
				p2=sign();
				if(p2==1){
					printf("\t\t\t-->Login for Continue\n");
					p=Login();
					while(choice3==1 && p==1){
						dist();
						shortest();
						printf("\t\t\tPress 1 for Continue\n");
						printf("\t\t\tPress 0 for Logout\n");
						scanf("%d",&choice3);
					}
				}
				else{
					printf("!!!user not created!!!\n");
				}
				printf("\t\t\tLogout Successfully\n\n");
				printf("Press 1 to continue...");
				scanf(" %c",&c);
				system("cls");
				break;
			case 3:
				printf("<<--Exit-->>");
				break;
			default:
				printf("Invalid choice\n");
	}
	
	}while(choice!=3);
}


