#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){
int i,j,n,t,k,x,t1,t2,t3,t4;
char message[100],message1[100];
char key[5][5]={
                 {'l','g','d','b','a'},
				 {'q','m','h','e','c'},
				 {'u','r','n','i','f'},
				 {'x','v','s','o','k'},
				 {'z','y','w','t','p'}
			   };

printf("..............Program for Playfair cipher...........\n");
printf("Enter the message to be trsnsfered\n");
gets(message);
strlwr(message);
n=strlen(message);

for(i=0;i<n;i++){
	message1[i]=message[i];
}
printf("\nPrinting the original message: ");
puts(message1);
//checking for the consecutive same character and adding extra char if found same
for(i=0;i<n;i++){
	if(message[i]==message[i+1]){
	for(t=i+2;t<n+1;t++){
		message1[t]=message[t-1];
		
	}	
	message1[i+1]='x';	
	}
}

printf("\nPrinting the altered message: ");
for(i=0;i<strlen(message1);i++){
	printf("%c",message1[i]);
	
}
n=strlen(message1);

//checking the length of the message
if(n%2!=0){
	message1[n]='x';
	//n=n+1;
}
n=strlen(message1);
//encrypting the message
char encrypted_message[n],p,q;

k=0;//k is used for incrementing the size of the encrypted_message;
for(i=0;i<strlen(message1);i=i+2){
    p=message1[i];
	q=message1[i+1];
	for(x=0;x<5;x++){
		for(j=0;j<5;j++){
			if(key[x][j]==p){
				t1=x;t2=j;
				
			}
			if(key[x][j]==q){
				t3=x;t4=j;
				//printf(" t1=%d, t2=%d, t3=%d,t4=%d",t1,t2,t3,t4);
				
			}
		}
	}
	if(t1==t3){
		encrypted_message[k++]=key[t1][t2+1];
		encrypted_message[k++]=key[t3][t4+1];
	}
	else if(t2==t4){
		encrypted_message[k++]=key[t1+1][t2];
		encrypted_message[k++]=key[t3+1][t4];
	}
	else{
	    encrypted_message[k++]=key[t1][t4];
		encrypted_message[k++]=key[t3][t2];	
	}	
}

printf("\nEncrypted message is: ");
//puts(encrypted_message);
for(i=0;i<n;i++){
printf("%c",encrypted_message[i]);
}


//decrypting the message
char decrypted_message[n];
k=0;//k is used for incrementing the size of the encrypted_message;
for(i=0;i<n;i=i+2){
    p=encrypted_message[i];
	q=encrypted_message[i+1];
	for(x=0;x<5;x++){
		for(j=0;j<5;j++){
			if(key[x][j]==p){
				t1=x;t2=j;
				
			}
			if(key[x][j]==q){
				t3=x;t4=j;
				//printf(" t1=%d, t2=%d, t3=%d,t4=%d",t1,t2,t3,t4);
				
			}
		}
	}
	if(t1==t3){
		decrypted_message[k++]=key[t1][t2-1];
		decrypted_message[k++]=key[t3][t4-1];
	}
	else if(t2==t4){
		decrypted_message[k++]=key[t1-1][t2];
		decrypted_message[k++]=key[t3-1][t4];
	}
	else{
	    decrypted_message[k++]=key[t1][t4];
		decrypted_message[k++]=key[t3][t2];	
	}	
}

printf("\nDecrypted message is: ");
for(i=0;i<n;i++){
printf("%c",decrypted_message[i]);
}
 
}
