/*
ʱ��:			�汾:			����:
19.8.31			1.0.0			������������,����ԭ�й���,������ǿ��Ϸ����;
19.9.12			1.1.0			�޸�����BUG,������β�Ű�
19.9.13 		1.1.1			�޸�ͶƱBUG,���inline�������,���̵��������峤��
19.9.13			1.1.2			У�������Ű�
19.9.13			1.2.0			�޸����0~6Ϊ1~7,����1��������inline,�޸�1����������
21.6.27			1.2.1			�滻����ͷ�ļ�,��������Ű�,�޸�time_t->int������ת������
*/

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<algorithm>

using namespace std;

struct position
{
	string pos{};	//ְҵ
	int rank{};	//���
	bool alive{};	//����
	bool lucky{};	//�Ƿ���
	bool haveLucky{};	//�Ƿ��ع�

	position() :alive{ 1 }, lucky{ 0 }, haveLucky{ 0 }{}
	~position() {}
};

struct ticket
{
	int rank{};	//��� 
	int num{};	//Ʊ�� 

	bool operator<(const ticket& other)const	//Ϊsort���� 
	{
		return this->num > other.num;
	}

	ticket() :num{ 0 } {}
	~ticket() {}
};

position person[9]{};	//����
ticket tp[9]{};	//ͶƱ

int yyj{}, nw{}, sw{};	//��ְ���⴦�� 
int kill{ 0 },	//����ɱ���� 
luckyDog{ 0 },	//Ů�۶����� 
luckyMan{ 0 };	//�����ص���
int good{ 5 }, bad{ 2 };	//�������뻵���� 
int day{ 0 };	//�������

bool milk{ 0 };	//�Ƿ�ι�� 
bool poi{ 1 }, anti{ 1 };	//������ʣ���� 

string name[9]{ "","����","����","Ů��","Ԥ�Լ�","����","ƽ��","ƽ��" };


inline void clh()	//�������� 
{
	cin.clear();
	cin.sync();
}

inline void prsToCls()	//�س�����
{
	getchar();
	clh();
	system("cls");
}

void head()	//��ʼ���� 
{
	system("color c");
	cout << "\n\n\n";
	cout << setw(30) << "��";	Sleep(500);
	cout << setw(30) << "��";	Sleep(500);
	cout << setw(30) << "ɱ" << "\n\n\n\n\n\n\n";	Sleep(1000);

	system("color d");
	cout << setw(70) << "Made by �����STUDIO" << "\n\n\n\n\n\n\n\n\n\n";	Sleep(1000);

	system("color e");
	cout << setw(71) << "��������:bhstudio.club";

	prsToCls();
}

inline void random()	//����������� 
{
	srand(unsigned(time(NULL)));	//���� 
	random_shuffle(name + 1, name + 8);	//�����������
}

void professionTip()	//����ǰ��׼������ʾ
{
	random();

	system("color F");
	cout << "����˭?��֪����?";

	prsToCls();

	cout << "�ƻ������!";
	Sleep(3000);
	system("cls");
	tone();

	prsToCls();
}

void profession()	//����ְҵ
{
	professionTip();	//����ǰ��׼������ʾ 

	for (int i = 1;i <= 7;i++)
	{
		person[i].pos = name[i];
		person[i].rank = i;
		tp[i].rank = i;

		if (name[i] == "Ԥ�Լ�") yyj = i;
		if (name[i] == "Ů��") nw = i;
		if (name[i] == "����") sw = i;

		cout << i << "�Ű�,�治��,����" << name[i];	//����������

		prsToCls();
		Sleep(3000);

		tone();
		prsToCls();
	}

	Beep(666, 500);	//������ʾ 
}

void wolfCheckIn(int& k)	//�ж����������Ƿ�����
{
	if (k > 7 || k < 1)
	{
		cout << "��ɱ����,ʲô��û��ɱ��";
		k = 0;
	}
	else if (!person[k].alive)
	{
		cout << "��ɳɾ�:��ʬ";
		k = 0;
	}
}

void werewolf()	//����ʱ�� 
{
	cout << "��Բ֮ҹ,��������" << endl;
	cout << "����ɱ˭��?" << endl;
	cin >> kill;
	clh();
	wolfCheckIn(kill);

	system("cls");
}

void propCheckIn(int& p)	//�ж�Ԥ�Լ������Ƿ�����
{
	if (p > 7 || p < 1)
	{
		cout << "��գ������,ʲô��û�п���";
		p = 0;
	}
	else if (!person[p].alive)
	{
		cout << "��ֻ������һ�߱����ʬ��...";
		p = 0;
	}
}

