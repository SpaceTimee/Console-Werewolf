#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//加密
string encrypt(string File)
{
	cout<<"[请输入纯数字密码(密码请不要高于18位)(数字前可加负号)]:";
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
		cout<<"[输入错误,密码请不要高于18位]"<<endl;
		
		goto REd;
	}
	
    return File;
}

//解密 
string decipher(string File)
{
	cout<<"[请输入纯数字密码(密码请不要高于18位)(数字前可加负号)]:";
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
		cout<<"[密码错误]"<<endl;
				
		goto REe;
	}
	
	return File;
}

//路径
string cinRoad(string oldRoad)
{
	string newRoad;
	cout<<"[请输入文件路径]:";
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
 
//读取 
string readFile(string road)
{
	string File;
	cout<<"[正在查找文件...]"<<endl;
	fstream read(road);
    if(read)
    {
    	cout<<"[查找成功]"<<endl;
        read>>File;
        read.close();
	}
    else
    {
        cout<<"[查找失败,请手动输入(默认操作为结束运行)]:";
        cin>>File;
        cin.clear();
		cin.sync();
	}
	
	return File;
}

//写入 
void writeFile(string File,string road)
{
	cout<<"[正在查找文件...]"<<endl;
	fstream write(road);
    if(write)
	{
		cout<<"[查找成功]"<<endl;
        write<<File;
        write.close();
	}
    else
    {
	   	cout<<"[写入失败,请手动输入结果]:"<<File<<endl;
	}
}

//输出
void print(string File)
{
	cout<<"结果:"<<File<<endl;
}


//
int main()
{
	int select{};
	string File{},road="C:\\Users\\Zeus\\Desktop\\c++.txt";
	
	cout<<"[输入1：加密]\n[输入2：解密]\n[请输入]:";
	
	REc:
		
    cin>>select;
    cin.clear();
	cin.sync();
    
    //加密
    if(select==1)
	{
		road=cinRoad(road);
        File=readFile(road);
	    if(!File.empty())
	    {
	    	File=encrypt(File);
	    	cout<<"[加密成功]\n[输入1:查看密文]\n[输入2:写入文件]\n[输入3:查看密文并写入文件]\n[请输入]:";
	    	
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
				//恶意输入
				cout<<"[无法识别,请重新输入]"<<endl;
				
				goto REa;
			}
		}
	    else
	    {
	    	cout<<"[文件为空,运行结束]"<<endl;
		}
    }
    
	//解密
    else if(select==2)
    {
		road=cinRoad(road);
        File=readFile(road);
	    if(!File.empty())
	    {
	    	File=decipher(File);
		    cout<<"[解密成功]\n[输入1:查看明文]\n[输入2:写入文件]\n[输入3:查看明文并写入文件]\n[请输入]:";
		    	    		    	
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
				//恶意输入
				cout<<"[无法识别,请重新输入]"<<endl;
				
				goto REb;
			}	
   		}
   		else
   		{
   			cout<<"[文件为空,运行结束]"<<endl;
		}
    }
    
	//恶意输入
	else
	{
		cout<<"[无法识别,请重新输入]"<<endl;
		
		goto REc;
	}
	
	cout<<"[谢谢使用]"<<endl;
	
	system("prsToCls"); 
	return 0;
}

