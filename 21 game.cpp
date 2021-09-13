#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

int nu = 1;
string usedCards[100];

void ShowCards(string& name, string handCards[18], int& sum, int& nh) {
	if (sum > 21) {
		cout << name << ": \n";
		for (int i = 1; i <= nh; ++i) {
			cout << handCards[i] << endl;
		}
		cout << "\n" << name << " покинул(-а) игру со счетом " << sum << "\n\n";
		sum = -1000;
	}
	else if (sum < 0) {
		cout << name << " покинул(-а) игру\n\n";
	}
	else {
		cout << name << ": \n";
		for (int i = 1; i <= nh; ++i) {
			cout << handCards[i] << endl;
		}
		cout << "____________Сумма очков: " << sum << "\n\n";
	}
}

void NewCard(string handCards[18], int& sum, int num[100], int& nh, string& name) {
	srand((unsigned)time(NULL)); //Автоматическая рандомизация
	string cards[9] = { "6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз" };
	string suit[4] = { " (червы)", " (пики)", " (трефы)", " (бубны)" };
	int values[9] = { 6, 7, 8, 9, 10, 2, 3, 4, 11 };
	string C;
	string S;
	string K;
	int c;
	int s;
	cout << endl;
randomCard:
	for (int i = 1; i <= nu; ++i) { //Проверяет массив только слева направо
		while (usedCards[i] == K) {
			c = rand() % 9;
			s = rand() % 4;
			C = cards[c];
			S = suit[s];
			K = C + S;
		}
	}
	for (int i = 1; i <= nu; ++i) { //Проверяет конечный массив еще раз на наличие совпадений
		if (usedCards[i] == K) {
			goto randomCard;
		}
	}
	num[nh] = values[c];
	usedCards[nu] = K;
	handCards[nh] = K;
	for (int i = nh; i < 100; ++i) {
		sum += num[i];
	}
	ShowCards(name, handCards, sum, nh);
	++nu;
}

void NewPlayer(int p, string& name, string handCards[18], int& sum, int num[100], int& nh) {
	if (p > 1) {
		system("pause");
	}
	system("cls");
	cout << "Введите имя " << p << " игрока и нажмите Enter: ";
	cin >> name;
	NewCard(handCards, sum, num, nh, name);
}

void StillStop(string& name, string handCards[18], int& sum, int num[100], int& nh, int p) {
	int T;
	if (sum >= 0 && sum <= 21) {
		if (p > 1) {
			system("pause");
		}
		system("cls");
		cout << "Ходит " << name << "\n\n";
		system("pause");
		cout << endl;
		ShowCards(name, handCards, sum, nh);
		cout << "Тянуть еще - 1\nХватит - 0\n\nВведите и нажмите Enter: ";
		while (!(cin >> T) || (cin.peek() != '\n') || T < 0 || T > 1) {
			cout << "\nНекорректный ввод, повторите попытку: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		if (T == 1) {
			++nh;
			NewCard(handCards, sum, num, nh, name);
		}
		if (T == 0) {
			cout << "\n" << name << " решает пропустить ход\n\n";
		}
	}
	else {
		if (p > 1) {
			system("pause");
		}
		system("cls");
		cout << "Ходит " << name << "\n\n";
		system("pause");
		cout << endl;
		ShowCards(name, handCards, sum, nh);
	}
}

