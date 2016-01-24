#include<stdio.h>
#include<string.h>
char* compress(char *);
int main()
{
	char srcstr[150];
	printf("Enter the string to compress : ");
	scanf("%[^\n]%*c",srcstr); // %[^\n]%*c is used to scan string with space
	printf("Compressed String : %s",compress(srcstr));
	return 0;
}
char* compress(char* str)
{
	int i,j,count=1;
	char comps[150]="",temp1[150],temp2[150];
	for(i=0;str[i]!='\0';i++)
	{
		j=i+1;
		while(str[i]==str[j]&&str[j]!='\0')
		{
			count++;
			j++;
		}
		sprintf(temp1,"%c",str[i]); //temp variable to store repeated character
		i=j-1;
		if(count>2)
		{
			sprintf(temp2,"%d",count); // if count > 2 count is stored
			strcat(temp1,temp2);
			strcat(comps,temp1);
		}
		else if(count==2)
		{
			sprintf(temp2,"%c",str[i]);   // else character itself is printed
		    	strcat(temp1,temp2);
			strcat(comps,temp1);
		}
		else
		{
			strcat(comps,temp1);        // when character is not repeated same character is stored in string
		}
		count=1;
	}
	return comps;
}
