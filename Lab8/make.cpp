#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	ifstream in;
	ofstream out;

	in.open("courses04.csv",ios::in);
	out.open("courses.sql",ios::out);
	string line;
	while(getline(in,line))
	{
		stringstream s(line);
		string temp,cid,cname;
		getline(s,temp,',');
		cid = temp;
		getline(s,temp,'\n');
		cname = temp;
		out<<"INSERT INTO courses VALUES('"<<cid<<"','"<<cname<<"');"<<'\n';
	}
	in.close(),out.close();
	in.open("rooms.csv",ios::in);
	out.open("rooms.sql",ios::out);
	while(getline(in,line))
	{
		stringstream s(line);
		string temp,room_no,room_location;
		getline(s,temp,',');
		room_no = temp;
		getline(s,temp,'\n');
		room_location = temp;
		out<<"INSERT INTO room VALUES('"<<room_no<<"','"<<room_location<<"');"<<'\n';
	}
	in.close(),out.close();
	in.open("room-allocation.csv",ios::in);
	out.open("room_allocation.sql",ios::out);
	while(getline(in,line))
	{
		stringstream s(line);
		string temp,cid,date,time,room_id,roll_no;
		getline(s,temp,',');
		cid = temp;
		getline(s,temp,',');
		date = temp;
		getline(s,temp,',');
		time = temp;
		getline(s,temp,',');
		room_id = temp;
		getline(s,temp,'\n');
		roll_no = temp;
		out<<"INSERT INTO room_allocation VALUES('"<<cid<<"','"<<date<<"','"<<time<<"','"<<room_id<<"','"<<roll_no<<"');"<<'\n';
	}


}