/*
Angel Guanill #137916
Andrés Rodríguez #113408
CECS 2222-22
*/

#include <iostream>
using namespace std;

int* getQuestionsInTest();
void getTestAnswers(char*, int*);
void getStudentAnswers(char*, int*);
int* checkAnswers(char*, char*, bool*, int*);
void passOrNot(int*, int*);
void showWrongAnswers(char*, char*, bool*, int*);

int main() {
	const int SIZE = 20;
	int* questionsInTest = nullptr, * counters;
	char* correctAnswers1 = nullptr, * studentAnswers1 = nullptr, correctAnswers[SIZE], studentAnswers[SIZE];;
	bool* checkedAnswers1 = nullptr, checkedAnswers[SIZE];

	correctAnswers1 = correctAnswers;
	checkedAnswers1 = checkedAnswers;
	studentAnswers1 = studentAnswers;

	questionsInTest = getQuestionsInTest();
	getTestAnswers(correctAnswers, questionsInTest);
	getStudentAnswers(studentAnswers, questionsInTest);
	counters = checkAnswers(correctAnswers, studentAnswers, checkedAnswers, questionsInTest);
	passOrNot(counters, questionsInTest);

	if (counters[1] != 0)
	{
		showWrongAnswers(correctAnswers, studentAnswers, checkedAnswers, questionsInTest);
	}

	return 0;
}

//Pide el numero de preguntas
int* getQuestionsInTest() {
	int* questionsInTest = new int;
	cout << "Questions in the test: ";
	cin >> *questionsInTest;
	return questionsInTest;
}

//Almacena las respuestas del examen
void getTestAnswers(char* correctAnswers, int* numberQuestions)
{
	cout << "\nEnter correct answers.\n";
	for (int i = 0; i < *numberQuestions; i++) {
		cout << "Question " << i + 1 << ": ";
		cin >> correctAnswers[i];
		while (!(correctAnswers[i] > 64 && correctAnswers[i] < 69))
		{
			cout << "Invalid option, enter again from A to D on capital letter.\n";
			cout << "Question " << i + 1 << ": ";
			cin >> correctAnswers[i];
		}
	}
}

//Almacena las respuestas entradas por el estudiante
void getStudentAnswers(char* studentAnswers, int* numberQuestions)
{
	cout << "\nAnswer the test.\n";
	for (int i = 0; i < *numberQuestions; i++) {
		cout << "Question " << i + 1 << ": ";
		cin >> studentAnswers[i];
		while (!(studentAnswers[i] > 64 && studentAnswers[i] < 69) && !(studentAnswers[i] > 96 && studentAnswers[i] < 101))
		{
			cout << "Invalid option, enter again from A to D on capital letter.\n";
			cout << "Question " << i + 1 << ": ";
			cin >> studentAnswers[i];
		}
	}
}

//Revisa la cantidad de respuestas correctas e incorrectas
int* checkAnswers(char* correctAnswers, char* studentAnswers, bool* checkedAnswers, int* numberQuestions) {
	static int correctAndIncorrect[2] = { 0 };

	for (int i = 0; i < *numberQuestions; i++)
	{
		if (studentAnswers[i] == correctAnswers[i])
		{
			correctAndIncorrect[0] ++;
			checkedAnswers[i] = true;
		}
		else
		{
			correctAndIncorrect[1] ++;
			checkedAnswers[i] = false;
		}
	}
	cout << "\nCorrect Answers: " << correctAndIncorrect[0] << "\nIncorrect Answers: " << correctAndIncorrect[1];

	return correctAndIncorrect;
}

//Revisa si paso el examen o no
void passOrNot(int* correctAndIncorrect, int* numberQuestions) {

	if (double(correctAndIncorrect[0]) / double(*numberQuestions) > 0.74)
		cout << "\n\nYou passed the test.\n";
	else
		cout << "\n\nYou didn't pass the test.\n";
}

//Si ha respuestas incorrectas, las muestra.
void showWrongAnswers(char* correctAnswers, char* studentAnswers, bool* checkedAnswers, int* numberQuestions) {

	cout << "\nThe following questions were incorrectly answered: ";
	for (int i = 0; i < *numberQuestions; i++)
	{
		if (checkedAnswers[i] == false) {
			cout << "\n\nQuestion " << i + 1 << "\nYour Answer: " << studentAnswers[i]
				<< "\nCorrect Answer: " << correctAnswers[i];
		}
	}
	cout << endl;
}

