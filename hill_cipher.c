#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){

char table[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int n,m,i,j,k;
char message[20],search;

printf("..............Program for HILL cipher...........\n");

printf("Enter the message to be trsnsfered\n");
gets(message);
m=strlen(message);
strlwr(message);

printf("Enter the size of matrix >= %d u want to take for the key\n",m);
scanf("%d",&n);

int key_matrix[n][n];
printf("Enter the element of the matrix\n");
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		scanf("%d",&key_matrix[i][j]);
	}
}

 
int message_table[m];

for(i=0;i<m;i++){
search=message[i];
for(k=0;k<26;k++){
if(table[k]==search){
break;
}
}
   message_table[i]=k;
}


//for(i=0;i<m;i++)
//printf("%d ",message_table[i]);
//printf("\n");
//transpose of the the message_table matrix


int message_matrix[m][1];

for(i=0;i<m;i++){
	message_matrix[i][0]=message_table[i];
}

//for(i=0;i<m;i++){
//	for(j=0;j<1;j++){
//       printf("%d\n",message_matrix[i][j]);	
//	}
// }

//multiplying the two matrices..
int sum=0;
int encrypted_matrix[m][1];

for (i = 0; i<n; i++) {
      for (j = 0; j < 1; j++) {
        for (k = 0; k < m; k++) {
          sum = sum + key_matrix[i][k]*message_matrix[k][j];
        }
 
        encrypted_matrix[i][j] = sum % 26;
        sum = 0;
      }
    }

printf("\n");

//printing the encrypted matrix
for(i=0;i<m;i++){
    for(j=0;j<1;j++){
       printf("%d\n",encrypted_matrix[i][j]);	
	}
}
//working on to produce encrypted message...
char encrypt_message[m];
for(i=0;i<m;i++){
encrypt_message[i]=table[encrypted_matrix[i][0]];
}

printf("\n");
//printing the encrypted message....
for(i=0;i<m;i++){
    for(j=0;j<1;j++){
       printf("%c\n",encrypt_message[i]);	
	}
}




}
