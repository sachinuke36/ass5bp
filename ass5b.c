#include<stdio.h>
#include<stdlib.h>
void encrypt(char* s1, int enc_key[], int len)
{
	for(int i=0,j=0; s1[i]!='\0'; i++) 
	{   
	    if(s1[i]==' ' || !((s1[i]>=65 && s1[i]<=90) || (s1[i]>96 && s1[i]<=122) )) //skipping the white spaces
	    
	    {
	        j=0;
	        continue;
	    }
	    if(s1[i]>='a' && s1[i]<='z'){
	    if((int)s1[i]+enc_key[j]>122) s1[i]=s1[i]-26; 
		s1[i]= s1[i]+ enc_key[j]; //changing the asci value by adding key
		j++;
	}
   if(s1[i]>='A' && s1[i]<='Z'){
	if((int)s1[i]+enc_key[j]>90)  s1[i]=s1[i]-26; 
		s1[i]= s1[i]+ enc_key[j]; //changing the asci value by adding key
		j++;
	}

}}

void decrypt(char* s1, int enc_key[], int len)
{
	for(int i=0,j=0; s1[i]!='\0'; i++) 
	{   
	    if(s1[i]==' ' || !((s1[i]>=65 && s1[i]<=90) || (s1[i]>96 && s1[i]<=122) )) //skipping the white spaces
	    
	    {
	        j=0;
	        continue;
	    }
	    if(s1[i]>='a' && s1[i]<='z'){
	    if((int)s1[i]-enc_key[j]<97) s1[i]=s1[i]+26; 
		s1[i]= s1[i]- enc_key[j]; //changing the asci value by adding key
		j++;
	}
   if(s1[i]>='A' && s1[i]<='Z'){
	if((int)s1[i]-enc_key[j]<65)  s1[i]=s1[i]+26; 
		s1[i]= s1[i]- enc_key[j]; //changing the asci value by adding key
		j++;
	}

}}


int main()
{
	char s1[100]; int enc_digit[1000]={0};
	int enc_key,enc_key_copy;

	printf("Enter the string \n");
	scanf("%[^\n]s",s1);//taking string as input
	
	printf("Enter the encription key \n");
	scanf("%d",&enc_key);//taking encription key as input

	int n=0;
	int i=0;
	int len=0;
	int j=0;

    //finding length of string
	while(s1[i]!='\0')
	   {
		len++;
		i++;
		}

  //copying encription key into an array
	enc_key_copy=enc_key;
	for( j=0; j<len; j++)
	{
	    enc_digit[j]=enc_key%10;
	    enc_key=enc_key/10;
	    if(enc_key==0) enc_key = enc_key_copy;
	    n++;
	}

	encrypt(&s1[0],&enc_digit[0],len);//function calling
	decrypt(&s1[0],&enc_digit[0],len);
	
	printf("%s",s1);

}

