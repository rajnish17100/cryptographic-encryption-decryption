#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){
int n,i,common_modulo=1;	
printf("..................Program to solve congruent modulo equation using chinies Remainder theorem....Applicable only iff moduli are relatively prime\n");
printf("Enter the number of  congruent modulo  equation\n");
scanf("%d",&n);

int a[n],m[n],M[n],Minverse[n];
printf("Enter values of a[]");
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}

printf("Enter values of m[]");
for(i=0;i<n;i++){
	scanf("%d",&m[i]);
}

// finding the common modulo
for(i=0;i<n;i++){
	common_modulo*=m[i];
}

//printf("common modulo is : %d\n",common_modulo);
//finding M[] array
for(i=0;i<n;i++){
	M[i]=common_modulo/m[i];
}

//finding multiplicative inverse of each M[] corresponding to each m[]
int t;
for(i=0;i<n;i++){
	for(t=0;t<m[i];t++){
     if((M[i]*t)%m[i]==1){
  	     break;
     }
   }
   Minverse[i]=t;
}
//printing M[] values
for(i=0;i<n;i++){
	printf(" %d ",M[i]);
}

printf("\nprinting Minverse[]");
for(i=0;i<n;i++){
	printf(" %d ",Minverse[i]);
}
printf("\n");
//calculating final solution
int solution=0;
for(i=0;i<n;i++){
	solution+=a[i]*M[i]*Minverse[i];
}
//printing final solution
printf("final solution is:%d",solution);

}
