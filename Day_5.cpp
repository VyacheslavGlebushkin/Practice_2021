//Задача 11
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Image {
public:
	int mx;
	int my;
	int* points;

	void createImage(int tmx, int tmy) {
		mx = tmx;
		my = tmy;
		points = new int[tmy * tmx];
		for (int i = 0; i < tmy * tmx; i++) {
			points[i] = 1;
		}
	}

	void showImage() {
		for (int i = 0; i < my; i++) {
			for (int j = 0; j < mx; j++) {
				cout << points[(i * mx) + j];
			}
			cout << endl;
		}
	}

	void getPointImage(int x, int y) {
		points[(y - 1) * my + x - 1];
	}

	void setPointImage(int x, int y, int color) {
		points[(y - 1) * mx + x - 1] = color;
	}

	void saveToPnmFile(const string filename)
	{
		fstream out;
		out.open(filename, fstream::out);
		out << "P1" << endl;
		out << mx << " " << my << endl;

		for (int i = 0; i < mx; i++)
		{
			for (int j = 0; j < my; j++)
			{
				out << points[i * my + j] << " ";
			}
			out << endl;
		}

		out.close();
	}
};

//Задача 12

//S - start
//F - final

int main()
{
	RenderWindow window(VideoMode(800, 700), "SFML");
	bool condition = false, moving = true;
	float width = 200, h = 250;
	while (window.isOpen())
	{	Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::S)
					condition = true;
				if (event.key.code == sf::Keyboard::F)
					condition = false;
			}
		}
		if (condition) 
		{
			if (width < 100)
			{
				moving = false;
			}
			if (width > 250)
			{
				moving = true;
			}
			if (moving) 
			{
				width -= 0.1;
				h += 0.2;
			}
			else 
			{
				width += 0.1;
				h -= 0.2;
			}
		}
		window.clear();
		RectangleShape rectangle(Vector2f(200.f, h));
		rectangle.move(200, width);
		rectangle.setFillColor(Color::Green);
		window.draw(rectangle);
		window.display();
	}
	return 0;
}