void prophet()	//Ԥ�Լ�ʱ�� 
{
	int prop{};

	cout << "Ԥ�Լ�,�������Ԥ��֮�۰�" << endl;
	cout << "͵͵������,��Ԥ����˭�����?" << endl;
	cin >> prop;
	clh();
	propCheckIn(prop);

	if (prop)
	{
		if (person[prop].pos == "����")
		{
			cout << "����...��";
		}
		else
		{
			cout << "����...��";
		}
	}

	prsToCls();
}

void witchCheckIn(int& w)	//�ж�Ů�������Ƿ�����
{
	if (w > 7 || w < 1)
	{
		cout << "�ܲ���,���ҩ����,û���˵��κ���";
		w = 0;
	}
	else if (!person[w].alive)
	{
		cout << "��ɳɾ�:��ʬ";
		w = 0;
	}
}

void witch()	//Ů��ʱ�� 
{
	bool s{};

	cout << "����������Ů��������" << endl;

	if (anti)
	{
		cout << "��������ɱ¾��Ѫҹ��," << kill << "������" << endl << "��Ҫ����ĸ���ҩˮ������[1:���� 0:������]" << endl;
		cin >> s;
		clh();

		if (s)
		{
			anti = 0;	//������ 
			milk = 1;	//����ι����
		}
	}

	if (!s && poi)
	{
		cout << "���˭ι�˵е�η?�������������ϼ�����[��ι������0]" << endl;
		cin >> luckyDog;
		if (luckyDog)
		{
			clh();
			witchCheckIn(luckyDog);
			poi = 0;	//������
		}
	}

	system("cls");
}

void defCheckIn(int& d, bool& hefa)	//�ж����������Ƿ�����
{
	if (d > 7 || d < 1)
	{
		cout << "��ɳɾ�:�����ػ���";
		d = 0;
	}
	else if (!person[d].alive)
	{
		cout << "��ɳɾ�:��Ĺ��";
		d = 0;
	}
	else if (person[d].haveLucky)
	{
		cout << "���������,ÿ����ֻ��ӵ��һ�λ���,�ٸ���һ��ѡ�����,��ѡ���ػ�˭?" << endl;
		hefa = 0;	//���� 
	}
}

void defender()	//����ʱ��
{
	bool hefa{ 1 };

	cout << "����������,��������������ҹɫ��" << endl;
	cout << "�����ػ�˭?" << endl;

	do
	{
		hefa = 1;	//�ж��Ƿ���Ҫ���� 

		cin >> luckyMan;
		clh();

		defCheckIn(luckyMan, hefa);
	} while (!hefa);

	if (luckyMan)
	{
		person[luckyMan].haveLucky = 1;
		person[luckyMan].lucky = 1;
	}

	system("cls");
}

inline void killOut(const int death)	//ɱ�� 
{
	person[death].alive = 0;

	if (person[death].pos == "����")
	{
		bad--;
	}
	else
	{
		good--;
	}
}

void wolfKill()	//��ɱ�ж� 
{
	if (kill)
	{
		if (person[kill].lucky)
		{
			if (milk)
			{
				killOut(kill);
			}
			else
			{
				person[kill].lucky = 0;
				kill = 0;	//ûɱ�ɹ� 
			}
		}
		else if (!milk)
		{
			killOut(kill);
		}
		else	//���� 
		{
			kill = 0;	//ûɱ�ɹ� 
		}
	}
}

void witchKill()	//Ů���ж�ɱ
{
	if (luckyDog)
	{
		if (person[luckyDog].lucky)
		{
			person[luckyDog].lucky = 0;
			luckyDog = 0;	//ûɱ�ɹ� 
		}
		else
		{
			killOut(luckyDog);
		}
	}
}

void killCheckIn()	//ɱ������ 
{
	wolfKill();
	witchKill();

	if (kill)
	{
		cout << kill << "��,������" << endl;
	}
	if (luckyDog && luckyDog != kill)
	{
		cout << luckyDog << "��,������";
	}
	else if (!kill && !luckyDog)
	{
		cout << "����ƽ��ҹ";
	}

	prsToCls();
}

void survivor()	//����Ҵ���
{
	cout << "��" << day << "ҹ���Ҵ�������:";

	for (int i = 1;i <= 7;i++)
	{
		if (person[i].alive)
		{
			cout << i << " ";
		}
	}

	prsToCls();
}

