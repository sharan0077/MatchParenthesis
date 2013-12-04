#include "parenthesisLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack/stackLib.h"
int doesParenthesisMatch(String text){
	int i,peek;
	char* temp;
	Stack* parenthesis= create(sizeof(String),1);
	for(i=0;i<sizeof(String);i++){
		temp = top(parenthesis); 
		if(text[i]=='{' || text[i]=='[' || text[i]=='('){
			push(parenthesis,&text[i]);
			continue;
		}
		if((text[i]=='}' || text[i]==')' || text[i]==']') && (isEmpty(parenthesis))){
			push(parenthesis,&text[i]);
			break;
		}
		if(text[i]=='}' && *temp=='{')
			pop(parenthesis);
		else if(text[i]==')' && *temp=='(')
			pop(parenthesis);
		else if(text[i]==']' && *temp=='[')
			pop(parenthesis);
	}
	peek = parenthesis->top;
	free(parenthesis->baseAddress);
	free(parenthesis);
	return (peek == -1);
}