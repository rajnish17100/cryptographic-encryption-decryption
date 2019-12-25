#include<stdio.h>
#include<string.h>
#include<math.h>

long long int x,y,g,n,A,B;

void alice(){
	printf("Choose a large prime number for alice\n");
	scanf("%lld",&x);
	A=(long long int)pow(g,x) % n;
	
}

void bob(){
	printf("Choose a large prime number for bob\n");
	scanf("%lld",&y);
	B=(long long int)pow(g,y) % n;
	
}

void main(){

long long int alice_key;
long long int bob_key;

printf(".........Program for Key Exchange Protocol using Deffie Helman ............\n");
printf("Choose the value of n ang g as a large prime number\n");
printf("Enter the value of n\n");
scanf("%lld",&n);
printf("Enter the value of g\n");
scanf("%lld",&g);
alice();
bob();

alice_key=(long long int)pow(B,x) % n;
bob_key=(long long int)pow(A,y) % n;


printf("\nAlice key is :%lld",alice_key);
printf("\nBOB key is :%lld",bob_key);
if(alice_key==bob_key){
printf("\ncommon key is %lld:",alice_key);	
}

}
