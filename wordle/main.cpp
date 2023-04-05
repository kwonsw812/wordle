#include "std_lib_facilities.h"

void dictionary();
void game();

void menu()
{
	int sel;

	cout << "<<<wordle>>>\n"
		<< "1. Dictionary\n"
		<< "2. Game\n"
		<< "3. Exit\n\n"
		<< "Choose an option (1-3): ";

	cin >> sel;

	switch (sel)
	{
	case 1:
		dictionary();
		break;

	case 2:
		game();
		break;

	case 3:
		return;

	default:
		menu();
		break;
	}

}

void dictionary()
{

}

void game()
{

}



int main()
{
	ifstream set{ "words.txt" };

	if (!set) error("can't open file ", "words.txt");

	vector<string> words;

	string word;

	while (!set.eof())
	{
		set >> word;

		words.push_back(word);
	}

	sort(words);

	menu();

	return 0;
	//for (string x : words) {
	//	cout << x << "\n" << endl;
	//}
}