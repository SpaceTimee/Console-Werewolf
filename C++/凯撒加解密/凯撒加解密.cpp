#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//����
string encrypt(string File)
{
	cout<<"[�����봿��������(�����벻Ҫ����18λ)(����ǰ�ɼӸ���)]:";
	long long password,i;
	
	REd:
		
	cin>>password;
	cin.clear();
	cin.sync();
	if(password<=999999999999999999)
	{
		for(i=0;i<File.length();i++)
    	{
    		File[i]+=password;
		}
	}
	else
	{
		cout<<"[�������,�����벻Ҫ����18λ]"<<endl;
		
		goto REd;
	}
	
    return File;
}

//���� 
string decipher(string File)
{
	cout<<"[�����봿��������(�����벻Ҫ����18λ)(����ǰ�ɼӸ���)]:";
	long long password,i;
	
	REe:
	
	cin>>password;
	cin.clear();
	cin.sync();
	if(password<=999999999999999999)
	{
		for(i=0;i<File.length();i++)
    	{
    		File[i]-=password;
		}
	} 
	else
	{
		cout<<"[�������]"<<endl;
				
		goto REe;
	}
	
	return File;
}

//·��
string cinRoad(string oldRoad)
{
	string newRoad;
	cout<<"[�������ļ�·��]:";
	cin>>newRoad;
	cin.clear();
	cin.sync();
	if(!newRoad.empty())
	{
		return newRoad;
	}
	else
	{
		return oldRoad;
	}
}
 
//��ȡ 
string readFile(string road)
{
	string File;
	cout<<"[���ڲ����ļ�...]"<<endl;
	fstream read(road);
    if(read)
    {
    	cout<<"[���ҳɹ�]"<<endl;
        read>>File;
        read.close();
	}
    else
    {
        cout<<"[����ʧ��,���ֶ�����(Ĭ�ϲ���Ϊ��������)]:";
        cin>>File;
        cin.clear();
		cin.sync();
	}
	
	return File;
}

//д�� 
void writeFile(string File,string road)
{
	cout<<"[���ڲ����ļ�...]"<<endl;
	fstream write(road);
    if(write)
	{
		cout<<"[���ҳɹ�]"<<endl;
        write<<File;
        write.close();
	}
    else
    {
	   	cout<<"[д��ʧ��,���ֶ�������]:"<<File<<endl;
	}
}

//���
void print(string File)
{
	cout<<"���:"<<File<<endl;
}


//
int main()
{
	int select{};
	string File{},road="C:\\Users\\Zeus\\Desktop\\c++.txt";
	
	cout<<"[����1������]\n[����2������]\n[������]:";
	
	REc:
		
    cin>>select;
    cin.clear();
	cin.sync();
    
    //����
    if(select==1)
	{
		road=cinRoad(road);
        File=readFile(road);
	    if(!File.empty())
	    {
	    	File=encrypt(File);
	    	cout<<"[���ܳɹ�]\n[����1:�鿴����]\n[����2:д���ļ�]\n[����3:�鿴���Ĳ�д���ļ�]\n[������]:";
	    	
	    	REa:
	    	
	    	cin>>select;
	    	cin.clear();
			cin.sync();
		    if(select==1)
		    {
		    	print(File);
			}
			else if(select==2)
			{
				road=cinRoad(road);
				writeFile(File,road);
			}
			else if(select==3)
			{
				print(File);
				road=cinRoad(road);
				writeFile(File,road);
			}
			else
			{
				//��������
				cout<<"[�޷�ʶ��,����������]"<<endl;
				
				goto REa;
			}
		}
	    else
	    {
	    	cout<<"[�ļ�Ϊ��,���н���]"<<endl;
		}
    }
    
	//����
    else if(select==2)
    {
		road=cinRoad(road);
        File=readFile(road);
	    if(!File.empty())
	    {
	    	File=decipher(File);
		    cout<<"[���ܳɹ�]\n[����1:�鿴����]\n[����2:д���ļ�]\n[����3:�鿴���Ĳ�д���ļ�]\n[������]:";
		    	    		    	
	    	REb:
	    		
		    cin>>select;
		    cin.clear();
			cin.sync();
		    if(select==1)
		    {
		    	print(File);
			}
			else if(select==2)
			{
				road=cinRoad(road);
				writeFile(File,road);
			}
			else if(select==3)
			{
				print(File);
				road=cinRoad(road);
				writeFile(File,road);
			}
			else
			{
				//��������
				cout<<"[�޷�ʶ��,����������]"<<endl;
				
				goto REb;
			}	
   		}
   		else
   		{
   			cout<<"[�ļ�Ϊ��,���н���]"<<endl;
		}
    }
    
	//��������
	else
	{
		cout<<"[�޷�ʶ��,����������]"<<endl;
		
		goto REc;
	}
	
	cout<<"[ллʹ��]"<<endl;
	
	system("prsToCls"); 
	return 0;
}

