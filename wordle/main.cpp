#include "std_lib_facilities.h"

void get_words(vector<string>& words);
void dictionary(vector<string> words);
void game_menu(vector<string> words);
void game_play(vector<string> words);

void menu()
{
	cout << "<<<wordle>>>\n"
		<< "1. Dictionary\n"
		<< "2. Game\n"
		<< "3. Exit\n" << endl;

	return;
}

void get_words(vector<string>& words)
{
	ifstream set{ "words.txt" };

	if (!set) error("can't open file ", "words.txt");

	string word;

	while (!set.eof())
	{
		set >> word;

		words.push_back(word);
	}

	sort(words);
}

void dictionary(vector<string> words)
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

		for (string x : words) {
			cout << x << endl;
		}

		cout << "\nA total of " << words.size() << " words are available\n" << endl;

		dictionary(words);
	}

	else {
		cout << endl;
		return;
	}
}

void game_menu(vector<string> words)
{
	short g_sel = 0;

	cout << "[ GAME ]\n"
		<< "1. Play\n"
		<< "2. Return\n" << endl;

	do {
		cout << "Choose an option (1-2): ";

		cin >> g_sel;
	} while (g_sel > 2);

	if (g_sel == 1) {
		game_play(words);
	}

	else {
		cout << endl;
		return;
	}
}

void game_play(vector<string> words)
{	
	short i = 0, j = 0;

	string user_in;

	cout << "\nA new 5-letter word has been chosen randomlyfrom the dictionary." << endl;

	string answer = words[randint(2023)];

	cout << answer;

	for (i = 0; i < 6; i++) {
		cout << "\n[" << i + 1 << "/6] Guess the word: ";
		cin >> user_in;

		if (user_in == answer) {
			cout << "\nCongratulation!!! Your guess is correct.\n" << endl;
			break;
		}

		cout << "==>";

		for (j = 0; j < 5; j++) {
			if (user_in[j] == answer[j]) {
				cout << "*";
			}
			else if (answer.find(user_in[j]) < 5) {
				cout << "#";
			}
			else cout << "@";
		}
		cout << endl;
	}

	if (i == 6) cout << "\nOoops!!! You lost all your chances. The correct answer is \"" << answer << "\"\n" << endl;

	game_menu(words);
}

int main()
{
	short sel = 0;

	vector<string> words;

	get_words(words);

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
			dictionary(words);
		}

		else if (sel == 2) {
			cout << endl;
			game_menu(words);
			cout << endl;
		}

		else {
			cout << "\nGood bye!!!" << endl;
			return 0;
		}
	}

	return 0;
}