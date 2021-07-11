#include <iostream>
#include <cmath>
using namespace std;
double const g = -9.8;

struct Node {
	double t;
	double h;
	double v;
	Node* next;
};

void init(Node* node, double height)
{
	node->t = 0;
	node->h = height;
	node->v = 0;
	node->next = NULL;
}

void pushNode(Node* head, double timeStep)
{
	Node* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = new Node;
	p->next->t = p->t + timeStep;
	p->next->h = p->h + (p->v * timeStep) + (g * timeStep * timeStep / 2);
	p->next->v = p->v + g * timeStep;
	p->next->next = NULL;
}

void show(Node* head)
{
	Node* element = head;
	while (element != NULL)
	{
		cout << "\nВремя: " << element->t << "\nВысота: " << element->h << "\nСкорость: " << element->v << "\nУскорение свободного падения: " << g;
		cout << "\n\n";
		element = element->next;
	}
	cout << "\n";
}

double Impact(Node* head, double h, double loss, double ImpactMoment)
{
	Node* l = head;
	while (l->next != NULL)
	{
		l = l->next;
	}
	l->t = ImpactMoment;
	l->h = 0;
	l->v = sqrt(2 * (-g) * h) * sqrt((100 - loss) / 100);
	return l->v;
}

int testImpact()
{
	Node* head = new Node;
	double h = 3;
	double loss = 50;
	double timeStep = 0.1;
	double ImpactMoment = sqrt(2.0 * h / (-g));
	init(head, h);
	double t = 0;
	while (h > 0.001)
	{
		while (t < ImpactMoment - timeStep)
		{
			pushNode(head, timeStep);
			t += timeStep;
		}
		double v = Impact(head, h, loss, ImpactMoment);
		t = ImpactMoment;
		double t = v / (-g);
		h = v * t + g * t * t / 2;
		ImpactMoment += 2 * t;
	}
	show(head);
	Node* end = head;
	return 0;
}

int mainImpact(int h, int loss, double timeStep)
{
	Node* head = new Node;
	double ImpactMoment = sqrt(2.0 * h / (-g));
	init(head, h);
	double t = 0;
	while (h > 0.001)
	{
		while (t < ImpactMoment - timeStep)
		{
			pushNode(head, timeStep);
			t += timeStep;
		}
		double v = Impact(head, h, loss, ImpactMoment);
		t = ImpactMoment;
		double t = v / (-g);
		h = v * t + g * t * t / 2;
		ImpactMoment += 2 * t;
	}
	show(head);
	Node* end = head;
	return 0;
}

static void runTest(int (*testFunction)(), const std::string& Name)
{
	if ((testFunction() == 0))
		cout << "Тест " << Name << " пройден" << std::endl;
	else
		cout << "Тест " << Name << " не пройден" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	runTest(testImpact, "Impact");
	cout << "\n\nВведите высоту: ";
	double h;
	cin >> h;
	cout << "Введите потери кинетической энергии: ";
	double loss;
	cin >> loss;
	cout << "Введите временной интервал: ";
	double timeStep;
	cin >> timeStep;
	mainImpact(h, loss, timeStep);
}