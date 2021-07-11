#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Задача 8
struct Image {
	int mx;
	int my;
	int* points;
};

//Создание изображения
void createlmage(Image* img, int tmx, int tmy) {
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmy * tmx];
	for (int i = 0; i < tmy * tmx; i++) {
		img->points[i] = 0;
	}
}

//Отображение изображения на экран в pnm формате
void showImage(Image* img) {
	for (int i = 0; i < img->mx; i++) {
		for (int j = 0; j < img->my; j++) {
			cout << img->points[(i * (img->my)) + j];
		}
		cout << endl;
	}
}

//Добавление точки на изображение
void getPointImage(Image* img, int x, int y) {
	img->points[(y - 1) * (img->my) + x - 1];
}

//Получение точки на изображение
void setPointImage(Image* img, int x, int y, int color) {
	img->points[(y - 1) * (img->my) + x - 1] = color;
}

//Сохранение изображения в pnm формате
void saveToPnmFile(Image* img, ofstream& fileName) {
	for (int i = 0; i < img->mx; i++) {
		for (int j = 0; j < img->my; j++) {
			fileName << img->points[(i * (img->mx + 1)) + j];
		}
		fileName << endl;
	}
}

//Задача 9
int testcreatelmage() {
	Image img;
	createlmage(&img, 3, 4);
	for (int i = 0; i < 3 * 4; i++) {
		if (img.points[i] != 0) return -1;
	}
	return 0;
}

int testsetPointImage() {
	Image* img = new Image;
	createlmage(img, 4, 4);
	setPointImage(img, 3, 3, 4);
	if (img->points[10] != 4) return -1;
	return 0;
}

int testgetPointImage() {
	Image img;
	img.points = new int[4 * 4];
	for (int i = 0; i < 4 * 4; i++) {
		img.points[i] = 0;
	}
	getPointImage(&img, 4, 4);
	if (img.points[(2 - 1) * (2) + 2 - 1] != 0) {
		return -1;
	}
	return 0;
}

int testsaveToPnmFile() {
	Image* img = new Image;
	createlmage(img, 2, 2);
	ofstream fount;
	fount.open("F1.txt");
	saveToPnmFile(img, fount);
	fstream f;
	f.open("F1.txt", ios::in);
	long file_size;
	f.seekg(0, ios::end);
	file_size = f.tellg();
	if (file_size == 0) {
		f.close();
		return -1;
	}
	f.close();
	return 0;
}

void runTest(int (*testfunction)(), string testname) {
	if (testfunction() == 0)
		cout << "Тест " << testname << " пройден\n";
	else
		cout << "Тест " << testname << " не пройден\n";
}

//Задача 10
const double g = 9.8;

void Coordinates(double t, double h, double v, double* x_, double* y_) {
	if (h > (g * t * t) / 2) {
		(*y_) = h - ((g * t * t) / 2);
		(*x_) = v * t;
	}
	if (h - (g * t * t) / 2 < 0.001) {
		(*y_) = 0;
		(*x_) = v * t;
	}
}

void setPointImage_(Image* img, int y, int x, int color) {
	if (x > 0 && y > 0) img->points[(y - 1) * (img->mx) + x - 1] = color;
	if (x == 0) img->points[img->mx * img->my - img->mx * (img->my - y + 1)] = color;
}

void saveToPnmFile_(Image* img, const string filename)
{
	fstream out;
	out.open(filename, fstream::out);
	out << "P1" << endl;
	out << img->mx << " " << img->my << endl;

	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			out << img->points[img->mx * img->my - img->mx * (i + 1) + j] << " ";
		}
		out << endl;
	}

	out.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	runTest(testcreatelmage, "testcreatelmage");
	runTest(testsetPointImage, "testsetPointImage");
	runTest(testgetPointImage, "testgetPointImage");
	runTest(testsaveToPnmFile, "testsaveToPnmFile");
	Image img;
	int mx, my, x, y, color;
	mx = 800;
	my = 400;
	createlmage(&img, mx, my);
	cout.precision(6);
	double h, t = 0, y_, x_ = 0, v;
	double T = 0.0001;
	cout << "\nВведите высоту шарика в метрах: ";
	cin >> h;
	cout << "Введите начальную скорость в метрах в секунду: ";
	cin >> v;
	y_ = h;
	while ((((int)y_) % my != 0) && (((int)x_) < 79)) {
		Coordinates(t, h, v, &x_, &y_);
		setPointImage_(&img, ((int)y_) % my, ((int)x_) % mx, 1);
		cout << ((int)y_) % my << ' ' << ((int)x_) % mx << ' ' << t << endl;
		t = t + T;
	}
	saveToPnmFile_(&img, "F1.pnm");
}