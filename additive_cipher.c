#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){

char table[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int i,key,k,n;
char message[20],search;

printf("..............Program for additive cipher...........\n");

printf("Enter the message to be trsnsfered\n");
gets(message);
strlwr(message);
printf("Enter the key...plese enter the number <= 26\n");
scanf("%d",&key);

n=strlen(message);
int message_table[n];

for(i=0;i<n;i++){
search=message[i];
for(k=0;k<26;k++){
if(table[k]==search){
break;
}
}
   message_table[i]=k;
}

//for(i=0;i<n;i++)
//printf("%d ",message_table[i]);

int encrypt_table[n];
for(i=0;i<n;i++)
encrypt_table[i]=(message_table[i]+key)%26;

//for(i=0;i<n;i++)
//printf("%d ",encrypt_table[i]);

char encrypt_message[n];
for(i=0;i<n;i++){
encrypt_message[i]=table[encrypt_table[i]];
}

puts(encrypt_message);

int decrypt_table[n];
for(i=0;i<n;i++){
	
		decrypt_table[i]=(26+encrypt_table[i]-key)%26;
	

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
