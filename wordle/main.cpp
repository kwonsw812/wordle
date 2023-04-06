#include "std_lib_facilities.h"

void dictionary();
void game_menu();
void game_play();

void menu()
{
	cout << "<<<wordle>>>\n"
		<< "1. Dictionary\n"
		<< "2. Game\n"
		<< "3. Exit\n";

	return;
}

void dictionary()
{
	short d_sel = 0;

	cout << "[ DICTIONARY ]\n"
		<< "1. Print\n"
		<< "2. Return\n\n";

	do {
		cout << "Choose an option (1-2): ";

		cin >> d_sel;
	} while (d_sel > 2);

	if (d_sel == 1) {
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

		for (string x : words) {
			cout << x << endl;
		}

		cout << "A total of " << words.size() << " words are available" << endl;

		dictionary();
	}

	else {
		cout << endl;
		return;
	}
}

void game_menu()
{
	short g_sel = 0;

	cout << "[ GAME ]\n"
		<< "1. Play\n"
		<< "2. Return\n";

	do {
		cout << "Choose an option (1-2): ";

		cin >> g_sel;
	} while (g_sel > 2);

	if (g_sel == 1) {
		game_play();
	}

	else {
		cout << endl;
		return;
	}
}

void game_play()
{
	
}

int main()
{
	short sel = 0;

	while (1)
	{
		menu();

		do
		{
			cout << "Choose an option (1-3): ";

			cin >> sel;
		} while (sel > 3);

		if (sel == 1) {
			cout << endl;
			dictionary();
		}

		else if (sel == 2) {
			cout << endl;
			game_menu();
		}

		else return 0;
	}

	return 0;

}