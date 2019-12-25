#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){

char table[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int i,key1,key2,k,n,mul_inverse;
char message[50],search;

printf("..............Program for additive cipher...........\n");

printf("Enter the message to be trsnsfered\n");
gets(message);
strlwr(message);

printf("Enter the first key...plese enter the number <= 26 ...also number should be such that gcd(num,key)=1 ....\n");
scanf("%d",&key1);
printf("Enter the second key...plese enter the number <= 26\n");
scanf("%d",&key2);

n=strlen(message);
int message_table[n];

//showing the numerical value of all the letters in the message.....
for(i=0;i<n;i++){
search=message[i];
for(k=0;k<26;k++){
if(table[k]==search){
break;
}
}
   message_table[i]=k;
}

for(i=0;i<n;i++)
printf("%d ",message_table[i]);
printf("\n");

//encrypting the data...
int encrypt_table[n];
for(i=0;i<n;i++)
encrypt_table[i]=(message_table[i]*key1+key2)%26;

for(i=0;i<n;i++)
printf("%d ",encrypt_table[i]);
printf("\n");

char encrypt_message[n];
for(i=0;i<n;i++){
encrypt_message[i]=table[encrypt_table[i]];
}

puts(encrypt_message);

//FINDING MULTIPLICATIVE INVERSE OF A NUMBER
for(i=0;i<26;i++){
  if((key1*i)%26==1){
  	break;
  }
}
mul_inverse=i;

//DECRYPTING THE DATA.....
int decrypt_table[n];
for(i=0;i<n;i++){

		decrypt_table[i]=((26+encrypt_table[i]-key2)*mul_inverse)%26;
	
   
}
//for(i=0;i<n;i++)
//printf("%d ",encrypt_table[i]);

char decrypt_message[n];

for(i=0;i<n;i++){
decrypt_message[i]=table[decrypt_table[i]];
}


for(i=0;i<n;i++)
printf("%c",decrypt_message[i]);


}




