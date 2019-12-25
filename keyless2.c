#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){


int i,j,n,temp=0,column,row;
char message[100],message1[100];

printf(".............. Program for KEYLESS TRANSPORTATION ... METHOD2 ... NUMBER OF COLUMN  IS DECIDED AT THE TIME OF MESSAGE TRANSFER ...........\n");
printf("Enter the message to be trsnsfered\n");
gets(message);
printf("Enter the number of columns to be fixed\n");
scanf("%d",&column);


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

//deciding the number of rows on basis of number of columns
if(n % column == 0){
	row = n/column;
}
else{
	row = (n/column)+1;
}
//encrypting the message
char encrypted_message[row][column];
//filling all elements with space value due to some reason
for(i=0;i<row;i++){
	for(j=0;j<column;j++){
		encrypted_message[i][j]=' ';
	}
}

//filling actual values
int k=0;
for(i=0;i<row,k<n;i++){
	for(j=0;j<column;j++){
		encrypted_message[i][j]=message1[k++];
	}
}

//printing the encrypted message
for(i=0;i<row;i++){
	for(j=0;j<column;j++){
		printf(" %c ",encrypted_message[i][j]);
	}
	printf("\n");
}

//storing the encrypted message
char encrypted_message1[n];

for(j=0,k=0;j<column,k<n;j++){
	for(i=0;i<row;i++){
	encrypted_message1[k++]=encrypted_message[i][j];	
	}
}

printf("\nEncrypted message is : ");
puts(encrypted_message1);


//decrypting th emessage
char decrypted_message[n];
for(i=0,k=0;i<row,k<n;i++){
	for(j=0;j<column;j++){
		decrypted_message[k++]=encrypted_message[i][j];
	}
}

printf("\n Decrypted MEssage is :");
puts(decrypted_message);

}


