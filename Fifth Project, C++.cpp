#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

/*
Task 1:
Write a function that accepts as parameters the name of a file with n lines and in each line n real numbers. The function must read the file into a two-dimensional array created by dynamic allocation and return the address of the array. A variable containing the size of the matrix will be accepted in the function as a pointer. The first line in the file will contain n.
For example, a file with a 4x4 matrix will look like this:
4
9.7 17.5 2.4 11.6
3.2 59.7 -7.1 43.8
4.5 6.8 22.7 35.2
-5.2 16.0 7.8 25.3
*/

double** read_mat(string filename, int* size)
{
	ifstream file(filename); // Creating a command to read from a file
	if (!file) // Condition if it is not possible to read from the file 
	{
		cout << "Can't open your file! " << endl;  
		exit(1);
	}
	file >> *size; // Entering the file size
	double** old_arr = new double* [*size]; //  Setting the file variable
	for (int i = 0; i < *size; i++) // Double loop to the matrix 
	{
		old_arr[i] = new double[*size];
		for (int j = 0; j < *size; j++)
		{
			file >> old_arr[i][j]; // Reading the matrix file from the file
		}
	}
	file.close(); // This command should be added at the end of reading from a file
	return old_arr; // A double function must return a value
}
void printmatrix(double** arr, int size) // A function to print a two-dimensional array 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl; 
	cout << endl; 
}

/*
Write a function named:
double * smallernum (double** arr, int size, double num, int* newsize)

which receives a pointer to the matrix read from the file in task 1 and its size, a real number and also a pointer to an integer.
The function will copy from the array all the numbers smaller than the given number.
The function will create a new array with the help of a dynamic memory allocation of size *newsize containing only the elements that are smaller than the given number of the original matrix, the function will return the pointer to the new array and its size as a parameter.
For example: input: num=10, output:
*new_size=8,new_array={9.7,2.4,3.2,-7.1,4.5,6.8,-5.2,7.8}
*/

double* smallernum(double** old_arr, int size, double num, int* newsize) // A function for the second task - printing small numbers
{
	ifstream file("numbers.txt"); // Definition of reading from text
	if (!file) // Condition if it is not possible to read from the file 
	{
		cout << "Can't open your file! " << endl;
		exit(1);
	}
	*newsize = 0;
	for (int i = 0; i < size; i++) // Defining a two-dimensional loop 
	{
		for (int j = 0; j < size; j++) 
		{
			if (old_arr[i][j] < num) // Setting a condition if the number is small in the array
			{
				(*newsize)++; // Adding the number
			}
		}
	}
	double* a = new double[*newsize]; // Defining a variable of type double
	for (int i = 0, k = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (old_arr[i][j] < num) // Setting a condition for the task 2
			{
				a[k] = old_arr[i][j]; // Defining a new array for receiving numbers that meet the condition
				k++; // Adding numbers in which the condition is met
			}
		}
	}
	return a; // A function of type double must return a value
}
void print_new_arrey(double* new_arr, int* newsize) // Setting up a function to print the new array
{
	cout << "(";
	for (int i = 0; i < *newsize; i++) // Setting up a print loop in assignment number 2
	{
		cout << " " << new_arr[i] << ", ";
	}
	cout << ")";
	cout << endl;
	cout << endl; 
	cout << endl; 
}

/*
התרגום ארוך מדי לשמירה
Write a function that accepts the name of a file with text, where a single space separates the words in the file and also accepts the variable ch of char type.
The function should find and write all the words in the file starting with the letter ch into a new string.
The function must return a string with all the words starting with ch.
The function title is:
string words_begin(string filename, char ch)
For example:
Given a file with the following text:
Strangers in the night, exchanging glances
Wondering in the night; what were the chances?
We'd be sharing love before the night was through
Something in your eyes was so inviting
Something in your smile was so exciting
Something in my heart told me I must have you
Strangers in the night, two lonely people
We were strangers in the night.
and the letter (ch): 's'
A string that a function will return will be:

sharing so smile so strangers
*/

