#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class Frame
{
	public:
	int id ;
	string data;
	
	Frame()
	{}
	Frame(int sid,string sdata)
	{
		this->id=sid;
		this->data=sdata;
	}
	
	void shuffleFrame(vector<Frame> f)
	{
		srand(time(NULL));
		for(int i=(int)f.size()-1;i>=0;i--)
		{
			int j=rand()%(i+1);
			Frame temp=f[j];
			f[j]=f[i];
			f[i]=temp;
		}
		cout<<"shuffled frame"<<endl;
		for(int i=0;i<f.size();i++)
		{
			cout<<"Frame "<<f[i].id<<" "<<f[i].data<<endl;
		}	
		sort(f.begin(),f.end(),[&](Frame &f1,Frame &f2){return f1.id<f2.id;});
		cout<<"After Sorting"<<endl;
		for(int i=0;i<f.size();i++)
		{
			cout<<"Frame "<<f[i].id<<" "<<f[i].data<<endl;
		}
		
	}	
};
int main()
{
	vector<Frame> f;
	Frame f1;
	int FrameSize;
	int m=0;
	int t=0;
	string message;
	cout<<"Enter Message"<<endl;
	getline(cin,message);
	cout<<"Enter FrameSize"<<endl;
	cin>>FrameSize;
	cout<<"Splitting The messages"<<endl;
	for(int i=0;i<message.size();i++)
	{
		int id=t;
		t++;
		string data;
		for(int j=0;j<FrameSize && m<message.size();j++)
		{
			data=data+message[m++];
			i=m;
		}
		
		Frame temp=Frame(id,data);
		f.push_back(temp);
		
	}
	//cout<<f.size()<<"t "<<t;
	for(int i=0;i<f.size();i++)
	{
		cout<<"Frame "<<i<<" "<<f[i].data<<endl;
	}
	f1.shuffleFrame(f);
	return 0;
}