void speak()	//���۷��� 
{
	cout << "��ҪͶƱ��,��������һ��?���Ҵ��߷���";

	prsToCls();
}

void voteCheckIn(int& v)	//�ж�ͶƱ�������Ƿ�����
{
	if (v > 7 || v < 1)
	{
		cout << "����Ʊ��";
		v = 0;
	}
	else if (!person[v].alive)
	{
		cout << "��ɳɾ�:��ʬ";
		v = 0;
	}
}

void voteKill()	//Ʊ�� 
{
	cout << tp[1].rank << "��,�㱻���˵�ŭ����û��";
	killOut(tp[1].rank);
}

void vote()	//ͶƱ 
{
	cout << "ͶƱ��ʼ,���Ʊ����������";

	prsToCls();

	for (int i = 1;i <= good + bad;i++)
	{
		int temp;
		cin >> temp;
		voteCheckIn(temp);
		if (temp)
		{
			tp[temp].num++;
		}

		prsToCls();
	}

	sort(tp + 1, tp + 8);

	if (tp[1].num == tp[2].num)
	{
		cout << "ƽƱ";
	}
	else
	{
		voteKill();
	}

	prsToCls();
}

void numDeal()	//�����ظ�ֵ����
{
	kill = luckyDog = luckyMan = milk = 0;
	for (auto i = 1;i <= 7;i++)	//����δ��벻ˬ�ܾ���,ƾʲô��֧��for(:),auto���ҹ���ӵ�,����Ҫ�ľ͸İ� 
	{
		tp[i].num = 0;
	}
}

void bodyTip()	//ÿ��ʼǰ��׼�� 
{
	numDeal();

	day++;
	cout << "��" << day << "��" << endl;

	cout << "��������";
	Sleep(5000);
	system("cls");
	tone();
}

void dayTip()	//������ķ��Ժ�ͶƱ
{
	Beep(666, 500);
	cout << "����������" << endl;

	killCheckIn();	//ɱ������

	if (!good || !bad)
	{
		return;
	}
	else
	{
		survivor();	//����Ҵ������� 

		speak();	//����

		vote();	//ͶƱ
		survivor();	//�ٴ�����Ҵ������� 	
	}
}

void body()	//��Ϸ���� 
{
	while (good && bad)
	{
		bodyTip();	//ÿ��ʼǰ��׼��

		werewolf();	//���˻غ�
		Sleep(3000);
		tone();

		if (person[yyj].alive)	//Ԥ�Լһغ�
		{
			prophet();
			Sleep(3000);
			tone();
		}

		if (person[nw].alive)	//Ů�׻غ� 
		{
			witch();
			Sleep(3000);
			tone();
		}

		if (person[sw].alive)	//�����غ� 
		{
			defender();
			Sleep(3000);
		}

		dayTip();	//������ķ��Ժ�ͶƱ
	}
}

void gadEnding()	//ƽ�� 
{
	cout << "��������˻����ɱ,���ܾ���,�ҿ������һֻ�ǵ���Ѫ����,��Ц��,ʤ������˭��?" << endl << "��ɳɾ�:ƽ��";

	prsToCls();

	return;
}

void badEnding()	//���˻�ʤ 
{
	cout << "����ɱ�������к���,����ʤ��,��,���ǲ����û�©��˭��?" << endl << "��ɳɾ�:���˻�ʤ";

	prsToCls();

	return;
}

void goodEnding()
{
	cout << "����������ɱ������,����ʤ��,������һֻֻ����ȥ,�������˼,����...����Ǻ�����?" << endl << "��ɳɾ�:���˻�ʤ";

	prsToCls();

	return;
}

void endingHouse()	//��Ϸ���� 
{
	if (!good && !bad)
	{
		gadEnding();	//ƽ��
	}
	if (!good)
	{
		badEnding();	//��Ӯ
	}
	if (!bad)
	{
		goodEnding();	//��Ӯ
	}
}

void tail()
{
	system("color d");
	cout << "\n\n\n\n\n\n\n\n";
	cout << setw(70) << "��ӭ��������STUDIO" << "\n\n" << setw(72) << "���ǵĹ���:bhstudio.club";

	prsToCls();

	return;
}

int main()
{
	head();	//չʾ���� 
	profession();	//����ְҵ 
	body();	//��ʽ�ӵ�һҹ��ʼ
	endingHouse();	//������
	tail();	//չʾ��β

	return 0;
}
