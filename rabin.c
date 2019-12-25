#include<stdio.h>
#include<string.h>
#include<math.h>

long long int CRT(int a1,int a2,int b1,int b2){
  int a[2],m[2],M[2],Minverse[2];
  int common_modulo=1;
  int i,n=2;
  a[0]=a1;
  a[1]=a2;
  m[0]=b1;
  m[1]=b2;

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
/*for(i=0;i<n;i++){
	printf(" %d ",M[i]);
}

printf("\nprinting Minverse[]");
for(i=0;i<n;i++){
	printf(" %d ",Minverse[i]);
}*/
//printf("\n");

//calculating final solution
int solution=0;
for(i=0;i<n;i++){
	solution+=a[i]*M[i]*Minverse[i];
}
return solution ;
}



void main(){
//public key n, private key p,q;	
long long int p,q,plaintext,i,gcdd,c,n;	
printf(".......Program for Rabin Crypto System.........\n");
printf("Enter Two large prime numbers P and Q \n");
printf("Enter the value of P\n");
scanf("%lld",&p);
printf("Enter the value of Q\n");
scanf("%lld",&q);

n=p*q;


//encryption,choose plaintext p such that gcd(p,zn)==1
printf("Enter the plain text\n\n");
scanf("%lld",&plaintext);
c=(plaintext*plaintext) % n;
printf("Cipher text is %lld\n",c); 

//decryption

long long int a1,a2,b1,b2,p1,p2,p3,p4;
a1 = (long long int)pow(c,(p+1)/4) % p;
a2 = ((-1*((long long int)(pow(c,(p+1)/4))))% p + p)%p;
b1 = (long long int)pow(c,(q+1)/4) % q;
b2 = ((-1*((long long int)(pow(c,(q+1)/4))))% q + q)%q;


printf("Printing a1,a2,b1,b2 : %lld %lld %lld %lld",a1,a2,b1,b2);
//finding plaintexts

p1=CRT(a1,b1,p,q) % n;
p2=CRT(a1,b2,p,q) % n;
p3=CRT(a2,b1,p,q) % n;
p4=CRT(a2,b2,p,q) % n;
printf("\n");
printf("%lld \n",p1);
printf("%lld \n",p2);
printf("%lld \n",p3);
printf("%lld \n",p4);

if(p1==plaintext){
	printf("\nDecrypted message is %lld",p1);
}
else if(p2==plaintext){
	printf("\nDecrypted message is %lld",p2);
}
else if(p3==plaintext){
	printf("\nDecrypted message is %lld",p3);
}
else if(p4==plaintext){
	printf("\nDecrypted message is %lld",p4);
}


}
