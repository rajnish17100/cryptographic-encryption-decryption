#include<stdio.h>
#include<string.h>
void main(){
char message[30],encrypt_message[30],decrypt_message[30];
int n,i,j,extra,count,length;

printf(".........Program for KEYED CIPHER............\n");

printf("Enter the message\n");
gets(message);
//puts(message);

printf("Enter the number in which message has to be divided\n");
scanf("%d",&n);
//check if  length of  the message is divisible by n
if(strlen(message)%n!=0){
//add bogos character at the end of message
extra=(n-(strlen(message)%n))%n;
length=strlen(message);
for(i=0;i<extra;i++){
message[length+i]='x';
}
}
puts(message);
int key[n],key2[n];

printf("Enter the key array\n");
for(i=0;i<n;i++){
scanf("%d",&key[i]);
}

//finding key for decryption
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(key[j]==i){
		
		key2[i]=j;
		break;
	   }
	}
	
}

printf("\nPrinting key2:  ");
for(i=0;i<n;i++){
printf(" %d ",key2[i]);
}


//encryption
length=strlen(message);
count=0;
for(j=0; j < (length/n); j++){
  for(i=0;i<n;i++){
  	encrypt_message[count+i]=message[count+key[i]];
  }
  count=count+n;
}

printf("\nEncrypted  message is :");
for(i=0;i<length;i++){
	printf("%c",encrypt_message[i]);
}

//decryption
count=0;
for(j=0; j < (length/n); j++){
  for(i=0;i<n;i++){
  	decrypt_message[count+i]=encrypt_message[count+key2[i]];
  }
  count=count+n;
}

printf("\ndecrypted  message is :");
for(i=0;i<length-extra;i++){
	printf("%c",decrypt_message[i]);
}


}
