/*
ʱ��:			�汾:			����:
19.8.31			1.0.0			������������,����ԭ�й���,������ǿ��Ϸ����;
19.9.12			1.1.0			�޸�����BUG,������β�Ű�
19.9.13 		1.1.1			�޸�ͶƱBUG,���inline�������,���̵��������峤��
19.9.13			1.1.2			У�������Ű�
19.9.13			1.2.0			�޸����0~6Ϊ1~7,����1��������inline,�޸�1����������
21.6.27			1.2.1			�滻����ͷ�ļ�,��������Ű�,�޸�time_t->int������ת������
21.7.11			1.2.2			��ʽ����Ϊһ����Ŀ������Ϊ64λ���������Ż�����
Future/Fornever	?.?.?			�޸��������һ������BUG���޸�������Ⱦ������BUG�����ʹ�ý̳�
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
ticket castVote[9]{};	//ͶƱ

int predictor{}, witch{}, guard{};	//��ְ���⴦�� 
int killedPerson{ 0 },	//����ɱ���� 
piosonedPerson{ 0 },	//Ů�۶����� 
defendedPerson{ 0 };	//�����ص���
int goodPerson{ 5 }, badPerson{ 2 };	//�������뻵���� 
int day{ 0 };	//�������

bool milk{ 0 };	//�Ƿ�ι�� 
bool poisonNum{ 1 }, milkNum{ 1 };	//������ʣ���� 

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

void statusTip()	//����ǰ��׼������ʾ
{
	srand(unsigned(time(NULL)));	//���� 
	random_shuffle(name + 1, name + 8);	//�����������

	system("color F");
	cout << "����˭?��֪����?";

	prsToCls();

	cout << "�ƻ������!";
	Sleep(3000);
	system("cls");
	cout << '\a';

	prsToCls();
}

void statusTime()	//����ְҵ
{
	statusTip();	//����ǰ��׼������ʾ 

	for (int i = 1;i <= 7;i++)
	{
		person[i].pos = name[i];
		person[i].rank = i;
		castVote[i].rank = i;

		if (name[i] == "Ԥ�Լ�") predictor = i;
		if (name[i] == "Ů��") witch = i;
		if (name[i] == "����") guard = i;

		cout << i << "�Ű�,�治��,����" << name[i];	//����������

		prsToCls();
		Sleep(3000);

		cout << '\a';
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

void wolfTime()	//����ʱ�� 
{
	cout << "��Բ֮ҹ,��������" << endl;
	cout << "����ɱ˭��?" << endl;
	cin >> killedPerson;
	clh();
	wolfCheckIn(killedPerson);

	system("cls");
}

void predictorCheckIn(int& p)	//�ж�Ԥ�Լ������Ƿ�����
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

void predictorTime()	//Ԥ�Լ�ʱ�� 
{
	int prop{};

	cout << "Ԥ�Լ�,�������Ԥ��֮�۰�" << endl;
	cout << "͵͵������,��Ԥ����˭�����?" << endl;
	cin >> prop;
	clh();
	predictorCheckIn(prop);

	if (prop)
	{
		if (person[prop].pos == "����")
			cout << "����...��";
		else
			cout << "����...��";
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

void witchTime()	//Ů��ʱ�� 
{
	bool s{};

	cout << "����������Ů��������" << endl;

	if (milkNum)
	{
		cout << "��������ɱ¾��Ѫҹ��," << killedPerson << "������" << endl << "��Ҫ����ĸ���ҩˮ������[1:���� 0:������]" << endl;
		cin >> s;
		clh();

		if (s)
		{
			milkNum = 0;	//������ 
			milk = 1;	//����ι����
		}
	}

	if (!s && poisonNum)
	{
		cout << "���˭ι�˵е�η?�������������ϼ�����[��ι������0]" << endl;
		cin >> piosonedPerson;
		if (piosonedPerson)
		{
			clh();
			witchCheckIn(piosonedPerson);
			poisonNum = 0;	//������
		}
	}

	system("cls");
}

void guardCheckIn(int& d, bool& hefa)	//�ж����������Ƿ�����
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

void guardTime()	//����ʱ��
{
	bool hefa{ 1 };

	cout << "����������,��������������ҹɫ��" << endl;
	cout << "�����ػ�˭?" << endl;

	do
	{
		hefa = 1;	//�ж��Ƿ���Ҫ���� 

		cin >> defendedPerson;
		clh();

		guardCheckIn(defendedPerson, hefa);
	} while (!hefa);

	if (defendedPerson)
	{
		person[defendedPerson].haveLucky = 1;
		person[defendedPerson].lucky = 1;
	}

	system("cls");
}

inline void killOut(const int death)	//ɱ�� 
{
	person[death].alive = 0;

	if (person[death].pos == "����")
		badPerson--;
	else
		goodPerson--;
}

void wolfKill()	//��ɱ�ж� 
{
	if (killedPerson)
	{
		if (person[killedPerson].lucky)
		{
			if (milk)
			{
				killOut(killedPerson);
			}
			else
			{
				person[killedPerson].lucky = 0;
				killedPerson = 0;	//ûɱ�ɹ� 
			}
		}
		else if (!milk)
		{
			killOut(killedPerson);
		}
		else	//���� 
		{
			killedPerson = 0;	//ûɱ�ɹ� 
		}
	}
}

void witchKill()	//Ů���ж�ɱ
{
	if (piosonedPerson)
	{
		if (person[piosonedPerson].lucky)
		{
			person[piosonedPerson].lucky = 0;
			piosonedPerson = 0;	//ûɱ�ɹ� 
		}
		else
		{
			killOut(piosonedPerson);
		}
	}
}

void killCheckIn()	//ɱ������ 
{
	wolfKill();
	witchKill();

	if (killedPerson)
		cout << killedPerson << "��,������" << endl;
	if (piosonedPerson && piosonedPerson != killedPerson)
		cout << piosonedPerson << "��,������";
	else if (!killedPerson && !piosonedPerson)
		cout << "����ƽ��ҹ";

	prsToCls();
}

void survivorDisplayTime()	//����Ҵ���
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

void speakTime()	//���۷��� 
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
	cout << castVote[1].rank << "��,�㱻���˵�ŭ����û��";
	killOut(castVote[1].rank);
}

void voteTime()	//ͶƱ 
{
	cout << "ͶƱ��ʼ,���Ʊ����������";

	prsToCls();

	for (int i = 1;i <= goodPerson + badPerson;i++)
	{
		int temp;
		cin >> temp;
		voteCheckIn(temp);
		if (temp)
		{
			castVote[temp].num++;
		}

		prsToCls();
	}

	sort(castVote + 1, castVote + 8);

	if (castVote[1].num == castVote[2].num)
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
	killedPerson = piosonedPerson = defendedPerson = milk = 0;
	for (auto i = 1;i <= 7;i++)	//����δ��벻ˬ�ܾ���,ƾʲô��֧��for(:),auto���ҹ���ӵ�,����Ҫ�ľ͸İ� 
	{
		castVote[i].num = 0;
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
	cout << '\a';
}

void dayTip()	//������ķ��Ժ�ͶƱ
{
	Beep(666, 500);
	cout << "����������" << endl;

	killCheckIn();	//ɱ������

	if (!goodPerson || !badPerson)
	{
		return;
	}
	else
	{
		survivorDisplayTime();	//����Ҵ������� 

		speakTime();	//����

		voteTime();	//ͶƱ
		survivorDisplayTime();	//�ٴ�����Ҵ������� 	
	}
}

void body()	//��Ϸ���� 
{
	while (goodPerson && badPerson)
	{
		bodyTip();	//ÿ��ʼǰ��׼��

		wolfTime();	//���˻غ�
		Sleep(3000);
		cout << '\a';

		if (person[predictor].alive)	//Ԥ�Լһغ�
		{
			predictorTime();
			Sleep(3000);
			cout << '\a';
		}

		if (person[witch].alive)	//Ů�׻غ� 
		{
			witchTime();
			Sleep(3000);
			cout << '\a';
		}

		if (person[guard].alive)	//�����غ� 
		{
			guardTime();
			Sleep(3000);
		}

		dayTip();	//������ķ��Ժ�ͶƱ
	}
}

void godEnding()	//ƽ�� 
{
	cout << "��������˻����ɱ,���ܾ���,�ҿ������һֻ�ǵ���Ѫ����,��Ц��,ʤ������˭��?" << endl << "��ɳɾ�:ƽ��";

	prsToCls();
}

void badEnding()	//���˻�ʤ 
{
	cout << "����ɱ�������к���,����ʤ��,��,���ǲ����û�©��˭��?" << endl << "��ɳɾ�:���˻�ʤ";

	prsToCls();
}

void goodEnding()
{
	cout << "����������ɱ������,����ʤ��,������һֻֻ����ȥ,�������˼,����...����Ǻ�����?" << endl << "��ɳɾ�:���˻�ʤ";

	prsToCls();
}

void endingHouse()	//��Ϸ���� 
{
	if (!goodPerson && !badPerson)
		godEnding();	//ƽ��
	if (!goodPerson)
		badEnding();	//��Ӯ
	if (!badPerson)
		goodEnding();	//��Ӯ
}

void tail()
{
	system("color d");
	cout << "\n\n\n\n\n\n\n\n";
	cout << setw(70) << "��ӭ��������STUDIO" << "\n\n" << setw(72) << "���ǵĹ���:bhstudio.club";

	prsToCls();
}

int main()
{
	head();	//չʾ���� 
	statusTime();	//����ְҵ 
	body();	//��ʽ�ӵ�һҹ��ʼ
	endingHouse();	//������
	tail();	//չʾ��β

	return 0;
}
