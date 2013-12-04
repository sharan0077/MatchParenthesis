#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_doesParenthsysMatch_should_accept_text_and_return_true_if_parethesis_match();
	tearDown();

	setup();
		test_doesParenthsysMatch_should_accept_text_and_return_false_if_parethesis_dont_match();
	tearDown();

	setup();
		test_doesParenthsysMatch_should_accept_text_and_return_true_for_multiple_parenthesis();
	tearDown();

	setup();
		test_doesParenthsysMatch_should_accept_text_and_return_false_for_multiple_parenthesis();
	tearDown();

	setup();
		test_doesParenthsysMatch_should_accept_text_and_return_false();
	tearDown();

	setup();
		test_doesParenthsysMatch_should_return_false_for_multiple_parenthesis();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