int main() {
	SetConsoleCP(1251); //Нет необходимости в setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251); //Для корректного вывода русских символов в консоль (если не работает, необходимо поменять шрифт консоли на Lucida Console)
	cout << "Игра ДВАДЦАТЬ ОДНО";
	cout << "\n\nПравила игры\n\n\
     Сначала вам будет предложено ввести количество игроков и их имена, после чего каждо-\n\
му игроку присваиваются случайные номера, т.е. «выдаются карты».  В данной программе реа-\n\
лизована стандартная колода из 36 карт таким образом, чтобы карты не повторялись.  В кон-\n\
соли программы представлены игроки,  их карты со значениями и мастями и общее число очков\n\
для каждого игрока.  Количеством очков является сумма значений карт,  где числам присваи-\n\
ваются их нумерования, а валету, даме, королю и тузу — 2, 3, 4 и 11 соответственно.\n\
     После раздачи карт программа предлагает каждому игроку в порядке очереди  воспользо-\n\
ваться командами «Тянуть еще» или «Хватит», добавляя себе карты или оставляя те,  что «на\n\
руках», чтобы набрать 21.  Если игрок набирает большее количество очков,  то он автомати-\n\
чески проигрывает и выбывает, о чем оповещает программа.\n\
     Игра заканчивается в следующих случаях.  Во-первых,  если все игроки,  кроме одного,\n\
выбыли,  тогда оставшийся становится победителем.  Во втором случае все игроки воспользо-\n\
вались командой «Хватит»,  тогда побеждает тот,  кто набрал наибольшее  количество очков.\n\
Также игрок может набрать ровно 21 очко,  в данном случае он становится победителем, если\n\
остальные игроки сделали свой ход за этот круг.  И последнее: когда все игроки выбыли или\n\
у некоторых из них совпало  количество набранных очков,  программа предлагает сыграть еще\n\
раз.\n\
     Программа завершается, когда на предложение сыграть снова, игрок отвечает «нет».\n\n\
ВАЖНО: игроки не должны видеть карты друг друга! Каждый игрок вводит свое имя самостоятельно!\n";
	cout << "\nНачать игру?\n\nДа - 1\nНет - 0\n\nВведите и нажмите Enter: ";
	int O;
start:
	while (!(cin >> O) || (cin.peek() != '\n') || O < 0 || O > 1) {
		cout << "\nНекорректный ввод, повторите попытку: ";
		cin.clear();
		while (cin.get() != '\n');
	}
	if (O == 1) {
		system("cls");
		int N;
		cout << "НАЧАЛО ИГРЫ\n\nВведите количество игроков от 2 до 4: ";
		while (!(cin >> N) || (cin.peek() != '\n') || N > 4 || N < 2) {
			cout << "\nНекорректный ввод, повторите попытку: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		string name_1, name_2, name_3, name_4;
		string Player_1[18], Player_2[18], Player_3[18], Player_4[18];
		int sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0;
		int num_1[100], num_2[100], num_3[100], num_4[100];
		memset(num_1, 0, 100 * sizeof(int)); //Обнуление массива
		memset(num_2, 0, 100 * sizeof(int));
		memset(num_3, 0, 100 * sizeof(int));
		memset(num_4, 0, 100 * sizeof(int));
		int n_1 = 1, n_2 = 1, n_3 = 1, n_4 = 1;
		NewPlayer(1, name_1, Player_1, sum_1, num_1, n_1);
		NewPlayer(2, name_2, Player_2, sum_2, num_2, n_2);
		if (N >= 3) {
			NewPlayer(3, name_3, Player_3, sum_3, num_3, n_3);
			if (N == 4) {
				NewPlayer(4, name_4, Player_4, sum_4, num_4, n_4);
			}
		}
		int a = 1;
		int b = 1;
		for (int i = 0; i < b; ++i) {
			if (b == 1) {
				system("pause");
			}
			StillStop(name_1, Player_1, sum_1, num_1, n_1, 1);
			StillStop(name_2, Player_2, sum_2, num_2, n_2, 2);
			if (N >= 3) {
				StillStop(name_3, Player_3, sum_3, num_3, n_3, 3);
				if (N == 4) {
					StillStop(name_4, Player_4, sum_4, num_4, n_4, 4);
				}
			}
			if ((sum_1 > 0 && sum_1 < 21) && (sum_2 <= 0 || sum_2 > 21) && (sum_3 <= 0 || sum_3 > 21) && (sum_4 <= 0 || sum_4 > 21) || \
				(sum_1 <= 0 || sum_1 > 21) && (sum_2 > 0 && sum_2 < 21) && (sum_3 <= 0 || sum_3 > 21) && (sum_4 <= 0 || sum_4 > 21) || \
				(sum_1 <= 0 || sum_1 > 21) && (sum_2 <= 0 || sum_2 > 21) && (sum_3 > 0 && sum_3 < 21) && (sum_4 <= 0 || sum_4 > 21) || \
				(sum_1 <= 0 || sum_1 > 21) && (sum_2 <= 0 || sum_2 > 21) && (sum_3 <= 0 || sum_3 > 21) && (sum_4 > 0 && sum_4 < 21)) { //Если остался один игрок
				goto win;
			}
			else if ((sum_1 <= 0 || sum_1 > 21) && (sum_2 <= 0 || sum_2 > 21) && (sum_3 <= 0 || sum_3 > 21) && (sum_4 <= 0 || sum_4 > 21)) { //Если игроков не осталось
				system("cls");
				ShowCards(name_1, Player_1, sum_1, n_1);
				cout << "\n";
				ShowCards(name_2, Player_2, sum_2, n_2);
				if (N >= 3) {
					cout << "\n";
					ShowCards(name_3, Player_3, sum_3, n_3);
					if (N == 4) {
						cout << "\n";
						ShowCards(name_4, Player_4, sum_4, n_4);
					}
				}
				cout << "\n\n\nК сожалению, все игроки набрали больше 21 очка. Для определения победителя сыграйте еще раз.\n\n\n";
				goto playAgain;
			}
			else if ((sum_1 == 21) && (sum_2 != 21) && (sum_3 != 21) && (sum_4 != 21) || \
				(sum_1 != 21) && (sum_2 == 21) && (sum_3 != 21) && (sum_4 != 21) || \
				(sum_1 != 21) && (sum_2 != 21) && (sum_3 == 21) && (sum_4 != 21) || \
				(sum_1 != 21) && (sum_2 != 21) && (sum_3 != 21) && (sum_4 == 21)) { //Если один игрок набрал 21 очко
				goto win;
			}
			else {
				system("pause");
				system("cls");
				cout << "Вопрос для всех игроков!\n\nВскрываем карты?\n\nДа - 1\nНет - 0\n\nВведите и нажмите Enter: ";
				while (!(cin >> a) || (cin.peek() != '\n') || a < 0 || a > 1) {
					cout << "\nНекорректный ввод, повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n');
				}
				if (a == 0) {
					++b;
				}
			}
		}
		if (((sum_1 == sum_2) && (N == 2)) || \
			(((sum_1 == sum_2) && (sum_1 >= sum_3) && (sum_1 >= sum_4)) || \
				((sum_1 == sum_3) && (sum_1 >= sum_2) && (sum_1 >= sum_4)) || \
				((sum_1 == sum_4) && (sum_1 >= sum_2) && (sum_1 >= sum_3)) || \
				((sum_2 == sum_3) && (sum_2 >= sum_1) && (sum_2 >= sum_4)) || \
				((sum_2 == sum_4) && (sum_2 >= sum_1) && (sum_2 >= sum_3)) || \
				((sum_3 == sum_4) && (sum_3 >= sum_1) && (sum_3 >= sum_2))) && (N > 2)) { //Проверка на совпадения
			system("cls");
			ShowCards(name_1, Player_1, sum_1, n_1);
			cout << "\n";
			ShowCards(name_2, Player_2, sum_2, n_2);
			if (N >= 3) {
				cout << "\n";
				ShowCards(name_3, Player_3, sum_3, n_3);
				if (N == 4) {
					cout << "\n";
					ShowCards(name_4, Player_4, sum_4, n_4);
				}
			}
			cout << "\n\nУ игроков с наибольшим балансом совпало количество набранных очков. Чтобы определить победителя, сыграйте еще раз.\n\n";
		}
		else {
		win:
			string winner;
			int maxScore = max(sum_1, max(sum_2, max(sum_3, sum_4)));
			if (maxScore == sum_1) {
				winner = name_1;
			}
			else if (maxScore == sum_2) {
				winner = name_2;
			}
			else if (maxScore == sum_3) {
				winner = name_3;
			}
			else {
				winner = name_4;
			}
			system("pause");
			system("cls");
			ShowCards(name_1, Player_1, sum_1, n_1);
			cout << "\n\n";
			ShowCards(name_2, Player_2, sum_2, n_2);
			if (N >= 3) {
				cout << "\n\n";
				ShowCards(name_3, Player_3, sum_3, n_3);
				if (N == 4) {
					cout << "\n\n";
					ShowCards(name_4, Player_4, sum_4, n_4);
				}
			}
			cout << "\n\n\nПобедил(-а) " << winner << ", набрав " << maxScore << " очко(-в)!\n\n\n\n";
		}
	playAgain:
		system("pause");
		system("cls");
		cout << "Играть еще раз?\n\nДа - 1\nНет - 0\n\nВведите и нажмите Enter: ";
		goto start;
	}
	cout << "\n\nВы вышли из игры\n\n";
	system("pause");
	return 0;
}