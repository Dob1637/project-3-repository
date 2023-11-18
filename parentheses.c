#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char *string;
    size_t maxlen = 10;
    int ret = EOF + 1;
    int paralen = 0;
    int i;
    char para_array[100];

    string = (char *) malloc(sizeof(char)*maxlen);
    ret = getline(&string, &maxlen, stdin);

    while(ret != EOF)
    {
	for(i = 0; i < ret - 1; i++)
	{
	    if((string[i]) == ')' && para_array[paralen - 1] == '(')
	    {
		paralen -= 1;		
	    }
	    else if((string[i]) == '}' && para_array[paralen - 1] == '{')
	    {
		paralen -= 1;
	    }
	    else if((string[i]) == ']' && para_array[paralen - 1] == '[')
	    {
		paralen -= 1;
	    }
	    else if((string[i]) == '}' && para_array[paralen - 1] != '{')
	    {
	        paralen += 1;
		break;
	    }
	    else if((string[i]) == ')' && para_array[paralen - 1] != '(')
	    {
		paralen += 1;
	        break;
	    }
	    else if((string[i]) == ']' && para_array[paralen - 1] != '[')
	    {
	        paralen += 1;
		break;
	    }
	    else if((string[i]) == '(' || string[i] == '{' || string[i] == '[')
	    {
		para_array[paralen] = string[i];
		paralen += 1;
	    }
	}

	if(paralen == 0)
	{
	    printf("VALID\n");
	}
	else
	{
	    printf("NOT VALID\n");
	}
	for(i=0; i<100; i++)
	{
	    para_array[i] = '0';
	}
	paralen = 0;
	ret = getline(&string, &maxlen, stdin);
    }

    free(string);
    return 0;
}
