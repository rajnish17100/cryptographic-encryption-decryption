#include<stdio.h>
#include<string.h>
#include<math.h>

int p,q,phi,e,d;
long long int message[20],encrypted_message[20],decrypted_message[20],n;
int gcd(int a, int b){
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

int decideE(){
	int i,gcdd;
   for(i=2;i<phi;i++){
	    gcdd=gcd(phi,i);
	    if(gcdd==1){
	      break;
		}
		else{
			continue;
		} 
	 
    }
	return i;	
}

int inverse(){
 int i;	
 for(i=0;i<phi;i++){
	  if((e*i)%phi==1){
	  	break;
	  }
 }
 return i%phi; 	
}

void encrypt_message(int length){
 	int i;
 	
	 for(i=0;i<length;i++){
	 	encrypted_message[i]=(long long int)(pow(message[i],e)) % n;
	 }
   for(i=0;i<length;i++){
	  printf("%lld ",encrypted_message[i]);
	 }	 
}

void decrypt_message(int length){
 	int i;
 	
	 for(i=0;i<length;i++){
	 	decrypted_message[i]=(long long int)(pow(encrypted_message[i],d)) % n;
	 }
   for(i=0;i<length;i++){
	  printf("%lld ",decrypted_message[i]);
	 }	 
}


void main(){

int i,length;


printf("............................Program for RSA cryptosystem..........................\n");
printf("Enter Two large prime numbers P and Q \n");
printf("Enter the value of P\n");
scanf("%d",&p);
printf("Enter the value of Q\n");
scanf("%d",&q);

//calculating n=p*q
n=p*q;
//calculating phi(n)=(p-1) * (q-1)
phi=(p-1)*(q-1);

//calculating the public key  e
e=decideE();

//computing private key d
d=inverse();

printf("%d\n",e);
printf("%d\n",d);

puts("Enter the length ogf array\n");
scanf("%d",&length);
puts("Enter the numeric message array\n");
for(i=0;i<length;i++){
	scanf("%d",&message[i]);
}

encrypt_message(length);
printf("\n");
decrypt_message(length);

}

