#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){


int i,j,n,temp=0;
char message[100],message1[100];

printf(".............. Program for KEYLESS TRANSPORTATION ... METHOD1 ... NUMBER OF ROW IS FIXED TO 2 ...........\n");
printf("Enter the message to be trsnsfered\n");
gets(message);
//strlwr(message);
n=strlen(message);
//puts(message);
//printf("Length of the strinfg is %d\n",n);

//removing spaces from the message
for(i=0;i<n;i++){
	if(message[i]==' '){
		i++;
	}
	message1[temp++]=message[i];
}

printf("\nSpace Removed  Message : ");
puts(message1);
n=strlen(message1);

//encrypting the message

char encrypted_message[2][n];

//filling all elements with space value due to some reason
for(i=0;i<2;i++){
	for(j=0;j<n;j++){
		encrypted_message[i][j]=' ';
	}
}

//now filling the actual character
for(j=0;j<n;j++){
	encrypted_message[j%2][j]=message1[j];
}

//printf("%c",encrypted_message[1][2]);

//printing the encrypted message
for(i=0;i<2;i++){
	for(j=0;j<n;j++){
		printf("%c",encrypted_message[i][j]);
	}
	printf("\n");
}
n=strlen(message1);
char encrypted_message1[n];
int k=0;
for(i=0;i<2,k<n;i++){
	for(j=0;j<n;j++){
		if(encrypted_message[i][j]==' '){
			j++;
		}
		encrypted_message1[k++]=encrypted_message[i][j];
		//printf(" %d%c ",k,encrypted_message1[k]);
		
	}
}
printf("Encrypted Message :\n");
puts(encrypted_message1);

//decrypting the message
char decrypted_message[n];
for(i=0;i<n;i++){
	decrypted_message[i]=encrypted_message[i%2][i];
}

printf("\nDecrypted Message is:");
puts(decrypted_message);

}
