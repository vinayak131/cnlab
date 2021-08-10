#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


string xored(string s1,string s2)
{
	string answer="";
	
	for(int i=1;i<s2.length();i++)
	{
		if(s1[i]==s2[i])
		answer=answer+"0";
		else
		answer=answer+"1";
	}
	return answer;
}

string moduloDivision(string divident ,string divisor)
{
	int pick =divisor.length();
	int n =divident.length();
	string temp=divident.substr(0,pick);
	while(pick<n)
	{
		
		if(temp[0]=='1')
		{
			temp=xored(divisor,temp)+divident[pick];
		}
		else
		{
			temp=xored(std::string(pick,'0'),temp)+divident[pick];
		}
		pick=pick+1;
	}
	
	if(temp[0]=='1')
	{
		temp=xored(temp,divisor);
	}
	else
	{
		temp=xored(std::string(pick,'0'),temp);
	}
	return temp;
}

string encodeData(string data, string key)
{
	string answer;
	int l_key=key.length();
	string appended_data=data+std::string(l_key-1,'0');
	string remainder=moduloDivision(appended_data,key);
	string codeWord=data+remainder;
	cout<<"Remainder:"<<remainder<<endl;
	cout<<"Encoded Data(Data+Remainder):"<<codeWord<<endl;
	return codeWord;
}

int main()
{
	string s1,s2,s3;
	cout<<"Enter Data String"<<endl;
	cin>>s1;
	cout<<"Enter Generator String"<<endl;
	cin>>s2;
	cout<<"Enter Rececived String"<<endl;
	cin>>s3;
	string answer=encodeData(s1,s2);
	if(answer==s3)
	cout<<"No Error"<<endl;
	else
	cout<<"Error Ocuurred"<<endl;
	return 0;
}