string words_begin(string filename, char ch) // Defining a function for task number 3
{
	int count = 0; // Defining a new variable equal to zero
	string word, new_word; // Defining two string variables
	ifstream Newfile(filename); // Setting up a command to read from a file
	if (!Newfile) // Condition if it is not possible to read from the file 
	{
		cout << "Can't open your file! " << endl;
		exit(1);
	}
	while (Newfile >> word) // Condition definition
	{
		if (word[0] == ch) // If my word is equal to ch
		{
			new_word += word + ", "; // substitution of the word
			count++;
		}
	}
	cout << endl;
	Newfile.close();
	return new_word; // The sting function must return a value
}
int main() // main function
{

		//Opening messages
		cout << "Matala_05 by Ariel Topaz\n\n";
		cout << "Choose opertion from the menu below\n\n";

		char opCod; // Setting a variable to the menu
		do
		{
			cout << "Menu: \n"
				"0. for Exit \n"
				"1. for read and print matrix from file function \n"
				"2. for print array with smaller numbers from matrix function \n"
				"3. for print words begins with  given char from file function \n"
				"Please enter your choice luna: \n";
			cin >> opCod;
			if (opCod == '0') // Result of choice 0
			{
				cout << "Exiting The Progtam, have a nice day." << endl << endl << endl << endl;//exit messeg
				exit(1);
			}
			if (opCod == '1') // Assignment of task 1
			{
				cout << endl;
				cout << "you chose for read and print matrix from file function." << endl;
				cout << endl;
				string filename = "numbers.txt"; // Defining a file variable
				int size; // Defining a variable of type size
				double** arrey = read_mat(filename, &size); // function call 
				if (arrey == NULL) // Setting a condition if the function is empty
				{
					cout << " empty matrix !!! \n";
				}
				cout << "the matrix is:" << endl;  
				cout << size << endl;
				printmatrix(arrey, size); // Calling a second function - printing an array
				for (int i = 0; i < size; i++) // Loop definition
				{
					delete[]arrey[i];
				}
				delete[]arrey;
			}
			if (opCod == '2') // Assignment of task 2
			{
				cout << "you chose print array with smaller numbers from matrix function." << endl;
				string filename = "numbers.txt"; // Defining a file variable   
				int size; // Defining a variable of type size
				int newsize = 0; // Defining an empty variable
				double num = 0; // Defining an empty variable
				cout << "enter number for num: \n";
				cin >> num;
				double** old_arr = read_mat(filename, &size); // function call 
				if (old_arr == NULL) // Setting a condition if the function is empty
				{
					cout << "empty matrix !!! \n";
				}
				cout << "Your old matrix is:" << endl;
				cout << endl; 
				cout << size << endl;
				printmatrix(old_arr, size); // Calling a second function - printing an array
				double* new_arr = smallernum(old_arr, size, num, &newsize); // function call 
				if (new_arr == NULL)
				{
					cout << " empty new arrey !!! \n";
				}
				cout << " *newsize = " << newsize << ", new_arrey = ";
				cout << endl; 
				print_new_arrey(new_arr, &newsize);
				for (int i = 0; i < size; i++)
				{
					delete[]old_arr[i];
				}
				delete[]old_arr; // Release of memory due to dynamic definition
				delete[]new_arr; // Release of memory due to dynamic definition
			}
			if (opCod == '3') // Placement of task 3
			{
				cout << "you chose print words begins with  given char from file function:" << endl;
				cout << endl;
				char ch; // Defining a variable of type char
				string filename = "strangers.txt"; // Setting a file name
				cout << "please enter latter:"; // Output for receiving a letter 
				cout << endl;
				cin >> ch; // Input to receive a number
				string final_words = words_begin(filename, ch); // Placement of the function 
				if (final_words == "") // Definition of a condition if the function is empty
				{
					cout << "empty string.";
					exit(1);
				}
				cout << "the final words are: " << final_words << endl << endl;
			}
		} while (1);
		return 0; 
	}