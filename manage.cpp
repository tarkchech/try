#include<iostream>
#include<cstdlib>
#include<string>
struct student
{
	std::string code;
	int score;
};
int main()
{
	using namespace std;
	int choicecode, count;
	string ultichoice;
	char cyclecode;
	int enter_flag=0;
	student* table = nullptr;
	do
	{
		cout << "Which function of score management system do you want to operate? " << endl;
		cout << "Press <1><ENTER> to enter students' score. Press <2><ENTER> to search an individual's score. " << endl;
		cout << "Enter your choice: ";
		(cin >> choicecode).get();
		if (choicecode == 1 && enter_flag == 0)
		{
			cout << "How many student's scores are you going to catalog? ";
			(cin >> count).get();
			if (count <= 0)
			{
				cout << "Invalid input! The program will be restarted!\n";
				continue;
			}
			table = new student[count];
			for (int i = 0;i < count;i++)
			{
				cout << "Student #" << i + 1 << ":\n";
				cout << "Please enter this student's code: ";
				getline(cin, table[i].code);
				cout << "Now please enter this student's score: ";
				(cin >> table[i].score).get();
			}
			cout << endl;
			int max = table[0].score;
			int min = table[0].score;
			int sum = table[0].score;
			for (int i = 1;i < count;i++)
			{
				if (table[i].score > max)
					max = table[i].score;
				if (table[i].score < min)
					min = table[i].score;
				sum += table[i].score;
			}
			double avg = sum * 1.0 / count;
			cout << "The maximum score in the whole class is: " << max << endl;
			cout << "The minimum score in the whole class is: " << min << endl;
			cout << "The average score of the whole class is: " << avg << endl;
			enter_flag = 1;
			continue;
		}
		if (choicecode == 1 && enter_flag == 1)
		{
			cout << "You had already entered a series of data!\n";
			cout << "You can search an individual's score instead!\n";
			continue;
		}
		if (choicecode == 2 && enter_flag == 0)
		{
			cout << "No data has been entered yet. Please enter students' scores first!\n";
			continue;
		}
		if (choicecode == 2 && enter_flag == 1)
		{
			do
			{
				cin.clear();
				string enter_code;
				cout << "Please enter the code of the student whose score will be searched next: ";
				getline(cin, enter_code);
				for (int i = 0;i < count;i++)
				{
					if (enter_code == table[i].code)
					{
						cout << "This student's score is: " << table[i].score << endl;
						break;
					}
				}
				cout << "Enter <#> to quit. Enter <1> to search another score: ";
				cin.get(cyclecode);
			} while (cyclecode != '#');
			break;
		}
		cout << "Do you want to end the whole program? Enter YES to continue. Enter NO to end. ";
		getline(cin, ultichoice);
	} while (ultichoice!="NO");
	delete[] table;
	system("pause");
	return 0;
}