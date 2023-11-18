#include <stdio.h>
#include <stdlib.h>

int main(void){

    char *string;
    size_t maxlen = 10;
    int ret = EOF + 1;

    string = (char *) malloc(sizeof(char)*maxlen);
    ret = getline(&string, &maxlen, stdin);

    while(ret != EOF){
	printf("VALID\n");
	ret = getline(&string, &maxlen, stdin);
    }

    printf("Used end of file input\n");
    free(string);
    return 0;
}
