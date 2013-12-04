#include "testUtils.h"
#include "parenthesisLib.h"
#include "../stack/stackLib.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_doesParenthsysMatch_should_accept_text_and_return_true_if_parethesis_match(){
	int result;
	String text = "{abv}";
	result = doesParenthesisMatch(text);
	ASSERT(result);
}
void test_doesParenthsysMatch_should_accept_text_and_return_false_if_parethesis_dont_match(){
	int result;
	String text = "{abv{";
	result = doesParenthesisMatch(text);
	ASSERT(result==0);
}
void test_doesParenthsysMatch_should_accept_text_and_return_true_for_multiple_parenthesis(){
	int result;
	String text = "{a[b]v}";
	result = doesParenthesisMatch(text);
	ASSERT(result);
}
void test_doesParenthsysMatch_should_accept_text_and_return_false_for_multiple_parenthesis(){
	int result;
	String text = "[b]v{";
	result = doesParenthesisMatch(text);
	ASSERT(result==0);
}
void test_doesParenthsysMatch_should_accept_text_and_return_false(){
	int result;
	String text = "[b]v}";
	result = doesParenthesisMatch(text);
	ASSERT(result==0);
}
void test_doesParenthsysMatch_should_return_false_for_multiple_parenthesis(){
	int result;
	String text = "a}uuh";
	result = doesParenthesisMatch(text);
	ASSERT(result==0);
}